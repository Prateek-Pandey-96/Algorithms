// 853. Car Fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> pos_time(n);
        for(int i=0; i<n; i++)
            pos_time[i] = {position[i], 1.0 * (target - position[i])/speed[i]};
        
        sort(pos_time.begin(), pos_time.end());
        int fleets = n;
        double time = pos_time[n-1].second;
        for(int i=n-2; i>=0; i--){
            if(pos_time[i].second <= time)
                fleets--;
            else
                time = pos_time[i].second;
        }
        return fleets;
    }
};