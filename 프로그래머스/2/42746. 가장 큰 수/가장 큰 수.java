import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String[] strNumbers = new String[numbers.length];
        for(int i = 0; i < numbers.length; i++) {
            strNumbers[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strNumbers, (o1, o2) -> { return (o2 + o1).compareTo(o1 + o2); });
        
        if (strNumbers[0].equals("0")) {
            return "0";
        }
        
        StringBuilder answer = new StringBuilder();
        for(String str : strNumbers) {
            answer.append(str);
        }
        
        return answer.toString();
    }
}