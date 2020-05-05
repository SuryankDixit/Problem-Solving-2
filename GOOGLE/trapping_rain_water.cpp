/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int Max=INT_MIN;
        vector<int> left_ht(height.size());
        vector<int> right_ht(height.size());
        for(int i=0;i<height.size();i++)
        {
            Max=max(height[i],Max);
            left_ht[i]=Max;
        }
        Max=INT_MIN;
        for(int i=height.size()-1;i>=0;i--)
        {
            Max=max(height[i],Max);
            right_ht[i]=Max;
        }
        int sum=0;
        for(int i=0;i<height.size();i++)
        {
            height[i]=min(left_ht[i],right_ht[i])-height[i];
            sum+=height[i];
        }
        return sum;
    }
};
