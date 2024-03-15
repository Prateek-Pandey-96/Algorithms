// 647. Palindromic Substrings

class Solution {
public:
    int expandAndCount(string s, int idx){
        int odd = 1, even = 0;
        //counting odd substrings
        int l = idx-1, r = idx+1;
        while(l>=0 and r<s.length()){
            if(s[l--]==s[r++])
                odd++;
            else
                break;
        }
        // counting even substrings
        // imaginary line between l and r
        l=idx, r=idx+1;
        while(l>=0 and r<s.length()){
            if(s[l--]==s[r++])
                even++;
            else
                break;
        }
        return odd+even;
    }
    int countSubstrings(string s) {
        // expand from the char to do it in O(n*n)
        int total_subStrings = 0;
        for(int i=0; i<s.length(); i++){
            total_subStrings += expandAndCount(s, i);
        }

        return total_subStrings;
    }
};