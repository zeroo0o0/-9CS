#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct str{
	string s; 
	int dot;//����� 
	int cnt;//������� 
	str(){
		dot=0;
	}
};
bool cmp(str a,str b){
	if(a.dot!=b.dot)
		return a.dot<b.dot;
	else
		return a.cnt<b.cnt;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<str> res;
	for(int i=0;i<m;i++){
		str temp;
		cin>>temp.s;//��¼������ַ��� 
		temp.cnt=i; //��¼������� 
		/*****************�����ַ����������******************************/
		for(int j=0;j<temp.s.length();j++){
			for(int k=j+1;k<temp.s.length();k++){
				if(temp.s[k]<temp.s[j]) temp.dot++;
			}
		}
		/*****************************************************************/
		res.push_back(temp);
	}
	sort(res.begin(),res.end(),cmp);
	for(int i=0;i<res.size();i++){
		cout<<res[i].s<<endl;
	}
	return 0;
}

