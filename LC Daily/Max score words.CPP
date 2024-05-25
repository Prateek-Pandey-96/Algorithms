// 1255. Maximum Score Words Formed by Letters

class Solution {
public:
    int max_score;
    // not passing reference as we dont want to change original freq
    bool isPossible(string word, vector<int> freq){
        for(char ch: word)
            if(!freq[ch-'a'])
                return false;
            else
                freq[ch-'a']--;
        return true;
    }
    // not passing reference as we dont want to change original freq
    pair<int, vector<int>> get_score(string word, vector<int>& score, vector<int> freq){
        int sc = 0;
        for(char ch: word)
        {
            sc += score[ch-'a'];
            freq[ch-'a']--;
        }
        return {sc, freq};
    }

    void dfs(int idx, vector<string>& words, vector<int>& score, vector<int>& freq, int curr_score){
        if(idx == words.size()){
            max_score = max(max_score, curr_score);
            return;
        }
        
        if(!isPossible(words[idx], freq)){
            //ignore the curr_word
            dfs(idx+1, words, score, freq, curr_score);
        }else{
            //ignore the curr_word
            dfs(idx+1, words, score, freq, curr_score);
            //include current word after checking
            pair<int, vector<int>> p = get_score(words[idx], score, freq);
            dfs(idx+1, words, score, p.second, curr_score + p.first);
        }
            
    
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        max_score = 0;
        vector<int> freq(26, 0);
        for(char ch: letters)
            freq[ch-'a']++;

        dfs(0, words, score, freq, 0);
        return max_score;
    }
};