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
#include<bitset>
#include<list>
#include<cassert>
#define rint register int
#define mem(a,b) memset(a,b,sizeof a)
#define lowbit(x) (x&-x)
#define debug(a,b) cout<<"line"<<__LINE__<<":"<<a<<"="<<b<<endl;
#define eb emplace_back
#define pb push_back
#define read raed
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll INF=1e18;
const int mod=998244353;
template<typename T>
void read(T &x){
    x=0;int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    x*=f;
}
template<typename T,typename ... Args>
void read(T &x,Args &... y){read(x);read(y...);}
template<int MOD>
struct modint{
    int val;
    inline static int norm(const int& x){return x<0?x+MOD:x;}
    inline friend int raw(modint m){return m.val;}
    static constexpr int getmod(){return MOD;}
    modint():val(0){}
    modint(const int& m):val(norm(m)){}
    modint(const long long& m):val(norm(m%MOD)){}
    modint(const modint& m):val(norm(m.val%MOD)){};
    friend istream& operator>>(istream& is,modint& a){
        read(a.val);a.val=norm(a.val);
        return is;
    }
    friend ostream& operator<<(ostream& os,const modint& a){return os<<a.val;}
    modint inv()const{
    	if(val==0) printf("error: Find val=0 in calculating inv.Error line:%d\n",__LINE__);
        int a=val,b=MOD,u=1,v=0,t;
        while(b>0) t=a/b,swap(a-=t*b,b),swap(u-=t*v,v);
        if(b==1) printf("error:Find no inv in calculating inv.Error line:%d\n",__LINE__);
        return modint(u);
    }
    modint 	operator-()const{return modint(norm(-val));}
    bool 	operator==(const modint& o)		{return val==o.val;}
    bool 	operator!=(const modint& o)		{return val!=o.val;}
    bool 	operator<(const modint& o)		{return val<o.val;}
    modint& operator+=(const modint& o)		{return val=(1ll*val+o.val)%MOD,*this;}
    modint& operator-=(const modint& o)		{return val=norm(1ll*val-o.val),*this;}
    modint& operator*=(const modint& o)		{return val=static_cast<int>(1ll*val*o.val%MOD),*this;}
    modint& operator/=(const modint& o)		{return *this*=o.inv();}
    modint& operator%=(const modint& o)		{return val=val%o,*this;}
    modint& operator^=(const modint& o)		{return val^=o.val,*this;}
    modint& operator&=(const modint& o)		{return val&=o.val,*this;}
    modint& operator|=(const modint& o)		{return val|=o.val,*this;}
    modint& operator>>=(const modint& o)	{return val>>=o.val,*this;}
    modint& operator<<=(const modint& o)	{return val<<=o.val,*this;}
    modint  operator-(const modint& o) const{return modint(*this)-=o;}
    modint  operator+(const modint& o) const{return modint(*this)+=o;}
    modint  operator*(const modint& o) const{return modint(*this)*=o;}
    modint  operator/(const modint& o) const{return modint(*this)/=o;}
    modint  operator%(const modint& o) const{return modint(*this)%=o;}
    modint  operator^(const modint& o) const{return modint(*this)^=o;}
    modint  operator&(const modint& o) const{return modint(*this)&=o;}
    modint  operator|(const modint& o) const{return modint(*this)|=o;}
    modint  operator>>(const modint& o)const{return modint(*this)>>=o;}
    modint  operator<<(const modint& o)const{return modint(*this)<<=o;}
    template<typename T>
    inline friend modint power(const modint& aa,const T& bb){
        assert(bb>=0);
        modint a=aa,b=bb,res=1;
        for(;b!=0;a*=a,b>>=1) if((b&1)!=0) res*=a;
        return res;
	}
	inline friend modint abs(const modint& a){return modint(abs(a.val));}
};
using m107=modint<1000000007>;
using m998=modint<998244353>;
using mint=modint<mod>;
signed main(){
	mint a,b;
	read(a,b);
	printf("mod=%d\n",a.getmod());
	printf("a=%d b=%d\n",raw(a),raw(b));
	printf("a+b=%d\n",raw(a+b));
	printf("a-b=%d\n",raw(a-b));
	printf("a*b=%d\n",raw(a*b));
	printf("a/b=%d\n",raw(a/b));
	printf("a^b=%d\n",raw(a^b));
	printf("a|b=%d\n",raw(a|b));
	printf("a&b=%d\n",raw(a&b));
	printf("abs(a)=%d abs(b)=%d\n",raw(abs(a)),raw(abs(b)));
	printf("power(a,10)=%d power(b,10)=%d\n",raw(power(a,10)),raw(power(b,10)));
	return 0;
}
