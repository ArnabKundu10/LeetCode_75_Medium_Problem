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
   TreeNode *deleteNode(TreeNode *root, int key)
   {
      if (!root)
         return NULL;
      if (root->val > key)
         root->left = deleteNode(root->left, key);
      else if (root->val < key)
         root->right = deleteNode(root->right, key);
      else
      {
         if (!root->left && !root->right)
            return NULL;
         else if (!root->left || !root->right)
            return root->left ? root->left : root->right;
         else
         {
            TreeNode *last = root->right;
            int temp = 0;
            while (last->left)
               last = last->left;
            root->val = last->val;
            root->right = deleteNode(root->right, root->val);
         }
      }
      return root;
   }
};