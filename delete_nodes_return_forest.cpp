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
    void deleteNodes(TreeNode *root, vector<int> &v, vector<TreeNode*> &r, TreeNode *parent)
    {
        if (root == nullptr) {
            return;
        }
        
        if (find(v.begin(), v.end(), root->val) != v.end()) {
                if (parent != nullptr) {
                    // delete the node
                    if (root == parent->left) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                }
                deleteNodes(root->left, v, r, nullptr);
                deleteNodes(root->right, v, r, nullptr);
        } else {
            if (parent == nullptr) {
                r.push_back(root);
            }
            deleteNodes(root->left, v, r, root);
            deleteNodes(root->right, v, r, root);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;

        deleteNodes(root, to_delete, result, nullptr);

        return result;
    }
};
