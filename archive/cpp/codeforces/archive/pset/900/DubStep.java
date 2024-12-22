import java.util.*;

public class DubStep
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] isWub = new int[s.length()];

        int i = 2;
        while(i < s.length()) {
            if(s.charAt(i-2) == 'W' && s.charAt(i-1) == 'U' && s.charAt(i) == 'B') {
                isWub[i] = isWub[i-1] = isWub[i-2] = 1;
                i += 3;
            } else {
                i++;
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        // get first non wub character
        int a = 0;
        if(isWub[0] == 0) {

        } else {
            while(isWub[++a] == 1);

        }

        stringBuilder.append(s.charAt(a++));
        for(int j = a; j < s.length(); j++) {
            if(isWub[j] == 0) {
                // not a wub, check if it's a new word
                if(isWub[j-1] == 1) {
                    stringBuilder.append(" ");
                }
                stringBuilder.append(s.charAt(j));
            }
        }

        System.out.println(stringBuilder);
    }
}