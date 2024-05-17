// 450. Delete Node in a BST
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root || (!root->left && !root->right && root->val == key))
            return NULL;
        
        // either the root has val equal to key or it is in left or right subtree
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else{
            if(root->left)
            {
                TreeNode* rightSubtree = root->right;
                TreeNode* leftSubtree = root->left;
                TreeNode* crawl = leftSubtree; 
                root->right = NULL;
                root = leftSubtree;
                while(crawl->right)
                    crawl = crawl->right;
                crawl->right = rightSubtree;
            }else{
                root = root->right;
            }
        }
        return root;
    }
};