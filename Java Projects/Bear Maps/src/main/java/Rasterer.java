import java.util.HashMap;
import java.util.Map;

/**
 * This class provides all code necessary to take a query box and produce
 * a query result. The getMapRaster method must return a Map containing all
 * seven of the required fields, otherwise the front end code will probably
 * not draw the output correctly.
 */
public class Rasterer {
    private double ROOT_ULLAT = 37.892195547244356, ROOT_ULLON = -122.2998046875,
            ROOT_LRLAT = 37.82280243352756, ROOT_LRLON = -122.2119140625;
    private int TILE_SIZE = 256;
    private int depth;
    private double[] lonDPPs = {0.00034332275390625, 0.000171661376953125, 0.0000858306884765625,
        0.00004291534423828125, 0.000021457672119140625, 0.000010728836059570312,
        0.000005364418029785156, 0.000002682209014892578};

    public Rasterer() {

    }

    public double lonDPPCalculate(double ulLon, double lrLon, double width) {
        return Math.abs(ulLon - lrLon) / width;
    }

    public void findDepth(double ulLon, double lrLon, double width) {
        double lonDPP = lonDPPCalculate(ulLon, lrLon, width);
        for (int i = 0; i < lonDPPs.length; i++) {
            if (lonDPPs[i] <= lonDPP) {
                depth = i;
                return;
            }
        }
        depth = 7;
        return;
    }

    public int convertToXUL(double ul, double lr, int d) {
        double denom = lonDPPCalculate(ROOT_ULLON, ROOT_LRLON, Math.pow(2, d));
        int result = (int) ((ul - ROOT_ULLON) / denom);
        return result;
    }

    public int convertToXLR(double ul, double lr, int d) {
        double denom = lonDPPCalculate(ROOT_ULLON, ROOT_LRLON, Math.pow(2, d));
        int result = (int) ((lr - ROOT_LRLON) / denom);
        result = (int) Math.pow(2, d) + result - 1;
        return result;
    }

    public int convertToYUL(double ul, double lr, int d) {
        double denom = lonDPPCalculate(ROOT_ULLAT, ROOT_LRLAT, Math.pow(2, d));
        int result = (int) ((ul - ROOT_ULLAT) / denom);
        return Math.abs(result);
    }

    public int convertToYLR(double ul, double lr, int d) {
        double denom = lonDPPCalculate(ROOT_ULLAT, ROOT_LRLAT, Math.pow(2, d));
        int result = (int) ((lr - ROOT_LRLAT) / denom);
        result = (int) Math.pow(2, d) - result - 1;
        return result;
    }


    public double convertToUlLon(int x, int d) {
        double dPP = lonDPPCalculate(ROOT_ULLON, ROOT_LRLON, Math.pow(2, d));
        return x * dPP + ROOT_ULLON;
    }

    public double convertToLrLon(int x, int d) {
        double dPP = lonDPPCalculate(ROOT_ULLON, ROOT_LRLON, Math.pow(2, d));
        return (x - Math.pow(2, d) + 1) * dPP + ROOT_LRLON;
    }

    public double convertToUlLat(int y, int d) {
        double dPP = lonDPPCalculate(ROOT_ULLAT, ROOT_LRLAT, Math.pow(2, d));
        return (-y * dPP + ROOT_ULLAT);
    }

    public double convertToLrLat(int y, int d) {
        double dPP = lonDPPCalculate(ROOT_ULLAT, ROOT_LRLAT, Math.pow(2, d));
        return (-y + Math.pow(2, d) - 1) * dPP + ROOT_LRLAT;
    }

    public String[][] convertToImages(int xUp, int yUp, int xDown, int yDown, int d) {
        String[][] imageArray = new String[yDown - yUp + 1][xDown - xUp + 1];
        String extension = ".png";
        for (int i = 0; i < imageArray.length; i++) {
            for (int j = 0; j < imageArray[0].length; j++) {
                String image = "d" + d + "_x";
                image += xUp + j + "_y";
                image += yUp + i + extension;
                imageArray[i][j] = image;
            }
        }
        return imageArray;


    }

    /**
     * Takes a user query and finds the grid of images that best matches the query. These
     * images will be combined into one big image (rastered) by the front end. <br>
     * <p>
     * The grid of images must obey the following properties, where image in the
     * grid is referred to as a "tile".
     * <ul>
     * <li>The tiles collected must cover the most longitudinal distance per pixel
     * (LonDPP) possible, while still covering less than or equal to the amount of
     * longitudinal distance per pixel in the query box for the user viewport size. </li>
     * <li>Contains all tiles that intersect the query bounding box that fulfill the
     * above condition.</li>
     * <li>The tiles must be arranged in-order to reconstruct the full image.</li>
     * </ul>
     *
     * @param params Map of the HTTP GET request's query parameters - the query box and
     *               the user viewport width and height.
     * @return A map of results for the front end as specified: <br>
     * "render_grid"   : String[][], the files to display. <br>
     * "raster_ul_lon" : Number, the bounding upper left longitude of the rastered image. <br>
     * "raster_ul_lat" : Number, the bounding upper left latitude of the rastered image. <br>
     * "raster_lr_lon" : Number, the bounding lower right longitude of the rastered image. <br>
     * "raster_lr_lat" : Number, the bounding lower right latitude of the rastered image. <br>
     * "depth"         : Number, the depth of the nodes of the rastered image <br>
     * "query_success" : Boolean, whether the query was able to successfully complete; don't
     * forget to set this to true on success! <br>
     */
    public Map<String, Object> getMapRaster(Map<String, Double> params) {
        System.out.println(params);
        Map<String, Object> results = new HashMap<>();
        double targetUlLat = params.get("ullat");
        double targetUlLon = params.get("ullon");
        double targetLrLat = params.get("lrlat");
        double targetLrLon = params.get("lrlon");
        double width = params.get("w");
        double height = params.get("h");
        findDepth(targetUlLon, targetLrLon, width);
        results.put("depth", depth);
        int xUl = convertToXUL(targetUlLon, targetLrLon, depth);
        int xLr = convertToXLR(targetUlLon, targetLrLon, depth);
        int yUl = convertToYUL(targetUlLat, targetLrLat, depth);
        int yLr = convertToYLR(targetUlLat, targetLrLat, depth);
        System.out.println(xUl);
        System.out.println(yUl);
        System.out.println(xLr);
        System.out.println(yLr);
        results.put("raster_ul_lon", convertToUlLon(xUl, depth));
        results.put("raster_ul_lat", convertToUlLat(yUl, depth));
        results.put("raster_lr_lon", convertToLrLon(xLr, depth));
        results.put("raster_lr_lat", convertToLrLat(yLr, depth));
        results.put("render_grid", convertToImages(xUl, yUl, xLr, yLr, depth));
        results.put("query_success", true);

        return results;
    }
}
