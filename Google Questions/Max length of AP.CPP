// 1218. Longest Arithmetic Subsequence of Given Difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        // hashmap seems the way to go
        int n = arr.size(), mx_len = 1;
        unordered_map<int, int> len;

        for(int i=0; i<n; i++){
            if(len.contains(arr[i]-diff))
                len[arr[i]] = len[arr[i]-diff]+1;
            else
                len[arr[i]] = 1;
            mx_len = max(mx_len, len[arr[i]]);
        }

        return mx_len;
    }
};