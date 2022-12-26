class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid;
        while(left <= right){
            mid = left+(right-left)/2;
            if(nums[mid] >= target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};