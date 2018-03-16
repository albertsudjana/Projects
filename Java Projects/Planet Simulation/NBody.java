public class NBody{
    public static double readRadius(String file){
        In in = new In(file);
        in.readDouble();
        return in.readDouble();
    }

    public static Planet[] readPlanets(String file){
        In in = new In(file);
        Planet[] array = new Planet[in.readInt()];
        in.readDouble();
        for(int i = 0; i < array.length; i++){
            Planet p = new Planet(in.readDouble(), in.readDouble(), in.readDouble(), in.readDouble(), in.readDouble(), in.readString());
            array[i] = p;
        }
        return array;
    }

    public static void main(String[] args){
        double T = Double.parseDouble(args[0]);
        double dt = Double.parseDouble(args[1]);
        String filename = args[2];
        double radius = readRadius(filename);
        Planet[] p = readPlanets(filename);
        StdDraw.setScale(-radius, radius);
        StdDraw.picture(0, 0, "images/starfield.jpg");
        for(Planet i: p){
            i.draw();
        }
        StdDraw.enableDoubleBuffering();
        int time = 0;
        while(time < T){
            double[] xForces = new double[p.length];
            double[] yForces = new double[p.length];
            for(int j = 0; j < p.length; j++){
                xForces[j] = p[j].calcNetForceExertedByX(p);
                yForces[j] = p[j].calcNetForceExertedByY(p);
            }
            for(int k = 0; k < p.length; k++ ){
                p[k].update(dt, xForces[k], yForces[k]);
            }
            StdDraw.picture(0, 0, "images/starfield.jpg");
            for(Planet l: p){
                l.draw();
            }
            StdDraw.show();
            StdDraw.pause(10);
            time += dt;
        }
        StdOut.printf("%d\n", p.length);
        StdOut.printf("%.2e\n", radius);
        for (int i = 0; i < p.length; i++) {
            StdOut.printf("%11.4e %11.4e %11.4e %11.4e %11.4e %12s\n",
                  p[i].xxPos, p[i].yyPos, p[i].xxVel,
                  p[i].yyVel, p[i].mass, p[i].imgFileName);   
        }
    }
}
