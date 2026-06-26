class Solution {
    int answer = Integer.MAX_VALUE;
    public int solution(int[] picks, String[] minerals) {
        dfs(0, 0, picks, minerals);
        return answer;
    }
    
    private void dfs(int index, int value, int[] picks, String[] minerals) {
        if (index == minerals.length || picks[0] + picks[1] + picks[2] == 0) {
            answer = Math.min(answer, value);
            return;
        }
        
        for (int i = 0; i < 3; i++) {
            if (picks[i] == 0) continue;
            int val = 0;
            int j;
            for (j = 0; j < 5 && j + index < minerals.length; j++) {
                val += cal(i, minerals[index + j]);
            }
            picks[i] -= 1;
            dfs(index + j, value + val, picks, minerals);
            picks[i] += 1;
        }
    }
    
    private int cal(int tool, String mineral) {
        if (tool == 0) return 1;
        if (tool == 1) {
            if (mineral.equals("diamond")) return 5;
            else return 1;
        }
        if (tool == 2) {
            if (mineral.equals("diamond")) return 25;
            else if (mineral.equals("iron")) return 5;
            else return 1;
        }
        return 0;
    }
}