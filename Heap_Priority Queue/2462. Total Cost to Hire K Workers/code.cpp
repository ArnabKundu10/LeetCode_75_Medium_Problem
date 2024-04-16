class Solution
{
public:
   long long totalCost(vector<int> &costs, int k, int candidates)
   {
      priority_queue<int, vector<int>, greater<int>> lpq, rpq;
      int lp = 0, rp = 0;
      for (int i = 0; i < costs.size(); i++)
      {
         int right = costs.size() - i - 1;
         if (i == right && i < candidates)
         {
            lp = i;
            lpq.push(costs[i]);
            break;
         }
         else if (i < right && i < candidates)
         {
            lp = i;
            rp = right;
            lpq.push(costs[lp]);
            rpq.push(costs[rp]);
         }
         else
            break;
      }
      long long session = 0, ans = 0;
      while (session < k)
      {
         int ltop = !lpq.empty() ? lpq.top() : INT_MAX;
         int rtop = !rpq.empty() ? rpq.top() : INT_MAX;
         if (rp - lp > 1)
         {
            if (ltop <= rtop)
            {
               ans += ltop;
               lpq.pop();
               lp++;
               lpq.push(costs[lp]);
            }
            else
            {
               ans += rtop;
               rpq.pop();
               rp--;
               rpq.push(costs[rp]);
            }
         }
         else
         {
            if (ltop <= rtop)
            {
               ans += ltop;
               lpq.pop();
            }
            else
            {
               ans += rtop;
               rpq.pop();
            }
         }
         session++;
      }
      return ans;
   }
};