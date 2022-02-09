import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int counter = 1;

        while (scanner.hasNextLine()) {
            System.out.println(String.valueOf(counter) + " " + scanner.nextLine());
            counter++;
        }
    }
}
