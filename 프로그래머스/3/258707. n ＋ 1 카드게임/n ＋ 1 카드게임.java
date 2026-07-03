import java.util.*;
    
class Solution {
    public int solution(int coin, int[] cards) {
        int n = cards.length;
        int target = n + 1;
        
        Set<Integer> have = new HashSet<>();
        Set<Integer> keep = new HashSet<>();
        
        for (int i = 0; i < n/3; i++) {
            have.add(cards[i]);
        }
        
        int idx = n / 3;
        int round = 1;
        
        while (idx < n) {
            keep.add(cards[idx++]);
            keep.add(cards[idx++]);
            
            // have + have
            if (removePair(have, have, target)) {
                round++;
                continue;
            }
            
            // have + keep
            if (coin >= 1 && removePair(have, keep, target)) {
                coin -= 1;
                round++;
                continue;
            }
            
            // keep + keep
            if (coin >= 2 && removePair(keep, keep, target)) {
                coin -= 2;
                round++;
                continue;
            }
            
            break;
        }
        
        return round;
    }
    
    private boolean removePair(Set<Integer> a, Set<Integer> b, int target) {
        for (int x : a) {
            int y = target - x;
            
            if (!b.contains(y)) continue;
            
            a.remove(x);
            b.remove(y);
            return true;
        }
        return false;
    }
}