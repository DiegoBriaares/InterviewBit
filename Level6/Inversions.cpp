#define ll long long
#define MAX 100002
ll bit[MAX];
void update(int i,ll x){
    while(i<=MAX){
        bit[i]+=x;
        i+=(i&-i);
    }
}
ll query(int i){
    ll r=0;
    while(i>0){
        r+=bit[i];
        i-=(i&-i);
    }
    return r;
}
int Solution::countInversions(vector<int> &A) {
    memset(bit,0,sizeof(bit));
    ll r=0;
    pair<int,int>v[A.size()+1];
    for(int i=0;i<A.size();i++){
        v[i].first=A[i];
        v[i].second=i+1;
    }
    sort(v,v+A.size());
    for(int i=0;i<A.size();i++){
        r+=(i-query(v[i].second));
        update(v[i].second,1);
    }
    return r;
}
