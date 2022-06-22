package cf.contest.round797;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class F {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            String s = sc.nextLine();
            int[] p = sc.readIntArray(n);
            List<Integer> numReturn = new ArrayList<>();
            Set<Integer> seen = new HashSet<>();
            for (int i = 0; i < n; i++) {
                if (!seen.contains(p[i])) {
                    List<Integer> cycle = new ArrayList<>();
                    seen.add(p[i]);
                    cycle.add(p[i]);
                    int j = p[p[i] - 1];
                    while (j != p[i]) {
                        seen.add(j);
                        cycle.add(j);
                        j = p[j - 1];
                    }

                    List<Character> initialCycle = new ArrayList<>();
                    for(int x = 0; x < cycle.size(); x++) {
                        initialCycle.add(s.charAt(cycle.get(x) - 1));
                    }
                    List<Character> currentCycle = new ArrayList<>(initialCycle);
                    for(int x = 0; x < cycle.size(); x++) {
                        char last = currentCycle.remove(currentCycle.size() - 1);
                        currentCycle.add(0, last);
                        if(currentCycle.equals(initialCycle)) {
                            numReturn.add(x + 1);
                            break;
                        }
                    }

                }
            }

            long ans = numReturn.get(0);
            MathUtils mathUtils = new MathUtils();
            for(int i = 1; i < numReturn.size(); i++) {
                ans = mathUtils.lcmLong(ans, numReturn.get(i));
            }

            System.out.println(ans);
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

}
