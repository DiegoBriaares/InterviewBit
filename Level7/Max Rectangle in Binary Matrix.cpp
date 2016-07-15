#define MAX 1002
int bit[MAX][MAX];
void update(int x,int y,int val){
	int y1;
	while(x<MAX){
		y1=y;
		while(y1<MAX){
			bit[x][y1]+=val;
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}
int query(int x,int y){    //query(x1,y1,x2,y2) = query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
	int r=0;
	while(x>0){
		int y1=y;
		while(y1>0){
			r+=bit[x][y1];
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return r;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    memset(bit,0,sizeof(bit));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            update(i+1,j+1,A[i][j]);
        }
    }
    int r=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            for(int i2=i;i2<A.size();i2++){
                for(int j2=j;j2<A[i2].size();j2++){
                    int uso=query(i2+1,j2+1)-query(i2+1,j)-query(i,j2+1)+query(i,j);
                    if(uso==(((j2-j)+1)*((i2-i)+1)))r=max(r,uso);
                }
            }
        }
    }
    return r;
}
