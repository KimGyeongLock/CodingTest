import java.util.*;
class Solution {
    int[] answer;
    int n;
    int max = -1;
    public int[] solution(int[][] dice) {
        n = dice.length;
        int[] A = new int[n/2];
        dfs(0, 0, A, dice);
        for (int i = 0; i < answer.length; i++) {
            answer[i]++;
        }
        return answer;
    }
    
    private void dfs(int idx, int start, int[] A, int[][] dice) {
        if (idx == n / 2) {
            int res = win(A, dice);
            if (max < res) {
                max = res;
                answer = A.clone();
            }
            return;
        }
        
        for (int i = start; i < dice.length; i++) {
            A[idx] = i;
            dfs(idx + 1, i + 1, A, dice);
        }
    }
    
    private int win(int[] A, int[][] dice) {
        boolean[] picked = new boolean[n];
        
        for (int idx : A) {
            picked[idx] = true;
        }
        
        int[] B = new int[n/2];
        int bidx = 0;
        
        for (int i = 0; i < n; i++) {
            if (!picked[i]) B[bidx++] = i;
        }
        
        List<Integer> sumA = new ArrayList<>();
        List<Integer> sumB = new ArrayList<>();
        
        makeSum(0, 0, A, dice, sumA);
        makeSum(0, 0, B, dice, sumB);
        
        Collections.sort(sumB);
        
        int winCnt = 0;
        for (int a : sumA) {
            winCnt += lowerBound(sumB, a);
        }
        
        return winCnt;
    }
    
    private void makeSum(int depth, int sum, int[] selected, int[][] dice, List<Integer> result) {
        if (depth == selected.length) {
            result.add(sum);
            return;
        }
        
        for (int i = 0; i < 6; i++) {
            makeSum(depth + 1, sum + dice[selected[depth]][i], selected, dice, result);
        }
    }
    
    private int lowerBound(List<Integer> sumB, int a) {
        int left = 0;
        int right = sumB.size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (sumB.get(mid) < a) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}