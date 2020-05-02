/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        
        queue<TreeNode* > next_q;
        if(root->left != NULL)
            next_q.push(root->left);
        if(root->right != NULL)
            next_q.push(root->right);
        
        ret.push_back(root->val);
        while(!next_q.empty()){
            ret.push_back(next_q.back()->val);
            queue<TreeNode* > temp_q;
            
            while(!next_q.empty()){
                TreeNode* tempNode = next_q.front();
                if(tempNode->left != NULL)
                    temp_q.push(tempNode->left);
                if(tempNode->right != NULL)
                    temp_q.push(tempNode->right);
                next_q.pop();
            }
            
            next_q = temp_q;
            
        }
        
        return ret;
    }
};