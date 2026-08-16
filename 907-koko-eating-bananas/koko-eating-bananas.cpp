class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int Maxspeed = 0;
        int Minspeed = 1;
        for(int i = 0; i < piles.size(); i++) {
            Maxspeed = max(Maxspeed, piles[i]);
        } 

        while(Minspeed < Maxspeed) {
            int mid = Minspeed + (Maxspeed - Minspeed) / 2;
            if(canEatinTime(piles, h, mid)) {
                Maxspeed = mid;
            } else {
                Minspeed = mid + 1; 
            }
        }
        return Minspeed;
    }
    
private: 
    bool canEatinTime(vector<int>& piles, int h, int speed) {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += ceil((double)piles[i] / speed);
        }
        return hours <= h;
    }
};