class Solution {
    public int solution(int[][] sizes) {
        int w = 0, h = 0;
        for (int[] s : sizes) {
            int a = Math.max(s[0], s[1]);
            int b = Math.min(s[0], s[1]);
            
            w = Math.max(w, a);
            h = Math.max(h, b);
        }
        return w*h;
    }
}