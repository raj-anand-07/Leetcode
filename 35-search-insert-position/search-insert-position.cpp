class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int lb = -1;

        while(low <= high) {
            int mid = (low + (high - low) / 2);

            if(nums[mid] >= target) {
                lb = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        if(lb == -1) {
            return n;
        }

        return lb;
    }
};