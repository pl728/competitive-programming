package cf.contest.round797;

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int n = sc.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            int indexLargestX = 0;
            for(int i = 0; i < n; i++) {
                x[i] = sc.nextInt();
                if(x[indexLargestX] < x[i]) {
                    indexLargestX = i;
                }

            }
            boolean yHasPositive = false;
            for(int i = 0; i < n; i++) {
                y[i] = sc.nextInt();
                if(y[i] != 0) {
                    yHasPositive = true;
                }
            }

            if(x[indexLargestX] == 0) {
                if(yHasPositive) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }
            } else {
                int numberOfOperations = x[indexLargestX] - y[indexLargestX];
//                System.out.println(numberOfOperations);
//                System.out.println(indexLargestX);
                if(numberOfOperations < 0) {
                    System.out.println("NO");
                    continue;
                }
                for(int i = 0; i < n; i++) {
                    x[i] = Math.max(0, x[i] - numberOfOperations);
                }

                boolean ans = true;
                for(int i = 0; i < n; i++) {
                    if(x[i] != y[i]) {
                        ans = false;
                    }
                }

                if (ans) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }

//                System.out.println(Arrays.toString(x));
//                System.out.println(Arrays.toString(y));

            }



            // find the first nonzero element of array X
            //


        }
    }
}