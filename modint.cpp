#include<bits/stdc++.h>
using namespace std;
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
    inline static int norm(const long long& x){return x<0?x+MOD:((x>=MOD)?x-MOD:x);}
    inline friend int raw(modint m){return m.val;}
    static constexpr int getmod(){return MOD;}
    modint():val(0){}
    modint(const int& m):val(norm(m)){}
    modint(const long long& m):val(norm(m%MOD)){}
    modint(const modint& m):val(norm(m.val%MOD)){};
    inline friend istream& operator>>(istream& is,modint& a){
        read(a.val);a.val=norm(a.val);
        return is;
    }
    inline friend ostream& operator<<(ostream& os,const modint& a){return os<<a.val;}
    inline modint inv()const{
    	assert(val!=0);
        int a=val,b=MOD,u=1,v=0,t;
        while(b>0) t=a/b,swap(a-=t*b,b),swap(u-=t*v,v);
    	assert(b!=1);
        return modint(u);
    }
    modint 	operator-()const{return modint(norm(-val));}
    bool 	operator==(const modint& o)		{return val==o.val;}
    bool 	operator!=(const modint& o)		{return val!=o.val;}
    bool 	operator<(const modint& o)		{return val<o.val;}
    bool 	operator<=(const modint& o)		{return val<=o.val;}
    bool 	operator>(const modint& o)		{return val>o.val;}
    bool 	operator>=(const modint& o)		{return val>o.val;}
    bool 	operator!()						{return !val;}
    modint& operator++()					{return val=norm(1ll*val+1),*this;}
    modint& operator--()					{return val=norm(1ll*val-1),*this;}
    modint& operator+=(const modint& o)		{return val=norm(1ll*val+o.val),*this;}
    modint& operator-=(const modint& o)		{return val=norm(1ll*val-o.val),*this;}
    modint& operator*=(const modint& o)		{return val=static_cast<int>(1ll*val*o.val%MOD),*this;}
    modint& operator/=(const modint& o)		{return *this*=o.inv();}
    modint& operator%=(const modint& o)		{return val=val%o,*this;}
    modint& operator&=(const modint& o)		{return val&=o.val,*this;}
    modint& operator^=(const modint& o)		{return val=norm(1ll*val^o.val),*this;}
    modint& operator|=(const modint& o)		{return val=norm(1ll*val|o.val),*this;}
    modint& operator>>=(const modint& o)	{return val=norm(1ll*val>>o.val),*this;}
    modint& operator<<=(const modint& o)	{return val=norm(1ll*val<<o.val),*this;}
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
    inline friend modint power(const modint& aa,const int& bb){
        assert(bb>=0);
        modint a=aa,b=bb,res=1;
        for(;b!=0;a*=a,b>>=1) if((b&1)!=0) res*=a;
        return res;
	}
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
	printf("power(a,10)=%d power(b,10)=%d\n",raw(power(a,10)),raw(power(b,10)));
	return 0;
}
