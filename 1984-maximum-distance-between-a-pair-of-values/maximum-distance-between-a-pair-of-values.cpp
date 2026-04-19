class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int dist = INT_MIN;
        int i = 0, j = 0; // two pointers
        while (i < n && j < m){
            // if the pair is valid, we try to maximize the value of j
            if (i <= j && nums1[i] <= nums2[j]){
                dist = max(dist, j - i);
                j ++; // moving j forward
            }
            // else we initialize i, j to the next set possible
            else {
                i ++; // only moving i forwards cuz of the non - increasing sequence
                // only modify j, if it is less than i
                if (j < i){
                    j = i;
                }
            }
        }

        return max(dist, 0);
    }
};