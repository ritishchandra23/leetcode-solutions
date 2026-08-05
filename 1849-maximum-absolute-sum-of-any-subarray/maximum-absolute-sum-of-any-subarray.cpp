class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }
        currSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currSum = min(currSum + nums[i], nums[i]);
            minSum = min(minSum, currSum); 
        }
        return max(abs(maxSum), abs(minSum));
    }
};