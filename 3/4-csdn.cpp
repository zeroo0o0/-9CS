/*
#include <iostream>
using namespace std;
int main(){
	int n, m, sum = 0, tmp, maxm = 0, minm = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		sum += tmp;
		if(sum > maxm) maxm = sum;
		if(sum < minm) minm = sum;
	}
	int result = m - maxm + 1 + minm; 
	if(result > 0) cout << result;
	else cout << 0;
	return 0;
}
*/
#include <iostream>
using namespace std;
int main() {
	int n,w;
	int sum=0,max=0,min=0,re;//�����ʼ�˿�Ϊ0
	int a;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>a;sum+=a;
		if(sum>max)max=sum;//�����������г��ֹ������˿���
		if(sum<min)min=sum;//�����������г��ֹ�����С�˿���
	}
    //�߽�Ϊmin��max������ʼ�˿���i������������[min+i,max+i]��[0,w]֮��
	if(min<0)re=w-max+min+1;//min<0��iֻ�ܴ�0��ʼ������Ҫ��ȥ|min|    //����������ʽ 
	else re=w-max+1;//i��СΪ0�����ʱmax+i=w��������w-max+1�����
	if(re>=0)cout<<re;
	else cout<<0;
}

