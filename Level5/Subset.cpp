vector<int>v;
vector<vector<int> > r;
void solve(int i,vector<int>uso){
    if(i>=v.size()){
        r.push_back(uso);
        return;
    }
    uso.push_back(v[i]);
    solve(i+1,uso);
    uso.pop_back();
    solve(i+1,uso);
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    v=A;
    r.clear();
    sort(v.begin(),v.end());
    vector<int>uso;
    solve(0,uso);
    sort(r.begin(),r.end());
    return r;
}
