class Solution {
public:
    int binaryGap(int n) {
        vector<int> pos;

        int len = 0;
        while (n){
            if (n & 1){
                pos.push_back(len);
            }

            n >>= 1;
            len ++;
        }

        int longest = 0;
        for (int j = 0; j < pos.size() - 1; j ++){
            longest = max(longest, (len - pos[j] - 1) - (len - 1 - pos[j + 1]));
        }

        return longest;
    }
};