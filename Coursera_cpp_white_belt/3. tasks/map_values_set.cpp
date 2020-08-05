set<string> BuildMapValuesSet(map<int, string> m) {
    set<string> s;
    for (const auto& item : m) {
        s.insert(item.second);
    }
    return s;
}