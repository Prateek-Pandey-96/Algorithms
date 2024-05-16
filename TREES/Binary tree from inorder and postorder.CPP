// 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:
    unordered_map<int, int> in_idx;
    TreeNode* Helper(vector<int>& inorder, vector<int>& postorder, int inlow, int inhigh, int postidx){
        if(inlow > inhigh)
            return nullptr;
        int val = postorder[postidx];
        int idx = in_idx[val];
        TreeNode* root = new TreeNode(val);
        root->right = Helper(inorder, postorder, idx+1, inhigh, postidx-1);
        root->left = Helper(inorder, postorder, inlow, idx-1, postidx-(inhigh-idx)-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // will be needed to find root in inorder array in o(1)
        for(int i=0; i<n; i++)
            in_idx[inorder[i]] = i;
        
        return Helper(inorder, postorder, 0, n-1, n-1);
    }
};