class SmallestInfiniteSet
{
public:
   // priority_queue<int,vector<int>,greater<int>>pq;
   set<int> s;
   SmallestInfiniteSet()
   {
      int cnt = 1;
      while (cnt <= 1000)
      {
         // pq.push(cnt);
         s.insert(cnt);
         cnt++;
      }
   }

   int popSmallest()
   {
      int ans = *(s.begin());
      s.erase(ans);
      // pq.pop();
      return ans;
   }

   void addBack(int num)
   {
      if (s.find(num) == s.end())
      {
         s.insert(num);
         // pq.push(num);
      }
   }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */