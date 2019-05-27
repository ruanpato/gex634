quadroMedalhas={} # Dicionário python

def incrementa(pais, medalhas):
	if pais not in quadroMedalhas: # Verifica se o pais está no quadro, caso contrário adiciona
		quadroMedalhas[pais] = medalhas
	else:
		aux=tuple() # Cria uma tupla auxiliar
		for i, j in zip(quadroMedalhas[pais], medalhas):
			aux += (i+j,)
		quadroMedalhas[pais] = aux

while 1:
	try:
		input() # Modalidade
		incrementa(input(), (1,0,0)) # Medalha de ouro
		incrementa(input(), (0,1,0)) # Medalha de prata
		incrementa(input(), (0,0,1)) # Medalha de cobre
	except EOFError:
		break;

qQuadroMedalhas = {} # Dicionário python
for i, j in sorted(quadroMedalhas.items()):
	if j not in qQuadroMedalhas:
		qQuadroMedalhas[j] = [i] 
	else:
		qQuadroMedalhas[j].append(i)

print("Quadro de Medalhas")
for i, j in sorted(qQuadroMedalhas.items())[::-1]:
	for h in j:
		print('{} {} {} {}'.format(h, i[0], i[1], i[2]))