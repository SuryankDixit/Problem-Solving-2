
/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid>0 && mid<nums.size()-1)
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                    return mid;
                else if(nums[mid]>nums[mid-1])
                    start=mid+1;
                else
                    end=mid-1;
            }
            else if(mid==0)
            {
                if(nums[mid]>nums[mid+1])
                    return 0;
                else 
                    return 1;
            }
            else if(mid==nums.size()-1)
            {
                if(nums[mid]>nums[mid-1])
                    return mid;
                else
                    return mid-1;
            }
        }
        return 0;
    }
};