import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.sql.Array;
import java.util.*;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int tc = sc.ni();
        while (tc-- != 0) {
            String s = sc.ns();
            int n = s.length();
            int cost = index(s.charAt(n-1)) - index(s.charAt(0));
            int steps = 1;

            Map<Integer, List<Integer>> treeMap = new TreeMap<>();

            if (cost < 0) {
                for(int i = 1; i < n; i++) {
                    if(index(s.charAt(i)) <= index(s.charAt(0))
                            && index(s.charAt(i)) >= index(s.charAt(n-1))) {
                        treeMap.putIfAbsent(index(s.charAt(0)) - index(s.charAt(i)), new ArrayList<>());
                        treeMap.get(index(s.charAt(0)) - index(s.charAt(i))).add(i+1);
                        steps++;
                    }
                }
            } else {
                for(int i = 1; i < n; i++) {
                    if(index(s.charAt(i)) >= index(s.charAt(0))
                            && index(s.charAt(i)) <= index(s.charAt(n-1))) {
                        treeMap.putIfAbsent(index(s.charAt(i)) - index(s.charAt(0)), new ArrayList<>());
                        treeMap.get(index(s.charAt(i)) - index(s.charAt(0))).add(i+1);
                        steps++;
                    }
                }
            }

            int[] output = new int[steps];
            output[0] = 1;
            int i = 1;
            for(int k : treeMap.keySet()) {
                List<Integer> list = treeMap.get(k);
                for(int l : list) {
                    output[i++] = l;
                }
            }

            System.out.println(Math.abs(cost) + " " + steps);
            for(int k = 0; k < steps; k++) {
                System.out.print(output[k] + " ");
            }
            System.out.println();

        }
    }

    static int index(char c) {
        return (int) c - 96;
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
