// 1980. Find Unique Binary String

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // 1> keep nums in a hashset
        // 2> create all possible numbers of length n
        int n = nums.size();
        int mask = 1<<n;
        unordered_set<string> present(nums.begin(), nums.end());

        for(int mk=0; mk<mask; mk++){
            string temp;
            for(int i=0; i<n; i++){
                if((mk&(1<<i)) != 0)
                    temp.push_back('1');
                else
                    temp.push_back('0');
            }
            
            reverse(temp.begin(), temp.end());
            if(!present.contains(temp))
                return temp;
        }

        return "";
    }
};