package cf.contest.round798;

import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            Map<Integer, List<Integer>> tree = new HashMap<>();
            for (int i = 0; i < n - 1; i++) {
                int from = sc.nextInt();
                int to = sc.nextInt();
                tree.putIfAbsent(from, new ArrayList<>());
                tree.get(from).add(to);
            }
            int[] balance = new int[n + 1];
            int[] numDescendants = new int[n + 1];
            numDescendants(tree, 1, numDescendants);
            balance(tree, 1, balance);
            int root = 1;
            // while not a leaf node
            int saved = 0;
            while(tree.get(root) != null) {
                if(tree.get(root).size() == 1) {
                    int child = tree.get(root).get(0);
                    saved += numDescendants[child];
                    break;
                } else if(tree.get(root).size() == 2){
                    int left = tree.get(root).get(0);
                    int right = tree.get(root).get(1);
                    if(balance[left] > balance[right]) {
                        root = right;
                        saved += numDescendants[left];
                    } else if (balance[left] < balance[right]) {
                        root = left;
                        saved += numDescendants[right];
                    } else {
                        // equal
                        if(numDescendants[left] >= numDescendants[right]) {
                            saved += numDescendants[right];
                            root = left;
                        } else {
                            saved += numDescendants[left];
                            root = right;
                        }
                    }
                }
            }

            System.out.println(saved);
        }
    }

    public static int numDescendants(Map<Integer, List<Integer>> tree, int root, int[] numDescendants) {
        if (tree.get(root) == null || tree.get(root).size() == 0) {
            numDescendants[root] = 0;
        } else if (tree.get(root).size() == 1) {
            int onlyChild = tree.get(root).get(0);
            numDescendants[root] = 1 + numDescendants(tree, onlyChild, numDescendants);
        } else {
            int leftChild = tree.get(root).get(0);
            int rightChild = tree.get(root).get(1);
            numDescendants[root] = 2 + numDescendants(tree, leftChild, numDescendants) + numDescendants(tree, rightChild, numDescendants);
        }

        return numDescendants[root];
    }

    public static int balance(Map<Integer, List<Integer>> tree, int root, int[] balance) {
        if(tree.get(root) == null || tree.get(root).size() == 0) {
            return 0;
        } else if (tree.get(root).size() == 1) {
            int onlyChild = tree.get(root).get(0);
            balance[root] = 1 + balance(tree, onlyChild, balance);
        } else {
            int leftChild = tree.get(root).get(0);
            int rightChild = tree.get(root).get(1);
            balance[root] = Math.abs(height(tree, leftChild) - height(tree, rightChild));
        }

        return balance[root];
    }

    public static int height(Map<Integer, List<Integer>> tree, int root) {
        if(tree.get(root) == null || tree.get(root).size() == 0) {
            return 1;
        }
        if (tree.get(root).size() == 1) {
            int onlyChild = tree.get(root).get(0);
            return 1  + height(tree, onlyChild);
        } else {
            int leftChild = tree.get(root).get(0);
            int rightChild = tree.get(root).get(1);
            return Math.max(height(tree, leftChild), height(tree, rightChild));
        }
    }
}
