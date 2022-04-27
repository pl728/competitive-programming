import org.junit.Test;

import static org.junit.Assert.*;

public class SortingAlgorithmsTest {

    @Test
    public void bubbleSortTest() {
        int[] A, B;
        A = new int[]{};
        B = new int[]{};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{0};
        B = new int[]{0};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{1, 0};
        B = new int[]{0, 1};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{0, 1, -1};
        B = new int[]{-1, 0, 1};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{5,4,3,2,1};
        B = new int[]{1,2,3,4,5};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{5, 2, 4, 1};
        B = new int[]{1, 2, 4, 5};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
        A = new int[]{1, 2, 3, 4};
        B = new int[]{1, 2, 3, 4};
        assertArrayEquals(SortingAlgorithms.bubbleSort(A), B);
    }

    @Test
    public void mergeSortTest() {
        int[] A, B;
        A = new int[]{};
        B = new int[]{};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{0};
        B = new int[]{0};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{1, 0};
        B = new int[]{0, 1};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{0, 1, -1};
        B = new int[]{-1, 0, 1};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{5, 4, 3, 2, 1};
        B = new int[]{1, 2, 3, 4, 5};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{1, 1, 1, 1, 1, 1};
        B = new int[]{1, 1, 1, 1, 1, 1};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{5, 2, 4, 1};
        B = new int[]{1, 2, 4, 5};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        A = new int[]{1, 2, 3, 4};
        B = new int[]{1, 2, 3, 4};
        assertArrayEquals(SortingAlgorithms.mergeSort(A), B);
        int[] actual = { 5, 1, 6, 2, 3, 4 };
        int[] expected = { 1, 2, 3, 4, 5, 6 };
        assertArrayEquals(expected, SortingAlgorithms.mergeSort(actual));
    }

    @Test
    public void quickSortTest() {
        int[] A, B;
        A = new int[]{};
        B = new int[]{};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{0};
        B = new int[]{0};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{1, 0};
        B = new int[]{0, 1};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{0, 1, -1};
        B = new int[]{-1, 0, 1};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{5, 4, 3, 2, 1};
        B = new int[]{1, 2, 3, 4, 5};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{1, 1, 1, 1, 1, 1};
        B = new int[]{1, 1, 1, 1, 1, 1};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{5, 2, 4, 1};
        B = new int[]{1, 2, 4, 5};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        A = new int[]{1, 2, 3, 4};
        B = new int[]{1, 2, 3, 4};
        assertArrayEquals(SortingAlgorithms.quicksort(A, 0, A.length - 1), B);
        int[] actual = { 5, 1, 6, 2, 3, 4 };
        int[] expected = { 1, 2, 3, 4, 5, 6 };
        assertArrayEquals(expected, SortingAlgorithms.quicksort(actual,0, actual.length - 1));
    }
}