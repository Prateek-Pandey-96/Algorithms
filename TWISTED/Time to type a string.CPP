// Constraints:

// length of keyboard will be equal to 26 and all the lowercase letters will occur exactly once;
// the length of text is within the range [1..100,000];
// string text contains only lowercase letters [a-z].
class Solution {
public:
    long findTime(string keyboard, string text) {
        vector<int> pos(26);
        int n = keyboard.size();
        for(int i=0; i<n; i++)
            pos[keyboard[i]-'a'] = i;


        long time = 0, curr_idx = 0;
        for(auto ch: text){
            time += abs(pos[ch-'a']-curr_idx);
            curr_idx = pos[ch-'a'];
        }

        return time;
    }
};