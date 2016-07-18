int Solution::bulbs(vector<int> &A) {
    int par=0,r=0;
    for(int i=0;i<A.size();i++){
        while(A[i]==1&&i<A.size()&&r%2==0||A[i]==0&&i<A.size()&&r%2!=0)i++;
        if(i<A.size())r++;
    }
    return r;
}
