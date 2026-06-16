class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();

        // finding the correct row to search using BS
        int l = 0, h = n - 1;
        int row = -1;
        while (l <= h){
            int mid = (l + h)/2;

            // find the last occurrence of the element that is <= target
            if (mat[mid][0] <= target){
                row = mid;
                l = mid + 1; // search lower
            }
            else {
                h = mid - 1; // search higher
            }
        }
        if (row == -1){ // cant find the valid row
            return false;
        }

        // search the row for the occurrence of target
        l = 0;
        h = m - 1;
        while (l <= h){
            int mid = (l + h)/2;

            if (mat[row][mid] == target){
                return true;
            }
            else if (mat[row][mid] < target){
                l = mid + 1; // searching right half
            }
            else {
                h = mid - 1; // searching left half
            }
        }

        return false;
    }
};