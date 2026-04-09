class Solution {
    int answer = 0;
    int cnt = 0;
    public int solution(String word) {
        dfs("", word);
        return answer;
    }
    
    private void dfs(String word, String word2) {
        if (word.equals(word2)) answer = cnt;
        if (word.length() == 5) {
            return;
        }
        for (char c : new char[]{'A', 'E', 'I', 'O', 'U'}) {
            cnt++;
            dfs(word + c, word2);
        }
    }
}