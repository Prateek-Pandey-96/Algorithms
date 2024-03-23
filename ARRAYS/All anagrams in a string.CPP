// 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        if(n<m)
            return {};
        
        vector<int> p_map(26, 0), n_sliding_map(26, 0);
        int mc = 0;
        for(char ch: p)
            p_map[ch-'a']++;
        for(int i=0; i<m; i++)
            n_sliding_map[s[i]-'a']++;
        for(int i=0; i<26; i++)
            if(p_map[i]==n_sliding_map[i])
                mc++;

        vector<int> result;
        if(mc == 26)
            result.push_back(0);
        
        for(int i=m; i<n; i++){
            n_sliding_map[s[i]-'a']++;
            if(n_sliding_map[s[i]-'a']==p_map[s[i]-'a'])
                mc++;
            else if(n_sliding_map[s[i]-'a']==p_map[s[i]-'a']+1)
                mc--;
            
            n_sliding_map[s[i-m]-'a']--;
            if(n_sliding_map[s[i-m]-'a']==p_map[s[i-m]-'a'])
                mc++;
            else if(n_sliding_map[s[i-m]-'a']==p_map[s[i-m]-'a']-1)
                mc--;
            if(mc == 26)
                result.push_back(i-m+1);
        }
        return result;
    }
};