#include<iostream>
#include<map>
using namespace std;
int main(){
	map<string,int>hyue={{"pop",0},{"no",1},{"zip",2},{"zotz",3},{"tzec",4},{"xul",5},{"yoxkin",6},{"mol",7},{"chen",8},{"yax",9},{"zac",10},{"ceh",11},{"mac",12},{"kankin",13},{"muan",14},{"pax",15},{"koyab",16},{"cumhu",17},{"uayet",18}};//h�������·ݶ�Ӧ
	string tyue[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};//t�������·ݶ�Ӧ
	int n;cin>>n;
	while(n--){
		int sum=0;
		string a;
		cin>>a;
		int hday=stoi(a);//�ַ���תint�����Զ�ɾ�����ַ�����
		int hmonth=hyue[a.substr(a.find('.')+1)];
		int hyear;cin>>hyear;
		sum=hyear*365+hmonth*20+hday;//���������
		int tyear=sum/260;
		string tmonth=tyue[sum%20];
		int tday=sum%13+1;
		cout<<tday<<" "<<tmonth<<" "<<tyear<<endl;	
		}
}

