class Solution
{
public:
   int orangesRotting(vector<vector<int>> &grid)
   {
      int m = grid.size();
      int n = grid[0].size();
      queue<pair<int, int>> q;
      bool flag = 0;
      for (int i = 0; i < m; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (grid[i][j] == 2)
            {
               q.push({i, j});
            }
            if (grid[i][j] == 1)
            {
               flag = 1;
            }
         }
      }
      if (flag == 0)
      {
         return 0;
      }
      q.push({-1, -1});
      int ansCount = -1;

      while (!q.empty())
      {
         int x = q.front().first;
         int y = q.front().second;

         if (x == -1 && q.size() != 1)
         {

            ansCount++;
            q.pop();
            q.push({-1, -1});
            continue;
         }
         else if (x == -1 && q.size() == 1)
         {
            ansCount++;
            q.pop();
            continue;
         }
         while (x != -1)
         {
            //  cout<<x<<" "<<y<<endl;
            if ((x + 1) < m && grid[x + 1][y] == 1)
            {
               grid[x + 1][y] = 2;
               //   cout<<x+1<<" "<<y<<endl;
               q.push({x + 1, y});
            }
            if ((x - 1) >= 0 && grid[x - 1][y] == 1)
            {
               grid[x - 1][y] = 2;
               //    cout<<x-1<<" "<<y<<endl;
               q.push({x - 1, y});
            }
            if ((y + 1) < n && grid[x][y + 1] == 1)
            {
               grid[x][y + 1] = 2;
               //    cout<<x<<" "<<y+1<<endl;
               q.push({x, y + 1});
            }
            if ((y - 1) >= 0 && grid[x][y - 1] == 1)
            {
               grid[x][y - 1] = 2;
               //  cout<<x<<" "<<y-1<<endl;
               q.push({x, y - 1});
            }
            q.pop();
            x = q.front().first;
            y = q.front().second;
         }
      }

      for (int i = 0; i < m; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (grid[i][j] == 1)
            {
               return -1;
            }
         }
      }
      return ansCount;
   }
};
