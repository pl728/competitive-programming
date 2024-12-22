import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";
    
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int m = sc.nextInt();
        int s = sc.nextInt();
        if(s == 0) {
            if(m == 1) {
                System.out.println("0 0");
            } else {
                System.out.println("-1 -1");
            }
            return;
        }
        StringBuilder minNum = new StringBuilder();
        StringBuilder maxNum = new StringBuilder();
        for(int i = 0; i < m; i+= 1) {
            int j = Math.min(9, s);
            maxNum.append(j);
            s -= j;
        }
        if(s > 0) {
            System.out.println("-1 -1");
            return;
        }
        for(int i = m - 1; i >= 0; i--) {
            minNum.append(maxNum.charAt(i));
        }
        //first non zero char
        int i = 0;
        while(i < m && minNum.charAt(i) == '0') i++;
        if(i == m) {
            System.out.println("-1 -1");
            return;
        }
        if(i != 0) {
            char firstNonZeroChar = minNum.charAt(i);
            int firstNonZero = Character.getNumericValue(firstNonZeroChar);
            minNum.replace(i, i+1, String.valueOf(firstNonZero - 1));
            minNum.replace(0, 1, "1");
        }

        System.out.println(minNum + " " + maxNum);
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
