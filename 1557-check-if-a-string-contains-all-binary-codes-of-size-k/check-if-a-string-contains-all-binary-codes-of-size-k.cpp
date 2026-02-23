class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        // Base Case : 
        if (n < k){
            return false;
        }

        unordered_set<string> st;
        for (int i = 0; i <= n - k; i ++){
            string temp = s.substr(i, k);
            if (st.find(temp) == st.end()){
                st.insert(temp);
            }
        }

        return (st.size() == (1 << k));
    }
};