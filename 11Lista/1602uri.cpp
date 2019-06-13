#include <iostream>
#include <string.h>
#include <bitset>
#include <vector>
#define MAX 2123456

using namespace std;
bitset<MAX> bs;    			      // 10^7 To sieve Eratosthenes
int divisores[MAX], primos[MAX];  // Vetor de primos
void sieve_and_div();             // Função de Sieve e divide


int main(){
    int n;
    sieve_and_div();
    while(scanf("%d", &n) != EOF)
        printf("%d\n", primos[n]);
    
    return 0;
}

void sieve_and_div(){
    // Sieve
    int divis, tam;
    bs.set();    // Put all values to 1
    memset(divisores, 0, sizeof(divisores));   // Vetor auxiliar divisores

    for(int i = 2; i < MAX; i++){
        if(bs[i]){  // if true
            divisores[i] = 2; // divisores = 2
            for(int j = i+i; j < MAX; j += i){
                bs.reset(j);
                divis=0;tam=j;
                while(tam%i==0) tam/=i, divis++;
                if(divisores[j] == 0) divisores[j] = divis+1;
                else divisores[j] *= (divis+1);
            }
        }
    }

    primos[0] = primos[1] = 0;
    for(int i = 2; i < MAX; i++){
        primos[i] = primos[i-1];
        if(bs[divisores[i]])
            primos[i]++;
    }
}