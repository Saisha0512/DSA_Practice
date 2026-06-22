class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (auto &s : strs){ // O(n)
            vector<int> freq(26, 0);
            for (char ch : s){ // O(m)
                freq[ch - 'a'] ++;
            }

            // creating the key on the basis of the freq of 26 chars
            string key = "";
            for (int f : freq){ // O(26)
                key += to_string(f) + '#';
            }

            m[key].push_back(s);
        }

        // resultant vector
        vector<vector<string>> res;
        for (auto &p : m){
            res.push_back(p.second);
        }

        return res;
    }
};

// TC : O(n*m)