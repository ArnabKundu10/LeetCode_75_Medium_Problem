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
   int lp = 0;
   void findlongest(TreeNode *root, char c, int cnt)
   {
      if (!root)
         return;
      lp = max(lp, cnt);
      if (c == 'D')
      {
         findlongest(root->left, 'L', cnt + 1);
         findlongest(root->right, 'R', cnt + 1);
      }
      else if (c == 'L')
      {
         findlongest(root->left, 'L', 1);
         findlongest(root->right, 'R', cnt + 1);
      }
      else
      {
         findlongest(root->left, 'L', cnt + 1);
         findlongest(root->right, 'R', 1);
      }
   }
   int longestZigZag(TreeNode *root)
   {
      findlongest(root, 'D', 0);
      return lp;
   }
};