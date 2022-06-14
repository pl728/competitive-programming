package cf.pset1200;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CheapTravel {
    public static void main(String[] args) {
        FastReader fastReader = new FastReader();
        int n = fastReader.nextInt();
        int m = fastReader.nextInt();
        int a = fastReader.nextInt();
        int b = fastReader.nextInt();
        if((double) b / m < a) {
            // special ride is cheaper per ride, buy as many times as possible
            int numSpecial = (int) Math.floor((double) n / m);
            // for the last n - numSpecial * m, need to decide what is cheaper - single or multi ticket
            int numNormal = n - numSpecial * m;
            if(numNormal * a < b) {
                System.out.println(numSpecial * b + numNormal * a);
            } else {
                System.out.println((numSpecial + 1) * b);
            }

        } else {
            System.out.println(n * a);
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

    }
}
