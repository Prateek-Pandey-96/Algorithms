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
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                double slope = getSlope(points[i], points[j]);
                cout<<slope<<endl;
                int count = 2;
                for(int k=j+1; k<n; k++){
                    double slope_new = getSlope(points[i], points[k]);
                    if(slope == slope_new)
                        count++;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};