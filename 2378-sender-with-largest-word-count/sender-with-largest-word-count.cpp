class Solution {
    int countWords(string s){
        int cnt = 0;
        int n = s.size();

        for (char ch : s){
            if (ch == ' '){
                cnt ++;
            }
        }
        cnt ++; // last word

        return cnt;
    }

public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();

        unordered_map<string, int> freq;
        for (int i = 0; i < n; i ++){
            int curr_cnt = countWords(messages[i]);
            freq[senders[i]] += curr_cnt;
        }

        // iterating over the map
        int max_freq = 0;
        string user;
        for (auto &p : freq){
            if (p.second > max_freq){
                max_freq = p.second;
                user = p.first;
            }
            else if (p.second == max_freq && p.first > user){
                user = p.first;
            }
        }

        return user;
    }
};