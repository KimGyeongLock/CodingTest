import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int n = genres.length;
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(genres[i], map.getOrDefault(genres[i], 0) + plays[i]);
        }
                
        HashMap<String, ArrayList<int[]>> map2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map2.putIfAbsent(genres[i], new ArrayList<>());
            map2.get(genres[i]).add(new int[]{plays[i], i});
        }
        
        
        for (ArrayList<int[]> list : map2.values()) {
            list.sort((a, b) -> {
                if (b[0] == a[0]) return a[1] - b[1];
                return b[0] - a[0];
            });
        }
        
        ArrayList<String> genreList = new ArrayList<>(map.keySet());
        genreList.sort((a, b) -> map.get(b) - map.get(a));
        
        ArrayList<Integer> answerList = new ArrayList<>();
        
        for (String genre : genreList) {
            ArrayList<int[]> list = map2.get(genre);
            
            answerList.add(list.get(0)[1]);
            if (list.size() > 1) {
                answerList.add(list.get(1)[1]);
            } 
        }
        
        int[] answer = new int[answerList.size()];
        for (int i = 0; i < answerList.size(); i++) {
            answer[i] = answerList.get(i);
        }
        
        return answer;
    }
}