vector<vector<int> > Solution::anagrams(const vector<string> &v) {
    vector<vector<int> >r;
    map<string,vector<int> >memo;
    for(int i=0;i<v.size();i++){
        string uso=v[i];
        sort(uso.begin(),uso.end());
        memo[uso].push_back((i+1));
    }
    for(map<string,vector<int> >::iterator it=memo.begin();it!=memo.end();it++){
        r.push_back(it->second);
    }
    sort(r.begin(),r.end());
    return r;
}
