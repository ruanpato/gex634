#include <stdio.h>
#include <string.h>
#define MAX 112345
//5*10^5 cabe em int.
using namespace std;

int bit[MAX], p[MAX], n; //
int getbit(int i);
void setbit(int i, int val);

int main(){
	int i; char c;
	scanf("%d", &n);
	memset(bit, 0, sizeof(bit));
	for(i = 1; i <= n; i++){//bit ignora pos 0.
		scanf("%d", &p[i]);
		setbit(i, p[i]);
	}
	while(scanf("\n%c %d", &c, &i) != EOF){
		switch(c){
			case 'a':
				setbit(i, -p[i]);
				p[i] = 0;
				break;
			case '?':
				printf("%d\n", getbit(i-1));
				break;
		}
	}

	return 0;
}

int getbit(int i){
	int ans = 0;
	while(i > 0){
		ans += bit[i]; i -= (i & -i);
	}
	return ans;
}

void setbit(int i, int val){
	while(i <= n) {
		bit[i] += val; i += i & -i;
	}
}
