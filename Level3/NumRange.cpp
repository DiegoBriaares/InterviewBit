long long s[900002],a,b,x;
bool check(int z){
    if(z>=a&&z<=b)return true;
    return false;
}
int bs(int in,int fin){
    if(in==fin||fin==0)return in;
    int mid=(in+fin)/2;
    if(s[mid]-x>b)return bs(in,mid);
    else return bs(mid+1,fin);
}
int Solution::numRange(vector<int> &A, int B, int C) {
    if(A.size()==0)return 0;
    long long n=A.size(),r=0;
    a=B;
    b=C;
    s[0]=A[0];
    for(int i=1;i<n;i++){
        s[i]=A[i]+s[i-1];
    }
    for(int i=0;i<n;i++){
        if(i==0)x=0;
        else x=s[i-1];
        if(A[i]>b)continue;
        int pos=bs(i,n-1);
        while(pos>=0&&s[pos]-x>b)pos--;
        if(pos<i||!check(s[pos]-x))continue;
        while(pos>=0&&check(s[pos]-x)){
        	r++;
        	pos--;
		}
    }
    return r;
}
