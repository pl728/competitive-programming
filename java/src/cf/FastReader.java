package cf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
        this.br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // int, long, double, String

    public int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    // int array, long array, double array, string array (primitive and object)

    public int[] nextIntArray(int n) {
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextInt();
        }
        return result;
    }

    public Integer[] nextIntArrayObject(int n) {
        Integer[] result = new Integer[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextInt();
        }
        return result;
    }

    public long[] nextLongArray(int n) {
        long[] result = new long[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextLong();
        }
        return result;
    }

    public Long[] nextLongArrayObject(int n) {
        Long[] result = new Long[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextLong();
        }
        return result;
    }

    public double[] nextDoubleArray(int n) {
        double[] result = new double[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextDouble();
        }
        return result;
    }

    public Double[] nextDoubleArrayObject(int n) {
        Double[] result = new Double[n];
        for (int i = 0; i < n; i++) {
            result[i] = this.nextDouble();
        }
        return result;
    }

    String[] nextLineArray(int n) {
        String line = "";
        try {
            line = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return line.split(" ");
    }
}

