import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] strNumber = new String[numbers.length];
        for(int i = 0; i < numbers.length; i++) {
            strNumber[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strNumber, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        if(strNumber[0].equals("0")) {
            return "0";
        }
        
        for(String s : strNumber) {
            answer += s;
        }
        
        return answer;
    }
}