package icpc;

public class MaxHeap {

    int[] heap;
    int length;

    // for each element i, left child is at 2i, right child is at 2i+1, parent is at floor(i/2)
    // in binary max heap, each node is greater than or equal to its left and right children
    //
    // functions:
    // insert, delete,

    public MaxHeap(int maxSize) {
        this.heap = new int[maxSize + 1];
        this.length = 0;
    }

    public void insert(int elem) {
        int current_index = this.length;
        this.heap[++this.length] = elem;

        // bubble it up
        while(current_index != 0) {
            int parent_index = current_index / 2;
            if(this.heap[current_index] > this.heap[parent_index]) {
                this.swap(current_index, parent_index);
                current_index = parent_index;
            } else {
                break;
            }
        }
    }

    private void swap(int index1, int index2) {
        int temp = this.heap[index1];
        this.heap[index1] = this.heap[index2];
        this.heap[index2] = temp;
    }

    public int peek() {
        if(this.length > 0) {
            return this.heap[0];
        } else {
            // only positive ints
            return -1;
        }
    }

    private boolean isEmpty() {
        return this.length == 0;
    }

    public int extract() {
        int elem;
        if(!isEmpty()) {
            elem = this.heap[0];
            swap(this.heap[0], this.heap[--this.length - 1]);
            return elem;
        } else {
            return -1;
        }


    }

}
