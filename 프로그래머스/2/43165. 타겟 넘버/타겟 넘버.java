class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, 0, 0, target);
        return answer;
    }
    private void dfs(int[] numbers, int current, int depth, int target) {
        
        if (depth == numbers.length) {
            if(current == target) answer++;
            return;
        }
        
        dfs(numbers, current + numbers[depth], depth + 1, target);
                
        dfs(numbers, current - numbers[depth], depth + 1, target);
    }
}