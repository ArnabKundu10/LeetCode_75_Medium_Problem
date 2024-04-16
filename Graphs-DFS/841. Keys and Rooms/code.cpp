class Solution
{
public:
   void markvisited(int index, vector<bool> &visit, vector<vector<int>> &rooms)
   {
      visit[index] = true;
      for (auto i : rooms[index])
      {
         if (!visit[i])
         {
            markvisited(i, visit, rooms);
         }
      }
   }
   bool canVisitAllRooms(vector<vector<int>> &rooms)
   {
      vector<bool> visit(rooms.size(), false);
      markvisited(0, visit, rooms);
      for (auto i : visit)
      {
         if (!i)
            return false;
      }
      return true;
   }
};