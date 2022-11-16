import java.util.*;

public class Dubstep
{
    public static void main(String[] args)
    {
        // 2, 4, 3, 6, 8
        // sum(a, b) is odd means
        //      a and b are odd, a and b are even
        //      a and b must be the same
        // 0, 0, 1, 0, 0
        // 1, 1, 1, 1, 1
        // 2, 2, 3, 3, 3

        Scanner sc = new Scanner(System.in);
        int t = sc.nextLine();

        for(int i = 0; i < t; i++) {
            int n = sc.nextLine();
            int a[] = new int[n];
            for(int j = 0; j < n; j++) {
                a[j] = sc.nextInt() % 2;
                System.out.println(a[j]);
            }



        }
    }
}