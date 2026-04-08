class Solution {
    public int[] solution(int brown, int yellow) {
        // w*h = brown + yellow
        // yellow = (w-2)(h-2) == wh - 2w - 2h + 4 
        // yellow = brown + yellow - 2w - 2h + 4
        // brown = 2w + 2h - 4
        int wh = brown + yellow;
        int w, h = 0;
        for (w = 1; w <= wh; w++) {
            if (wh % w == 0) h = wh / w;
            if ((w - 2) * (h - 2) == yellow) break;
        }
        return new int[]{Math.max(w, h), Math.min(w, h)};
    }
}