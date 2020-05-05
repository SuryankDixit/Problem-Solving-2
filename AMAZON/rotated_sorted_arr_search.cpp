//33. Search in Rotated Sorted Array
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return -1;
        if(nums.size()==1 && nums[0]!=target)
            return -1;
        int mid;
        int start=0;
        int end=nums.size()-1;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]<nums[end])
                end=mid;
            else
                start=mid+1;
        }
        int lowest_index=start;
        start=0;
        end=nums.size()-1;
        if(target>=nums[lowest_index] && target<=nums[end])
            start=lowest_index;
        else
            end=lowest_index;
        
         while(start<=end)
            {
                mid=start+(end-start)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    end=mid-1;
                else
                    start=mid+1;
            }
        return -1;
