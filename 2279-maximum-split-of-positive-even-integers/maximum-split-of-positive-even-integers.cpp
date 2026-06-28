class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> res;
        // base case
        if (sum % 2 != 0){
            return res;
        }

        long long curr_num = 2;
        while (sum >= curr_num){
            res.push_back(curr_num);
            sum -= curr_num;
            curr_num += 2;
        }

        if (sum > 0){
            res.back() += sum;
        }

        return res;
    }
};