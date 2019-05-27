#include <iostream>
#include <set>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	char palavra[212], aux[212];
	int i, j;
	set<string> resposta;
	memset(aux, '\0', 212); // Limpa a cadeia de caracteres

	while(scanf("%s", palavra) != EOF){
		
		for(i = 0, j = 0; i <= strlen(palavra); i++){
			if(isalpha(palavra[i])){ // Se o caractere é uma letra
				aux[j] = (palavra[i] <= 90 ? palavra[i]+=32 : palavra[i]);// coloca para caixa baixa a letra
				j++;
			}else if( !(isalpha(palavra[i])) && j){ // Se não é uma letra e a substring tem pelo menos um caractere
				resposta.insert(aux);
				memset(aux, '\0', 212);
				j=0; // Atribui o tamanho da string auxiliar para 0
			}
		}
	}

	for(auto it = resposta.begin(); it != resposta.end(); it++) // Cria um iterador para imprimir as strings
		cout << *it << endl;

	return 0;
}