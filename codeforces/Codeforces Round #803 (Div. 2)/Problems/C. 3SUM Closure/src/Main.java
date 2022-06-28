import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();
        // cannot have more than 2 positive numbers or 32
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int[] a = sc.readIntArray(n);
            List<Integer> positive = new ArrayList<>();
            List<Integer> negative = new ArrayList<>();
            int numZero = 0;
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) {
                    negative.add(a[i]);

                } else if (a[i] > 0) {
                    positive.add(a[i]);
                } else {
                    numZero++;
                }
                set.add(a[i]);
                if(positive.size() > 2 || negative.size() > 2) {
                    break;
                }
            }

            if (positive.size() > 2 || negative.size() > 2) {
                // has more than 2 positives or negatives
                System.out.println("NO");
                continue;
            }
            int z = positive.size() + negative.size();
            if(z == 0 || z == 1) {
                System.out.println("YES");
                continue;
            }
            boolean ans = true;
            int[] posNeg = new int[z];
            int c = 0;
            for (int i = 0; i < positive.size(); i++) {
                posNeg[c++] = positive.get(i);
            }
            for (int i = 0; i < negative.size(); i++) {
                posNeg[c++] = negative.get(i);
            }
            for (int i = 0; i < z; i++) {
                for (int j = 0; j < z; j++) {
                    for (int k = 0; k < z; k++) {
                        if (i != j && j != k && i != k) {
                            if (!set.contains(posNeg[i] + posNeg[j] + posNeg[k])) {
                                ans = false;
                            }
                        }
                    }
                }
            }
            // has a zero, we check pairs as well because we will always need to add pairs with 0 and this
            // result must be in the set
            if (numZero > 0) {
                for (int i = 0; i < z; i++) {
                    for (int j = 0; j < z; j++) {
                        if (i != j) {
                            if (!set.contains(posNeg[i] + posNeg[j])) {
                                ans = false;
                            }
                        }
                    }
                }
            }

            if(!ans) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }


        }
    }

    static class FastReader {
        /**
         * Uses BufferedReader and StringTokenizer for quick java I/O
         * get next int, long, double, string
         * get int, long, double, string arrays, both primitive and wrapped object when array contains all elements
         * on one line, and we know the array size (n)
         * next: gets next space separated item
         * nextLine: returns entire line as space
         */
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            this.br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String[] readStringArrayLine(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
        }

        public String[] readStringArrayLines(int n) {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.next();
            }
            return result;
        }

        // to parse something else:
        // T x = T.parseT(fastReader.next());
        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public Integer[] readIntArrayObject(int n) {
            Integer[] result = new Integer[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public char[] readCharArray(int n) {
            return this.nextLine().toCharArray();
        }

    }

    static class MathUtils {
        public MathUtils() {
        }

        public long gcdLong(long a, long b) {
            if (a % b == 0)
                return b;
            else
                return gcdLong(b, a % b);
        }

        public long lcmLong(long a, long b) {
            return a * b / gcdLong(a, b);
        }
    }

    static class ArrayUtils {
        public ArrayUtils() {
        }

        public static int[] reverse(int[] a) {
            int n = a.length;
            int[] b = new int[n];
            int j = n;
            for (int i = 0; i < n; i++) {
                b[j - 1] = a[i];
                j = j - 1;
            }

            return b;
        }

        public int sumArray(int[] a) {
            int ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }
    }
}
