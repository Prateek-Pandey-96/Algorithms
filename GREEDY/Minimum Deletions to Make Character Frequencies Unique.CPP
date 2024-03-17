// 1647. Minimum Deletions to Make Character Frequencies Unique

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch-'a']++;
        unordered_set<int> has_occured;
        int to_remove = 0;
        for(int i=0; i<26; i++){
            while(has_occured.contains(freq[i]) and freq[i]!=0)
            {
                to_remove += 1;
                freq[i]--;
            }
            has_occured.insert(freq[i]);
        }
        return to_remove;
    }
};