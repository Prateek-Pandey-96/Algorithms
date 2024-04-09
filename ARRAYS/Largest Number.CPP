// 179. Largest Number

class Solution {
public:
    static bool compare(int a, int b){
        string as = to_string(a);
        string bs = to_string(b);
        return as+bs > bs+as;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result;
        for(int num: nums)
            result += to_string(num);
        if(result[0]=='0')
            return "0";
        return result;
    }
};