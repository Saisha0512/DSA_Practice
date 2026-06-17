class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        int n = words.size();

        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        q.push(begin);

        int len = 1; // no of words currently present in the chain
        while (!q.empty()){
            int size = q.size();
            while (size --){
                string curr_word = q.front();
                q.pop();

                // if the end word is reached
                if (curr_word == end){
                    return len;
                }

                // otheriwse we try replacing each character of the word with an alphabet
                for (int i = 0; i < curr_word.size(); i ++){
                    char org = curr_word[i];
                    for (char ch = 'a'; ch <= 'z'; ch ++){
                        curr_word[i] = ch; // replacing
                        
                        // if this word exists in the words list
                        if (s.find(curr_word) != s.end()){
                            q.push(curr_word);
                            s.erase(curr_word);
                        }
                    }

                    curr_word[i] = org;
                }
            }

            len ++;
        }

        return 0;
    }
};