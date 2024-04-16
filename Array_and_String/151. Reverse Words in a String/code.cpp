class Solution
{
public:
   string reverseWords(string s)
   {
      stringstream str(s);
      string ans;
      vector<string> v;
      while (str >> ans)
      {
         v.push_back(ans);
         v.push_back(" ");
      }
      v.pop_back();
      reverse(v.begin(), v.end());
      ans = "";
      for (auto i : v)
      {
         ans += i;
      }
      return ans;
   }
};