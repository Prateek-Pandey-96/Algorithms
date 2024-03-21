// 2483. Minimum Penalty for a Shop

class Solution {
public:
    int bestClosingTime(string customers) {
        // we can store open till an idx
        int n = customers.size();
        vector<int> yes(n, 0);
        int yes_ctr = 0;

        for(int i=1; i<n; i++){
            if(customers[i-1] == 'Y')
                yes_ctr++;
            yes[i] = yes_ctr;
        }
        // store total yes in yes counter
        if(customers[n-1] == 'Y')
            yes_ctr++;

        // trying to close the shop at each idx
        int min_idx = -1, min_penalty = INT_MAX;
        for(int i=0; i<n; i++){
            int yes_before = (i-1 >= 0)? yes[i]: 0;
            int no_before = i - yes_before;
            int penalty, yes_after;
            if(customers[i] == 'Y'){
                yes_after = yes_ctr - yes_before - 1;
                penalty = no_before + 1 + yes_after;
            }else{
                yes_after = yes_ctr - yes_before;
                penalty =  no_before + yes_after;
            }
            if(penalty < min_penalty){
                min_penalty = penalty;
                min_idx = i;
            }
        }

        if(n-yes_ctr < min_penalty){
            min_idx = n;
        }
        return min_idx;
    }
};