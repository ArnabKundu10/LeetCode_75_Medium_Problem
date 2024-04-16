class Solution
{
public:
   vector<vector<int>> combinationSum3(int k, int n)
   {
      vector<int> current;
      vector<vector<int>> res;
      vector<int> input;
      for (int i = 1; i <= 9; i++)
      {
         input.push_back(i);
      }
      int index = 0;

      combinations(0, k, current, res, n, input);
      return res;
   }
   void combinations(int s, int k, vector<int> current, vector<vector<int>> &res, int n, vector<int> &input)
   {
      if (k == 0)
      {
         int sum = accumulate(current.begin(), current.end(), 0);
         if (sum == n)
         {
            res.push_back(current);
         }
         return;
      }
      for (int i = s; i <= input.size() - k; i++)
      {
         current.push_back(input[i]);
         combinations(i + 1, k - 1, current, res, n, input);
         current.pop_back();
      }
   }
};