// 1899. Merge Triplets to Form Target Triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /*Step 1 :- filter out triplets that can't be included*/
        int n = triplets.size();
        vector<int> result(3, 0);
        for(int i=0; i<n; i++){
            auto triplet = triplets[i];
            if(triplet[0]<=target[0] and triplet[1]<=target[1] and triplet[2]<=target[2])
            {
                result[0] = max(result[0], triplet[0]);
                result[1] = max(result[1], triplet[1]);
                result[2] = max(result[2], triplet[2]);
            }
        }
        return result==target;
    }
};