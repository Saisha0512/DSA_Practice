class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        // m1 : For mapping the characters of s with the characters of t (s -> t)
        // m2 : For mapping the characters of t with the characters of s (t -> s)

        for (int i = 0; i < s.size(); i ++){
            char a = s[i], b = t[i];

            // Checking for a : 
            if (m1.find(a) != m1.end() && m1[a] != b){
                return false;
            }
            // Checking for b : 
            if (m2.find(b) != m2.end() && m2[b] != a){
                return false;
            }

            m1[a] = b;
            m2[b] = a;
        }

        return true; // Returning true if both the strings are parsed without any hinderance.
    }
};