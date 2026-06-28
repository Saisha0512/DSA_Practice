class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        map<int, pair<string, string>> m; // {index, {source, target}}
        // adding the valid indices, source & target strings to the map
        for (int i = 0; i < k; i ++){
            int idx = indices[i];
            if (idx + sources[i].size() <= s.size() && s.substr(idx, sources[i].size()) == sources[i]){
                m[idx] = {sources[i], targets[i]};
            }
        }

        // iterating over the map elements in the reverse order
        for (auto it = m.rbegin(); it != m.rend(); it ++){
            int idx = it -> first;
            string source = it -> second.first;
            string target = it -> second.second;
            s.replace(idx, source.size(), target);
        }

        return s;
    }
};