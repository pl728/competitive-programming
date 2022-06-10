package icpc;

import java.util.Arrays;

public class SortingAlgorithms {

    public static int[] bubbleSort(int[] A) {
        for(int i = 0; i < A.length; i++) {
            for(int j = 1; j < A.length - i ; j++) {
                if(A[j] < A[j - 1]) {
                    int temp = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }
        return A;
    }

    public static int[] mergeSort(int[] A) {
        int n = A.length;
        if(n < 2) {
            return A;
        }
        int midpoint = n / 2;
        int[] a = Arrays.copyOfRange(A, 0, midpoint);
        int[] b = Arrays.copyOfRange(A, midpoint, n);
        return merge(mergeSort(a), mergeSort(b));
    }

    public static int[] merge(int[] A, int[] B) {
        int i, j;
        i = j = 0;
        int[] C = new int[A.length + B.length];

        while(i < A.length && j < B.length) {
            if(A[i] < B[j]) {
                C[i + j] = A[i];
                i++;
            } else {
                C[i + j] = B[j];
                j++;
            }
        }
        if(i == A.length) {
            for(int k = i + j; k < A.length + B.length; k++) {
                C[k] = B[j];
                j++;
            }
        } else {
            // j = B.length
            for(int k = i + j; k < A.length + B.length; k++) {
                C[k] = A[i];
                i++;
            }
        }

        return C;
    }

    public static int[] quicksort(int[] A, int lower, int higher) {
        // find pivot, then put all numbers lower than the pivot before and all nums greater after.
        // call quicksort on each half (quicksort(A[:x]) + pivot + quicksort(A[x:])
        // [4, 1, 2, 5, 3]

        if(lower < higher) {
            int j = partition2(A, lower, higher);
            quicksort(A, lower, j-1);
            quicksort(A, j+1, higher);
        }

        return A;
    }

    public static void swap(int[] A, int a, int b) {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }

    public static int partition1(int[] A, int lower, int higher) {
        int pivot = A[lower];
        int i = lower;
        for(int j = lower + 1; j <= higher; j++) {
            if(A[j] < pivot) {
                i++;
                swap(A, i, j);
            }
        }

        swap(A, lower, i);

        return i;
    }

    public static int partition2(int[] A, int lower, int higher) {
        int pivot = A[lower];
        int i = lower;
        int j = higher;

        while(i < j) {
            do {
                i++;
            }
            while(A[i] <= pivot);

            do {
                j--;
            }
            while(A[j] > pivot);

            if(i < j) {
                swap(A, i, j);
            }
        }

        swap(A, lower, j);

        return j;
    }
}
