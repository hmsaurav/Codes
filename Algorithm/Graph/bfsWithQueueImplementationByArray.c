#include<stdio.h>
#define INF 99999
int G[100][100];
int level[100];
int vis[100];
int Q[100*100];
int V, f, r;


void initG()
{
    int i,j;
    for(i = 0; i <= V; i++)
    {
        level[i] = INF;
        for(j = 0; j <= V; j++)
        {
            G[i][j] = 0;
        }
    }
}

void initQ()
{
    f = r = 0;
}

void Qpush(int x)
{
    Q[r] = x;
    r++;
}

int Qempty()
{
    return f == r ? 1: 0;
}

int Qpop()
{
    return Q[f++];
}

void bfs(int s)
{
    level[s] = 0;
    Qpush(s);
    int u, v;
    while(!Qempty())
    {
        u = Qpop();
        for(v = 0; v <= V; v++)
        {
            if(G[u][v] == 1 && level[v] == INF)
            {
                G[u][v] = G[v][u] = 0;
                level[v] = level[u] + 1;
                Qpush(v);
            }
        }
    }
}

int main()
{
    freopen("Bfsinput.txt", "r", stdin);
    int i, E,x, y, src, des;
    scanf("%d %d",&V, &E);
    initG();
    for(i = 1; i <=E; i++)
    {
        scanf("%d %d",&x, &y);
        G[x][y] = G[y][x] = 1;
    }
    src = 1;
    des = 4;
    initQ();
    bfs(src);
    printf("%d\n", level[des]);
}
