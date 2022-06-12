package cf.contest;

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

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) throws IOException {
        int[] result = new int[n];
        for(int i = 0; i < n; i++) {
            result[i] = this.nextInt();
        }
        return result;
    }

    public Integer[] nextIntegerArray(int n) throws IOException {
        Integer[] result = new Integer[n];
        for(int i = 0; i < n; i++) {
            result[i] = this.nextInt();
        }
        return result;
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

