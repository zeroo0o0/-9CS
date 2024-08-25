#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
const int maxn = 2e5 + 17;

int n;
vector<int> g[maxn];
long double Expect(int v = 0, int p = -1) {
	long double expect = 0;
	for (auto u : g[v])
		if (u != p)
			expect += Expect(u, v) + 1;
	if(expect)return expect / (g[v].size() - (p != -1)); //���˵�һ���������Ķ�Ҫ��ȥ1�����ڵ㣩 
	else return 0;				//��ֹҶ�ӽ��  ��ĸΪ0 
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int v, u, i = 1; i < n; i++) {
		cin >> v >> u, v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	cout << fixed << setprecision(7) << Expect() << '\n';
	return 0;
}


