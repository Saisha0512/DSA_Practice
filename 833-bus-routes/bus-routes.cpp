class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        // base case
        if (source == target){
            return 0;
        }

        int max_el = INT_MIN;
        for (auto r : routes){
            for (int stop : r){
                max_el = max(max_el, stop);
            }
        }

        // out of bounds
        if (target > max_el || source > max_el){
            return -1;
        }

        vector<int> min_stop(max_el + 1, INT_MAX);
        // min_stop[i] = min no bus changes needed to reach the ith stop on starting from the source
        min_stop[source] = 0;
        bool flag = true;

        while (flag){
            flag = false;

            for (auto r : routes){
                int min_bus = n + 1;
                for (int stop : r){
                    min_bus = min(min_bus, min_stop[stop]);
                }
                min_bus ++; // for the current route

                // updating all the stop in the current route that they can be reached via the stop with min buses
                for (int stop : r){
                    if (min_stop[stop] > min_bus){
                        min_stop[stop] = min_bus;
                        flag = true; // done atleast one modification
                    }
                }
            }
        }

        return (min_stop[target] < n + 1)? min_stop[target] : -1;
    }
};