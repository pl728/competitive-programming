import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            String str = sc.nextLine();

            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < n; i++) {
                sb.append(9 - Integer.parseInt(String.valueOf(str.charAt(i))));
//                System.out.println("test: " + sb);

            }
            if(sb.charAt(0) == '0') {
                // add 11111...12
                sb.delete(0, 1);
                String x = sb.toString();
                StringBuilder oneonetwo = new StringBuilder();
                for(int i = 0; i < n - 1; i++) {
                    oneonetwo.append('1');
                }
                oneonetwo.append('2');
                String y = oneonetwo.toString();
                String z = addTwoNums(x, y);
                System.out.println(z);
            } else {
                System.out.println(sb);
            }
        }
    }

    static String addTwoNums(String x, String y) {
        // x is n-1, y is n
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for(int i = y.length() - 1; i >= 0; i--) {
            int toAdd;
            if(i == 0) {
                toAdd = Integer.parseInt(String.valueOf(y.charAt(i))) + carry;
            } else {
                toAdd = Integer.parseInt(String.valueOf(y.charAt(i))) + Integer.parseInt(String.valueOf(x.charAt(i - 1))) + carry;
                if(toAdd > 9) {
                    carry = 1;
                } else {
                    carry = 0;
                }

                toAdd %= 10;
            }

            sb.insert(0, toAdd);
        }


        return sb.toString();
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
