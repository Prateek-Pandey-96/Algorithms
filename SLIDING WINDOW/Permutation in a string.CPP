// 567. Permutation in String
class Solution {
public:
    static bool check(vector<int> a, vector<int> b){
        int n = a.size();
        for(int i=0; i<n; i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> ques(26, 0), ans(26, 0);
        
        int m = s1.length(), n = s2.length();
        if(m > n) return false;
        
        for(auto ch: s1) ques[ch-'a']++;
        for(int i=0; i<m; i++) ans[s2[i]-'a']++;

        if(check(ques, ans))
            return true;

        for(int i=m; i<n; i++){
            ans[s2[i]-'a']++;
            ans[s2[i-m]-'a']--;
            if(check(ques, ans))
                return true;
        }

        return false;
    }
};