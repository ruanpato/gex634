#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 2123456  // 2 * 10^6
bool primo[MAX];
int primos[MAX], divisores[MAX];
using namespace std;
// Sieve of Eratosthenes
void sieve();

int main(){
	int n;
    sieve();
	while(scanf("%d", &n) != EOF)
		printf("%d\n", primos[n]);
		//sieve();
	return 0;
}

void sieve(){
    int divis, tam;
	memset(primo, true, sizeof(primo));	// Define all as primo
	
	// Sive of Eratosthenes
	for(int i=2; i*i <= MAX; i++)
		if(primo[i]){
			divisores[i] = 2;
            for(int j=i*i; j <= MAX; j += i){
				primo[j]=false;//x--;
                divis=0;tam=j;
                while(tam%i==0)tam/=i, divis++;
                if(divisores[j] == 0) divisores[j]=divis+1;
                else divisores[j] *= (divis+1);
            }
        }
    primos[1] = 0;
	for(int i=2; i<=MAX; i++){
        primos[i] = primos[i-1];
		if(primo[divisores[i]])
			primos[i]++;
	}
}