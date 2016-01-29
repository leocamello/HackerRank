import java.util.Scanner;
import java.util.regex.*;

public class Solution {
public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());
        while(testCases>0) {
                Boolean isValid = true;
                String pattern = in.nextLine();
                try{
                        Pattern.compile(pattern);
                }catch(PatternSyntaxException e) {
                        isValid = false;
                }
                if(isValid) {
                        System.out.println("Valid");
                }else{
                        System.out.println("Invalid");
                }
        }
}
}
