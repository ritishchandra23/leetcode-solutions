class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int mid) {
        int total = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while(i < bloomDay.size() && count < k && bloomDay[i] <= mid) {
                count++;
                i++;
            }
            if(count == k) {
                total++;
                i--;
            }
        }
        return total >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};