// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0, totalcost = 0;
        for(int i=0; i<n; i++)
            totalgas += gas[i], totalcost += cost[i];
        
        if(totalgas < totalcost)
            return -1;
        
        int sum = 0, start = 0;
        for(int i=0; i<n; i++){
            sum += gas[i]-cost[i];
            if(sum < 0)
            {
                sum = 0;
                start = i+1;
            }
        }

        return start;
    }
};