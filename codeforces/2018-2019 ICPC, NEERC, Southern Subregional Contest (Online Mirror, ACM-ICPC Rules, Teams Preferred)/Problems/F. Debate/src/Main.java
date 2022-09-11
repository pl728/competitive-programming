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

        int n = sc.ni();
        int ans = 0;
        int numSupporters = 0;
        int alice = 0;
        int bob = 0;
        int numCentrists = 0;
        Map<Integer, Queue<Integer>> map = new HashMap<>();
        map.put(0, new PriorityQueue<>(Collections.reverseOrder()));
        map.put(10, new PriorityQueue<>(Collections.reverseOrder()));
        map.put(1, new PriorityQueue<>(Collections.reverseOrder()));
        map.put(11, new PriorityQueue<>(Collections.reverseOrder()));
        while (n-- != 0) {
            int s = sc.ni();
            int a = sc.ni();
            map.get(s).add(a);

            if(s == 11) {
                alice++;bob++;
                numSupporters++;
                ans += a;
                numCentrists++;
            }
        }

        while(!map.get(1).isEmpty() && !map.get(10).isEmpty()) {
            alice++;bob++;
            numSupporters += 2;
            int next = map.get(1).remove() + map.get(10).remove();
            ans += next;
        }

        for(int i = 0; i < numCentrists; i++) {
            int max = returnMax(map.get(0), map.get(1), map.get(10));
            if(max == -1) break;
            ans += max;
        }

        System.out.println(ans);
    }
    // 11, 11, 00, 00, 10

    public static int returnMax(Queue<Integer> a, Queue<Integer> b, Queue<Integer> c) {
        if(a.isEmpty() && b.isEmpty() && c.isEmpty()) {
            return -1;
        }

        if(a.isEmpty() && b.isEmpty()) {
            return c.remove();
        }
        if(a.isEmpty() && c.isEmpty()) {
            return b.remove();
        }
        if(b.isEmpty() && c.isEmpty()) {
            return a.remove();
        }

        if(a.isEmpty()) {
            if(b.peek() > c.peek()) {
                return b.remove();
            }
            return c.remove();
        }
        if(b.isEmpty()) {
            if(a.peek() > c.peek()) {
                return a.remove();
            }
            return c.remove();
        }
        if(c.isEmpty()) {
            if(b.peek() > a.peek()) {
                return b.remove();
            }
            return a.remove();
        }

        if(a.peek() >= b.peek() && a.peek() >= c.peek()) {
            return a.remove();
        } else if(b.peek() >= c.peek() && b.peek() >= a.peek()) {
            return b.remove();
        } else {
            return c.remove();
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
