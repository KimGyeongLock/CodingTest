#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genre_total;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    for(int i = 0; i < genres.size(); i++) {
        genre_total[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> sorted_genres(genre_total.begin(), genre_total.end());
    sort(sorted_genres.begin(), sorted_genres.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;    
        });
    
    vector<int> answer;
    
    for (auto& genre : sorted_genres) {
        auto& songs = genre_songs[genre.first];
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, pair<int, int>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        
        for(int i = 0; i < songs.size() & i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }
    return answer;
}