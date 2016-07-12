string wrd(int x){
    string r="";
    while(x>0){
        r+=((x%10)+'0');
        x/=10;
    }
	reverse(r.begin(),r.end());
    return r;
}
bool cmp(string a,string b){
	return a+b>b+a;
}
string Solution::largestNumber(const vector<int> &v) {
    string r[v.size()];
    for(int i=0;i<v.size();i++){
    	r[i]="";
        r[i]+=wrd(v[i]);
    }
    sort(r,r+v.size(),cmp);
    string re="";
    for(int i=0;i<v.size();i++)re+=r[i];
    if(re=="")re+='0';
    return re;
}
