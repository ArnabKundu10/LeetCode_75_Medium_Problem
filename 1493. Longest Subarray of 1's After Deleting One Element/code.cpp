class Solution
{
public:
   int longestSubarray(vector<int> &nums)
   {
      int cntzero = 0;
      int prev = 0, maxsize = 0;
      for (int i = 0; i < nums.size(); i++)
      {
         if (nums[i] == 0)
            cntzero++;
         if (cntzero > 1)
         {
            while (cntzero > 1 && prev <= i)
            {
               if (nums[prev] == 0)
                  cntzero--;
               prev++;
            }
         }
         maxsize = max(maxsize, i - prev);
      }
      return maxsize;
   }
};