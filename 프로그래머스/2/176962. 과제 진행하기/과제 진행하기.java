import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        ArrayList<String> arr = new ArrayList<>();
        
        Arrays.sort(plans, (a, b) -> a[1].compareTo(b[1]));
        
        Stack<String[]> st = new Stack<>();
        
        for (int i = 0; i < plans.length - 1; i++) {
            String name = plans[i][0];
            int playTime = Integer.parseInt(plans[i][2]);
            
            int t = diff(plans[i][1], plans[i + 1][1]);
            
            if (t < playTime) {
                st.push(new String[]{plans[i][0], String.valueOf(playTime - t)});
            }
            else {
                arr.add(name);
                t -= playTime;
                
                while (t > 0 && !st.isEmpty()) {
                    String[] back = st.pop();
                    int remain = Integer.parseInt(back[1]);
                    
                    if (t >= remain) {
                        t -= remain;
                        arr.add(back[0]);
                    } else {
                        st.push(new String[]{back[0], String.valueOf(remain - t)});
                        t = 0;
                    }
                }
            }
        }
        
        arr.add(plans[plans.length - 1][0]);
        while (!st.isEmpty()) {
            arr.add(st.pop()[0]);
        }
        
        return arr.toArray(new String[0]);
    }
    
    private int diff(String t1, String t2) {
        int h1 = Integer.parseInt(t1.substring(0, 2));
        int m1 = Integer.parseInt(t1.substring(3, 5));
        int h2 = Integer.parseInt(t2.substring(0, 2));
        int m2 = Integer.parseInt(t2.substring(3, 5));
        return (h2 * 60 + m2) - (h1 * 60 + m1);
    }
}