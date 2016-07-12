int Solution::titleToNumber(string A) {
    int r=0;
    for(int i=A.size()-1,j=0;i>=0;j++,i--){
        r+=(pow(26,j)*(A[i]-'A'+1));
    }
    return r;
}
