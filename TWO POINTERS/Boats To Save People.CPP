// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), low = 0, high = n-1, boats = 0;
        sort(people.begin(), people.end());
        while(low < high){
            if(people[low]+people[high] > limit){
                high--;
            }else{
                low++;
                high--;
            }
            boats++;
        }
        return low==high? ++boats: boats;
    }
};