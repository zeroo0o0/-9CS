#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int Cfind(string s) {//ͳ���ʺŸ��� 
	int su=0;
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='?')su++;
	}
	return su;
}
int main() {
	string s;
	while(cin>>s) {
		string ss;
		cin>>ss;
		int sum=Cfind(s);//sumΪ�ʺ����� 
		int num=0;
		for(int i=0; i<s.length(); i++) {
			if(s[i]=='?') {//�����ʺ� 
				sum--;//���º����ʺ����� 
				num+=('9'-ss[i])*pow(10,sum);//����X��λ��7 ��W��λ����ȡ 8��9��������ʺſ���ȡ0��9 
			}
			if(s[i]!='?'&&s[i]>ss[i]) {//�������֣���λ�󣬺���������ʺŶ�����ȡ0��9 
				num+=pow(10,sum);
				break;
			}
			if(s[i]!='?'&&s[i]==ss[i])continue;//�������֣���λ��ͬ��Ҫ�����Ƚϵ�λ 
			if(s[i]!='?'&&s[i]<ss[i])break;//�������֣���λС����λ�Ͳ��ñ��� 
		}
		cout<<num<<endl;
	}
}

