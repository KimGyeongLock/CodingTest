import java.util.*;

class Solution {
    private List<Map<String, Integer>> arr;
    
    public String[] solution(String[] orders, int[] course) {
        List<String> answer = new ArrayList<>();
        
        arr = new ArrayList<>();
        
        for (int i = 0; i <= 10; i++) {
            arr.add(new HashMap<>());
        }
        
        for (String order : orders) {
            char[] chars = order.toCharArray();
            Arrays.sort(chars);
            String sortedOrder = new String(chars);
            
            for (int num : course) {
                if (order.length() >= num) {
                    occ(sortedOrder, 0, 0, "", num);
                }
            }
        }
        
        for (int num : course) {
            Map<String, Integer> res = arr.get(num);
            
            int max_v = 0;
            
            for (Map.Entry<String, Integer> entry : res.entrySet()) {
                max_v = Math.max(max_v, entry.getValue());
            }
            
            if (max_v < 2) continue;
            
            for (Map.Entry<String, Integer> entry : res.entrySet()) {
                if (max_v == entry.getValue()) {
                    answer.add(entry.getKey());
                }
            }
        }
        
        Collections.sort(answer);
        return answer.toArray(new String[0]);
    }
    
    private void occ(String order, int start, int depth, String result, int num) {
        if (depth == num) {
            arr.get(num).put(result, arr.get(num).getOrDefault(result, 0) + 1);
            return;
        }
        
        for (int i = start; i < order.length(); i++) {
            occ(order, i + 1, depth + 1, result + order.charAt(i), num);    
        }
    }
}