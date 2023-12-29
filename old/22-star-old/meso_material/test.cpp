#include<bits/stdc++.h>
using namespace std;
class dpoly;
class polynomial {
public:
	int n;
	vector<double> A;
	polynomial(int nn=0) {
		n=nn;
		A.resize(n+1);
	}
	double& operator[](int x) {
		return A[x];
	}
	dpoly operator*(polynomial y) {
		dpoly ret(n,y.n);
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=y.n;j++) {
				ret[i][j]+=A[i]*y.A[j];
			}
		}
		return ret;
	}
	polynomial derivation() {
		polynomial ret(n-1);
		for(int i=1;i<=n;i++) {
			ret[i-1]=A[i]*i;
		}
		return ret;
	}
	polynomial integral(int C=0) {
		polynomial ret(n+1);
		ret[0]=C;
		for(int i=0;i<=n;i++) {
			ret[i+1]=A[i]/(i+1);
		}
	}
	double integral(int a,int b) {
		polynomial ret=this->integral();
		return ret.calc(b)-ret.calc(a);
	}
	void print() {
		cout<<n<<"polynomial:\n\t";
		for(int i=n;i>0;i++) {
			cout<<A[i]<<"x^"<<i<<"+";
		}
		cout<<A[0]<<endl;
	}
	double calc(double x) {
		double p=1;
		double ret=0;
		for(int i=0;i<n;i++) {
			ret+=A[i]*p;
			p*=x;
		}
	}
};
class dpoly {
public:
	int n,m;
	vector< vector<double> >  f;
	dpoly(int nn,int mm) {
		n=nn;m=mm;
		f.resize(n+1);
		for(int i=0;i<=n;i++) {
			f[i].resize(m+1);
		}
	}
	vector<double> operator[](int x) {
		return f[x];
	}
	double integral(double x0,double y0,double x,double y) {
		
	}
};
struct point {
	int x,y;
};
polynomial Lagrange(vector<point> A) {
	
}
int main() {
	int n,m;
	vector<point> A,B;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		point x;
		cin>>x.x>>x.y;
		A.push_back(x);
	}
	for(int i=0;i<m;i++) {
		point x;
		cin>>x.x>>x.y;
		B.push_back(x);
	}
	polynomial fxi=Lagrange(A).derivation(),fiy=Lagrange(B).derivation();
	dpoly fxy=fxi*fiy;
	


	return 0;
}