class Solution
{
public:
   void provinces(int index, vector<bool> &visit, vector<vector<int>> &isConnected)
   {
      visit[index] = true;
      for (int i = 0; i < isConnected[index].size(); i++)
      {
         if (isConnected[index][i] && !visit[i])
            provinces(i, visit, isConnected);
      }
   }
   int findCircleNum(vector<vector<int>> &isConnected)
   {
      vector<bool> visit(isConnected.size(), false);
      int cnt = 0;
      for (int i = 0; i < visit.size(); i++)
      {
         if (!visit[i])
         {
            cnt++;
            provinces(i, visit, isConnected);
         }
      }
      return cnt;
   }
};