#include<bits/stdc++.h>
using namespace std;  //�����·�� 
const long long INF = 0x3f3f3f3f3f3f3f3fLL; //��������INF�ĺô���: INF <= INF+x
const int N= 3e5+2;
struct edge{
    int from, to; long long w; //��㣬�յ㣬Ȩֵ�����from��û���õ���e[i]��i����from
    edge(int a, int b,long long c){from=a; to=b; w=c;}
};
vector<edge>e[N];  		   //���ڴ洢ͼ
struct s_node{
    int id; long long n_dis;   //id����㣻n_dis�������㵽���ľ���
    s_node(int b,long long c){id=b; n_dis=c;}
    bool operator < (const s_node & a) const
    { return n_dis > a.n_dis;}
};
int n,m;

long long  dis[N];         //��¼���н�㵽���ľ���
void dijkstra(){
    int s = 1;             //���s��1
    bool done[N]; //done[i]=true��ʾ�����i�����·���Ѿ��ҵ�
    for (int i=1;i<=n;i++) {dis[i]=INF; done[i]=false; }    //��ʼ��
    dis[s]=0;                           //��㵽�Լ��ľ�����0
    priority_queue <s_node> Q;          //���ȶ��У�������Ϣ
    Q.push(s_node(s, dis[s]));          //��������
    while (!Q.empty())   {
        s_node u = Q.top();             //pop�������s������С�Ľ��u
        Q.pop();
        if(done[u.id])  continue;       //�����Ѿ��ҵ����·���Ľ�㡣������A�еĽ��
        done[u.id]= true;
        for (int i=0; i<e[u.id].size(); i++) {  //�����u�������ھ�
            edge y = e[u.id][i];         //u.id�ĵ�i���ھ���y.to
            if(done[y.to])  continue;    //�����Ѿ��ҵ����·�����ھӽ��
            if (dis[y.to] > y.w + u.n_dis) {
                dis[y.to] = y.w + u.n_dis;
                Q.push(s_node(y.to, dis[y.to]));  //��չ�µ��ھӣ��ŵ����ȶ�����
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)    e[i].clear();
    while (m--) {
        int u,v,w;  scanf("%d%d%lld",&u,&v,&w);
        e[u].push_back(edge(u,v,w));
     // e[v].push_back(edge(v,u,w));    //�����ǵ����·
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        if(dis[i]>=INF)  cout<<"-1 ";
        else   printf("%lld ", dis[i]);
    }
}


