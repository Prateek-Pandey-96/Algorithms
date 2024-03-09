// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int n = s.length();
        int i=0, j=0, max_len=0;
        
        while(j < n){
            hashmap[s[j]]++;

            while(hashmap[s[j]]>1){
                hashmap[s[i]]--;
                i++;
            }

            max_len = max(max_len, j-i+1);
            j++;
        }

        return max_len;
    }
};