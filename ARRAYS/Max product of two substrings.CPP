// 2002. Maximum Product of the Length of Two Palindromic Subsequences

class Solution {
public:
    bool isPallindrome(string s){
        int low = 0, high = s.length()-1;
        while(low<high)
            if(s[low++]!=s[high--])
                return false;
        return true;
    }
    int maxProduct(string s) {
        int n = s.length();
        int totalSubstrs = 1<<n;
        //store lengths of substrs
        unordered_map<int, int> hashmap;
        // we dont want empty substring hence not taking mask = 0
        for(int mask=1; mask<totalSubstrs; mask++){
            string str;
            for(int i=0; i<n; i++){
                if((mask & (1<<i)))
                    str.push_back(s[n-1-i]);

            if(isPallindrome(str))
                hashmap[mask] = str.length(); 
        }
        
        int ans = -1;
        for(auto [u1, v1]: hashmap)
            for(auto [u2, v2]: hashmap)
                if((u1&u2) == 0)
                    ans = max(ans, v1*v2);
            
        return ans;
    }
};