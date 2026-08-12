class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0, end = num;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            long long square = static_cast<long long>(mid) * mid;
            if(num == square) {
                return true;
            } else if(square > num) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};