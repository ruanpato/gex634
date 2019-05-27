#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef long long int lli;
typedef tuple<double,lli,lli,lli> tllll;
priority_queue<tllll, vector<tllll>, greater<tllll>> pq;// int dia*multa para a priority, int Dia chegada, Dias para treino, multa por dias não treinado em espera

int main(){
	tllll aux;
	lli t, f, tot = 0, totDias=1, dEmtreino=0;

	while(cin >> t >> f){
		pq.push(make_tuple(((double)t/(double)f), totDias, t, f));
		if(dEmtreino==0){
			aux=pq.top();pq.pop();// Coloca o valor da fila de prioridade em uma tupla auxiliar e remove da lista de prioridade
			tot += ( (totDias-get<1>(aux))*get<3>(aux) );// Aumenta o total da multa

			dEmtreino=get<2>(aux);//Atualiza os dias de espera
		}totDias++;dEmtreino--;
	}
	
	while(!pq.empty()){
		if(dEmtreino==0){
			aux=pq.top();pq.pop();// Coloca o valor da fila de prioridade em uma tupla auxiliar e remove da lista de prioridade
			tot += ( (totDias-get<1>(aux))*get<3>(aux) );// Aumenta o total da multa

			dEmtreino=get<2>(aux);//Atualiza os dias de espera
		}totDias++;dEmtreino--;
	}

	cout << tot << endl;
	return 0;
}