// 720. Longest Word in Dictionary

class Solution {
public:
    static bool compare(string wordA, string wordB){
        if(wordA.length() == wordB.length())
            return wordA < wordB;
        return wordA.length() < wordB.length();
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        unordered_map<string, bool> dp;
        int mx_len = 0;
        string ans;

        for(string word: words){
            string prefix = word.substr(0, word.length()-1);
            // single character word
            if(prefix.length() == 0){
                if(mx_len == 0){
                    mx_len = 1;
                    ans = word;
                }
                dp[word] = true;
            }else{
                if(dp.contains(prefix) and dp[prefix])
                {
                    dp[word] = true;
                    if(word.length() > mx_len){
                        mx_len = word.length();
                        ans = word;
                    }
                }else{
                    dp[word] = false;
                }
            }
        }
        return ans;
    }
};