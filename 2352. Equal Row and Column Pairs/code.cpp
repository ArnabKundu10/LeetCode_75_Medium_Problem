class Solution
{
public:
   int equalPairs(vector<vector<int>> &grid)
   {
      int cnt = 0;

      vector<vector<int>> u;

      for (int j = 0; j < grid.size(); j++)
      {
         vector<int> demo;
         for (int k = 0; k < grid.size(); k++)
         {
            demo.push_back(grid[k][j]);
         }
         u.push_back(demo);
      }

      for (int i = 0; i < grid.size(); i++)
      {
         for (int m = 0; m < grid.size(); m++)
         {
            if (grid[i] == u[m])
            {
               cnt++;
            }
         }
      }

      return cnt;
   }
};