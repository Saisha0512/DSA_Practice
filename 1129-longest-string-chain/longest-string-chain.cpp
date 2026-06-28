class Solution {
    static bool compare(const string &a, const string &b){
        if (a.size() == b.size()){
            return a < b;
        }

        return a.size() < b.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare); // sorting first
        
        int max_len = 1;
        unordered_map<string, int> dp;
        
        for (auto &word : words){
            int curr_len = 1;

            for (int k = 0; k < word.size(); k ++){
                // removing the kth character from the current word
                string temp = word.substr(0, k) + word.substr(k + 1);

                if (dp.count(temp)){
                    curr_len = max(curr_len, dp[temp] + 1);
                }
            }

            dp[word] = curr_len;
            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};