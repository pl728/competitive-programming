import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// code written by pl728 on codeforces

public class Main {
    static Map<Integer, List<Integer>> adj = new HashMap<>();
    static int[] dp = new int[300007];     // number of vertices we can save at vertex
    static int[] descendants = new int[300007];     // number of descendants
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int t = sc.nextInt();

        while (t-- != 0) {
            int n = sc.nextInt();
            for(int i = 1; i <= n; i++) {
                adj.put(i, new ArrayList<>());
            }
            for(int i = 0; i < n - 1; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                adj.get(x).add(y); adj.get(y).add(x);
            }

            dfs(1, 0);
            System.out.println(dp[1]);
        }
    }

    public static void dfs(int currNode, int parent_node) {
        descendants[currNode] = 1;
        dp[currNode] = 0;
        int s = 0;
        for(int child : adj.get(currNode)) {
            if(child != parent_node) {
                dfs(child, currNode);
                descendants[currNode] += descendants[child];
                // total number you can "save" in a child vertex if that vertex is infected
                s += dp[child];
            }
        }
        for(int child : adj.get(currNode)) {
            if (child != parent_node) {
                dp[currNode] = Math.max(dp[currNode], s - dp[child] + descendants[child] - 1);
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

        public int maxArray(int[] a) {
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < a.length; i++) {
                max = Math.max(max, a[i]);
            }

            return max;
        }
    }
}
