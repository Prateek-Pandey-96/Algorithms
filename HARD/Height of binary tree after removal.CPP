// 2458. Height of Binary Tree After Subtree Removal Queries

class Solution {
public:
    int DFS(TreeNode* root, int curr_level, unordered_map<int, int>& height, unordered_map<int, int>& level)
    {
        if(!root)
            return -1;
        level[root->val] = curr_level;
        int lheight = DFS(root->left, curr_level+1, height, level);
        int rheight = DFS(root->right, curr_level+1, height, level);
        int curr_height = max(lheight, rheight) + 1;
        height[root->val] = curr_height;
        return curr_height;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // find level and height for each node
        unordered_map<int, int> height, level;
        int max_height = DFS(root, 0, height, level);

        // keep max height and second max height for each level
        unordered_map<int, pair<int, int>> level_heights;
        for(auto [node_val, l]: level){
            if(!level_heights.contains(l))
                level_heights[l] = {height[node_val], -1};
            else{
                if(height[node_val]>level_heights[l].first){
                    level_heights[l].second = level_heights[l].first;
                    level_heights[l].first = height[node_val];
                }else if(height[node_val]>=level_heights[l].second){
                    level_heights[l].second = height[node_val];
                }   
            }
        }

        vector<int> result;
        for(int query: queries){
            if(level_heights[level[query]].second == -1){
                result.push_back(level[query]-1);
            }else{
                if(level_heights[level[query]].first == height[query])
                    result.push_back(level[query] + level_heights[level[query]].second);
                else if(level_heights[level[query]].second == height[query])
                    result.push_back(level[query] + level_heights[level[query]].first);
                else
                    result.push_back(level[query] + level_heights[level[query]].first);
            }
        }

        return result;
    }
};