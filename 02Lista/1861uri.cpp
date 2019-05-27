#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

typedef pair<int,int> ii;// Deve ser usado após o using namespace std;
typedef pair<string, ii> sii;

int main(){
	char murderer[12], murdered[12];
	map<string, ii> murdererTree; //String == Nome, int == Contador de assassinatos, int == 1 vivo || 0 assassinato.
	map<string, ii>::iterator it0, it1; // Iterator para navegar no map.

	while(scanf("%s %s", murderer, murdered) != EOF){
		it0 = murdererTree.find(murderer); it1 = murdererTree.find(murdered);
		if(it0 != murdererTree.end()){// Se o assassino está na lista.
			murdererTree[murderer].first += 1; // Aumenta o contador de assassinatos.
		}else{ // Caso o assassino não esteja na lista
			murdererTree.insert(sii(murderer, make_pair(1, 1))); // Adiciona o assassino com um assassinato no map e com o status de vivo
		}
	
		if(it1 != murdererTree.end()){ // Se o assassino está na lista
			murdererTree[murdered].second = 0; // Muda o status de 1 para zero, atribuindo que está morto
		}else{ // Caso o assassinado não esteja na lista
			murdererTree.insert(sii(murdered, make_pair(0, 0))); //Adiciona o assassinado a lista.
		}
	}

	printf("HALL OF MURDERERS\n");
	// Imprime o hall dos assassinos
	for (it0 = murdererTree.begin(); it0 != murdererTree.end(); it0++)
		if(it0->second.second == 1) // Mostra somente os assassinos que não foram mortos
			cout << it0->first << " " << it0->second.first << endl;

	return 0;
}