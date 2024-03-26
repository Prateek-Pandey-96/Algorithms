// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.length();
        vector<string> temp(numRows, "");
        bool down = true;
        int idx = 0;

        for(int i=0; i<n; i++){
            temp[idx].push_back(s[i]);
            if(down)
                idx++;
            else
                idx--;
            if(idx==numRows)
            {
                idx = numRows-2;
                down = false;
            }
            if(idx==-1){
                idx = 1;
                down = true;
            }
        }

        string result;
        for(string str: temp)
            cout<<str<<endl, result += str;
        
        return result;
    }
};