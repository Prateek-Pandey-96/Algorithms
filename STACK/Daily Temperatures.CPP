//739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /* monotonous stack problem */
        int n = temperatures.size();
        vector<int> hotterIndices(n);
        stack<int> st;

        /* for each day we need a day with temperature just higher than that day */
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and temperatures[st.top()] <= temperatures[i]) 
                st.pop();
            if(st.empty())
                hotterIndices[i] = -1;
            else
                hotterIndices[i] = st.top();
            st.push(i);
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            if(hotterIndices[i]==-1)
                result.push_back(0);
            else
                result.push_back(hotterIndices[i]-i);
        }

        return result;
    }
};