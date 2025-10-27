class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({begin, 1});
        while (!q.empty()){
            auto curr = q.front();
            q.pop();

            string word = curr.first;
            if (word == end){
                return curr.second;
            }

            string org = word;
            for (int i = 0; i < word.size(); i ++){
                for (char ch = 'a'; ch <= 'z'; ch ++){
                    word[i] = ch;
                    if (s.find(word) != s.end()){
                        q.push({word, curr.second + 1});
                        s.erase(word);
                    }
                }
                word = org;
            }
        }

        return 0;
    }
};