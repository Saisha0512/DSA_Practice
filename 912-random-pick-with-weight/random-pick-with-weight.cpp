class Solution {
    int n;
    vector<int> presum;
public:
    Solution(vector<int>& w) {
        this -> n = w.size();
        presum.resize(n, 0);

        // calculating prefix sum over w
        for (int i = 0; i < n; i ++){
            presum[i] = w[i] + ((i > 0)? presum[i - 1] : 0);
        }
    }
    
    int pickIndex() {
        int num = rand() % presum.back() + 1; 
        // gives random number in the range [0, presum[n - 1]]
        auto it = lower_bound(presum.begin(), presum.end(), num);
        return it - presum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */