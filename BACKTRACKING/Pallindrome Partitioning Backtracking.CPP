class Solution {
public:
    bool isPallindrome(string temp){
        int low = 0, high = temp.length()-1;
        while(low<=high){
            if(temp[low]!=temp[high])
                return false;
            low++,high--;
        }
        return true;
    }
    void pallindromeGenerator(vector<vector<string>>& result, vector<string>& temp, string A){
        if(A.length()==0)
        {
            result.push_back(temp);
            return;
        }

        for(int i=0;i<A.length();i++){
            string pre = A.substr(0, i+1);
            string remaining = A.substr(i+1);
            if(isPallindrome(pre)){
                temp.push_back(pre);
                pallindromeGenerator(result, temp, remaining);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        pallindromeGenerator(result, temp, s);
        return result;
    }
};