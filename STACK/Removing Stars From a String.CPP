//2390. Removing Stars From a String

class Solution {
public:
    string removeStars(string s) {
        string result;
        for(char ch: s){
            if(ch!='*')
                result.push_back(ch);
            else
                result.pop_back();
        }
        return result;
    }
};