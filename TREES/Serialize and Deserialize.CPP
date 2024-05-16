// 297. Serialize and Deserialize Binary Tree
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "*";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val)+","+left+","+right;
    }
    TreeNode* decode(queue<string>& q){
        string front = q.front();
        q.pop();
        if(front == "*")
            return NULL;
        TreeNode* root = new TreeNode(stoi(front));
        root->left = decode(q);
        root->right = decode(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;

        for(int i=0; i<data.length(); i++){
            if(data[i]!=','){
                temp.push_back(data[i]);
            }else{
                q.push(temp);
                temp.clear();
            }
        }
        q.push(temp);
        temp.clear();

        return decode(q);
    }
};
