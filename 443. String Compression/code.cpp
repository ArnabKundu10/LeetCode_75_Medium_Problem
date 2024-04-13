class Solution
{
public:
   int compress(vector<char> &chars)
   {
      int cnt = 0;
      char cur = chars[0];
      vector<char> ans;
      int prev = 0, last = 0;
      for (int i = 0; i < chars.size(); i++)
      {
         if (chars[i] == cur)
         {
            last = i;
            cnt++;
         }
         else
         {
            ans.push_back(cur);
            if (cnt > 1)
            {
               string s = to_string(cnt);
               for (auto c : s)
                  ans.push_back(c);
            }
            cur = chars[i];
            cnt = 1;
         }
      }
      ans.push_back(cur);
      if (cnt > 1)
      {
         string s = to_string(cnt);
         for (auto c : s)
            ans.push_back(c);
      }
      chars = ans;
      ans.clear();
      return chars.size();
   }
};