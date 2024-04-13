class Solution
{
public:
   int maxVowels(string s, int k)
   {
      deque<char> vowel;
      set<char> st;
      st.insert('a');
      st.insert('e');
      st.insert('i');
      st.insert('o');
      st.insert('u');
      int cnt = 0, maxcnt = 0;
      for (int i = 0; i < s.size(); i++)
      {
         if (maxcnt == k)
            return k;
         if (vowel.size() == k)
         {
            char first = vowel.front();
            vowel.pop_front();
            if (st.find(first) != st.end())
            {
               cnt--;
            }
         }
         if (st.find(s[i]) != st.end())
            cnt++;
         vowel.push_back(s[i]);
         maxcnt = max(maxcnt, cnt);
      }
      return maxcnt;
   }
};