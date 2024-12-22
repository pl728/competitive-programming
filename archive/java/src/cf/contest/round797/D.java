package cf.contest.round797;

import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();
            int numWhite = 0;
            for(int i = 0; i < k; i++) {
                if(s.charAt(i) == 'W') {
                    numWhite++;
                }
            }

            int minFlips = numWhite;

            int start = 1;
            int end = start + k - 1;
            while(end < n){
                if(s.charAt(start - 1) == 'W') {
                    numWhite--;
                }
                if(s.charAt(end) == 'W'){
                    numWhite++;
                }

                minFlips = Math.min(minFlips, numWhite);
                start++;
                end++;
            }

            System.out.println(minFlips);

        }
    }
}