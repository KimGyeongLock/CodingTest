import java.util.*;

class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        
        for (int i = 0; i < places.length; i++) {
            String[] place = places[i];
            if (isPossible(place)) answer[i] = 1;
            else answer[i] = 0;
        }
        
        return answer;
    }
    
    private boolean isPossible(String[] place) {
        Set<int[]> positions = new HashSet<>();
        
        for (int r = 0; r < place.length; r++) {
            for (int c = 0; c < place[r].length(); c++) {
                if (place[r].charAt(c) == 'P') positions.add(new int[]{r, c});
            }
        }
        
        boolean[][] visited = new boolean[5][5];
        for (int[] position : positions) {
            visited[position[0]][position[1]] = true;
            if (dfs(position[0], position[1], 0, place, visited)) return false; // 거리두기 x
        }
        
        return true;
    }
    
    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, 1, 0, -1};
    // true: 거리두기 실패 false: 거리두기 성공 
    private boolean dfs(int r, int c, int dist, String[] place, boolean[][] visited) {
        if (dist > 0 && place[r].charAt(c) == 'P') return true;
        if (dist >= 2) return false;
        
        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            if (place[nx].charAt(ny) == 'X') continue;
            
            visited[nx][ny] = true;
            if (dfs(nx, ny, dist + 1, place, visited)) return true;
            visited[nx][ny] = false;
        }
        
        return false;
    }
}