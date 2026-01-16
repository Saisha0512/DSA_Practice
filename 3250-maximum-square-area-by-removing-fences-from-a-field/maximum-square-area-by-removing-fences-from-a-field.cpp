class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> s;
        long long ans = 0;

        for (int i = 0; i < hFences.size(); i ++){
            for (int j = i + 1; j < hFences.size(); j ++){
                s.insert(abs(hFences[j] - hFences[i]));
            }
        }

        for (int i = 0; i < vFences.size(); i ++){
            for (int j = i + 1; j < vFences.size(); j ++){
                int val = abs(vFences[j] - vFences[i]);
                if (s.find(val) != s.end()){
                    ans = max(ans, (long long)val);
                }
            }
        }

        if (ans == 0){
            return -1;
        }

        long long mod = 1e9 + 7;
        return (ans * ans) % mod;
    }
};