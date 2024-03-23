// 1461. Check If a String Contains All Binary Codes of Size K

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;
        int required_size = pow(2, k);

        int n = s.length();
        for(int i=0; i<=n-k; i++)
            codes.insert(s.substr(i, k));
        
        if(codes.size() == required_size)
            return true;
        return false;
    }
};