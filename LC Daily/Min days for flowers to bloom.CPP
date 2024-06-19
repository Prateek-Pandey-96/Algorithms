class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int limit){
        int n = bloomDay.size();
        int bouquets = 0, idx = 0, size = 0;
        while(idx < n){
            if(bloomDay[idx]>limit){
                idx++;
                continue;
            }
            while(idx<n and bloomDay[idx]<=limit){
                size++;
                idx++;
                if(size==k)
                {
                    bouquets++;
                    break;
                }
            }
            size = 0;
        }
        return bouquets >= m;        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, n = bloomDay.size();
        int high = 0, ans = -1;
        for(int day: bloomDay)
            high = max(high, day);
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};