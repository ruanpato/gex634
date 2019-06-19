#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
// MDCEuclides
int mdc(int a, int b);

int main(){
	int n, m, i, j, last_m[11234][31], soma_rodada[31];
	while(true){
		memset(soma_rodada, 0, sizeof(soma_rodada));
		scanf("%d %d", &n, &m);
		if(n==0 && m==0)	break;

		for(i=0; i < n; i++){
			for(j=0; j < m; j++){
				scanf("%d", &last_m[i][j]);
				soma_rodada[j] += last_m[i][j];
			}
		}

		for(i=0, j=m-1; i < n; i++){
			if(soma_rodada[j]==0){
				i= -1; j--; // Faz com que na próxima iteração i seja 0/Recua uma posição na soma
			}else{
				m = mdc(last_m[i][j], soma_rodada[j]);
				printf("%d / %d\n", last_m[i][j]/m, soma_rodada[j]/m);
			}
		}
	}
	return 0;
}

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a%b);
}