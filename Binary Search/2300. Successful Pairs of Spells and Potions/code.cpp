class Solution
{
public:
   int findindex(vector<int> &potions, int s, int e, long long amount, long long success)
   {
      int store = e + 1;
      while (s <= e)
      {
         int mid = (s + e) / 2;
         long long res = amount * potions[mid];
         if (res >= success)
         {
            store = mid;
            e = mid - 1;
         }
         else if (res < success)
         {
            s = mid + 1;
         }
      }
      return store;
   }
   vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
   {
      sort(potions.begin(), potions.end());
      vector<int> ans;
      for (int i = 0; i < spells.size(); i++)
      {
         int index = findindex(potions, 0, potions.size() - 1, spells[i], success);
         ans.push_back(potions.size() - index);
      }
      return ans;
   }
};