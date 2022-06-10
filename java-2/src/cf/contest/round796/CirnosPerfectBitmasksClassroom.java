package cf.contest.round796;

import java.util.Scanner;

public class CirnosPerfectBitmasksClassroom {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int x = sc.nextInt();
            if(x == 1) {
                System.out.println(3);
                continue;
            }
            int and = x&1;
            int xor = x^1;
            if(and > 0 && xor > 0) {
                System.out.println(1);
                continue;
            }

            String bits = Integer.toBinaryString(x);
            int idx_last_1 = 0;
            for(int i = bits.length() - 1; i >= 0; i--) {
                if(bits.charAt(i) == '1') {
                    idx_last_1 = i;
                    break;
                }
            }

            StringBuilder sb1 = new StringBuilder();
            for(int i = 0; i < bits.length(); i++) {
                if(i == idx_last_1) {
                    sb1.append('1');
                } else {
                    sb1.append('0');
                }
            }
            and = x&Integer.parseInt(sb1.toString(), 2);
            xor = x^Integer.parseInt(sb1.toString(), 2);
            if(and > 0 && xor > 0) {
                System.out.println(Integer.parseInt(sb1.toString(), 2));
                continue;
            }
            StringBuilder sb2 = new StringBuilder();
            for(int i = 0; i < bits.length(); i++) {
                if(i == idx_last_1 || i == bits.length() - 1) {
                    sb2.append('1');
                } else {
                    sb2.append('0');
                }
            }
            System.out.println(Integer.parseInt(sb2.toString(), 2));


        }
    }
}