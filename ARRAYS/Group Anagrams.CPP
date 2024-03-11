// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
    
        for(string str: strs){
            // storing str in a hashmap ch vs count
            vector<int> arr(26, 0);
            for(auto ch: str) 
                arr[ch-'a']++;
            
            // forming key
            string key;
            for(char ch='a'; ch<='z'; ch++)
                key.push_back(ch), key.push_back(arr[ch-'a']);
            
            // creating hashmap of string vs vector<string>
            hashMap[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto [key, value]: hashMap)
            result.push_back(value);
        

        return result;
    }
};