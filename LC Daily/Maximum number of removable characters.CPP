// 1898. Maximum Number of Removable Characters

class Solution {
public:
    bool isSubsequence(string s, string p, int mid, vector<int>& removable){
        for(int it=0; it<=mid; it++)
            s[removable[it]]='#';
        int i=0, j=0, m=s.length(), n=p.length();
        while(i<m && j<n){
            if(s[i]==p[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==n;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size()-1;
        int idx = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isSubsequence(s, p, mid, removable)){
                idx = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return idx+1;
    }
};