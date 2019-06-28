#include <iostream>
#include <stdio.h>
#include <cstring>
#define MAX 1123456

struct point {
    int x, y;
    point(){}
    point(int _x, int _y) : x(_x), y(_y){}

};

struct vec {
    int x, y;
    vec(){}
    vec(point a) : x(a.x), y(a.y){}
    vec(int _x, int _y) : x(_x), y(_y){}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y){}
};

int dot(vec u, vec v) { return u.x * v.x + u.y * v.y; }
int cross(vec u, vec v) { return u.x * v.y - u.y * v.x; }

int kdoms, flag[MAX];
point kd[MAX][MAX], n[MAX];

void c_hull(point p[], int n, point q, int &m){
    if(n < 3){m=0; return;}
}

// Na função de área tratar se o poligono existe(caso não, apenas soma 0)

int main(){
    int N, i, x, y, ans=0;
    point pt[MAX];
    kdoms = 0;
    while(scanf("%d", &N), N != -1){
        for(i = 0; i < N; i++)
            scanf("%d %d", &pt[i].x, &pt[i].y);
        c_hull(pt, N, kd[kdoms], n[kdoms]);//Convex Hull
        kdoms++;
    }
    memset(flag, 0, sizeof(flag));
    // Mísseis
    while(scanf("%d %d", &x, &y) != EOF){
        for(i=0; i < kdoms; i++)
            flag[i] |= in_pgon(point(x, y), kd[i], n[i]);
    }
    for (i =0; i < kdoms; i++)
        if(flag[i]) ans += areax2(kd[i], n[i]);
    printf("%.2lf\n", ans/2.);

    return 0;
}
