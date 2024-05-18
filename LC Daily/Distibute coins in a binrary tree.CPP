// 979. Distribute Coins in Binary Tree

class Solution {
public:
    // we will write a dfs function which when negative shows demand and positive shows excess
    int moves;
    int DFS(TreeNode* root){
        if(!root)
            return 0;
        int left_coins = DFS(root->left);
        int right_coins = DFS(root->right);

        moves += abs(left_coins)+abs(right_coins);
        return root->val-1 + left_coins + right_coins;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        DFS(root);
        return moves;
    }
};