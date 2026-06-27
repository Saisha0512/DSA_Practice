class SnapshotArray {
    int curr_snap;
    vector<vector<pair<int, int>>> arr;
public:
    SnapshotArray(int length) {
        arr.resize(length);
        curr_snap = 0;
    }
    
    void set(int index, int val) {
        // if we are updating the value at this index for current snap_id only
        if (!arr[index].empty() && arr[index].back().first == curr_snap){
            arr[index].back().second = val;
        }
        // otherwise, we will push back a new pair for current snap_id at this index
        else {
            arr[index].push_back({curr_snap, val});
        }
    }
    
    int snap() {
        // updating the snap_id
        curr_snap ++;
        return curr_snap - 1;
    }
    
    int get(int index, int snap_id) {
        // finding the valid index
        int pos = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX)) - arr[index].begin() - 1;

        // if it is empty
        if (pos == -1){
            return 0;
        }

        return arr[index][pos].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */