// 2486. Append Characters to String to Make Subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        int m = s.length(), n = t.length();

        for(int j=0; j<n; j++){
            char curr = t[j];
            bool found = false;
            for(int i=idx; i<m; i++){
                if(s[i]==curr)
                {
                    found = true;
                    idx = i+1;
                    break;
                }
            }
            if(!found)
                return n-j;
        }
        // if the loop completes
        return 0;
    }
};