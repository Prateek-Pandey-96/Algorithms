// 332. Reconstruct Itinerary

#include <bits/stdc++.h>
#define minHeap priority_queue<string, vector<string>, greater<string>>
class Solution {
public:
    void DFS(string src, unordered_map<string, minHeap>& destinations, vector<string>& result){
        minHeap& children = destinations[src];
        while(!children.empty()){
            string dest = children.top();
            children.pop();
            DFS(dest, destinations, result);
        }
        result.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, minHeap> destinations;
        for(vector<string> ticket: tickets)
            destinations[ticket[0]].push(ticket[1]);
        
        vector<string> result;
        DFS("JFK", destinations, result);
        reverse(result.begin(), result.end());
        return result;
    }
};