import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int tc = sc.ni();
        while (tc-- != 0) {
            int a = sc.ni();
            int b = sc.ni();
            String s = sc.ns();
            int n = s.length();
            Map<Character, Integer> letterCounts = new HashMap<>();
            letterCounts.putIfAbsent('0',0);
            letterCounts.putIfAbsent('1',0);
            letterCounts.putIfAbsent('?',0);

            for (int i = 0; i < s.length(); i++) {
                letterCounts.put(s.charAt(i), letterCounts.get(s.charAt(i)) + 1);
            }

            int i = 0, j = n - 1;
            char[] x = s.toCharArray();
            boolean ans = true;

            while(i < j && ans) {
                if (x[i] == '?' && x[j] != '?') {
                    x[i] = x[j];
                    letterCounts.put(x[j], letterCounts.get(x[j]) + 1);
                } else if (x[j] == '?' && x[i] != '?') {
                    x[j] = x[i];
                    letterCounts.put(x[i], letterCounts.get(x[i]) + 1);
                } else if(x[i] != x[j]) {
                    ans = false;
                }
                i++;j--;
            }

            if(!ans) {
                System.out.println(-1);
                continue;
            }

            if (letterCounts.get('0') > a || letterCounts.get('1') > b) {
                System.out.println(-1);
                continue;
            }


            i = 0;
            j = n - 1;
            while (i < j && ans) {
                if (x[i] == '?' && x[j] == '?') {
                    if(letterCounts.get('1') + 2 <= a) {
                        x[i] = '1';
                        x[j] = '1';
                        letterCounts.put('1', letterCounts.get('1') + 2);
                    } else if (letterCounts.get('0') + 2 <= b) {
                        x[i] = '0';
                        x[j] = '0';
                        letterCounts.put('0', letterCounts.get('0') + 2);
                    } else {
                        ans = false;
                    }
                }
                i++;j--;
            }
            if(n % 2 == 1 && x[i] == '?') {
                if (letterCounts.get('0') < a) {
                    x[i] = '0';
                } else if (letterCounts.get('1') < b) {
                    x[i] = '1';
                } else {
                    ans = false;
                }
            }
            if(ans) System.out.println(String.valueOf(x));
            else System.out.println(-1);
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
}
