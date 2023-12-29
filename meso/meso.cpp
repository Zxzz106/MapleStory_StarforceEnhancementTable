#include<bits/stdc++.h>
using namespace std;
int cost[30];
int from,to;
double succ[30]={0.95,0.90,0.85,0.85,0.80,0.75,0.70,0.65,0.60,0.55,0.50,0.45,0.40,0.35,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.30,0.03,0.02,0.01},
       keep[30]={0.05,0.10,0.15,0.15,0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55,0.60,0.65,0.70,0.679,0.0,0.00,0.00,0.00,0.63},
	   drop[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.000,0.679,0.679,0.672,0.672,0.0,0.63,0.776,0.686,0.594},
	   dsty[30]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.021,0.021,0.021,0.028,0.028,0.07,0.07,0.194,0.294,0.396};
void init(int level,bool discount,bool certain) {
	for(int i=0;i<=9;i++)
		cost[i]=100*round((pow(level,3)*(i+1)/2500.0+10));
	cost[10]=100*round((pow(level,3)*pow(10+1,2.7)/40000.0+10));
	cost[11]=100*round((pow(level,3)*pow(11+1,2.7)/22000.0+10));
	cost[12]=100*round((pow(level,3)*pow(12+1,2.7)/15000.0+10));
	cost[13]=100*round((pow(level,3)*pow(13+1,2.7)/11000.0+10));
	cost[14]=100*round((pow(level,3)*pow(14+1,2.7)/7500.0+10));
	for(int i=15;i<=24;i++)
		cost[i]=100*round((pow(level,3)*pow(i+1,2.7)/20000.0+10));
}
double dp[6000005][11][3];
double dfs(int meso,int star,int t) {	
	if(meso<0) return 0;
	if(dp[meso][star-12][t]!=0) return dp[meso][star-12][t];
	if(star==to){
		assert(t==0);
		dp[meso][star-12][t]=1;
		return 1;
	}
	if(t==2) {
		dp[meso][star-12][t]=dfs(meso-cost[star],star+1,0);
		return dp[meso][star-12][t];
	}
	double ret=dfs(meso-cost[star],star+1,0)*succ[star];
	if(keep[star]!=0) ret+=dfs(meso-cost[star],star,0)*keep[star];
	if(drop[star]!=0) ret+=dfs(meso-cost[star],star-1,t+1)*drop[star];
	if(dsty[star]!=0) ret+=dfs(meso-cost[star],12,0)*dsty[star];
	dp[meso][star-12][t]=ret;
	return ret;
}
int gcd(int a,int b) {
	return !b?a:gcd(b,a%b);
}
int main() {
	int lvl;
	bool thirtyoff,successon15,safeguard;
	cin>>thirtyoff>>successon15>>safeguard;
	cin>>from>>to;
	cin>>lvl;
	init(lvl,0,0);
	double ratio=10000;
	for(int i=12;i<=21;i++) {
		if(safeguard&&i==15&&!successon15)cost[i]=ceil(cost[i]/ratio*(thirtyoff?0.7:1)+cost[i]/ratio);
		else if(safeguard&&i==16)cost[i]=ceil(cost[i]/ratio*(thirtyoff?0.7:1)+cost[i]/ratio);
		else cost[i]=ceil(cost[i]/ratio*(thirtyoff?0.7:1));
	}
	// for(int i=12;i<=21;i++) cout<<cost[i]<<" ";cout<<endl;
	if(successon15) {
		succ[15]=1;keep[15]=0;drop[15]=0;dsty[15]=0;
	}
	if(safeguard) {
		keep[15]+=dsty[15]; dsty[15]=0;
		drop[16]+=dsty[16]; dsty[16]=0;
	}
	double x;
	cin>>x;	x/=1000;
	// cout<<fixed<<setprecision(1)<<x<<"b"<<"\t ";
	x=x*1000000000/ratio;
	assert(x<=6000000);
	cout<<fixed<<setprecision(3);
	double ans;
	double p=0,step=x/40;
	do {
		ans=dfs((int)p,from,0);
		cout<<setprecision(1)<<p*ratio/1e9<<"b\t";
		cout<<setprecision(3)<<ans<<endl;
		p+=step;
	}while(p<=x);
	return 0;
}