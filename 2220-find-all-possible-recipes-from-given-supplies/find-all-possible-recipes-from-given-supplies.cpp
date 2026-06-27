class Solution {
    vector<string> res;
    unordered_set<string> supp;

    bool dfs_traversal(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_map<string, int> &idx, vector<int> &state, int curr){
        // cycle detection base case
        if (state[curr] == 1){
            return false;
        }
        if (state[curr] == 2){
            return (supp.count(recipes[curr]));
        }

        // visiting the current recipe
        state[curr] = 1;

        // visiting its ingredients to check if they are available or not
        for (auto &i : ingredients[curr]){
            // ingredient found
            if (supp.find(i) != supp.end()){
                continue;
            }
            // if its a recipe
            else if (idx.find(i) != idx.end()){
                // unvisited recipe
                bool subprob = dfs_traversal(recipes, ingredients, idx, state, idx[i]);

                if (!subprob){
                    state[curr] = 2; // visited, but cannot be made
                    return false;
                }
            }
            else {
                state[curr] = 2;
                return false; // an ingredient is unavailable
            }
        }

        // all the ingredients are available
        state[curr] = 2;
        res.push_back(recipes[curr]);
        supp.insert(recipes[curr]);
        return true;
    }

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        // storing the available supplies
        this -> supp = unordered_set<string>(supplies.begin(), supplies.end());

        unordered_map<string, int> idx;
        for (int i = 0; i < recipes.size(); i ++){
            idx[recipes[i]] = i;
        }

        vector<int> state(n, 0);
        // checking for all the recipes if they are creatable or not
        for (int i = 0; i < n; i ++){
            // unvisited recipe
            if (state[i] == 0){
                dfs_traversal(recipes, ingredients, idx, state, i);
            }
        }

        return res;
    }
};