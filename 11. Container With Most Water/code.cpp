class Solution
{
public:
   int maxArea(vector<int> &height)
   {

      int water = 0;
      int i = 0, j = height.size() - 1;
      while (i < j)
      {
         int h = min(height[i], height[j]);
         water = max(water, (j - i) * h);
         while (height[i] <= h && i < j)
            i++;
         while (height[j] <= h && i < j)
            j--;
      }
      return water;
   }
};
// vector<int>v;

/*   for(int i=0;i<height.size()-1;i++) {
       for(int j=i+1;j<height.size();j++) {
           int sum=0;
           if(height[i]>=height[j]){
           sum=height[j]*(j-i);
           }
         else if(height[i]<height[j]){
           sum=height[i]*(j-i);
           }
          v.push_back(sum);
       }
  }
  int ans=*max_element(v.begin(),v.end());
  return ans; */