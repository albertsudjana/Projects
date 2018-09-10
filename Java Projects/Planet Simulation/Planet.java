public class Planet {
    public double xxPos;
    public double yyPos;
    public double xxVel;
    public double yyVel;
    public double mass;
    public String imgFileName;
    private static final double g = 6.67e-11;

    public Planet(double xP, double yP, double xV, double yV, double m, String img){
        xxPos = xP;
        yyPos = yP;
        xxVel = xV;
        yyVel = yV;
        mass = m;
        imgFileName = img;
    }

    public Planet(Planet p){
        xxPos = p.xxPos;
        yyPos = p.yyPos;
        xxVel = p.xxVel;
        yyVel = p.yyVel;
        mass = p.mass;
        imgFileName = p.imgFileName;
    }
    
    public double calcDistance(Planet p){
        return Math.sqrt(Math.pow(xxPos - p.xxPos, 2) + Math.pow(yyPos - p.yyPos, 2));
    }

    public double calcForceExertedBy(Planet p){
        return (g * mass * p.mass) / Math.pow(calcDistance(p), 2);
    }

    public double calcForceExertedByX(Planet p){
        return (calcForceExertedBy(p) * (p.xxPos - xxPos)) / calcDistance(p);
    }

    public double calcForceExertedByY(Planet p){
        return (calcForceExertedBy(p) * (p.yyPos - yyPos)) / calcDistance(p);
    }

    public double calcNetForceExertedByX(Planet[] p){
        double netForceX = 0;
        for(int i = 0; i < p.length; i++){
            if(!this.equals(p[i])){
                netForceX = netForceX + calcForceExertedByX(p[i]);
            }
        }
        return netForceX;
    }
    
    public double calcNetForceExertedByY(Planet[] p){
        double netForceY = 0;
        for(int i = 0; i < p.length; i++){
            if(!this.equals(p[i])){
                netForceY = netForceY + calcForceExertedByY(p[i]);
            }
        }
        return netForceY;
    }
    
    public void update(double dt, double fX, double fY){
        double netAccX = fX / mass;
        double netAccY = fY / mass;
        xxVel = xxVel + (dt * netAccX);
        yyVel = yyVel + (dt * netAccY);
        xxPos = xxPos + (dt * xxVel);
        yyPos = yyPos + (dt * yyVel);
    }
    
    public void draw(){
        StdDraw.picture(xxPos, yyPos, "images/" + imgFileName);
    }




















}
