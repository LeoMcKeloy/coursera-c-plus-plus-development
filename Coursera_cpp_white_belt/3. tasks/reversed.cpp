vector<int> Reversed(const vector<int>& v) {
    vector<int> new_v;
    for (int i = v.size() - 1; i >= 0; i--) {
        new_v.push_back(v[i]);
    }
    return new_v;
}
