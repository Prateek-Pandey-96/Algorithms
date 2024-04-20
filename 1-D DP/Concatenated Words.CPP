// 472. Concatenated Words

class Solution {
public:
    map<pair<string, int>, bool> isPresent;
    bool isConcatenated(string word, unordered_set<string>& wordset, int count){
        if(!word.length())
            return count >= 2;
        if(isPresent.contains({word, count}))
            return isPresent[{word, count}];
        // for(string setword: wordset){
        //     if(setword.length() > word.length())
        //         continue;
        //     string substr = word.substr(0, setword.length());
        //     if(substr == setword){
        //         bool check = isConcatenated(word.substr(setword.length()), wordset, count+1);
        //         if(check)
        //             return isPresent[{word, count}]=true;
        //     }
        // }
        for(int i=1; i<=word.length(); i++){
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            if(wordset.contains(prefix) and isConcatenated(suffix, wordset, count+1))
                return isPresent[{word, count}]=true;
        }
        return isPresent[{word, count}]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordset(words.begin(), words.end());
        vector<string> result;
        isPresent.clear();
        for(string word: words){
            bool check = isConcatenated(word, wordset, 0);
            if(check)
                result.push_back(word);
        }
        return result;
    }
};