class Solution
{
public:
   bool increasingTriplet(vector<int> &nums)
   {
      vector<int> lb;
      lb.push_back(nums[0]);
      for (int i = 1; i < nums.size(); i++)
      {
         if (nums[i] > lb.back())
         {
            lb.push_back(nums[i]);
         }
         else
         {
            auto x = lower_bound(lb.begin(), lb.end(), nums[i]);
            int ind = x - lb.begin();
            lb[ind] = nums[i];
         }
         if (lb.size() >= 3)
            return true;
      }
      return false;
   }
};