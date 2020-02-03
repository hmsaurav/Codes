#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct
{
    int endMark;
    int next[26];
}NODE;

NODE* createNode()
{
    int i;
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->endMark = 0;
    for(i = 0; i < 26; i++)
    {
        newNode->next[i] = NULL;
    }
    return newNode;
}

void insertNode(char* str, NODE* root)
{
    int i;
    NODE* cur = root;
    for(i = 0; str[i]; i++)
    {
        int id = str[i] - 'a';
        if(cur->next[id] == NULL)
        {
            cur->next[id] = createNode();
        }
        cur = cur->next[id];
    }
    cur->endMark = 1;
}

int searchNode(char* str, NODE* root)
{
    int i;
    NODE* cur = root;
    for(i = 0; str[i]; i++)
    {
        int id = str[i] - 'a';
        if(cur->next[id] == NULL)
        {
            return 0;
        }
        cur = cur->next[id];
    }
    return cur->endMark;
}

int main()
{
    NODE* root = createNode();
    insertNode("hasan", root);
    insertNode("hasa", root);
    insertNode("has", root);
    int Ans;
    Ans = searchNode("has", root);
    if(Ans)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    return 0;
}
