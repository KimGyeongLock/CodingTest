class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        int left = 1;
        int right = 0;
        for (int d : diffs) {
            right = Math.max(d, right);
        }
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (possible(diffs, times, limit, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
    
    private boolean possible(int[] diffs, int[] times, long limit, int level) {
        long total = 0;
        for (int i = 0; i < diffs.length; i++) {
            long time_cur = times[i];
            if (diffs[i] <= level) {
                total += time_cur;
            } else {
                long fail = diffs[i] - level;
                long time_prev = i > 0 ? times[i - 1] : 0;
                total += (time_cur + time_prev) * fail + time_cur;
            }
        }
        return total <= limit;
    }
}