class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();

        string res;
        for (int i = 0; i < n; i ++){
            int total = 0; 
            // iterating over each letter of the current word
            for (char ch : words[i]){
                total += weights[ch - 'a'];
            }

            // taking modulo
            total %= 26;

            res.push_back((25 - total) + 'a');
        }

        return res;
    }
};