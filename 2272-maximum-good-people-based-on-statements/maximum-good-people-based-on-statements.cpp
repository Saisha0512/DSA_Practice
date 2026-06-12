class Solution {
public:
    int maximumGood(vector<vector<int>>& stat) {
        int n = stat.size();

        // for every person 2 choices - good or bad
        // bit = 1 -> person is good
        // bit = 0 -> person is bad

        int res = 0; // max no of good people

        // trying out all the possible combinations of 0 & 1 for n people
        // and assume them true to verify if they work for all the further combinations
        for (int mask = 0; mask < (1 << n); mask ++){
            // assuming that this is a valid combination
            // ie. set bits -> good people
            bool flag = true;

            // iterating over all the people in this mask
            for (int i = 0; i < n; i ++){
                // if the ith person is bad
                if ((mask & (1 << i)) == 0){
                    continue;
                    // we will only focus on the statements of good people
                    // as bad people sometimes lie or sometimes speak truth
                    // so not verfiying the statements of this person
                }

                // if the ith person is good
                // then we need to verify all of his/her statements
                for (int j = 0; j < n; j ++){
                    // checking if the statement of i about the jth person says that j is good
                    int good = (mask & (1 << j))? 1 : 0;

                    // case 1 : if we have assumed that the jth person is not good, but the jth person is good or vice versa
                    if ((!good && stat[i][j] == 1) || (good && stat[i][j] == 0)){
                        flag = false;
                        // our mask assumption is wrong 
                    }
                }

                if (flag == false){
                    break;
                }
            }

            // updating the number of max good people only if the assumption mask was correct
            if (flag){
                res = max(res, __builtin_popcount(mask));
            }
        }

        return res;
    }
};