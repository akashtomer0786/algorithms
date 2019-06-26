///this is the perfect way for multiple strings to find anagrams

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > sol;
    unordered_map <string, vector<int>> mep;
    vector<vector<int>> res;
    for (int i = 0; i < A.size(); i++) {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        mep[temp].push_back(i + 1);

    }
    auto it = mep.begin();
    while (it!=mep.end()) {
        res.push_back(it->second);
        it++;
    }
    return res;
}
