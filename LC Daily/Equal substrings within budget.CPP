// 1208. Get Equal Substrings Within Budget

class Solution {
public:
    int getDiff(char a, char b){
        return abs((a-'a') - (b-'a'));
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i=0, j=0;
        int cost = 0;
        int max_len = 0;
        while(j < n){
            cost += getDiff(s[j], t[j]);

            while(i<=j and cost > maxCost){
                cost -= getDiff(s[i], t[i]);
                i++;
            }

            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};