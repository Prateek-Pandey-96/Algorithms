// 129. Sum Root to Leaf Numbers

class Solution {
public:
    void helper(TreeNode* root, int curr, int& sum){
        if(!root)
            return;
        if(!root->left and !root->right){ 
            sum += curr*10+root->val;
            return;
        }
        curr = curr*10 + root->val;
        helper(root->left, curr, sum);
        helper(root->right, curr, sum);
        curr = curr/10;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, curr = 0;
        helper(root, curr, sum);
        return sum;
    }
};