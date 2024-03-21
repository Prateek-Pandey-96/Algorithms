// 2405. Optimal Partition of String

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> hashset;
        int substrs = 0;
        int idx = 0, n = s.length();
        
        while(idx < n){
            if(hashset.size() and hashset.contains(s[idx])){
                substrs++;
                hashset.clear();
            }
            hashset.insert(s[idx++]);
        }

        return ++substrs;
    }
};