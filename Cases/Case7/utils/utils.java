package utils;

public class utils {
    
    public static double getRandom(){
        return Math.random();
    }

    public static boolean inRange(double pIni, double pEnd, double pValue){
        return ((pIni < pValue) && (pValue <= pEnd));
    }

}
