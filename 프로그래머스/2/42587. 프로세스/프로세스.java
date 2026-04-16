import java.util.*;

class Solution {
    class Process {
        int priority;
        int index;
        
        Process (int priority, int index) {
            this.priority = priority;
            this.index = index;
        }
    }
    public int solution(int[] priorities, int location) {
        Queue<Process> q = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            q.offer(new Process(priorities[i], i));
        }
        
        int order = 0;
        while (!q.isEmpty()) {
            Process cur = q.poll();
            
            boolean hasHigher = false;
            for (Process p : q) {
                if (cur.priority < p.priority) hasHigher = true;
            }
            
            if (hasHigher) {
                q.offer(cur);
            } else {
                order++;
                if (cur.index == location) return order;
            }
        }
        return 0;
    }
}