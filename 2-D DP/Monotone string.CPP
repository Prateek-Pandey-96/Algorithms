// 926. Flip String to Monotone Increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> pref_sum(n, 0), suff_sum(n, 0);
        int pre_sum = 0, suf_sum = 0;
        
        for(int i=0; i<n; i++){
            pre_sum += (s[i]=='1')? 1: 0;
            suf_sum += (s[n-1-i]=='1')? 1: 0;
            pref_sum[i] = pre_sum;
            suff_sum[n-1-i] = suf_sum;
        }
        
        int min_flips = min(n-pre_sum, pre_sum);
        
        // assuming all 0 before i and all 1 after and including i
        for(int i=1; i<n; i++)
            min_flips = min(min_flips, pref_sum[i-1] + (n-i) - suff_sum[i]);
        

        return min_flips;
    }
};