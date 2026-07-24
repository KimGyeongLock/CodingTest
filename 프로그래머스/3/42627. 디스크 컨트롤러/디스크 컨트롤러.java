import java.util.*;

class Solution {
    private static class State implements Comparable<State> {
        int time;
        int duration;
        int number;
        
        State (int time, int duration, int number) {
            this.time = time;
            this.duration = duration;
            this.number = number;
        }
        
        @Override
        public int compareTo(State other) {
            if (this.duration != other.duration) return Integer.compare(this.duration, other.duration);
            else if (this.time != other.time) return Integer.compare(this.time, other.time);
            return Integer.compare(this.number, other.number);
        }
    }
    
    public int solution(int[][] jobs) {
        int n = jobs.length;
        
        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(jobs[i][0], key -> new ArrayList<>())
                .add(new int[]{jobs[i][1], i});
        } 
        
        PriorityQueue<State> pq = new PriorityQueue<>();
        
        int time = 0;
        State current = null;
        int total = 0;
        int cnt = 0;
        
        while (cnt != n) {
            if (current != null && current.duration == 0) { // 작업 완료
                total += (time - current.time);
                current = null;
                cnt++;
            }
            
            if (map.containsKey(time)) { // 대기큐 저장
                for (int[] job : map.get(time)) {
                    pq.offer(new State(time, job[0], job[1]));
                }
            }
            
            if (current == null && !pq.isEmpty()) { // current로 넣기
                current = pq.poll();
            }

            time++;
            if (current != null) current.duration--;
        }
        
        return total / n;
    }
}