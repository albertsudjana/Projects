import edu.princeton.cs.algs4.Picture;

public class SeamCarver {
    private Picture pic;
    private double[][] MDistV;
    private double[][] MDistH;
    private double[][] energy;

    public SeamCarver(Picture picture) {
        pic = new Picture(picture);
    }

    public Picture picture() {
        Picture pic2 = new Picture(pic);
        return pic2;
    }                      // current picture

    public int width() {
        return pic.width();
    }                       // width of current picture

    public int height() {
        return pic.height();
    }                        // height of current picture

    public double energy(int x, int y) {
        try {
            if (x >= pic.width() || x < 0 || y >= pic.height() || y < 0) {
                throw new IndexOutOfBoundsException("Index out of bounds");
            }
            int rx, gx, bx, ry, gy, by;
            double deltax, deltay, nrg;
            rx = pic.get((x + 1) % width(), y).getRed()
                    - pic.get(Math.floorMod(x - 1, width()), y).getRed();
            gx = pic.get((x + 1) % width(), y).getGreen()
                    - pic.get(Math.floorMod(x - 1, width()), y).getGreen();
            bx = pic.get((x + 1) % width(), y).getBlue()
                    - pic.get(Math.floorMod(x - 1, width()), y).getBlue();
            ry = pic.get(x, (y + 1) % height()).getRed()
                    - pic.get(x, Math.floorMod(y - 1, height())).getRed();
            gy = pic.get(x, (y + 1) % height()).getGreen()
                    - pic.get(x, Math.floorMod(y - 1, height())).getGreen();
            by = pic.get(x, (y + 1) % height()).getBlue()
                    - pic.get(x, Math.floorMod(y - 1, height())).getBlue();
            deltax = Math.pow(rx, 2) + Math.pow(gx, 2) + Math.pow(bx, 2);
            deltay = Math.pow(ry, 2) + Math.pow(gy, 2) + Math.pow(by, 2);
            nrg = deltax + deltay;
            return nrg;
        } catch (IndexOutOfBoundsException e) {
            return 0.0;
        }
    }            // energy of pixel at column x and row y

