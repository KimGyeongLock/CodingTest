class Solution {
    // 초침 : 360 / 60    6도/1s      720칸
    // 분침 : 360 / 3600  0.1도/1s    12칸
    // 시침 : 360 / 43200 1/120도/1s  1칸
    static final int FULL = 43200;
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        int start = h1 * 3600 + m1 * 60 + s1;
        int end = h2 * 3600 + m2 * 60 + s2;
        
        if (isOverlap(start)) {
            answer++;
        }
        
        for (int t = start; t < end; t++) {
            if (crossSecondAndMinute(t)) answer++;
            if (crossSecondAndHour(t)) answer++;
            if (crossSecondAndMinute(t) && crossSecondAndHour(t) && (t + 1) % FULL == 0) answer--;
        }
        return answer;
    }
    
    private boolean crossSecondAndMinute(int time) {
        int second = (time * 720) % FULL;
        int minute = (time * 12) % FULL;
        
        int nextSecond = ((time + 1) * 720) % FULL;
        int nextMinute = ((time + 1) * 12) % FULL;
        
        if (nextSecond == 0) nextSecond = FULL;
        if (nextMinute == 0) nextMinute = FULL;
        
        return second < minute && nextSecond >= nextMinute;
    }
    
    private boolean crossSecondAndHour(int time) {
        int second = (time * 720) % FULL;
        int hour = time % FULL;
        
        int nextSecond = ((time + 1) * 720) % FULL;
        int nextHour = (time + 1) % FULL;
        
        if (nextSecond == 0) nextSecond = FULL;
        if (nextHour == 0) nextHour = FULL;
        
        return second < hour && nextSecond >= nextHour;
    }
    
    private boolean isOverlap(int time) {
        int hour = time % FULL;
        int minute = (time * 12) % FULL;
        int second = (time * 720) % FULL;
        return second == hour || second == minute;
    }
}