class Solution {
    bool isSubseq(string subseq, string word){
        int n = subseq.size(), m = word.size();
        int i = 0;
        for (int j = 0; j < m; j ++){
            if (word[j] == subseq[i]){
                i ++;
            }
        }

        return (i == n);
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;

        unordered_map<string, bool> mp;
        for (auto &word : words){
            // if the current word is present in the map
            if (mp.find(word) != mp.end()){
                if (mp[word]){
                    cnt += 1;
                }

                continue;
            }

            // otherwise, we check if this word is subseq of s
            mp[word] = isSubseq(word, s);
            cnt += mp[word];
        }

        return cnt;
    }
};