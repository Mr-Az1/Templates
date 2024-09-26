#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#include<cmath>
#define rint int
#define mem(a,b) memset(a,b,sizeof a)
#define lowbit(x) (x&-x)
#define debug(a,b) cout<<"line"<<__LINE__<<":"<<a<<" = "<<b<<endl;
#define eb emplace_back
#define pb push_back
#define read raed
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll INF=1e18;
const int N=1e7+8,mod=998244353;
template<typename T> 
void read(T &x){
    x=0;int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    x*=f;
}
template<typename T,typename ... Args>
void read(T &x, Args &... y){read(x);read(y...);}
int n,a,b,ans;
template<typename T> 
class matrix{
private:
    T row,col;
    vector<vector<T>> data;
    inline T size(){return row*col;}
public:
    inline void clean(){data.clear();return ;}
    inline void set(vector<vector<T>> dat){data=dat;return ;}
    matrix(T row,T col):row(row),col(col){data.resize(row,vector<T>(col+8,0));}
    inline int get(int x,int y){return data[x][y];}
    void unit(){
    	for(rint i=0;i<row;i++) data[i][i]=1;
    	return ;
	}
    matrix operator+(const matrix& other)const{
        matrix res(row,col);
        for(rint i=0;i<row;++i){
        	for(rint j=0;j<col;++j){
				res.data[i][j]=(data[i][j]+other.data[i][j])%mod;
			}
		}
	    return res;
    }
    matrix operator*(const matrix& other)const{
        matrix res(row,other.col);
        for(rint i=0;i<row;++i){
            for(rint j=0;j<other.col;++j){
                for(rint k=0;k<col;++k){
					res.data[i][j]=(res.data[i][j]+data[i][k]*other.data[k][j]%mod+mod)%mod;
                }
            }
        }
        return res;
    }
    matrix power(int k){
    	matrix A(row,row),B(row,row);B.unit();
    	A=(*this);
    	while(k){
    		if(k&1) B=B*A;
    		A=A*A;
			k>>=1;
		}
		return B;
	}
};
template class matrix<int>;
signed main(){
    read(a,b,n);
    matrix<int> ans(2,1),tmp(2,2);
    ans.set({{a},{2}});tmp.set({{a,-b},{1,0}});
    ans=ans*tmp.power(n-1);
    cout<<ans.get(1,1)<<endl;
	return 0;
}
