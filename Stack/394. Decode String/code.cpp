class Solution
{
public:
   string decodeString(string s)
   {
      stack<char> st;
      for (int i = 0; i < s.size(); i++)
      {
         if (s[i] != ']')
         {
            st.push(s[i]);
         }
         else
         {
            string inside = "";
            while (st.top() != '[')
            {
               inside = st.top() + inside;
               st.pop();
            }
            st.pop();
            string cnt = "";
            while (!st.empty() && isdigit(st.top()))
            {
               cnt = st.top() + cnt;
               st.pop();
            }
            int num = stoi(cnt);
            while (num > 0)
            {
               for (int j = 0; j < inside.size(); j++)
               {
                  st.push(inside[j]);
               }
               num--;
            }
         }
      }
      string ans = "";
      while (!st.empty())
      {
         ans = st.top() + ans;
         st.pop();
      }
      return ans;
   }
};