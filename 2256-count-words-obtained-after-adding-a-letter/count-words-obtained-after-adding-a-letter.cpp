class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        // inserting all the starting words in sorted order
        unordered_set<string> start;
        for (auto &w : startWords){
            sort(w.begin(), w.end());
            start.insert(w);
        }

        int cnt = 0;
        // checking for all the target words
        for (string &target : targetWords){
            sort(target.begin(), target.end());
            int n = target.size();
            // removing one character from the target string at a time
            for (int i = 0; i < n; i ++){
                string search = target.substr(0, i) + target.substr(i + 1);

                if (start.count(search)){
                    cnt ++;
                    break;
                }
            }
        }

        return cnt;
    }
};