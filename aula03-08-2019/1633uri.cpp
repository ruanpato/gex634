#include <iostream>
#include <queue>
#include <vector>
#define MAX 112345

using namespace std;

typedef struct{ int t, c; } process;
typedef pair<int,int> pii; // pair int int = pii
process p[MAX];
int cmp(const void *a, const void *b){ // Função para o qsort
  process *pa = (process *)a, *pb = (process *)b;
  return (pa->t - pb->t);
}


int main(){
  int i, n, t; long long ans;
  while(scanf("%d", &n) != EOF){
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Muda a ordem da priority queue

    for(i = 0; i < n; i++)
      scanf("%d %d", &p[i].t, &p[i].c); // Lê os dados do processo

      qsort(p, n, sizeof(process), &cmp);
      i = 0; t = 1; ans = 0;

      while(!pq.empty() || i < n){
        for( ; (i < n && p[i].t <=t); i++)
          pq.push(pii(p[i].c, p[i].t));
        if(!pq.empty()){
          ans +=  t-pq.top().second; t += pq.top().first; pq.pop(); // Adicionando a resposta e retirando da fila de prioridade
        }else if(i < n)
          t = p[i].t;
      }
      printf("%lld\n", ans);
  }
  
  return 0;
}