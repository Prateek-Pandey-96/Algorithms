// 652. Find Duplicate Subtrees

class Solution {
public:
    string inorder(TreeNode* root, unordered_map<string, int>& freq, unordered_map<string, TreeNode*>& helper){
        if(!root)
            return "null";
        string leftsubtree = inorder(root->left, freq, helper);
        string rightsubtree = inorder(root->right, freq, helper);
        string key = "(" + leftsubtree + "*" + to_string(root->val) + "*" + rightsubtree + ")";
        freq[key]++;
        helper[key] = root;
        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> freq;
        unordered_map<string, TreeNode*> helper;
        inorder(root, freq, helper);
        vector<TreeNode*> result;

        for(auto [k, v]: freq)
            if(v > 1)
                result.push_back(helper[k]);
            
    
        return result;
    }
};