package icpc.Week1;

public class ModularExponentiation {

    public static int modExpRecursive(int x, int y, int m) {
        if (y == 0) {
            return 1;
        }

        if (y % 2 == 0) {
            return (modExpRecursive((x * x), y / 2, m)) % m;
        } else {
            return ((x % m) * modExpRecursive((x * x), (y - 1) / 2, m)) % m;
        }
    }

    public static int powRecursive(int x, int y) {
        if (y == 0) {
            return 1;
        }

        if (x % 2 == 0) {
            return powRecursive((x * x), y / 2);
        } else {
            return x * powRecursive(x, y - 1);
        }
    }

    public static int powIterative(int x, int y){
        int res = 1;
        while(y > 0) {
            if(y % 2 == 1) {
                res *= x;
            }

            y /= 2;
            x = x * x;
        }

        return res;
    }

    public static int modExpIterative(int x, int y, int m) {
        int res = 1;
        x = x % m;
        if(x == 0) {
            return 0;
        }

        while(y > 0) {
            if(y % 2 == 1) {
                res *= (x % m);
            }

            y /= 2;
            x = (x * x) % m;
        }

        return res;
    }
}
