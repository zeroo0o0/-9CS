#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int num[n];
	for(int i=0; i<n; i++)cin>>num[i];
	int max=0;
	for(int i=0; i<n; i++) {	
		for(int j=i; j<n; j++) {
			int m=0;
			for(int k=0; k<i; k++)if(num[k])m++;//iǰ����1
			for(int k=i; k<=j; k++)if(!num[k])m++;//i��j֮����0
			for(int k=j+1; k<n; k++)if(num[k])m++;//j������1
			if(m>max)max=m;
		}	
	}
	cout<<max;
}

