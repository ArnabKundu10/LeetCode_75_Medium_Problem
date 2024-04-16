class Solution
{
public:
   int maxOperations(vector<int> &nums, int k)
   {
      sort(nums.begin(), nums.end());
      int i = 0, j = nums.size() - 1;
      int cnt = 0;
      while (i < j)
      {
         if (nums[i] + nums[j] == k)
         {
            cnt++;
            nums.erase(nums.begin() + i);
            nums.erase(nums.begin() + j - 1);
            j = j - 2;
         }
         else if (nums[i] + nums[j] > k)
         {
            j--;
         }
         else
         {
            i++;
         }
      }
      return cnt;
   }
};