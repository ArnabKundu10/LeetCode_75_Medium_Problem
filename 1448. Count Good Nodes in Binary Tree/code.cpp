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
   int chooseNodes(TreeNode *parent, TreeNode *root, int maxval)
   {
      if (!root)
         return 0;
      if (maxval <= root->val)
         return 1 + chooseNodes(root, root->left, root->val) + chooseNodes(root, root->right, root->val);
      else
         return 0 + chooseNodes(root, root->left, maxval) + chooseNodes(root, root->right, maxval);
   }
   int goodNodes(TreeNode *root)
   {
      if (!root)
         return 0;
      return chooseNodes(root, root->left, root->val) + chooseNodes(root, root->right, root->val) + 1;
   }
};