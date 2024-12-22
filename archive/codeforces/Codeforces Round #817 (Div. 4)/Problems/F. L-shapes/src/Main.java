import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int tc = sc.ni();
        while (tc-- != 0) {
            int n = sc.ni(), m = sc.ni();
            char[][] grid = new char[n][m];
            int[][] id = new int[n][m];
            // iterate through each cell
            // keep track of a set of x cords, y cords
            // if either > 2, return no
            // keep track of connected stars
            // if > 3, return no
            for (int i = 0; i < n; i++) {
                grid[i] = sc.ns().toCharArray();
            }

            boolean ans = true;
            int curr = 1;
            for (int i = 0; i < n && ans; i++) {
                for (int j = 0; j < m; j++) {
                    if(grid[i][j] == '*') {
                        int numNeighbors = numNeighbors(grid, i, j);
                        if(numNeighbors > 2) {
                            ans = false;
                            break;
                        }
                        if (numNeighbors == 2) {
                            if(isLine(grid, i, j)) {
                                ans = false;
                                break;
                            }
                            if(!markL(grid, id, i, j, curr)) {
                                ans = false;
                                break;
                            }

                            curr++;
                        }
                    }
                }
            }

            for(int i = 0; i < n && ans; i++) {
                for(int j = 0; j < m; j++) {
                    // check diagonal shaded cells are same number
                    if (grid[i][j] == '*') {
                        if(id[i][j] == 0) ans = false;
                        if(i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '*' && id[i - 1][j - 1] != id[i][j]) ans = false;
                        if(i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == '*' && id[i - 1][j + 1] != id[i][j]) ans = false;
                        if(i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == '*' && id[i + 1][j - 1] != id[i][j]) ans = false;
                        if(i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == '*' && id[i + 1][j + 1] != id[i][j]) ans = false;
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

    static boolean markL(char[][] grid, int[][] id, int i, int j, int mark) {
        if(id[i][j] == 0) id[i][j] = mark;
        else return false;

        if(i - 1 >= 0 && grid[i-1][j] == '*') {
            if(id[i - 1][j] == 0) id[i - 1][j] = mark;
            else return false;
        }
        if(i + 1 < grid.length && grid[i+1][j] == '*') {
            if(id[i + 1][j] == 0) id[i + 1][j] = mark;
            else return false;
        }

        if(j - 1 >= 0 && grid[i][j-1] == '*') {
            if(id[i][j - 1] == 0) id[i][j - 1] = mark;
            else return false;
        }
        if(j + 1 < grid[0].length && grid[i][j + 1] == '*') {
            if(id[i][j + 1] == 0) id[i][j + 1] = mark;
            else return false;
        }

        return true;
    }

    static boolean isLine(char[][] grid, int i, int j) {
        boolean a = false, b = false, c = false, d = false;
        if(i - 1 >= 0 && grid[i-1][j] == '*') {
            a = true;
        }
        if(i + 1 < grid.length && grid[i+1][j] == '*') {
            b = true;
        }

        if(j - 1 >= 0 && grid[i][j-1] == '*') {
            c = true;
        }
        if(j + 1 < grid[0].length && grid[i][j + 1] == '*') {
            d = true;
        }

        return (a && b) || (c && d);
    }

    static int numNeighbors(char[][] grid, int i, int j) {
        int count = 0;
        if(i - 1 >= 0 && grid[i-1][j] == '*') {
            count++;
        }
        if(i + 1 < grid.length && grid[i+1][j] == '*') {
            count++;
        }

        if(j - 1 >= 0 && grid[i][j-1] == '*') {
            count++;
        }
        if(j + 1 < grid[0].length && grid[i][j + 1] == '*') {
            count++;
        }

        return count;
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
