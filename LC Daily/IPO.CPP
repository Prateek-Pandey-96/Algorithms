// 502. IPO

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // final capital is always adding up
        int n = capital.size();

        vector<pair<int, int>> project;
        for(int i=0; i<n; i++)
            project.push_back({capital[i], profits[i]});
        sort(project.begin(), project.end());

        int available_capital = w, j = 0;
        priority_queue<int> maxHeap;
        
        while(k){
            while(j<n and project[j].first<=available_capital){
                maxHeap.push(project[j].second);
                j++;
            }
            if(!maxHeap.empty())
            {
                available_capital += maxHeap.top();
                maxHeap.pop();
                k--;
            }else{
                break;
            }
        }

        return available_capital;
    }
};