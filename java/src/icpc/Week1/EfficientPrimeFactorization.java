package icpc.Week1;

import java.util.ArrayList;

public class EfficientPrimeFactorization {

    // calculate SPF using sieve of eratosthenes
    public static int[] spf(int n) {
        boolean[] prime = new boolean[n + 1];
        int[] spf = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }

        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = false;
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    public static ArrayList<Integer> epf(int n) {
        ArrayList<Integer> prime_factors = new ArrayList<>();
        int[] spf = spf(n);
        while (n != 1) {
            if (spf[n] == 0) {
                prime_factors.add(n);
                n = 1;
            } else {
                prime_factors.add(spf[n]);
                n = n / spf[n];
            }

        }

        return prime_factors;
    }
}
