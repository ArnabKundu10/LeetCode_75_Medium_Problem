class Solution
{
public:
   int cnt = 0;
   void dfs(int num, unordered_map<int, vector<int>> &mp, vector<bool> &visit)
   {
      visit[num] = 1;
      for (auto i : mp[num])
      {
         if (i > 0 && !visit[abs(i)])
         {
            cnt++;
            dfs(abs(i), mp, visit);
         }
         else if (i < 0 && !visit[abs(i)])
         {
            dfs(abs(i), mp, visit);
         }
      }
   }
   int minReorder(int n, vector<vector<int>> &connections)
   {
      unordered_map<int, vector<int>> mp;
      vector<bool> visit(n, false);
      for (int i = 0; i < connections.size(); i++)
      {
         mp[connections[i][0]].push_back(connections[i][1]);
         mp[connections[i][1]].push_back(connections[i][0] * -1);
      }
      dfs(0, mp, visit);
      return cnt;
   }
};