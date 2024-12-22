package cf.contest.round799;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            sc.nextLine();
            char[][] board = new char[8][8];
            for(int i = 0; i < board.length; i++) {
                board[i] = sc.readCharArray(8);
            }
            boolean ans = false;
            int r = -1;
            int c = -1;
            for(int i = 0; i < 6 && !ans; i++) {
                for(int j = 0; j < 6; j++) {
                    if(check(board, i, j)) {
                        ans = true;
                        r = i + 2;
                        c = j + 2;
                    }
                }
            }

            System.out.println(r + " " + c);
        }
    }

    static boolean check(char[][] board, int r, int c) {
        if(board[r][c+1] == '.' && board[r+1][c] == '.' && board[r+1][c+2] == '.' && board[r+2][c+1] == '.'
                && board[r][c] == '#' && board[r][c+2] == '#' && board[r+1][c+1] == '#' && board[r+2][c] == '#' && board[r+2][c+2] == '#' ) {
            return true;
        }

        return false;
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
