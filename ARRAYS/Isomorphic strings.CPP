// 205. Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> mapping, mapping2;

        for(int i=0; i<n; i++){
            if(!mapping.contains(s[i]))
                mapping[s[i]] = t[i];
            else{
                if(mapping[s[i]] != t[i])
                    return false;
            }
            if(!mapping2.contains(t[i]))
                mapping2[t[i]] = s[i];
            else{
                if(mapping2[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};