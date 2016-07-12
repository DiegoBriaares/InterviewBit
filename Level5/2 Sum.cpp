vector<int> Solution::twoSum(const vector<int> &v, int B) {
    map<int,int>memo;
    vector<int>r;
    int a=0,b=(1<<30);
    for(int i=0;i<v.size();i++){
        if(memo[v[i]]&&v[i]*2==B){
            a=memo[v[i]];
            b=min(b,i+1);
        }
        if(!memo[v[i]])memo[v[i]]=i+1;
    }
    for(int i=0;i<v.size();i++){
        if(memo.find(B-v[i])!=memo.end()){
            if(memo[B-v[i]]<b&&i+1<memo[B-v[i]]){
                b=memo[B-v[i]];
                a=i+1;
            }
            else if(memo[B-v[i]]==b&&(i+1<a&&i+1<memo[B-v[i]]||a==0)){
                b=memo[B-v[i]];
                a=i+1;
            }
        }
    }
    if(a==0)return r;
    r.push_back(a);
    r.push_back(b);
    return r;
}
