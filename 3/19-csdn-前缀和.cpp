#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s;
	vector<int> a,b;
	cin>>s;
	/**********ǰ׺��init��ʼ��**************/
	if(s[0]=='a') {
		a.push_back(1);
		b.push_back(0);
	}else{
		a.push_back(0);
		b.push_back(1);
	} 
	for(int i=1;i<s.length();i++){
		if(s[i]=='a'){
			a.push_back(a[i-1]+1);
			b.push_back(b[i-1]);
		}else{// == 'b'
			a.push_back(a[i-1]);
			b.push_back(b[i-1]+1);
		}
	}
	int max=-1;//��¼��������ֵ 
	int a_first,b_mid,a_final;//��ʵ��������������ӣ�
	//������ñ���Ҳ�������������ò������֣�����������ǰ׺�������͸��Ӷ� 
	/************������������ڵ㣬���Խس�����������Ϊ�������������***********************/
	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			a_first=a[i-1];//��һ�������е�a 
			b_mid=b[j]-b[i-1];//�ڶ��������е�b 
			a_final=a[s.length()-1]-a[j];//�����������е�a 
			if(a_first+b_mid+a_final>max){
				max=a_first+b_mid+a_final;
			} 
		}
	} 
	cout<<max<<endl;
	return 0;
} 

