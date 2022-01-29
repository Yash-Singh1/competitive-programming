import java.util.Scanner;
import java.util.ArrayList;

public class USACOProblem1 {
    public static ArrayList<String> subStrings(String str) {
        ArrayList<String> substrings = new ArrayList<>();
        for (int i = 0; i < str.length(); i++)
           for (int j = i + 3; j <= str.length(); j++)
                substrings.add(str.substring(i, j));
        return substrings;
    }
    
    public static int occurences(String str, char character) {
        int count = 0;
 
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == character) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String lineup = in.next();
        int throwout = 0;
        ArrayList<String> substrings = subStrings(lineup);
        for (int i = 0; i < substrings.size(); i++) {
            if (occurences(substrings.get(i), 'G') == 1 || occurences(substrings.get(i), 'H') == 1) {
                throwout++;
            }
        }
        System.out.println(throwout);
     }
}
