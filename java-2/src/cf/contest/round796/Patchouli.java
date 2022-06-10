package cf.contest.round796;

import java.util.Scanner;

public class Patchouli {
    public static void main(String[] args) {
        // [2, 2, 2, 3, 3]
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int x = 0; x < t; x++) {
            int n = sc.nextInt();
            int[] a = new int[n];
            boolean hasOdd = false;
            int numEven = 0;
            boolean hasSpecial = false;
            int smallestEven = 2;
            for(int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                if(a[i] % 2 == 1) {
                    hasOdd = true;
                } else {
                    numEven++;
                }
                if(!hasSpecial && (a[i] - 2) % 4 == 0) {
                    hasSpecial = true;
                }

                if(a[i] % 2 == 0) {
                    smallestEven = Math.min(smallestEven, a[i]);
                }
            }
            if(hasOdd) {
                System.out.println(numEven);
                continue;
            } else {
                // array has no odd numbers, need to make an odd number
                if(hasSpecial) {
                    System.out.println(numEven);
                } else {

                }
            }
        }
    }

    public static int f(int x) {
        int count = 0;
        while(x % 2 == 0) {
            x /= 2;
            count++;
        }

        return count;
    }
}