    private void energize() {
        energy = new double[height()][width()];
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                energy[i][j] = energy(j, i);
            }
        }
    }

    private void mVertical(int x, int y) {
        double tempMin;
        if (y == 0) {
            tempMin = Integer.MAX_VALUE;
            for (int i = 0; i < 2; i++) {
                if (tempMin >= MDistV[x - 1][y + i]) {
                    tempMin = MDistV[x - 1][y + i];
                }
            }
        } else if (y == width() - 1) {
            tempMin = Integer.MAX_VALUE;
            for (int i = -1; i < 1; i++) {
                if (tempMin >= MDistV[x - 1][y + i]) {
                    tempMin = MDistV[x - 1][y + i];
                }
            }
        } else {
            tempMin = MDistV[x - 1][y - 1];
            for (int i = 0; i < 2; i++) {
                if (tempMin >= MDistV[x - 1][y + i]) {
                    tempMin = MDistV[x - 1][y + i];
                }
            }
        }
        MDistV[x][y] = tempMin + energy[x][y];
    }

    private void calculateAllMVertical() {
        MDistV = new double[height()][width()];
        if (width() == 1) {
            for (int i = 0; i < height(); i++) {
                MDistV[i][0] = 0;
            }
        } else {
            for (int z = 0; z < width(); z++) {
                MDistV[0][z] = energy[0][z];
            }
            for (int i = 1; i < height(); i++) {
                for (int j = 0; j < width(); j++) {
                    mVertical(i, j);
                }
            }
        }
    }

    private int[] buildMinVerticalArray() {
        int[] arr = new int[height()];
        if (width() == 1) {
            for (int i = 0; i < height(); i++) {
                arr[i] = 0;
            }
            return arr;
        } else {
            double minValue = Integer.MAX_VALUE;
            int startIndex = 0;
            int counter = 0;
            for (int j = 0; j < width(); j++) {
                if (minValue >= MDistV[height() - 1][j]) {
                    minValue = MDistV[height() - 1][j];
                    startIndex = j;
                }
            }
            arr[counter] = startIndex;
            counter++;
            for (int i = 1; i < height(); i++) {
                int tempIndex = 0;
                if (startIndex == 0) {
                    minValue = Integer.MAX_VALUE;
                    for (int k = 0; k < 2; k++) {
                        if (minValue >= MDistV[height() - i - 1][startIndex + k]) {
                            minValue = MDistV[height() - i - 1][startIndex + k];
                            tempIndex = startIndex + k;
                        }
                    }
                } else if (startIndex == width() - 1) {
                    minValue = Integer.MAX_VALUE;
                    for (int k = -1; k < 1; k++) {
                        if (minValue >= MDistV[height() - i - 1][startIndex + k]) {
                            minValue = MDistV[height() - i - 1][startIndex + k];
                            tempIndex = startIndex + k;
                        }
                    }
                } else {
                    minValue = MDistV[height() - i - 1][startIndex - 1];
                    tempIndex = startIndex - 1;
                    for (int k = 0; k < 2; k++) {
                        if (minValue >= MDistV[height() - i - 1][startIndex + k]) {
                            minValue = MDistV[height() - i - 1][startIndex + k];
                            tempIndex = startIndex + k;
                        }
                    }
                }
                startIndex = tempIndex;
                arr[counter] = startIndex;
                counter++;
            }
            int[] reverse = new int[arr.length];
            for (int a = 0; a < arr.length; a++) {
                reverse[a] = arr[arr.length - 1 - a];
            }
            return reverse;
        }
    }

    private void mHorizontal(int x, int y) {
        double tempMin;
        if (x == 0) {
            tempMin = Integer.MAX_VALUE;
            for (int i = 0; i < 2; i++) {
                if (tempMin >= MDistH[x + i][y - 1]) {
                    tempMin = MDistH[x + i][y - 1];
                }
            }
        } else if (x == height() - 1) {
            tempMin = Integer.MAX_VALUE;
            for (int i = -1; i < 1; i++) {
                if (tempMin >= MDistH[x + i][y - 1]) {
                    tempMin = MDistH[x + i][y - 1];
                }
            }
        } else {
            tempMin = MDistH[x - 1][y - 1];
            for (int i = 0; i < 2; i++) {
                if (tempMin >= MDistH[x + i][y - 1]) {
                    tempMin = MDistH[x + i][y - 1];
                }
            }
        }
        MDistH[x][y] = tempMin + energy[x][y];
    }

    private void calculateAllMHorizontal() {
        MDistH = new double[height()][width()];
        if (height() == 1) {
            for (int i = 0; i < width(); i++) {
                MDistH[0][i] = 0;
            }
        } else {
            for (int z = 0; z < height(); z++) {
                MDistH[z][0] = energy[z][0];
            }
            for (int i = 1; i < width(); i++) {
                for (int j = 0; j < height(); j++) {
                    mHorizontal(j, i);
                }
            }
        }
    }

    private int[] buildMinHorizontalArray() {
        int[] arr = new int[width()];
        if (height() == 1) {
            for (int i = 0; i < width(); i++) {
                arr[i] = 0;
            }
            return arr;
        } else {
            double minValue = Integer.MAX_VALUE;
            int startIndex = 0;
            int counter = 0;
            for (int j = 0; j < height(); j++) {
                if (minValue >= MDistH[j][width() - 1]) {
                    minValue = MDistH[j][width() - 1];
                    startIndex = j;
                }
            }
            arr[counter] = startIndex;
            counter++;
            for (int i = 1; i < width(); i++) {
                int tempIndex = 0;
                if (startIndex == 0) {
                    minValue = Integer.MAX_VALUE;
                    for (int k = 0; k < 2; k++) {
                        if (minValue >= MDistH[startIndex + k][width() - i - 1]) {
                            minValue = MDistH[startIndex + k][width() - i - 1];
                            tempIndex = startIndex + k;
                        }
                    }
                } else if (startIndex == height() - 1) {
                    minValue = Integer.MAX_VALUE;
                    for (int k = -1; k < 1; k++) {
                        if (minValue >= MDistH[startIndex + k][width() - i - 1]) {
                            minValue = MDistH[startIndex + k][width() - i - 1];
                            tempIndex = startIndex + k;
                        }
                    }
                } else {
                    minValue = MDistH[startIndex - 1][width() - i - 1];
                    tempIndex = startIndex - 1;
                    for (int k = 0; k < 2; k++) {
                        if (minValue >= MDistH[startIndex + k][width() - i - 1]) {
                            minValue = MDistH[startIndex + k][width() - i - 1];
                            tempIndex = startIndex + k;
                        }
                    }
                }
                startIndex = tempIndex;
                arr[counter] = startIndex;
                counter++;
            }
            int[] reverse = new int[arr.length];
            for (int a = 0; a < arr.length; a++) {
                reverse[a] = arr[arr.length - 1 - a];
            }
            return reverse;
        }
    }

    public int[] findHorizontalSeam() {
        energize();
        calculateAllMHorizontal();
        return buildMinHorizontalArray();
    }            // sequence of indices for horizontal seam

    public int[] findVerticalSeam() {
        energize();
        calculateAllMVertical();
        return buildMinVerticalArray();
    }

    // sequence of indices for vertical seam
    public void removeHorizontalSeam(int[] seam) {
        try {
            if (pic.width() > 1 && seam.length == pic.width()) {
                for (int i = 0; i < seam.length; i++) {
                    if (i == seam.length) {
                        throw new IllegalArgumentException();
                    }
                    if (i != seam.length - 1) {
                        if (seam[i] - seam[i + 1] > 1) {
                            throw new IllegalArgumentException();
                        }
                    }
                }
                SeamRemover sr = new SeamRemover();
                pic = sr.removeHorizontalSeam(pic, findHorizontalSeam());
            } else {
                throw new IllegalArgumentException();
            }
        } catch (IllegalArgumentException e) {
            return;
        }
    }  // remove horizontal seam from picture

    public void removeVerticalSeam(int[] seam) {
        try {
            if (pic.height() > 1 && seam.length == pic.height()) {
                for (int i = 0; i < seam.length; i++) {
                    if (i == seam.length) {
                        throw new IllegalArgumentException();
                    }
                    if (i != seam.length - 1) {
                        if (seam[i] - seam[i + 1] > 1) {
                            throw new IllegalArgumentException();
                        }
                    }
                }
                SeamRemover sr = new SeamRemover();
                pic = sr.removeVerticalSeam(pic, findVerticalSeam());
            } else {
                throw new IllegalArgumentException();
            }
        } catch (IllegalArgumentException e) {
            return;
        }
    }    // remove vertical seam from picture
}
