package Week1;

public class SieveOfEratosthenes {

    public static void sieve(int n) {
        boolean[] prime = new boolean[n + 1];

        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }

        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (prime[i]) {
                System.out.println(i);
            }
        }
    }

}
