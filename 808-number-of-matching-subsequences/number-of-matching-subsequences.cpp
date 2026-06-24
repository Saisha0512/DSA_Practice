class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        unordered_map<char, queue<pair<string, int>>> mp;

        // pushign the word in the queue of the first character
        for (auto &word : words){
            mp[word[0]].push({word, 0});
        }

        // iterating over the given string to cater to characters in the given subseq order
        for (char ch : s){
            auto &q = mp[ch];
            int size = q.size();

            // iterating over the currently present elements in the queue
            while (size --){
                auto [word, idx] = q.front();
                q.pop();

                // moving to the next character in the word
                idx ++;

                // if the pointer has reached the end, then this is the subseq of s
                if (idx == word.size()){
                    cnt ++;
                }
                else {
                    // otherwise, we push the current word to the queue of the next character
                    mp[word[idx]].push({word, idx});
                }
            }
        }

        return cnt;
    }
};