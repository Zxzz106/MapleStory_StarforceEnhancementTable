#include<bits/stdc++.h>
using namespace std;
int main() {
	cout<<fixed<<setprecision(3);
	int n,m;
	cin>>n>>m;
	vector<pair<int,double> > meso,material;
	for(int i=0;i<n;i++) {
		double x,y;
		cin>>x>>y;
		meso.push_back((pair<double,double>){x,y});
	}
	for(int i=0;i<m;i++) {
		double x,y;
		cin>>x>>y;
		material.push_back((pair<double,double>){x,y});
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<meso[i].first<<","<<material[j].first<<","<<meso[i].second*material[j].second<<endl;
		}
	}
	return 0;
}