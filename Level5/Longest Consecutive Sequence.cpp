int Solution::longestConsecutive(const vector<int> &A) {
    int res=1,r=1,a=0;
    vector<int>v=A;
    sort(v.begin(),v.end());
    a=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]-a==1){
            r++;
            res=max(res,r);
        }
        else if(v[i]!=a) r=1;
        a=v[i];
    }
    return res;
}
