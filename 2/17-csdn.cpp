#include<iostream>
#include<vector>
using namespace std;
vector<int> map;
int n,a,b,c;
string name[2]={"Lele","Yueyue"};
int get_num(string temp){
	int num=0;
	for(int i=1;i<temp.length();i++){
		num*=10;
		num+=temp[i]-'0';
	}	
	return num;
}
void go(int cnt,int A,int B,int bushu){
	if(A==n-1||B==n-1){
		if(A==n-1) cout<<name[0]<<endl;
		else cout<<name[1]<<endl;
		return ;
	} 
	if(cnt==0){
		A+=bushu;
		/*************�Ƿ���*******************/
		if(A>=n) A=n-1-A%(n-1);
		/*************�Ƿ���*******************/
		if(map[A]!=-1) A=map[A]; 
		/*************�Ƿ���ɶ���*******************/
		if(A==B&&A!=0) B=0;
	}else{
		B+=bushu;
		/*************�Ƿ���*******************/
		if(B>=n) B=n-1-B%(n-1);
		/*************�Ƿ���*******************/
		if(map[B]!=-1) B=map[B]; 	
		/*************�Ƿ���ɶ���*******************/
		if(A==B&&A!=0) A=0;	
	}
	//cout<<cnt<<" "<<A<<" "<<B<<" "<<bushu<<endl; 
	go((cnt+1)%2,A,B,(a*bushu+b)%6+1);//����+�����µĲ������ݹ�ģ�� 
}
int main(){
	while(cin>>n>>a>>b>>c){
		map.clear();
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			if(temp=="N")
				map.push_back(-1);
			else
				map.push_back(get_num(temp));	
		}
		go(0,0,0,(a*c+b)%6+1);		
	}
	return 0;
} 

