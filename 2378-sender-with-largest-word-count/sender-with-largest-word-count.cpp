class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();

        int max_freq = 0;
        string user;
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i ++){
            int curr_cnt = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            freq[senders[i]] += curr_cnt;

            if ((freq[senders[i]] > max_freq) || (max_freq == freq[senders[i]] && senders[i] > user)){
                max_freq = freq[senders[i]];
                user = senders[i];
            }
        }

        return user;
    }
};