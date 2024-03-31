// 1011. Capacity To Ship Packages Within D Days

class Solution {
public:
    int getSum(vector<int>& weights){
        int sum = 0;
        for(int weight: weights)
            sum += weight;
        return sum;
    }
    int getMax(vector<int>& weights){
        int mx = -1;
        for(int weight: weights)
            mx = max(mx, weight);
        return mx;
    }
    int getDays(vector<int>& weights, int capacity){
        int idx = 0, n = weights.size(), sum = 0;
        int reqDays = 0;
        while(idx < n){
            sum += weights[idx];
            if(sum > capacity){
                sum = weights[idx];
                reqDays++;
            }
            idx++;
        }
        return ++reqDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // if i use sum(weights) as capacity answer will be one day
        int n = weights.size(), low = getMax(weights), high = getSum(weights);
        int result;
        cout<<low<<high<<endl;
        while(low <= high){
            int mid = low + (high-low)/2;
            int daysRequired = getDays(weights, mid);
            if(daysRequired > days)
                low = mid+1;
            else{
                result = mid;
                high = mid-1;
            }
        }

        return result;
    }
};