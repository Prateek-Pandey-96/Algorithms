// 1888. Minimum Number of Flips to Make the Binary String Alternating

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        // create the helper option strings
        string option1(2*n, '0'), option2(2*n, '0');
        for(int i=0; i<2*n; i++){
            if(i % 2 == 0)
                option1[i]='1';
            else
                option2[i]='1';
        }

        s += s;
        cout<<option1<<" "<<option2<<" "<<s<<endl;
        // sliding window to compare string s with both the options
        int diff1 = 0, diff2 = 0, min_flips = n;
        for(int i=0; i<n; i++){
            if(s[i] != option1[i]) diff1++;
            if(s[i] != option2[i]) diff2++;
        }
        min_flips = min(diff1, diff2);

        for(int i=n; i<2*n; i++){
            if(s[i] != option1[i]) diff1++;
            if(s[i-n] != option1[i-n]) diff1--;

            if(s[i] != option2[i]) diff2++;
            if(s[i-n] != option2[i-n]) diff2--;
            
            min_flips = min({min_flips, diff1, diff2});
        }

        return min_flips;
    }
};