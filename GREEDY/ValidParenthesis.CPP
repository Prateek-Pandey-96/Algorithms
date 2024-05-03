// 678. Valid Parenthesis String

class Solution {
public:
    bool checkValidString(string s) {
        // open_max each * is (
        // open min each * is )
        // open will always be in this range
        int open_max = 0, open_min = 0;

        for(char ch: s){
            if(ch == '(')
            {
                open_max++;
                open_min++;
            }else if(ch == ')'){
                open_max--;
                open_min--;
            }else{
                open_max++;
                open_min--;
            }
            if(open_max < 0)
                return false;
            open_min = max(0, open_min);
        }
        return open_min==0;
    }
};