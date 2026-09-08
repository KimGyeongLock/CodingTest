class Solution {
    
    long min;
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        
        for (int i = 0; i < numbers.length; i++) {
            min = Long.MAX_VALUE;
            
            dfs(numbers[i], numbers[i], 0, 0);
            
            answer[i] = min;
        }
        return answer;
    }
    
    private void dfs(long original, long current, int index, int depth) {
        if (depth > 0 && current > original) {
            min = Math.min(min, current);
        }
        
        if (depth == 2) {
            return;
        }
        
        
        for (int i = index; i < 61; i++) {
            long next = current ^ (1L << i);
            
            dfs(original, next, i + 1, depth + 1);
        }
    }
}