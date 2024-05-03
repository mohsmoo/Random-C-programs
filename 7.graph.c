#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
struct Vertex
{
    char label;
    bool visited;
};
int stack[MAX];
int top = -1;
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;
void push(int item)
{
    stack[++top] = item;
}
int pop()
{
    return stack[top--];
}
int peek()
{
    return stack[top];
}
bool isStackEmpty() 
{
    return top == -1;
}
void addVertex(char label)
{
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}
void addEdge(int start,int end)
{
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex)
{
    printf("%c ",lstVertices[vertexIndex]->label);
}
int getAdjUnvisitedVertex(int vertexIndex)
{
    int i;
    for(i = 0; i < vertexCount; i++)
    {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
        {
            return i;
        }
    }
    return -1;
}
void depthFirstSearch()
{
    int i;
    lstVertices[0]->visited = true;
    displayVertex(0);
    push(0);
    int unvisitedVertex;
    while(!isStackEmpty())
    {
        int unvisitedVertex = getAdjUnvisitedVertex(peek());
        if(unvisitedVertex == -1)
        {
            pop();
        }
        else
        {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
    for (i = 0;i < vertexCount; i++)
    {
        lstVertices[i]->visited = false;
    }
}
int main()
{
    int i, j;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    addVertex('A'); // 0
    addVertex('B'); // 1
    addVertex('C'); // 2
    addVertex('D'); // 3
    addVertex('E'); // 4
    addVertex('F'); // 5
    addVertex('G'); // 6
    addVertex('H'); // 7
    addEdge(0, 1); // A - B
    addEdge(0, 2); // A - C
    addEdge(1, 3); // B - D
    addEdge(1, 4); // B - E
    addEdge(1, 5); // B - F
    addEdge(2, 5); // C - F
    addEdge(2, 6); // C - G
    addEdge(2, 7); // C - H
    printf("Depth First Search: ");
    depthFirstSearch();
    printf("\n");
    return 0;
}