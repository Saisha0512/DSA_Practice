class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()){
            return 0;
        }

        int steps = 1;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int size = q.size();
            while (size --){
                string curr = q.front();
                q.pop();

                if (curr == endWord){
                    return steps;
                }

                for (int i = 0; i < curr.size(); i ++){
                    char org = curr[i];
                    for (char ch = 'a'; ch <= 'z'; ch ++){
                        if (ch == org)  continue;
                        curr[i] = ch;

                        if (s.find(curr) != s.end()){
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr[i] = org;
                }
            }
            steps ++;          
        }

        return 0;
    }
};