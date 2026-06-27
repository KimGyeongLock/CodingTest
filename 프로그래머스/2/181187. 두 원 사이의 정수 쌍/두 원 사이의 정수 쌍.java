class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        // r1^2 <= x^2 + y^2 <= r2^2
        // sqrt(r1^2 - x^2) <= y <= sqrt(r2^2 - x^2)
        for (int x = 1; x <= r2; x++) {
            
            long maxY = (long) Math.floor(Math.sqrt((long) r2*r2 - (long) x*x));
            long minY = (long) Math.ceil(Math.sqrt((long) r1*r1 - (long) x*x));
            answer += maxY - minY + 1;
        }
        
        return answer * 4;
    }
}