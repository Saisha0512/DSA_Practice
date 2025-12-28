class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res = "";
        stack<int> s;

        for (int i = 0; i <= n; i ++){
            s.push(i + 1);

            if (i == n || pattern[i] == 'I'){
                while (!s.empty()){
                    int curr = s.top();
                    s.pop();
                    res += to_string(curr);
                }
            }
        }

        return res;
    }
};