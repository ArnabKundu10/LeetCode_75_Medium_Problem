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
   int cnt = 0;
   void countpair(TreeNode *root, int targetSum, long long sum)
   {
      if (!root)
         return;
      sum += root->val;
      if (sum == targetSum)
         cnt++;
      countpair(root->left, targetSum, sum);
      countpair(root->right, targetSum, sum);
   }
   void dfs(TreeNode *root, int targetSum)
   {
      if (!root)
         return;
      long long sum = 0;
      countpair(root, targetSum, sum);
      dfs(root->left, targetSum);
      dfs(root->right, targetSum);
   }
   int pathSum(TreeNode *root, int targetSum)
   {
      dfs(root, targetSum);
      return cnt;
   }
};