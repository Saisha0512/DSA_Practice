class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long currmass = mass;
        // sorting the asteroids to get avoid the planet from getting destroyed
        sort(asteroids.begin(), asteroids.end());

        // iterating over all the asteroids
        for (int i = 0; i < n; i ++){
            // the asteroid gets destroyed and the mass of it is added upto the planet
            if (currmass >= asteroids[i]){
                currmass += asteroids[i];
            }
            else {
                return false;
            }
        }

        // all asteroids are now destroyed
        return true;
    }
};