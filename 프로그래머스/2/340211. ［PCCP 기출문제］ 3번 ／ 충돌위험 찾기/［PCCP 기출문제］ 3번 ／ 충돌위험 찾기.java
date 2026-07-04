import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        int maxTime = 0;
        List<int[]>[] paths = new ArrayList[routes.length];
        
        for (int i = 0; i < routes.length; i++) {
            paths[i] = makePath(points, routes[i]);
            maxTime = Math.max(maxTime, paths[i].size());
        }
        
        for (int t = 0; t < maxTime; t++) {
            Map<String, Integer> map = new HashMap<>();
            
            for (int r = 0; r < paths.length; r++) {
                if (t >= paths[r].size()) continue;
                
                int[] pos = paths[r].get(t);
                String key = pos[0] + "," + pos[1];
                
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
            
            for (int count : map.values()) {
                if (count >= 2) {
                    answer++;
                }
            }
        }
        return answer; 
    }
    
    private List<int[]> makePath(int[][] points, int[] route) {
        List<int[]> path = new ArrayList<>();
        
        int startPoint = route[0] - 1;
        int r = points[startPoint][0];
        int c = points[startPoint][1];
        
        path.add(new int[]{r, c});
        
        for (int i = 1; i < route.length; i++) {
            int nextPoint = route[i] - 1;
            int nr = points[nextPoint][0];
            int nc = points[nextPoint][1];
            
            while (r != nr) {
                if (r < nr) {
                    r++;
                } else {
                    r--;
                }
                
                path.add(new int[]{r, c});
            }
            
            while (c != nc) {
                if (c < nc) {
                    c++;
                } else {
                    c--;
                }
                path.add(new int[]{r, c});
            }
        }
        
        return path;
    }
}