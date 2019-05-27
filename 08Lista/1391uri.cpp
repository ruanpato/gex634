#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

// Melhores caminhos: aqueles que estão empatados como o melhor se houver casos onde exista mais de um melhor caminho.
// Algoritmo vai passando um dijsktra enquanto for o "melhor caminho" e eliminando os melhores caminhos, após os "melhores caminhos" forem excluidos mostra o melhor, ou então -1
// Usar uma matriz pra 

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<ii> G[512];
int M[512][512];
vector<int> BT[512];
int D[512];

void dfs_destroy(int q, int s){
	if(q == s) return;
	for(int i = 0; i < BT[q].size(); i++){
		dfs_destroy(BT[q][i], s);
		M[BT[q][i]][q] = 1;
	}
}

int dijsktra(int s, int d){
	priority_queue<iii, vector<iii>, greater<iii>> pq;

	memset(D, -1, sizeof(D));
	for(int i = 0; i < 512; i++){
		BT[i].clear();
	}

	pq.push(iii(0, ii(s, -1)));
	while(!pq.empty()){
		iii z = pq.top();
		pq.pop();

		int a = z.first;
		int b = z.second.first;
		int c = z.second.second;

		if(D[b] != -1 && D[b] != a) continue;// goto pro while
		if(D[b] != -1){
			BT[b].push_back(c);
			continue;
		} 

		D[b] = a;
		BT[b].push_back(c);

		for(int i = 0; i < G[b].size(); i++){
			ii y = G[b][i];

			int g = y.first;
			int h = y.second;

			if(M[b][g] == 1) continue;

			if(D[g] == -1){
				pq.push(iii(D[b] + h, ii(g, b)));
			}
		}
	}

	if(D[d] == -1) return -1;

	dfs_destroy(d, s);

	return D[d];
}

int main(){
	int n, m;
	int s, d;
	int u, v, p;
	int res;

	while(scanf("%d %d", &n, &m), n + m){
		scanf("%d %d", &s, &d);

		for(int i = 0; i < 512; i++){
			G[i].clear();
		}

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &p);
			G[u].push_back(ii(v, p));
		}

		memset(M, 0, sizeof(M));// Arestas visitadas
		
		res = dijsktra(s, d);
		res = dijsktra(s, d);

		printf("%d\n", res);
	}

	return 0;
} 
