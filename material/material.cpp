#include<bits/stdc++.h>
using namespace std;
int dif,to;
double succ[30]={0.95,0.90,0.85,0.85,0.80,0.75,0.70,0.65,0.60,0.55,0.50,0.45,0.40,0.35,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.03,0.02,0.01},
       keep[30]={0.05,0.10,0.15,0.15,0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55,0.60,0.65,0.70,0.679,0.0,0.00,0.00,0.00,0.63},
	   drop[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.000,0.679,0.679,0.672,0.672,0.0,0.63,0.776,0.686,0.594},
	   dsty[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.021,0.021,0.021,0.028,0.028,0.07,0.07,0.194,0.294,0.396};
double P[80][30];
int Material;
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
			for(auto j:i)
				cout<<j<<"\t";
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
}
void init(Matrix& A,Matrix& b,int x) {
	for(int i=0;i<=dif-2;i++) {
		A[i][i]=keep[i+12]-1;
		if(i!=0)A[i][i-1+dif]=drop[i+12];
		A[i][i+1]=succ[i+12];
	}
	A[dif-1][dif-1]=1;

	for(int i=dif;i<=2*dif-2;i++) {
		A[i][i-dif]=keep[i+12-dif];
		A[i][i]=-1;
		if(i!=dif)A[i][i-1+dif]=drop[i+12-dif];
		A[i][i-(dif-1)]=succ[i+12-dif];
	}
	A[2*dif-1][2*dif-1]=1;

	for(int i=2*dif;i<=3*dif-2;i++) {
		A[i][i-(2*dif-1)]=1;
		A[i][i]=-1;
	}
	A[3*dif-1][3*dif-1]=1;

	for(int i=0;i<=dif-2;i++) {
		b[i][0]=-dsty[i+12]*P[x-1][0];
		b[i+dif][0]=-dsty[i+12]*P[x-1][0];
	}
	b[dif-1][0]=1;
	b[2*dif-1][0]=1;
	b[3*dif-1][0]=1;
}
void Solve(Matrix A ,Matrix b,Matrix X,int x) {
	init(A,b,x);
	Gauss(A,b);
	solvex(A,b,X);
	for(int i=0;i<dif;i++)P[x][i]=X[i][0];
}
void print(int x) {
	P[0][x-12]=1;
	for(int i=0;i<=Material;i++) {
		cout<<P[i][3]/P[i][x-12];
		cout<<endl;
	}
}
void Print() {
	print(to);
}
int main() {
	
	int type;
	cin>>to>>type>>Material;
	dif=to-12+1;
	bool successon15=(type==1),safeguard=(type==2);
	if(successon15) {
		succ[15]=1;keep[15]=0;drop[15]=0;dsty[15]=0;
	}
	if(safeguard) {
		keep[15]+=dsty[15]; dsty[15]=0;
		drop[16]+=dsty[16]; dsty[16]=0;
	}

	Matrix A(3*dif,3*dif),X(3*dif,1),b(3*dif,1);
	for(int i=1;i<=Material;i++) 
		Solve(A,b,X,i);
	Print();
	return 0;
}