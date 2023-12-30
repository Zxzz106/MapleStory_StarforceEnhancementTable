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
			// cout<<"|";
			for(auto j:i)
				cout<<j<<"\t";
			// cout<<"|"<<endl;
			cout<<endl;
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
	for(int i=0;i<=8;i++) {
		A[i][i]=keep[i+12]-1;
		if(i!=0)A[i][i-1+10]=drop[i+12];
		A[i][i+1]=succ[i+12];
	}
	A[9][9]=1;

	for(int i=10;i<=18;i++) {
		A[i][i-10]=keep[i+2];
		A[i][i]=-1;
		if(i!=10)A[i][i-1+10]=drop[i+2];
		A[i][i-9]=succ[i+2];
	}
	A[19][19]=1;

	for(int i=20;i<=28;i++) {
		A[i][i-19]=1;
		A[i][i]=-1;
	}
	A[29][29]=1;

	for(int i=0;i<=8;i++) {
		b[i][0]=-dsty[i+12]*P[x-1][0];
		b[i+10][0]=-dsty[i+12]*P[x-1][0];
	}
	b[9][0]=1;
	b[19][0]=1;
	b[29][0]=1;
}
void Solve(Matrix A ,Matrix b,Matrix X,int x) {
	init(A,b,x);
	// A.print();b.print();exit(0);
	Gauss(A,b);
	solvex(A,b,X);
	for(int i=0;i<10;i++)P[x][i]=X[i][0];
	// for(int i=0;i<30;i++) cout<<X[i][0]<<endl;
}
void print(int x,int Max) {
	for(int j=15;j<=x;j++) cout<<"\t"<<j<<"*->"<<x<<"*";cout<<endl;
	P[0][x-12]=1;
	for(int i=0;i<=Max;i++) {
		cout<<i<<"\t";
		for(int j=3;j<=x-12;j++) cout<<P[i][j]/P[i][x-12]<<"\t";
		cout<<endl;
	}
}
void Print(int Max) {
	cout<<fixed<<setprecision(3);
	cout<<endl;
	// for(int i=22;i>=15;i--) print(i);
	print(21,Max);
}
int main() {
	from=21;to=22;
	bool successon15=0,safeguard=1;
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
	int x=20;

	Matrix A(30,30),X(30,1),b(30,1);
	for(int i=1;i<=x;i++) 
		Solve(A,b,X,i);
	Print(x);
	return 0;
}