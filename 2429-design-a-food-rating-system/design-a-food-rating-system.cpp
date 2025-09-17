class FoodRatings {
unordered_map<string, pair<string, int>> foodInfo; // Food -> {Cuisine, Rating}
unordered_map<string, set<pair<int, string>>> cuisineInfo; // Cuisine -> {Rating, Food}
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i ++){
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineInfo[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRatings] = foodInfo[food];

        // Removing old entry : 
        cuisineInfo[cuisine].erase({-oldRatings, food});

        // Adding new entry : 
        cuisineInfo[cuisine].insert({-newRating, food});

        // Updating foodInfo :
        foodInfo[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineInfo[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */