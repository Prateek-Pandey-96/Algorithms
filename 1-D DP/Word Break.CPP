// 139. Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> isPossible(n+1, false);
        isPossible[0] = true;

        for(int i=1; i<=n; i++){
            for(auto word: wordDict){
                if(i >= word.length() and s.substr(i-word.length(), word.length()) == word){
                    isPossible[i] = isPossible[i-word.length()];
                    if(isPossible[i])
                        break;
                }
            }
        }


        return isPossible[n]; 
    }
};