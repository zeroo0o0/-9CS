#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int num[n][n];
	num[1][1]=1;
	for(int i=2; i<=n; i++)num[i][1]=num[i-1][1]+i-1;//��ʼ����1�� 
	for(int i=1; i<=n; i++) {
		for(int j=2; j<=n+1-i; j++) {
			num[i][j]=num[i][j-1]+i+j-1;//ÿһ�� 
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n+1-i; j++) {
			cout<<num[i][j]<<" ";//��� 
		}
		cout<<endl;
	}
}

