// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char ch: s)
            freq[ch]++;

        int len = 0, odd = 0;
        for(auto [key, val]: freq){
            if(val%2 == 0)
                len += val;
            else
                odd++, len += val-1;
        }
        return len + (odd>0?1:0);
    }
};