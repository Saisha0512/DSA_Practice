class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(); // No. of houses

        int pickup = 0; // To count the pickup time of each unit of garbage
        int lastm = -1, lastp = -1, lastg = -1; // To store the max house no till which the specific truck needs to travel
        for (int i = 0; i < n; i ++){
            for (char ch : garbage[i]){
                pickup ++;
                if (ch == 'M'){
                    lastm = i;
                }
                if (ch == 'P'){
                    lastp = i;
                }
                if (ch == 'G'){
                    lastg = i;
                }
            }
        }

        int total = pickup;
        // Calculating the travel time prefix sum : 
        for (int i = 1; i < travel.size(); i ++){
            travel[i] += travel[i - 1];
        }

        // Adding the travel time to the pickup time, to get the total time : 
        if (lastm > 0){
            total += travel[lastm - 1];
        }
        if (lastp > 0){
            total += travel[lastp - 1];
        }
        if (lastg > 0){
            total += travel[lastg - 1];
        }

        return total;
    }
};