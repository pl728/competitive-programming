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

        int tc = sc.ni();
        while (tc-- != 0) {
            int n = sc.ni();
            int[] a = sc.readIntArray(n);
            int[] b = sc.readIntArray(n);

            List<Integer> fireDamage = new ArrayList<>();
            List<Integer> frostDamage = new ArrayList<>();


            for(int i = 0; i < n; i++) {
                if(a[i] == 0) {
                    fireDamage.add(b[i]);
                } else {
                    frostDamage.add(b[i]);
                }
            }
            fireDamage.sort(Comparator.naturalOrder());
            frostDamage.sort(Comparator.naturalOrder());

            long totalDamage = 0;

            if(fireDamage.size() == 0) {
                for(int i : frostDamage) {
                    totalDamage += i;
                }
                System.out.println(totalDamage);
                continue;
            }
            if(frostDamage.size() == 0) {
                for(int i : fireDamage) {
                    totalDamage += i;
                }
                System.out.println(totalDamage);
                continue;
            }

            if(fireDamage.size() > frostDamage.size()) {
                totalDamage += fireDamage.get(0);
                fireDamage.remove(0);
                for(int i = frostDamage.size() - 1; i >= 0; i--) {
                    totalDamage += frostDamage.get(i) * 2;
                }
                for(int i = fireDamage.size() - 1; i >= fireDamage.size() - frostDamage.size(); i--) {
                    totalDamage += fireDamage.get(i) * 2;
                }
                for(int i = 0; i < fireDamage.size() - frostDamage.size(); i++) {
                    totalDamage += fireDamage.get(i);
                }
            } else if (fireDamage.size() < frostDamage.size()){
                totalDamage += frostDamage.get(0);
                frostDamage.remove(0);
                for(int i = fireDamage.size() - 1; i >= 0; i--) {
                    totalDamage += fireDamage.get(i) * 2;
                }
                for(int i = frostDamage.size() - 1; i >= frostDamage.size() - fireDamage.size(); i--) {
                    totalDamage += frostDamage.get(i) * 2;
                }
                for(int i = 0; i < frostDamage.size() - fireDamage.size(); i++) {
                    totalDamage += frostDamage.get(i);
                }
            } else {
                if(frostDamage.get(0) < fireDamage.get(0)) {
                    totalDamage += frostDamage.get(0);
                    for(int i = 1; i < frostDamage.size(); i++) {
                        totalDamage += 2L * frostDamage.get(i);
                    }
                    for(int i = 0; i < fireDamage.size(); i++) {
                        totalDamage += 2L * fireDamage.get(i);
                    }
                } else {
                    totalDamage += fireDamage.get(0);
                    for(int i = 1; i < fireDamage.size(); i++) {
                        totalDamage += 2L * fireDamage.get(i);
                    }
                    for(int i = 0; i < frostDamage.size(); i++) {
                        totalDamage += 2L * frostDamage.get(i);
                    }
                }

            }

            System.out.println(totalDamage);

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
