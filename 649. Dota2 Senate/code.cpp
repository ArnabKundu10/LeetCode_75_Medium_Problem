class Solution
{
public:
   string predictPartyVictory(string senate)
   {
      queue<int> rq, dq;
      for (int i = 0; i < senate.size(); i++)
      {
         if (senate[i] == 'R')
         {
            rq.push(i);
         }
         if (senate[i] == 'D')
         {
            dq.push(i);
         }
      }
      while (!rq.empty() && !dq.empty())
      {
         int p = rq.front();
         int q = dq.front();
         rq.pop();
         dq.pop();
         if (p > q)
         {
            dq.push(q + senate.size());
         }
         else
         {
            rq.push(p + senate.size());
         }
      }
      if (rq.size() > dq.size())
         return "Radiant";
      return "Dire";
   }
};