class Solution
{
public:
   bool closeStrings(string word1, string word2)
   {
      if (word1.size() != word2.size())
         return 0;
      unordered_map<char, int> um1, um2;
      for (auto i : word2)
      {
         um2[i]++;
      }
      for (auto i : word1)
      {
         if (um2.find(i) == um2.end())
            return 0;
         um1[i]++;
      }

      if (um1.size() != um2.size())
         return 0;
      priority_queue<int> mxpq1, mxpq2;
      for (auto i : um1)
      {
         mxpq1.push(i.second);
      }
      for (auto i : um2)
      {
         mxpq2.push(i.second);
      }
      if (mxpq1.size() != mxpq2.size())
         return 0;
      while (!mxpq1.empty())
      {
         if (mxpq1.top() != mxpq2.top())
            return 0;
         mxpq1.pop();
         mxpq2.pop();
      }
      return 1;
   }
};