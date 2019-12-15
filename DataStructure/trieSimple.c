#include<stdio.h>

int node[100][26];
int isWord[100];
int root, nnode;

void initialize()
{
    root = 0;
    nnode = 0;
    int i;
    for(i = 0; i < 26; i++)
    {
        node[root][i] = -1;
    }
}

void insertNode(char* str)
{
    int i, j;
    int cur = root;
    for(i = 0; str[i]; i++)
    {
        int id = str[i] - 'a';
        if(node[cur][id] == -1)
        {
            node[cur][id] = ++nnode;
            for(j = 0; j < 26; j++)
            {
                node[nnode][j] = -1;
            }
        }
        cur = node[cur][id];
    }
    isWord[cur] = 1;
}

int searchNode(char* str)
{
    int i,cur;
    cur = root;
    for(i = 0; str[i]; i++)
    {
        int id = str[i] - 'a';
        if(node[cur][id] == -1)
        {
            return 0;
        }
        cur = node[cur][id];
    }
    return isWord[cur];
}

int main()
{
    initialize();
    int Ans;
    insertNode("hasan");
    insertNode("hasa");
    insertNode("has");
    Ans = searchNode("has");
    if(Ans)
    {
        printf("Found");
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}
