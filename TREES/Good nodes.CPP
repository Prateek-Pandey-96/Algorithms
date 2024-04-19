// 1448. Count Good Nodes in Binary Tree
class Solution {
public:
    int goodNodes(TreeNode* root) {
        // level order traversal can help    
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int good_nodes = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [front, max_till_now] = q.front();
                q.pop();
                if(front->val >= max_till_now)
                    good_nodes++;
                max_till_now = max(max_till_now, front->val);
                if(front->left)
                    q.push({front->left, max_till_now});
                if(front->right)
                    q.push({front->right, max_till_now});
            }
        }

        return good_nodes;
    }
};