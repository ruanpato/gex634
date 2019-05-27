#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;
typedef map<string,int> msi; // Esse tipo de typedef só deve ser feito após using namespace std;

int main(){
	string murderer, murdered; // Nome do assassino, nome do assassinado
	msi murdererTree, murderedTree; // String == Nome, int == Contador de assassinatos.
	msi::iterator it; // iterator
	

	while(cin >> murderer >> murdered){
		murdererTree[murderer]++; // Adiciona os assassinos a árvore de assassinos.
		murderedTree[murdered]++; // Adiciona os assassinados a árvore de assassinados.
	}

	cout << "HALL OF MURDERERS" << endl;
	// Imprime o hall dos assassinos
	for (it = murdererTree.begin(); it != murdererTree.end(); it++){
		if(!murderedTree[it->first]) // Mostra somente os assassinos que não foram mortos
			cout << it->first << " " << it->second << endl;
	}

	return 0;
}