// 103. Binary Tree Zigzag Level Order Traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        bool left_to_right = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode* front = q.front();
                temp.push_back(front->val);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(left_to_right){
                result.push_back(temp);
            }else{
                reverse(temp.begin(), temp.end());
                result.push_back(temp);
            }
            left_to_right = !left_to_right;
        }

        return result;
    }
};