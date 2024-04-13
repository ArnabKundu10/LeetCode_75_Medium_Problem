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
class Solution
{
public:
   void rightview(vector<int> &ans, TreeNode *root, int leftind)
   {
      if (root == NULL)
      {
         return;
      }
      if (leftind == ans.size())
      {
         ans.push_back(root->val);
      }
      rightview(ans, root->right, leftind + 1);
      rightview(ans, root->left, leftind + 1);
   }
   vector<int> rightSideView(TreeNode *root)
   {
      vector<int> ans;
      rightview(ans, root, 0);
      return ans;
   }
};