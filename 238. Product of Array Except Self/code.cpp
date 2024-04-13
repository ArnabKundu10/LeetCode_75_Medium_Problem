class Solution
{
public:
   vector<int> productExceptSelf(vector<int> &nums)
   {
      long long sum = 1;
      vector<int> left(nums.size(), 1), right(nums.size(), 1), ans(nums.size(), 1);
      for (int i = 1; i < nums.size(); i++)
      {
         sum *= nums[i - 1];
         left[i] = sum;
      }
      sum = 1;
      for (int i = nums.size() - 2; i >= 0; i--)
      {
         sum *= nums[i + 1];
         right[i] = sum;
      }
      for (int i = 0; i < nums.size(); i++)
      {
         ans[i] = left[i] * right[i];
      }
      return ans;
   }
};