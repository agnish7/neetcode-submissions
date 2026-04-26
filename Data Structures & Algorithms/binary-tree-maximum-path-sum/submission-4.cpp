/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int maxPathSum(TreeNode* root) {
        vector<int> res = maxPath(root);
        cout << res[0] << " " << res[1] << endl;
        return max(res[0], res[1]);
    }
    vector<int> maxPath(TreeNode* root) {
        if(!root) {
            return vector<int>({0, INT_MIN});
        }
        vector<int> left = maxPath(root->left);
        vector<int> right = maxPath(root->right);
        vector<int> res(2);
        vector<int> temp = {root->val, root->val + left[0], root->val + right[0]};

        res[0] = *max_element(temp.begin(), temp.end());
        cout << res[0] << endl;
        res[1] = max(
            max(root->val, root->val + left[0] + right[0]),
            max(left[1], right[1])
        );
        cout << res[1] << endl;
        return res;
    }
};
