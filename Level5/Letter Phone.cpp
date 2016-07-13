vector<string>r;
vector<string >m;
string v;
void ini(){
    string uso="0"; m.push_back(uso);uso="1";m.push_back(uso);
    uso="abc";m.push_back(uso);uso="def";m.push_back(uso);
    uso="ghi";m.push_back(uso);uso="jkl";m.push_back(uso);uso="mno";
    m.push_back(uso);uso="pqrs";m.push_back(uso);uso="tuv";m.push_back(uso);
    uso="wxyz";m.push_back(uso);
}
void solve(int i,string uso){
    if(i==v.size()){
        r.push_back(uso);
        return;
    }
    for(int j=0;j<m[(v[i]-'0')].size();j++){
        solve(i+1,uso+m[(v[i]-'0')][j]);
    }
}
vector<string> Solution::letterCombinations(string A) {
    r.clear();
    m.clear();
    ini();
    v=A;
    solve(0,"");
    sort(r.begin(),r.end());
    return r;
}
