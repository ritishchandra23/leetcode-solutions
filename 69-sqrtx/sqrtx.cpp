class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        int mid = -1;

        while(start <= end) {
            mid = start + (end - start) / 2;
            long long square = static_cast<long long>(mid) * mid;

            if(square > x) {
                end = mid - 1;
            } else if(square == x) {
                return mid;
            } else {
                start = mid + 1;
            }
        }
        return static_cast<int>(std::round(end));
    }
};