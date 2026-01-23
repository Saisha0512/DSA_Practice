class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int, pair<int, int>> freq; // {Element, {Freq in a, Freq in b}}
        // Counting the frequency of each element in both the arrays : 
        for (int num : a){
            freq[num].first ++;
        }
        for (int num : b){
            freq[num].second ++;
        }

        vector<int> res;
        for (auto &p : freq){
            int el = p.first;
            int fa = p.second.first, fb = p.second.second;
            for (int i = 0; i < min(fa, fb); i ++){
                res.push_back(el);
            }
        }

        return res;
    }
};