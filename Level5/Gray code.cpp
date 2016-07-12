vector<int> Solution::grayCode(int A) {
    vector<vector<int> >v,v2;
    vector<int>a,b,r;
    a.push_back(0);
    b.push_back(1);
    v.push_back(a);
    v.push_back(b);
    for(int i=1;i<A;i++){
    	v2=v;
    	reverse(v2.begin(),v2.end());
    	for(int j=0;j<v.size();j++){
    		v[j].insert(v[j].begin(),0);
		}
		for(int j=0;j<v2.size();j++){
    		v2[j].insert(v2[j].begin(),1);
		}
		for(int j=0;j<v2.size();j++){
    		v.push_back(v2[j]);
		}
	}
	for(int i=0;i<v.size();i++){
		int s=0;
		for(int j=v[i].size()-1,k=0;j>=0;j--,k++){
			if(v[i][j]==1)s+=(pow(2,k));
		}
		r.push_back(s);
	}
	return r;
}
