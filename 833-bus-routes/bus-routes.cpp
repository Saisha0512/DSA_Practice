class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target){
            return 0;
        }

        int max_stop = INT_MIN;
        for (auto &r : routes){
            for (int stop : r){
                max_stop = max(max_stop, stop);
            }
        }

        if (target > max_stop || source > max_stop){
            return -1;
        }

        vector<int> buses(max_stop + 1, INT_MAX);
        buses[source] = 0;
        bool flag = true;
        while (flag){
            flag = false;

            for (auto &r : routes){
                int min_buses = INT_MAX;
                for (int stop : r){
                    min_buses = min(min_buses, buses[stop]);
                }

                if (min_buses == INT_MAX){
                    continue;
                }
                
                min_buses ++; // considering the bus on the current route

                for (int stop : r){
                    if (buses[stop] > min_buses){
                        buses[stop] = min_buses;
                        flag = true;
                    }
                }
            }
        }

        return (buses[target] == INT_MAX)? -1 : buses[target];
    }
};