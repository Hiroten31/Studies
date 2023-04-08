package org.example;

public class MainStringChallenge {
    public static String StringChallenge(int num) {
        String str = String.valueOf(num);
        int strLength = str.length();
        for(int i = 1; i < strLength; i++) {
            int current = num%10;
            num = num/10;
            int next = num%10;
            if(current%2 == 0) {
                if(next%2 == 0 && next != 0) {
                    str = num + "*" + str.substring(strLength-i);
                }
            } else {
                if(next%2 == 1) {
                    str = num + "-" + str.substring(strLength-i);
                }
            }
        }
        return str;
    }
    public static void main(String[] args) {
        int s = 56443304;
        System.out.println(StringChallenge(s));
    }
}