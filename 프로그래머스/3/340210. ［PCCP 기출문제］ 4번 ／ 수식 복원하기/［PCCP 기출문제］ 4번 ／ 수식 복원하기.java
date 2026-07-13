import java.util.*;

class Solution {
    public String[] solution(String[] expressions) {
        List<Integer> possibleBases = new ArrayList<>();
        
        for (int base = 2; base <= 9; base++) {
            if (isPossibleBase(expressions, base)) {
                possibleBases.add(base);
            }
        }
        
        List<String> answer = new ArrayList<>();
        
        for (String expression : expressions) {
            String[] parts = expression.split(" ");
            
            String aStr = parts[0];
            String operator = parts[1];
            String bStr = parts[2];
            String resultStr = parts[4];
            
            if (!resultStr.equals("X")) continue;
            
            String commonResult = null;
            boolean same = true;
            
            for (int base : possibleBases) {
                int a = Integer.parseInt(aStr, base); // 진법으로 변환
                int b = Integer.parseInt(bStr, base);
                
                int result;
                
                if (operator.equals("+")) {
                    result = a + b;
                } else {
                    result = a - b;
                }
                
                String convertedResult = Integer.toString(result, base);
                
                if (commonResult == null) {
                    commonResult = convertedResult;
                } else if (!commonResult.equals(convertedResult)) {
                    same = false;
                    break;
                }
            }
            
            String restoredResult = same ? commonResult : "?";
            
            answer.add (aStr + " " + operator + " " + bStr + " = " + restoredResult);
        }
        
        return answer.toArray(new String[0]);
    }
    
    private boolean isPossibleBase(String[] expressions, int base) {
        for (String expression : expressions) {
            String[] parts = expression.split(" ");
            
            String aStr = parts[0];
            String operator = parts[1];
            String bStr = parts[2];
            String resultStr = parts[4];
            
            if (!isValidNumber(aStr, base) || !isValidNumber(bStr, base)) {
                return false;
            }
            
            if (!resultStr.equals("X") && !isValidNumber(resultStr, base)) {
                return false;
            }
            
            if (resultStr.equals("X")) {
                continue;
            }
            
            int a = Integer.parseInt(aStr, base);
            int b = Integer.parseInt(bStr, base);
            int expected = Integer.parseInt(resultStr, base);
            
            int actual;
            
            if (operator.equals("+")) {
                actual = a + b;
            } else {
                actual = a - b;
            }
            
            if (actual != expected) {
                return false;
            }
        }
        return true;
    }
    
    private boolean isValidNumber(String number, int base) {
        for (int i = 0; i < number.length(); i++) {
            int digit = number.charAt(i) - '0';
            
            if (digit >= base) {
                return false;
            }
        }
        return true;
    }
}