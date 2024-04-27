// 17. Letter Combinations of a Phone Number

class Solution {
public:
    unordered_map<char, vector<char>> ch;
    vector<string> recursiveHelper(string digits, int idx){
        if(idx == digits.size())
            return {};
        
        vector<string> result;
        string temp;
        for(char c: ch[digits[idx]]){
            vector<string> rem = recursiveHelper(digits, idx+1);
            temp.push_back(c);
            if(rem.size())
            {
                for(string& str: rem)
                    result.push_back(temp + str);
            }else{
                result.push_back(temp);
            }
            temp.pop_back();
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        ch['2'] = {'a', 'b', 'c'};
        ch['3'] = {'d', 'e', 'f'};
        ch['4'] = {'g', 'h', 'i'};
        ch['5'] = {'j', 'k', 'l'};
        ch['6'] = {'m', 'n', 'o'};
        ch['7'] = {'p', 'q', 'r', 's'};
        ch['8'] = {'t', 'u', 'v'};
        ch['9'] = {'w', 'x', 'y', 'z'};

        return recursiveHelper(digits, 0);
    }
};