class SnapshotArray {
public:
    int size;
    int snap_id = 0;
    vector<int> check;
    map<int,int> t = {{-1,0}};
    vector<int> v;
    vector<map<int,int>> snaps;
    SnapshotArray(int length) {
        v.resize(length);
        size = length;
        for(int i = 0; i < size; ++i){
            snaps.push_back(t);
        }
    }
    void set(int index, int val) {
        v[index] = val;
        check.push_back(index);
    }
    
    int snap() {
        for(auto a: check){
            auto it = snaps[a].rbegin();
            if(it->second!=v[a]){
                snaps[a].insert(make_pair(snap_id, v[a]));
            }
        }
        check.clear();
        return ++snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

