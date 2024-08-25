#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
/******************���ַ���ȫ��ת��ΪСд�ĺ���************************/
string to_lower(string str){
	for(int i=0;i<str.length();i++){
		if(isupper(str[i])){
			str[i]=tolower(str[i]);
		}
	}
	return str;
}
/******************���ַ����и�Ϊ���ʴ洢��map,�����ѯ************************/
map<string,int> to_word_map(string str){
	map<string,int> temp;
	stringstream ss;
	ss<<str;
	while(ss>>str){
		temp[str]=1;
	} 
	return temp;
}
/******************���ַ����и�Ϊ���ʴ洢��vector,�����ѯ************************/
vector<string> to_word_vector(string str){
	vector<string> temp;
	stringstream ss;
	ss<<str;
	while(ss>>str){
		temp.push_back(str);
	} 
	return temp;
}
/*****************************���Ľṹ��*******************************/
struct paper{
	map<string,int> name;//���Դ�Сд�����ڲ�ѯ 
	string true_name; 
	int quote;
}; 
/***************************vector�������*****************************/
bool cmp(paper a,paper b){
	return a.quote>b.quote;
} 
int main(){
	int n,k;
	while(cin>>n){
		if(!n) break; 
		vector<paper> res;
		while(n--){
			paper temp;
			cin.ignore();//���Ի��з� 
			getline(cin,temp.true_name);//��ȡ�����ַ��� 
			temp.name=to_word_map(to_lower(temp.true_name));//ת��ΪСд���и�ʴ浽map
			cin>>temp.quote;
			res.push_back(temp);
		} 
		sort(res.begin(),res.end(),cmp);//�Ƚ���������ٲ�ѯ�����Ľṹ��Ȼ������� 
		cin>>k;
		cin.ignore();
		while(k--){
			string check;//bug��δ���Կ��� 
			getline(cin,check);
			check=to_lower(check);
			/**********************��ѯ�Ƚ��鷳������ֱ��find**************************/ 
			/**********************��������Ҫ��һ�������и�****************************/ 
			vector<string> check_word=to_word_vector(check);//�и�洢��vector
			for(int i=0;i<res.size();i++){//��������õ����� 
				int j;
				for(j=0;j<check_word.size();j++){//һ������һ�����ʵ�ȥ�� 
					if(res[i].name.find(check_word[j])==res[i].name.end())	
						break;
				} 
				if(j==check_word.size()) cout<<res[i].true_name<<endl; //���ÿ�����ʶ��ҵ��˾���� 
			}
			cout<<"***"<<endl;	
		} 
		cout<<"---"<<endl;		
	}
	return 0;
} 
