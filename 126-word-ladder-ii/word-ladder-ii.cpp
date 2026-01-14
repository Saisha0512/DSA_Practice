class Solution {
    unordered_map<string, int> m;
    vector<vector<string>> res;

private : 
    void dfs(string word, vector<string> &curr, string beginWord){
        // Base Case : 
        if (word == beginWord){
            reverse(curr.begin(), curr.end());
            res.push_back(curr);
            reverse(curr.begin(), curr.end());
            return;
        }

        // Recursive Case : 
        int currlev = m[word];
        for (int i = 0; i < word.size(); i ++){
            char org = word[i];

            for (char ch = 'a'; ch <= 'z'; ch ++){
                word[i] = ch;

                if (m.find(word) != m.end() && m[word] + 1 == currlev){
                    curr.push_back(word);
                    dfs(word, curr, beginWord);
                    curr.pop_back();
                }
            }
            word[i] = org;
        }
    }

public :
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()){
            return res;
        }

        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;
        s.erase(beginWord);

        while (!q.empty()){
            string word = q.front();
            q.pop();

            if (word == endWord)    break;

            int currlev = m[word];
            for (int i = 0; i < word.size(); i ++){
                char org = word[i];

                for (char ch = 'a'; ch <= 'z'; ch ++){
                    word[i] = ch;

                    if (s.find(word) != s.end()){
                        q.push(word);
                        m[word] = currlev + 1;
                        s.erase(word);
                    }
                }
                word[i] = org;
            }
        }

        if (m.find(endWord) != m.end()){
            vector<string> curr;
            curr.push_back(endWord);
            dfs(endWord, curr, beginWord);
        }

        return res;
    }
};