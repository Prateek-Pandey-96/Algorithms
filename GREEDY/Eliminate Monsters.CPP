// 1921. Eliminate Maximum Number of Monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        int n = dist.size();
        
        for(int i=0; i<n; i++)
            time.push_back(1.0*dist[i]/speed[i]);
        sort(time.begin(), time.end());
        
        /*
             First monster is always eliminated
        */
        int t = 1, monsters = 1;
        /*
            Eliminate monsters at each step and 
            reduce time[i] of next monster by one
        */ 
        for(int i=1; i<n; i++){
            cout<<time[i]-t<<" "<<endl;
            if(time[i]-t <= 0)
                return monsters;
            t += 1;
            monsters += 1;
        }

        return monsters;
    }
};