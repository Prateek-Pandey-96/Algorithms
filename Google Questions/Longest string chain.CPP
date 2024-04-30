// 1048. Longest String Chain

class SolutionOptimal {
public:
    static bool compare(string wordA, string wordB)
    {
        return wordA.length() < wordB.length();
    }
    int longestStrChain(vector<string>& words) {
        // First we need to sort it by length
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int ans = 1;

        for(auto word: words){
            dp[word] = 1;
            for(int i=0; i<word.length(); i++){
                string prefix = word.substr(0, i);
                string suffix = word.substr(i+1);
                if(dp.contains(prefix+suffix)){
                    dp[word] = max(dp[word], dp[prefix+suffix]+1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};

class SolutionNormal {
public:
    static bool compare(string wordA, string wordB)
    {
        return wordA.length() < wordB.length();
    }
    bool isPredecessor(string wordA, string wordB){
        int i = 0, j = 0, l1 = wordA.length(), l2 = wordB.length();
        if(l1+1 != l2)
            return false;
        while(i<l1 and j<l2){
            if(wordA[i]==wordB[j]){
                i++, j++;
            }else{
                j++;
            }
        }
        return i==l1;
    }
    // lis modification
    int longestStrChain(vector<string>& words) {
        // First we need to sort it by length
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        vector<int> lis(n, 1);

        int ans = 1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(isPredecessor(words[j], words[i]) and lis[i]<lis[j]+1)
                    lis[i] = lis[j]+1;
            }
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};