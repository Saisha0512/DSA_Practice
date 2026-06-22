class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size(), m = result.size();
        // base case
        if (n != m){
            return false;
        }

        int i = 0; // pointer at start
        int j = 0; // pointer at end
        while (i < n || j < m){
            // if any of these are pointing to 'X, then we skip it
            while (i < n && start[i] == 'X')    i ++;
            while (j < m && result[j] == 'X')    j ++;

            if (i == n || j == m){
                return (i == n && j == m);
            }

            // if the currently pointed characters dont match then return false
            if (start[i] != result[j]){
                return false;
            }

            // if i is pointing at L which needs to be moved towards right, then not possible as L can only be moved towards left
            if (start[i] == 'L' && i < j){
                return false;
            }
            
            // similarly R can only be moved towards right
            if (start[i] == 'R' && i > j){
                return false;
            }

            i ++;
            j ++;
        }

        return true;
    }
};