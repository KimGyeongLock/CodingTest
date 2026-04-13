class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        dfs(0, numbers, 0, target);
        return answer;
    }
    
    private void dfs(int idx, int[] numbers, int total, int target) {
        if (idx == numbers.length) {
            if (total == target) answer++;
            return;
        }
        
        dfs(idx+1, numbers, total + numbers[idx], target);
        dfs(idx+1, numbers, total - numbers[idx], target);
    }
}