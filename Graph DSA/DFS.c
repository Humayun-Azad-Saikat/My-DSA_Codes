#include<stdio.h>

  
int visited[7] = {0,0,0,0,0,0,0};
int graph[7][7] = {

// 0 1 2 3 4 5 6 
{0,1,1,1,0,0,0},//0 // adjecency matrix for graph connection representation
{1,0,1,0,0,0,0},//1
{1,1,0,1,1,0,0},//2
{1,0,1,0,1,0,0},//3
{0,0,1,1,0,1,1},//4
{0,0,0,0,1,0,0},//5
{0,0,0,0,1,0,0} //6
};

//dfs function

void DFS(int i){

    int j;
    printf("%d ",i);
    visited[i] = 1;
    for(j = 0; j < 7;j++){
        
        if(graph[i][j] == 1 && !visited[j]){ // if node is connected and node is not visited
            DFS(j);
        }
    }
}

int main(){


    DFS(0);


    return 0;
}