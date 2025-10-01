class Solution {
public:
    int numWaterBottles(int num, int exch) {
        int full = num, empty = 0, cnt = 0;
        while (full > 0){
            cnt += full;
            empty += full;
            full = empty / exch;
            empty = empty % exch;
        }
        return cnt;
    }
};