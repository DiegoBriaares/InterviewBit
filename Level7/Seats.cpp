#define MOD 10000003
int Solution::seats(string v) {
    int n=v.size();
    int mid=0,x=0,pos,pos2,r=0;
    for(int i=0;i<n;i++){
        if(v[i]=='x')mid++;
    }
    mid/=2;
    mid++;
    for(int i=0;i<n;i++){
        if(v[i]=='x'){
        	x++;
        	if(x==mid)pos=i;
		}
    }
    x=mid-1;
    pos2=pos;
    for(int i=pos-1;i>=0&&x>0;i--){  //De la mid pa abajo
    	if(v[i]=='x'){
    		r+=(pos2-i)-1;
    		r%=MOD;
    		pos2--;
    		x--;
		}
	}
	x=mid-1;
	pos2=pos;
    for(int i=pos+1;i<n&&x>0;i++){  //de la mid pa arriba
    	if(v[i]=='x'){
    		r+=(i-pos2)-1;
    		r%=MOD;
    		pos2++;
    		x--;
		}
	}
    return r%MOD;
}
