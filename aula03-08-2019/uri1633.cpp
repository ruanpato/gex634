#include<stdio.h>
#include<stdlib.h>
#include<queue>
 
using namespace std;
 
#define MAX 112345
 
typedef struct { int t, c; } process;
typedef pair<int, int> ii;
 
process p[MAX];
 
int cmp(const void *a, const void *b) {
  process *pa = (process *)a, *pb = (process *)b;
  return pa->t - pb->t;
}
 
int main(void) {
  int i, n, t;
  long long int r;
  while (scanf("%d", &n) != EOF) {
    priority_queue< ii, vector<ii>, greater<ii> > Q;
    for (i = 0; i < n; i++) scanf("%d %d", &p[i].t, &p[i].c);
    qsort(p, n, sizeof(process), &cmp);
    i = 0; t = 1; ans = 0;
    while (!Q.empty() || i < n) {
      while (i < n && p[i].t <= t) { Q.push(ii(p[i].c, p[i].t)); i++; }
      if (!Q.empty()) {
        ans += t - Q.top().second; t += Q.top().first; Q.pop();
      }
      else if (i < n) t = p[i].t;
    }
    printf("%lld\n", ans);
  }
  return 0;
}