class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        while (num >= 1000) {
            ret += "M";
            num -= 1000;
        }
        if (num >= 900) {
            num -= 900;
            ret += "CM";
        }
        if (num >= 500) {
            num -= 500;
            ret += "D";
        }
        if (num >= 400) {
            num -= 400;
            ret += "CD";
        }
        while (num >= 100) {
            num -= 100;
            ret += "C";
        }
        if (num >= 90) {
            num -= 90;
            ret += "XC";
        }
        if (num >= 50) {
            num -= 50;
            ret += "L";
        }
        if (num  >= 40) {
            num -= 40;
            ret += "XL";
        }
        while (num >= 10) {
            num -= 10;
            ret += "X";
        }
        if (num >= 9) {
            num -= 9;
            ret += "IX";
        }
        if (num >= 5) {
            num -= 5;
            ret += "V";
        }
        if (num >= 4) {
            num -= 4;
            ret += "IV";
        }
        while (num >= 1) {
            num -= 1;
            ret += "I";
        }
        return ret;
    }
};
