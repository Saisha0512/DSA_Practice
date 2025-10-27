class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        int cnt = 0;
        queue<string> q;
        q.push(begin);
        
        while (!q.empty()){
            cnt ++;
            int size = q.size();
            while (size --){
                string word = q.front();
                q.pop();
                if (word == end){
                    return cnt;
                }

                string org = word;
                for (int i = 0; i < word.size(); i ++){
                    word = org;
                    for (char ch = 'a'; ch <= 'z'; ch ++){
                        word[i] = ch;

                        if (s.find(word) != s.end()){
                            s.erase(word);
                            q.push(word);
                        }
                    }
                }
            }
        }

        return 0;
    }
};