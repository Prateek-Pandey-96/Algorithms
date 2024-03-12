// 424. Longest Repeating Character Replacement

class Solution {
public:
    int getMaxFrequency(vector<int>& count){
        int freq = -1;
        for(auto ele: count)
            freq = max(freq, ele);
        return freq;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        
        int i=0, j=0, ans=0;
        
        while(j<n){
            count[s[j]-'A']++;
            
            while((j-i+1)-getMaxFrequency(count) > k){
                count[s[i]-'A']--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};