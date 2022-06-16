import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            // min creepiness is |a - b|
            StringBuilder sb = new StringBuilder();
            int smaller = Math.min(a, b);
            for(int i = 0; i < Math.min(a, b); i++) {
                sb.append("01");
            }
            if(smaller == a) {
                for(int i = 0; i < b - a; i++) {
                    sb.append("1");
                }
            } else {
                for(int i = 0; i < a - b; i++) {
                    sb.append("0");
                }
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

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String[] readStringArray(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
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

        public char[] readCharArray(int n) {
            return this.nextLine().toCharArray();
        }

    }
}
