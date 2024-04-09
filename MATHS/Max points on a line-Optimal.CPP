// 149. Max Points on a Line

class Solution {
public:
    double getSlope(vector<int> pointA, vector<int> pointB){
        double slope = 0.0;
        if(!(pointB[0] - pointA[0]))
            slope = (double)1e6;
        else
            slope = (double)(pointB[1] - pointA[1])/(pointB[0] - pointA[0]);
        return slope;
    }
    int maxPoints(vector<vector<int>>& points) {
        /*
            For each pair of points check all points.size()-2 points
        */
        int n = points.size();
        if(n==1 || n==2)
            return n;
        
        int result = 2;
        int maxF = 2;
        unordered_map<double, int> freq;
        for(int i=0; i<n-1; i++){
            freq.clear();
            maxF = 2;
            for(int j=i+1; j<n; j++){
                double slope = getSlope(points[i], points[j]);
                if(!freq.contains(slope)){
                    freq[slope] = 2;
                }else{
                    freq[slope] += 1;
                }
                maxF = max(maxF, freq[slope]);
            }
            result = max(result, maxF);
        }
        return result;
    }
};