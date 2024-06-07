//1002. Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> hashedWords;
        for(int i=0; i<n; i++){
            string word = words[i];
            vector<int> freq(26, 0);
            for(auto ch: word){
                freq[ch-'a']++;
            }
            hashedWords.push_back(freq);
        }
        vector<string> result;

        for(int j=0; j<26; j++){
            int mn = 101;
            for(int i=0; i<n; i++){
                mn = min(mn, hashedWords[i][j]);
            }
            string temp;
            temp.push_back(j+'a');
            while(mn--)
                result.push_back(temp);
        }
        return result;
    }
};