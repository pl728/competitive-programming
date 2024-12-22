package cf.contest.round799;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            String s = sc.next();
            int x = sc.nextInt();
            int ans = 0;
            String added = addTime(s, x);
            if(isPalindrome(s)){
                ans++;
            }
            while(!added.equals(s)) {
//                System.out.println(added);
                if(isPalindrome(added)) {
                    ans ++;
                }
                added = addTime(added, x);
            }

            System.out.println(ans);
        }
    }

    static String addTime(String hhmm, int minutes) {
        int h = minutes / 60;
        int m = minutes % 60;
        int hh = Integer.parseInt(hhmm.substring(0, 2));
        int mm = Integer.parseInt(hhmm.substring(3, 5));
        hh += h;
        mm += m;
        if(mm > 59) {
            hh += mm / 60;
            mm %= 60;
        }

        hh %= 24;
        String hhs = String.valueOf(hh);
        String mms = String.valueOf(mm);
        if(mms.length() == 1) {
            mms = "0" + mms;
        }
        if(hhs.length() == 1) {
            hhs = "0" + hhs;
        }
        return hhs + ":" + mms;
    }

    static boolean isPalindrome(String hhmm) {
        String a = hhmm.substring(0, 2);
        StringBuilder b = new StringBuilder(hhmm.substring(3, 5)).reverse();
        return a.equals(b.toString());
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
