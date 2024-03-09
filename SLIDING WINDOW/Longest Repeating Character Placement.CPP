// 424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), i = 0, j = 0;
        int max_f = 0, max_len = 0;
        vector<int> hash(26, 0);

        while(j < n){
            hash[s[j]-'A']++;
            if(hash[s[j]-'A'] > max_f)
                max_f = hash[s[j]-'A'];

            while((j-i+1) - max_f > k){
                hash[s[i]-'A']--;
                i++;
            }

            max_len = max(max_len, j-i+1);
            j++;
        }

        return max_len;
    }
};