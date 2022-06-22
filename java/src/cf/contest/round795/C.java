package cf.contest.round795;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.nextLine();
            int first = -1, last = -1;
            int ones = 0;
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '1') {
                    if(first == -1) {
                        first = i;
                    }
                    last = i;
                    ones++;
                }
            }

            int operationsLast = s.length() - 1 - last;
            int operationsFirst = first;

            if(first == -1) {
                System.out.println(0);
            } else if(ones == 1) {
                if(operationsLast <= k) {
                    System.out.println(1);
                } else if (operationsFirst <= k) {
                    System.out.println(10);
                } else {
                    System.out.println(11);
                }
            }else {
                if(operationsFirst + operationsLast <= k) {
                    System.out.println(11 + (ones - 2) * 11);
                } else if(operationsLast <= k) {
                    System.out.println(1 + (ones - 1) * 11);
                } else if (operationsFirst <= k) {
                    System.out.println(10 + (ones - 1) * 11);
                } else {
                    System.out.println(ones * 11);
                }
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
