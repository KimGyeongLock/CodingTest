import java.util.*;

class Solution {
    ArrayList<String> answer = new ArrayList<>();
    boolean[] visited;
    boolean found = false;
    
    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        
        Arrays.sort(tickets, (a, b) -> a[1].compareTo(b[1]));
        ArrayList<String> arr = new ArrayList<>();
        arr.add("ICN");
        dfs(0, arr, "ICN", tickets);
        return answer.toArray(new String[0]);
    }
    
    private void dfs(int depth, ArrayList<String> arr, String start, String[][] tickets) {
        if (depth == tickets.length) {
            answer = new ArrayList<>(arr);
            found = true;
            return;
        }
        
        for (int i = 0; i < tickets.length; i++) {
            if (visited[i]) continue;
            if (!tickets[i][0].equals(start)) continue;
            
            visited[i] = true;
            arr.add(tickets[i][1]);
            dfs(depth + 1, arr, tickets[i][1], tickets);
            arr.remove(arr.size() - 1);
            visited[i] = false;
            if (found) return;
        }
    }
}