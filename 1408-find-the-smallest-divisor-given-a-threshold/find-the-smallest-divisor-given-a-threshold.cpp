class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int mid) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result += ceil((double)nums[i] / mid);
        }
        return result <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, threshold, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};