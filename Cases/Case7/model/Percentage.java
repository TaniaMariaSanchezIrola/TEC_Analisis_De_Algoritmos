package model;

public class Percentage{
    public double iniRange;
    public double endRange;
    public double percentage;

    public Percentage(double pIniRange, double pEndRange, double pPercentage){
        this.iniRange = pIniRange;
        this.endRange = pEndRange;
        this.percentage = pPercentage;
    }

    @Override
    public String toString(){
        return "Percentage{ iniRange:" + this.iniRange + ", endRange: "
                + this.endRange + ", percentage: " + this.percentage + " }" ; 
    }

}
