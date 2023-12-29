#include<bits/stdc++.h>
using namespace std;
int from,to;
double succ[30]={0.95,0.90,0.85,0.85,0.80,0.75,0.70,0.65,0.60,0.55,0.50,0.45,0.40,0.35,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.03,0.02,0.01},
       keep[30]={0.05,0.10,0.15,0.15,0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55,0.60,0.65,0.70,0.679,0.0,0.00,0.00,0.00,0.63},
	   drop[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.000,0.679,0.679,0.672,0.672,0.0,0.63,0.776,0.686,0.594},
	   dsty[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.021,0.021,0.021,0.028,0.028,0.07,0.07,0.194,0.294,0.396};
double P[80][30];

class Matrix {
public:
	int n,m;
	vector< vector<double> > mat;
	Matrix(int nn,int mm) {
		n=nn;m=mm;
		mat.resize(n);
		for(auto &v:mat) {
			v.resize(m);
		}
	}
	void modify(int i,int j,double x){
		mat[i][j]=x;
	}
	void swapr(int i,int j){
		swap(mat[i],mat[j]);
	}
	void swapc(int i,int j){
		for(auto &v:mat) {
			swap(v[i],v[j]);
		}
	}
	void print(){
		cout<<"An "<<n<<"x"<<m<<" matrix:"<<endl;
		for(auto i:mat) {
			cout<<"|";
			for(auto j:i)
				cout<<j<<"\t";
			cout<<"|"<<endl;
		}
	}
	vector<double>& operator [](int x){
		return mat[x];
	}
	void clear() {
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++)
				mat[i][j]=0;
	}
};
void Gauss(Matrix& A,Matrix& b) {
	int n=A.n,m=A.m;
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			double mk=A[j][i]/A[i][i];
			for(int k=i;k<m;k++) {
				A[j][k]=A[j][k]-A[i][k]*mk;
			}
			b[j][0]=b[j][0]-b[i][0]*mk;
		}
		// cout<<"i="<<i<<endl;
		// A.print();
		// b.print();
	}
}

void solvex(Matrix& A ,Matrix& b,Matrix& x) {
	int n=A.n,m=A.m;
	for(int i=n-1;i>=0;i--) {
		for(int j=i+1;j<m;j++) {
			b[i][0]-=A[i][j]*x[j][0];
		}
		x[i][0]=b[i][0]/A[i][i];
	}
	// for(int i=0;i<n;i++) 
	// 	cout<<x[i][0]<<" ";
	// cout<<endl;
}
void init(Matrix& A,Matrix& b,int x) {
	// A.clear();b.clear();
	for(int i=0;i<=9;i++) {
		A[i][i]=keep[i+12]-1;
		if(i!=0)A[i][i-1+11]=drop[i+12];
		A[i][i+1]=succ[i+12];
	}
	A[10][10]=1;

	for(int i=11;i<=20;i++) {
		A[i][i-11]=keep[i+1];
		A[i][i]=-1;
		if(i!=11)A[i][i-1+11]=drop[i+1];
		A[i][i-10]=succ[i+1];
	}
	A[21][21]=1;

	for(int i=22;i<=31;i++) {
		A[i][i-21]=1;
		A[i][i]=-1;
	}
	A[32][32]=1;

	for(int i=0;i<=9;i++) {
		b[i][0]=-dsty[i+12]*P[x-1][0];
		b[i+11][0]=-dsty[i+12]*P[x-1][0];
	}
	b[10][0]=1;
	b[21][0]=1;
	b[32][0]=1;

	// b.print();
}
void Solve(Matrix A ,Matrix b,Matrix X,int x) {
	init(A,b,x);
	// A.print();b.print();exit(0);
	Gauss(A,b);
	solvex(A,b,X);
	for(int i=0;i<11;i++)P[x][i]=X[i][0];
}
void print(int x) {
	for(int j=15;j<=x;j++) cout<<"\t"<<j<<"*->"<<x<<"*";cout<<endl;
	P[0][x-12]=1;
	for(int i=0;i<=20;i++) {
		cout<<i<<"\t";
		for(int j=3;j<=x-12;j++) cout<<P[i][j]/P[i][x-12]<<"\t";
		cout<<endl;
	}
}
void Print() {
	cout<<fixed<<setprecision(3);
	cout<<endl;
	for(int i=22;i>=15;i--) print(i);
}
int main() {
	cout<<fixed<<setprecision(3);
	// cin>>from>>to;
	// for(int i=12;i<=21;i++) {
	// 	cout<<i<<"\t"<<succ[i]<<"\t"<<keep[i]<<"\t"<<drop[i]<<"\t"<<dsty[i]<<endl;
	// }
	from=21;to=22;
	bool successon15=0,safeguard=0;
	if(successon15) cout<<"必成 "; else cout<<"无必成 ";
	if(safeguard) cout<<"保护 "; else cout<<"无保护 ";
	cout<<endl;
	if(successon15) {
		succ[15]=1;keep[15]=0;drop[15]=0;dsty[15]=0;
	}
	if(safeguard) {
		keep[15]+=dsty[15]; dsty[15]=0;
		drop[16]+=dsty[16]; dsty[16]=0;
	}
	int x=30;

	Matrix A(33,33),X(33,1),b(33,1);
	for(int i=1;i<=x;i++) 
		Solve(A,b,X,i);
	Print();
	return 0;
}