bool ok(int k,vector<int>v,int n,int x){
    int _max_ele = *max_element(v.begin(), v.end());
            if(_max_ele > k)
                    return false; 
    int s=0,c=0;
    for(int i=0;i<n;){
        s+=v[i];
        if(s>k){
            c++;
            s=0;
        }
        else i++;
    }
    if(c<x)return true;
    return false;
}
int Solution::books(vector<int> &v, int x) {
    int n=v.size(),fin=0,in=0,r=(1<<30);
    if(x>n)return -1;
    for(int i=0;i<n;i++){
        fin+=v[i];
    }
    while(in<=fin){
        int mid=(in+fin)/2;
        if(ok(mid,v,n,x)){
            r=min(r,mid);
            fin=mid-1;
        }
        else in=mid+1;
    }
    return r;
}
