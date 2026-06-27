class Solution {
    unordered_map<long long, int> dp;

    int calcPower(long long num){
        // base case
        if (num == 1){
            return 0;
        }

        // check dp
        if (dp.count(num)){
            return dp[num];
        }

        // recursive case
        // case 1 : even number
        if (num % 2 == 0){
            return dp[num] = 1 + calcPower(num / 2);
        }

        // case 2 : odd number
        return dp[num] = 1 + calcPower(3LL*num + 1);
    }

public:
    int getKth(int lo, int hi, int k) {
        // dp initialization
        dp[1] = 0;

        priority_queue<pair<int, int>> pq; // max heap of size k
        for (int num = lo; num <= hi; num ++){
            if (!dp.count(num)){
                calcPower(num);
            }

            // pushing the element in the priority queue while maintaining the size
            pq.push({dp[num], num});
            if (pq.size() > k){
                pq.pop();
            }
        }

        return pq.top().second;
    }
};