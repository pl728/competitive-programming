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
        Debug debug = new Debug();

        int n = sc.ni();
        // try every possible square of size n x n
        Set<String> points = new HashSet<>();

        for (int i = 0; i < 4 * n + 1; i++) {
            int x = sc.ni(); int y = sc.ni();
            points.add(encodeInts(x, y));
        }


        for(int N = 2; N <= 50; N++) {
            for (int y = 0; y <= 50 - N; y++) {
                for (int x = 0; x <= 50 - N; x++) {
                    // x, y is the bottom left corner of the square
                    Set<String> pointsClone = new HashSet<>(points);
                    for(int a = x; a <= x + N; a++) {
                        pointsClone.remove(encodeInts(a, y));
                    }
                    for(int a = x; a <= x + N; a++) {
                        pointsClone.remove(encodeInts(a, y+N));
                    }
                    for(int a = y; a <= y + N; a++) {
                        pointsClone.remove(encodeInts(x, a));
                    }
                    for(int a = y; a <= y + N; a++) {
                        pointsClone.remove(encodeInts(x + N, a));
                    }
                    if(pointsClone.size() == 1) {
                        String[] remaining = new String[1];
                        for(String s : pointsClone) {
                            remaining[0] = s;
                        }
                        System.out.println(decodeInts(remaining[0])[0] + " " + decodeInts(remaining[0])[1]);
                        return;
                    }
                }
            }
        }


        // construct a graph
        // search the graph
        // if any nodes have no adjacent neighbors, return the node
        //
        // pick a node with 2 adjacent neighbors and start iterating one direction
        // (this guarantees that we start on a point on the square)
        //
        // when we hit a crossroads, one may lead to a dead end.
        // if a dead end is reached, return this node
        // else, the extra point lies in a corner of the square
        //

        Map<String, List<String>> adjList = new HashMap<>();


    }

    static String encodeInts(int x, int y) {
        return x + "," + y;
    }

    static int[] decodeInts(String s) {
        String[] ints = s.split(",");
        return new int[]{Integer.parseInt(ints[0]), Integer.parseInt(ints[1])};
    }

    static class Debug {
        int counter;

        public Debug() {
            this.counter = 0;
        }

        public void debug() {
            System.out.println("Debug: " + counter);
            this.counter++;
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
