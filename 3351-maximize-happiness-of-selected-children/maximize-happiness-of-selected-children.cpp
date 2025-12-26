class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long x = 0;
        long long sum = 0;
        for (int i = 0; i < k; i ++){
            long long curr = happiness[n - 1 - i] + x;
            if (curr >= 0){
                sum += curr;
            }
            x --;
        }

        return sum;
    }
};