// 1
    public static String intToRoman(int num) {
        String M[] = {"", "M", "MM", "MMM"};
        String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }


// 2

import java.util.LinkedHashMap;
public class Solution {

    private static LinkedHashMap<Integer, String> numToRoman = new LinkedHashMap<Integer, String>();
    static {
        numToRoman.put(1000, "M");
        numToRoman.put(900, "CM");
        numToRoman.put(500, "D");
        numToRoman.put(400, "CD");
        numToRoman.put(100, "C");
        numToRoman.put(90, "XC");
        numToRoman.put(50, "L");
        numToRoman.put(40, "XL");
        numToRoman.put(10, "X");
        numToRoman.put(9, "IX");
        numToRoman.put(5, "V");
        numToRoman.put(4, "IV");
        numToRoman.put(1, "I");
    }
    public String intToRoman(int num) {
        for (Integer i : numToRoman.keySet()) {
            if (num >= i) {
                return numToRoman.get(i) + intToRoman(num - i);
            }
        }
        return "";
    }
}


