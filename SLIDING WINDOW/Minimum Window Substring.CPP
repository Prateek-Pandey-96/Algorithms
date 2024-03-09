//76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        //haystack and needle length
        int m = s.length(), n = t.length();
        if(m < n) return "";

        unordered_map<char, int> needle_map, haystack_map;
        for(auto ch: t)
            needle_map[ch]++;
        
        int matches = 0, required_matches = n, i = 0, j = 0;
        int min_len = INT_MAX, start = -1;

        // slide the window on haystack
        while(j < m){
            char curr = s[j];
            haystack_map[curr]++;
            if(needle_map.contains(curr) and needle_map[curr]>=haystack_map[curr])
                matches++;

            if(matches == required_matches){
                while(i<=j and haystack_map[s[i]]>needle_map[s[i]])
                    haystack_map[s[i++]]--;

                if(j-i+1 < min_len){
                    min_len = j-i+1;
                    start = i;
                }
                // disturb the match count
                haystack_map[s[i++]]--;
                matches--;
            }

            
            j++;
        }
        if(start == -1)
            return "";
        
        return s.substr(start, min_len);
    }
};