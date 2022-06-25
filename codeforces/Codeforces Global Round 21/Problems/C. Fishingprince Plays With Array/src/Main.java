import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] a = sc.readIntArray(n);
            int k = sc.nextInt();
            int[] b = sc.readIntArray(k);

            List<long[]> deconstructA = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                if(a[i] % m != 0) {
                    if(deconstructA.size() != 0 && deconstructA.get(deconstructA.size() - 1)[0] == a[i]) {
                        deconstructA.get(deconstructA.size() - 1)[1]++;
                    } else {
                        deconstructA.add(new long[]{a[i], 1});
                    }

                } else {
                    int x = a[i];
                    int numDivide = 1;
                    while(x % m == 0) {
                        x /= m;
                        numDivide *= m;
                    }

                    if(deconstructA.size() != 0 && deconstructA.get(deconstructA.size() - 1)[0] == x) {
                        deconstructA.get(deconstructA.size() - 1)[1] += numDivide;
                    } else {
                        deconstructA.add(new long[]{x, numDivide});
                    }
                }
            }

            List<long[]> deconstructB = new ArrayList<>();
            for(int i = 0; i < k; i++) {
                if(b[i] % m != 0) {
                    if(deconstructB.size() != 0 && deconstructB.get(deconstructB.size() - 1)[0] == b[i]) {
                        deconstructB.get(deconstructB.size() - 1)[1]++;
                    } else {
                        deconstructB.add(new long[]{b[i], 1});
                    }

                } else {
                    int x = b[i];
                    int numDivide = 1;
                    while(x % m == 0) {
                        x /= m;
                        numDivide *= m;
                    }

                    if(deconstructB.size() != 0 && deconstructB.get(deconstructB.size() - 1)[0] == x) {
                        deconstructB.get(deconstructB.size() - 1)[1] += numDivide;
                    } else {
                        deconstructB.add(new long[]{x, numDivide});
                    }
                }
            }

            if(deconstructA.size() != deconstructB.size()) {
                System.out.println("No");
                continue;
            }

            boolean ans = true;
            for(int i = 0; i < deconstructA.size(); i++) {
                if(!Arrays.equals(deconstructA.get(i), deconstructB.get(i))) {
                    ans = false;
                    break;
                }
            }

            if(ans) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
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

        public long gcdLong(long a, long b)
        {
            if(a%b==0)
                return b;
            else
                return gcdLong(b,a%b);
        }

        public long lcmLong(long a, long b) {
            return a * b / gcdLong(a, b);
        }
    }

    static class ArrayUtils {
        public ArrayUtils() {
        }

        public static int[] reverse(int[] a)
        {
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
