class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l = 0, r = 0, blank = 0;

        for (char ch : moves){
            if (ch == 'L'){
                l ++;
            }
            else if (ch == 'R'){
                r ++;
            }
            else {
                blank ++;
            }
        }

        if (l > r){
            return abs(l + blank - r);
        }

        return abs(r + blank - l);
    }
};