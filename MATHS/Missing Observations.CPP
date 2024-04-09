// 2028. Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);

        int visible_sum = 0;
        for(int roll: rolls)
            visible_sum += roll;
        
        int required_sum = sum - visible_sum;
        
        if(required_sum > 6*n || required_sum < n)
            return {};
        
        int repeating_number = required_sum/n;
        int diff = required_sum%n;

        vector<int> result(n, repeating_number);
        for(int i=0; i<diff; i++)
            result[i]++;

        return result;
    }
};