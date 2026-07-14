class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size(),i=0,j=n-1;
        while(i<j)
        {
            int mid =i+ (j-i) /2;
            if(nums[mid] > nums[j]) i = mid +1;
            else if(nums[mid]<nums[j]) j=mid;
            else j--;
        }
    return nums[i];
    } 
};
