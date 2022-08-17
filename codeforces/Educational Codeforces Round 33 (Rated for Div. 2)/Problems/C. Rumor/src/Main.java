import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";
    static boolean[] seen;
    
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int n = sc.nextInt();
        int m = sc.nextInt();
        seen = new boolean[n+1];

        long[] c = sc.readLongArray(n);
        Map<Integer, List<Integer>> friends = new HashMap<>();


        for(int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            friends.putIfAbsent(x, new ArrayList<>());
            friends.putIfAbsent(y, new ArrayList<>());

            friends.get(x).add(y);
            friends.get(y).add(x);
        }

        Queue<Integer> q = new LinkedList<>();
        long ans = 0;
        for(int i = 1; i <= n; i++) {
            if (!seen[i]) {
                ans += dfs(i, c, friends);
            }
        }

        System.out.println(ans);
    }

    static long dfs(int friend, long[] cost, Map<Integer, List<Integer>> graph) {
        long ans = cost[friend - 1];
        seen[friend] = true;
        if (graph.containsKey(friend)) {
            List<Integer> friendsList = graph.get(friend);
            for (int otherFriend : friendsList) {
                if (!seen[otherFriend]) {
                    ans = Math.min(ans, dfs(otherFriend, cost, graph));
                }
            }

        }
        return ans;
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
        
        public long[] readLongArray(int n) {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
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

        public int sumIntArrayInt(int[] a) {
            int ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }

        public long sumLongArray(long[] a) {
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
