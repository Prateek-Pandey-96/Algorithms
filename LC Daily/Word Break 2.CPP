// 140. Word Break II

class Solution {
public:
    void dfs(int idx, string s, unordered_set<string>& words, vector<string>& temp, vector<vector<string>>& result){
        if(idx==s.length()){
            result.push_back(temp);
            return;
        }

        for(int len=1; len<=s.length()-idx; len++){
            string prefix = s.substr(idx, len);
            if(words.contains(prefix)){
                temp.push_back(prefix);
                dfs(idx+len, s, words, temp, result);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<string>> result;
        vector<string> temp;

        dfs(0, s, words, temp, result);
        vector<string> sentences;
        for(vector<string> res: result){
            string temp;
            for(string r: res)
            {
                temp+=r;
                temp.push_back(' ');
            }
            temp.pop_back();
            sentences.push_back(temp);
        }
        return sentences;
    }
};