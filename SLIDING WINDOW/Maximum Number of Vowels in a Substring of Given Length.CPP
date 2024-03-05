// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int vowels = 0;

        /* initial window */
        for(int i=0; i<k; i++){
            if(isVowel(s[i]))
                vowels++;
        }
        int max_vowels = vowels;

        /* slide the window */
        for(int i=k; i<s.length(); i++){
            if(isVowel(s[i]))
                vowels++;
            if(isVowel(s[i-k]))
                vowels--;
            max_vowels = max(vowels, max_vowels);
        }

        return max_vowels;
    }
};