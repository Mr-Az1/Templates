#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T>
inline T gcd(T x,T y){
	if(!y)return x;
	return gcd(y,x%y);
}
template<typename T>
inline T power(T a,T b){
	int res=1;
	while(b){
		if(b&1) res=res*a;
		a*=a;
		b>>=1;
	}
	return res;
}
template<typename T>
class frac{
private:
    T numerator;
    T denominator;

public:
    frac(T num=0,T den=1){
        if(den==0){
            cout<<"Error: Denominator cannot be zero!"<<endl;
            exit(1);
        }
        T commonDivisor=gcd(abs(num),abs(den));
        numerator=num/commonDivisor;
        denominator=den/commonDivisor;

        if(denominator<0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }
    
	void operator=(const frac& other){
		numerator=other.numerator;
		denominator=other.denominator;
		return ;
	}
	
	void operator=(const T& other){
		frac<T> res(other,1);
		*this=res;
		return ;
	}
	
    frac operator+(const frac& other)const{
        T newNum=(numerator*other.denominator)+(other.numerator*denominator);
        T newDen=denominator*other.denominator;
        return frac(newNum,newDen);
    }
	frac operator+(const T& other){
		frac<T> res=other; 
		return *this+res;
	}
    void operator+=(const frac& other){(*this)=*this+other;return ;}
    void operator+=(const T& other) {(*this)=*this+other;return ;}

    frac operator-(const frac& other)const{
        T newNum=(numerator*other.denominator)-(other.numerator*denominator);
        T newDen=denominator*other.denominator;
        return frac(newNum,newDen);
    }
	frac operator-(const T& other){
		frac<T> res=other; 
		return *this-res;
	}
    void operator-=(const frac& other){(*this)=*this-other;return ;}
    void operator-=(const T& other) {(*this)=*this-other;return ;}

    frac operator*(const frac& other)const{
        T newNum=numerator*other.numerator;
        T newDen=denominator*other.denominator;
        return frac(newNum,newDen);
    }
	frac operator*(const T& other){
		frac<T> res=other; 
		return *this*res;
	}
	void operator*=(const frac& other){(*this)=*this*other;return ;}	
    void operator*=(const T& other) {(*this)=*this*other;return ;}

    frac operator/(const frac& other)const{
        if(other.numerator==0){
            cerr<<"Error: Division by zero!"<<endl;
            exit(0);
        }
        T newNum=numerator*other.denominator;
        T newDen=denominator*other.numerator;
        return frac(newNum,newDen);
    }
	frac operator/(const T& other){
		frac<T> res=other; 
		return *this/res;
	}
	frac operator^(const T a){
		frac<T> res(power(numerator,a),power(denominator,a));
		return res;
	}                      
	void operator/=(const frac& other){(*this)=*this/other;return ;}
    void operator/=(const T& other) {(*this)=*this/other;return ;}

    bool operator>(const frac<T>& other)const{
        long double thisVal=static_cast<long double>(numerator)/denominator;
        long double otherVal=static_cast<long double>(other.numerator)/other.denominator;
        return thisVal>otherVal;
    }
    bool operator>(const ll& othe){frac<T> other=othe;return other<*this;}
    
    bool operator<(const frac<T>& other)const{return other>*this;}
    bool operator<(const ll& othe){frac<T> other=othe;return other>*this;}

    bool operator==(const frac<T>& other)const{return numerator==other.numerator && denominator==other.denominator;}
    bool operator==(const ll& othe){frac<T> other=othe;return other==*this;}

    bool operator>=(const frac<T>& other)const{return *this>other || *this==other;}
    bool operator>=(const ll& othe){frac<T> other=othe;return *this>=other;}

    bool operator<=(const frac<T>& other)const{return *this<other || *this==other;}
    bool operator<=(const ll& othe){frac<T> other=othe;return *this<=other;}

    bool operator!=(const frac<T>& other)const{return !(*this==other);}
    bool operator!=(const ll& othe){frac<T> other=othe;return *this!=other;}
    
    void simplifyAndRound(){
        T commonDivisor=gcd(abs(numerator),abs(denominator));
        numerator=static_cast<T>(round(static_cast<long double>(numerator)/commonDivisor));
        denominator=static_cast<T>(round(static_cast<long double>(denominator)/commonDivisor));
        return ;
    }
    void print()const{
        cout<<numerator<<"/"<<denominator<<endl;
    }
};
template class frac<int>;
template class frac<long long>;

int main(){
	frac<int> a(2,3),b(4,5);
	puts("frac op frac"); 
	printf("a=");a.print();
	printf("b=");b.print();
	printf("a+b=");(a+b).print();
	printf("a-b=");(a-b).print();
	printf("a*b=");(a*b).print();
	printf("a/b=");(a/b).print();
	printf("(a<b)=%d\n",a<b);
	printf("(a>b)=%d\n",a>b);
	printf("(a<=b)=%d\n",a<=b);
	printf("(a>=b)=%d\n",a>=b);
	printf("(a==b)=%d\n",a==b);
	printf("(a!=b)=%d\n",a!=b);
	printf("(a^3)=");(a^3).print();
    return 0;
}
