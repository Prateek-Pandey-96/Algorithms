// 875. Koko Eating Bananas

class Solution {
public:
    int getHours(vector<int>& piles, int capacity){
        long hours = 0;
        for(int pile: piles)
        {
            hours += (long)pile/capacity;
            if(pile%capacity)
                hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 1e9, low = 1, ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            int hours = getHours(piles, mid);
            if(hours < 0)
                break;
            if(hours > h)
                low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};