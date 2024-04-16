class Solution
{
public:
   int minEatingSpeed(vector<int> &piles, int h)
   {
      int s = 1;
      long long e = *max_element(piles.begin(), piles.end());
      int ans = s;
      while (s <= e)
      {
         int mid = (s + e) / 2;
         int hr = h;
         for (int i = 0; i < piles.size(); i++)
         {
            if (hr < 0)
               break;
            if (piles[i] % mid == 0)
               hr = hr - (piles[i] / mid);
            else
               hr = hr - ((piles[i] / mid) + 1);
         }
         if (hr >= 0)
         {
            ans = mid;
            e = mid - 1;
         }
         else
         {
            s = mid + 1;
         }
      }
      return ans;
   }
};