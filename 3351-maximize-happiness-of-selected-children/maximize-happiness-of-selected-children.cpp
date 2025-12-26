class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        priority_queue<int> pq; // Max - Heap
        for (int i = 0; i < n; i ++){
            pq.push(happiness[i]);
        }

        long long diff = 0, sum = 0;
        while (k --){
            int val = pq.top() + diff;
            pq.pop();

            if (val >= 0){
                sum += val;
            }
            diff --;
        }

        return sum;
    }
};