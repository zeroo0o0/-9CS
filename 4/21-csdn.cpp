#include<iostream>
#include<string>
#include<list>
using namespace std;
int n,ret=1,red=15,scoreA=0,scoreB=0,hitA=0,hitB=0,loneA=0,loneB=0;
//ret=1,A���֣�scoreAB��AB�ı���������hitAB�ǵ��˷�����loneAB�ǵ��˳�100�ִ���
list<string> l; //�洢������¼
list<char> color_l; //�������˳��
void init_list(list<char> &color_l) {
	//�ơ��̡����ȡ������ۺ졢��
	color_l.push_back('y');
	color_l.push_back('g');
	color_l.push_back('c');
	color_l.push_back('b');
	color_l.push_back('p');
	color_l.push_back('B');
}
int get_ballScore(char ball) {
	switch(ball) {
		case 'r':{
			return 1;
			break;
		}
		case 'y':{
			return 2;
			break;
		}
		case 'g':{
			return 3;
			break;
		}
		case 'c':{
			return 4;
			break;
		}
		case 'b':{
			return 5;
			break;
		}
		case 'p':{
			return 6;
			break;
		}
		case 'B':{
			return 7;
			break;
		}
	}
}
bool check(string s, char goal) {    //������¼��Ŀ����
	if(s=="NULL") { //���ֱ�ӷ���
		if(ret==1) {    //��¼���������Է��ӷ�
			scoreB+=(get_ballScore(goal)>4?get_ballScore(goal):4);
		}
		else if(ret==-1) {
			scoreA+=(get_ballScore(goal)>4?get_ballScore(goal):4);
		}
		return true;
	}
	string temp=s+" ",left="",right=""; //leftΪ���������rightΪ�������
	int pos=temp.find(" ");
	left=temp.substr(0,pos);
	if(pos!=s.size()) { //����������յ����Ҫ����
		right=s.substr(pos+1);
	}
	int num=0;
 	if(right!="") { //�ȴ���������������������Ƿ񷸹棬����һ������Ͳ��ܷŻ�
 		for(int i=0; i<right.size(); i++) {
 			if(right[i]=='r') {
 				for(int j=i+1; j<right.size(); j++) {
 					if(!(right[j]>='0'&&right[j]<='9')) {
 						break;
					 }
					 num=num*10+right[j]-'0';
				 }
				 red-=num;
				 break;
			 }
		 }
	 }
	
	bool flag=false;    //�ж��Ƿ��б���򱻻���������
	
	for(int i=0; i<left.size(); i++) {	//�����жϻ���������Ƿ��б����
		if(!(left[i]>='0'&&left[i]<='9')&&left[i]!=goal) {	//�б����
			flag=true;
		}
	}
	
	if(right!="") { //���ж����������Ƿ��б����
		for(int i=0; i<right.size(); i++) {
			if(!(right[i]>='0'&&right[i]<='9')&&right[i]!=goal) {
				flag=true;
			}
		}
	}
 
	if(flag) {
		int tempScore=0;
		for(int j=0; j<s.size(); j++) { //		?��������1�ֻ�����num��?
			if(!((s[j]>='0'&&s[j]<='9')||s[j]==' ')) {
				if(get_ballScore(s[j])>tempScore) {
					tempScore=get_ballScore(s[j]);
				}
			}
		}
		if(ret==1) {    //��¼���������Է��ӷ�
			scoreB+=(tempScore>4?tempScore:4);
		}
		else if(ret==-1) {
			scoreA+=(tempScore>4?tempScore:4);
		}
		return true;
	}
	
	if(right=="") { //δ������ջ���Ҫ����
		return true;
	}
	
	return false;
}
void getScore(string s, char goal) {
	//�����ж������浫��û������������
	string temp=s+" ",left="",right=""; //leftΪ���������rightΪ�������
	int pos=temp.find(" ");
	left=temp.substr(0,pos);
	if(pos!=s.size()) { //����������յ����Ҫ����
		right=s.substr(pos+1);
	}
	if(right=="") {
		return; //û��������������κδ���
	}
	int sum=0;
	if(goal=='r') {
		for(int i=1; i<right.size(); i++) {
			sum=sum*10+right[i]-'0';
		}
	}
	else {
  		sum=get_ballScore(goal);
	}
	//�ֽܷ����ۼ�
	if(ret==1) {
		scoreA+=sum;
		hitA+=sum;
	}
	else if(ret==-1) {
		scoreB+=sum;
		hitB+=sum;
	}
}
void change(int Ret) {
	if(Ret==1) {    //��A����B
		if(hitA>=100) {
			loneA++;
		}
		hitA=0;
	}
	else if(Ret==-1) {  //��B����A
		if(hitB>=100) {
			loneB++;
		}
		hitB=0;
	}
}
void play_color(int* Ret) {
	if(l.empty()) {
		return;
	}
	string s=l.front();
	l.pop_front();
	if(check(s,color_l.front())) {  //�����˾ͻ���
		change(ret);    //���㵥�˵÷�
		*Ret=-*Ret;
		play_color(&ret);
		return;
	}
	getScore(s,color_l.front());    //�Լ��÷�
	color_l.pop_front();    //û�з���͵���һ������
	play_color(&ret);
}
void play(int* Ret) {
	if(l.empty()) { //����������
		return;
	}
	if(red==0) {
		play_color(&ret);
		return;
	}
AGAIN:
	string s=l.front(); //��ȡ��һ��������¼
	l.pop_front();
	//�������ȷ���Ƿ񷸹�
	if(check(s,'r')) {
		change(ret);    //���㵥�˵÷�
		*Ret=-*Ret;   //����
		play(&ret);
		return;
	}
	getScore(s,'r');    //�Լ��÷�
	if(l.empty()) {
		return;
	}
	s=l.front();
	l.pop_front();	//������������������ж��Ƿ񷸹�
	if(s=="NULL") { //��������������գ��Է���4��
		if(*Ret==1) {
			scoreB+=4;
		}
		else if(*Ret==-1) {
			scoreA+=4;
		}
		change(ret);    //���㵥�˵÷�
		*Ret=-*Ret;
		play(&ret);
		return;
	}
	if(check(s,s[0])) { //�ѵ�һ���򵽵Ĳ�����ΪĿ����
		change(ret);    //���㵥�˵÷�
		*Ret=-*Ret;
		play(&ret);
		return;
	}
	getScore(s,s[0]);
	if(l.empty()) {
		return;
	}
	if(red==0) {
		play_color(&ret);
		return;
	}
	//���������ʣ�࣬���ظ���������
	goto AGAIN;
 
}
int main() {
	string s="";
	cin>>n;
	cin.get();
	for(int i=0; i<n; i++) {
		l.clear();
		color_l.clear();
		init_list(color_l);     //ע���ʼ��
		red=15; //����һ����15��
		scoreA=scoreB=hitA=hitB=0;    //A��B��ʼ�÷�Ϊ0
		ret=1; //A������
		while(getline(cin,s)) {
			if(s=="-1") {
				break;
			}
			l.push_back(s); //�Ա�����Ϣ���м�¼
		}
		//�Դ���õı�����¼���е÷�ģ��
		play(&ret);
		if(hitA>=100) {
			loneA++;
		}
		if(hitB>=100) {
			loneB++;
		}
		cout<<scoreA<<":"<<scoreB<<endl;
	}
	cout<<loneA<<":"<<loneB<<endl;
	return 0;
}
