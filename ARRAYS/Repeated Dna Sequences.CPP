// 187. Repeated DNA Sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10)
            return {};
        
        unordered_map<string, int> hashmap;
        for(int i=0; i<=s.length()-10; i++){
            string temp = s.substr(i, 10);
            hashmap[temp]++;
        }

        vector<string> result;
        for(auto [key, value]: hashmap)
            if(value>1)
                result.push_back(key);

        return result;
    }
};