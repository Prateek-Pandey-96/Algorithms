// 337. House Robber III

class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(!root)
            return {0, 0};
        
        pair<int, int> leftValues = dfs(root->left);
        pair<int, int> rightValues = dfs(root->right);

        int possibility1 = leftValues.first + rightValues.first + root->val;
        int possibility2 = max(leftValues.first, leftValues.second) + max(rightValues.first, rightValues.second);

        return {possibility2, possibility1};
    }   
    // Use a pair
    int rob(TreeNode* root) {
        pair<int, int> possibilities = dfs(root);
        return max(possibilities.first, possibilities.second);
    }
};