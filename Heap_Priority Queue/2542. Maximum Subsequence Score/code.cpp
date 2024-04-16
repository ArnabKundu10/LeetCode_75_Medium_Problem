class Solution
{
public:
   long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
   {
      vector<pair<int, int>> serial;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = 0; i < nums1.size(); i++)
      {
         serial.push_back({nums2[i], nums1[i]});
      }
      sort(serial.rbegin(), serial.rend());
      long long sum = 0, score = 0;
      for (int i = 0; i < k - 1; i++)
      {
         sum += serial[i].second;
         pq.push(serial[i].second);
      }
      for (int i = k - 1; i < serial.size(); i++)
      {
         sum += serial[i].second;
         pq.push(serial[i].second);
         score = max(score, sum * serial[i].first);
         sum -= pq.top();
         pq.pop();
      }
      return score;
   }
};