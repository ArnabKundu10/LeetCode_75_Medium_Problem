class Solution
{
public:
   int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
   {
      vector<vector<int>> fourdir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      // vector<vector<bool>>visit(maze.size(),vector<bool>(maze[0].size(),false));
      queue<vector<int>> q;
      q.push(entrance);
      q.push({-1, -1});
      int cnt = 0;
      while (!q.empty())
      {
         vector<int> temp = q.front();
         if (temp[0] == -1 && q.size() > 1)
         {
            cnt++;
            q.pop();
            q.push({-1, -1});
            temp = q.front();
         }
         else if (temp[0] == -1 && q.size() == 1)
            break;
         q.pop();
         if ((temp != entrance) &&
             (temp[0] == 0 || temp[0] == maze.size() - 1 || temp[1] == 0 || temp[1] == maze[0].size() - 1))
         {
            return cnt;
         }
         // visit[temp[0]][temp[1]]=true;
         for (int i = 0; i < fourdir.size(); i++)
         {
            int row = temp[0] + fourdir[i][0];
            int col = temp[1] + fourdir[i][1];
            if (row >= 0 && row <= maze.size() - 1 && col >= 0 && col < maze[0].size())
            {
               if (maze[row][col] != '+')
               {
                  maze[row][col] = '+';
                  //  if(row==0 || row==maze.size()-1 || col==0 || col==maze[0].size()-1)  return cnt;
                  q.push({row, col});
               }
            }
         }
      }
      return -1;
   }
};