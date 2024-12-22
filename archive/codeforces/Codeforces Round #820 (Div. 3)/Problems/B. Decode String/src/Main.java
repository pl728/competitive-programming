import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int q = sc.ni();
        while (q-- != 0) {
            int n = sc.ni();
            String s = sc.ns();
            StringBuilder sb = new StringBuilder();
            List<Integer> decode = new ArrayList<>();

            // test for 00
            //
            if(s.length() < 3) {
                for (int x = 0; x < s.length(); x++) {
                    decode.add(Character.getNumericValue(s.charAt(x)));
                }
                for (int j : decode) {
                    sb.append(Character.toChars(j + 96));
                }
                System.out.println(sb);
                continue;
            }

            Stack<Integer> stack = new Stack<>();

            int lastAdded = n - 1;
            int i = n - 3;
            while(i >= 0) {
                if(s.charAt(i + 2) == '0') {
                    stack.push(Integer.parseInt(s.charAt(i) + "" + s.charAt(i + 1)));
                    lastAdded = i;
                    i -= 3;
                } else {
                    stack.push(Character.getNumericValue(s.charAt(i + 2)));
                    lastAdded = i + 2;
                    i -= 1;
                }
            }
            if(i == -3) {

            } else if(i == -2) {
                stack.push(Character.getNumericValue(s.charAt(0)));

            } else if(i == -1) {
                if(lastAdded == 1) {
                    stack.push(Character.getNumericValue(s.charAt(0)));
                } else {
                    // from index 2
                    stack.push(Character.getNumericValue(s.charAt(1)));
                    stack.push(Character.getNumericValue(s.charAt(0)));
                }
            }

            while (!stack.isEmpty()) {
                sb.append(Character.toChars(stack.pop() + 96));
            }

            System.out.println(sb);
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

        // to parse something else:
        // T x = T.parseT(fastReader.next());
        public int ni() {
            return Integer.parseInt(next());
        }

        public String ns() {
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

        public int[] readIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.ni();
            }
            return result;
        }

        public long[] readLongArray(int n) {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nl();
            }
            return result;
        }

        public Integer[] readIntArrayObject(int n) {
            Integer[] result = new Integer[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.ni();
            }
            return result;
        }

        public long nl() {
            return Long.parseLong(next());
        }

        public char[] readCharArray(int n) {
            return this.ns().toCharArray();
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

        public int sumIntArrayInt(int[] a) {
            int ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }

        public long sumLongArrayLong(int[] a) {
            long ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }

    }

    public static int lowercaseToIndex(char c) {
        return (int) c - 97;
    }

    public static int indexToLowercase(int i) {
        return (char) i - 97;
    }

}
