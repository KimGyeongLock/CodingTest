import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> genreTotal = new HashMap<>();
        Map<String, List<int[]>> byGenre = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            genreTotal.merge(genres[i], plays[i], Integer::sum);
            byGenre.computeIfAbsent(genres[i], k -> new ArrayList<>())
                .add(new int[]{plays[i], i});
        }
        
        List<String> orderedGenres = new ArrayList<>(genreTotal.keySet());
        orderedGenres.sort((a, b) -> genreTotal.get(b) - genreTotal.get(a));
        
        List<Integer> result = new ArrayList<>();
        for (String g : orderedGenres) {
            List<int[]> list = byGenre.get(g);
            list.sort((x, y) -> {
                if (y[0] != x[0]) return y[0] - x[0];
                return x[1] - y[1];
            });
            for (int k = 0; k < Math.min(2, list.size()); k++) {
                result.add(list.get(k)[1]);
            }
        }
        return result.stream().mapToInt(i -> i).toArray();
    }
}