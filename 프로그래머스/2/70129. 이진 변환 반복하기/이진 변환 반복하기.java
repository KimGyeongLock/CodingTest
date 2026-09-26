class Solution {
    int[] answer;
    public int[] solution(String s) {
        answer = new int[2];
        
        while(true) {
            answer[0]++;
            s = trans(s);
            if (s.equals("1")) break;
        }
                
        return answer;
    }
    
    private String trans(String s) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') cnt++;
            if (c == '0') answer[1]++;
        }
        
        String new_x = "";
        while(cnt > 0) {
            new_x = (cnt % 2) + new_x;
            cnt /= 2;
        }
        
        return new_x;
    }
}