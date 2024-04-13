class Solution
{
public:
   vector<int> asteroidCollision(vector<int> &as)
   {
      stack<int> st;
      for (int i = 0; i < as.size(); i++)
      {
         if (st.empty())
            st.push(as[i]);
         else if ((st.top() > 0 && as[i] > 0) || (st.top() < 0 && as[i] < 0))
         {
            st.push(as[i]);
         }
         else if (st.top() > 0 && as[i] < 0)
         {
            while (!st.empty() && st.top() > 0 && abs(st.top()) < abs(as[i]))
            {
               st.pop();
            }
            if (st.empty() || st.top() < 0)
               st.push(as[i]);
            else if (abs(st.top()) == abs(as[i]))
               st.pop();
         }
         else
         {
            st.push(as[i]);
         }
      }
      vector<int> ans;
      while (!st.empty())
      {
         ans.push_back(st.top());
         st.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
   }
};