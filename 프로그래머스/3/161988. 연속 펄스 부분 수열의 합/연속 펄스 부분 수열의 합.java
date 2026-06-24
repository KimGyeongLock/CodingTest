import java.util.*;
class Solution {
    public long solution(int[] sequence) {        
        int[] nseq = sequence.clone();
        
        for (int i = 0; i < sequence.length; i++) {
            nseq[i] *= Math.pow(-1, i); 
        }
        
        long current = 0; // 카데인 알고리즘
        long max = Long.MIN_VALUE;
        for (int i = 0; i < nseq.length; i++) {
            current = Math.max(nseq[i], current + nseq[i]);
            max = Math.max(max, current);
        }
        // 2 -3 -6 -1 3 1 2 -4
        
        
        for (int i = 0; i < sequence.length; i++) {
            sequence[i] *= Math.pow(-1, i+1); 
        }
        long current2 = 0; // 카데인 알고리즘
        long max2 = Long.MIN_VALUE;
        for (int i = 0; i < sequence.length; i++) {
            current2 = Math.max(sequence[i], current2 + sequence[i]);
            max2 = Math.max(max2, current2);
        }
        return Math.max(max, max2);
    }
}