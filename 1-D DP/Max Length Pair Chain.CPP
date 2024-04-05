// 646. Maximum Length of Pair Chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> max_till_now(n, 1);
        int curr_len = 1, max_len = 1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--)
                if(pairs[j][1] < pairs[i][0])
                    max_till_now[i] = max(max_till_now[i], max_till_now[j] + 1);

            max_len = max(max_len, max_till_now[i]);
        }
        return max_len;
    }
};