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
   int maxLevelSum(TreeNode *root)
   {
      queue<TreeNode *> q;
      q.push(root);
      int index = 0, ansind = 0, mxsum = INT_MIN;
      while (!q.empty())
      {
         index++;
         int n = q.size();
         int sum = 0;
         for (int i = 0; i < n; i++)
         {
            TreeNode *cur = q.front();
            sum += cur->val;
            if (cur->left)
               q.push(cur->left);
            if (cur->right)
               q.push(cur->right);
            q.pop();
         }
         if (sum > mxsum)
         {
            mxsum = sum;
            ansind = index;
         }
      }
      return ansind;
   }
};