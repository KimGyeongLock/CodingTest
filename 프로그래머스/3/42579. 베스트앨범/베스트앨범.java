import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> genrePlayCount = new HashMap<>();
        HashMap<String, List<Song>> genreSongs = new HashMap<>();
        
        for(int i = 0; i < genres.length; i++) {
            genrePlayCount.put(genres[i], genrePlayCount.getOrDefault(genres[i], 0) + plays[i]);
            
            genreSongs.computeIfAbsent(genres[i], k -> new ArrayList<>()).add(new Song(i, plays[i]));
        }
        
        List<String> sortedGenres = new ArrayList<>(genrePlayCount.keySet());
        sortedGenres.sort((a, b) -> { return genrePlayCount.get(b) - genrePlayCount.get(a); });
        
        List<Integer> answerList = new ArrayList<>();
        
        for(String genre : sortedGenres) {
            List<Song> songs = genreSongs.get(genre);
            
            songs.sort((a, b) -> {
                if(a.play == b.play) {
                   return a.index - b.index;
                } 
                return b.play - a.play;
            });
            
            for(int i = 0; i < Math.min(2, songs.size()); i++) {
                answerList.add(songs.get(i).index);
            }
        }
        
        return answerList.stream().mapToInt(i -> i).toArray();
    }
    
    class Song {
        int index;
        int play;
        
        Song(int index, int play){
            this.index = index;
            this.play = play;
        }
    }
}