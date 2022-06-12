package study.Week1;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Test {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue(
                new Comparator<Integer>() {
                    public int compare(Integer a, Integer b) {
                        return a - b;
                    }
                }
        );
        pq.add(0);
        pq.add(1);
        pq.add(5);
        pq.add(Integer.MAX_VALUE);

        while(!pq.isEmpty()) {
            System.out.println(pq.poll());
        }

    }
}
