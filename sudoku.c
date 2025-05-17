#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int i, j;

    for (i = 0 ; i < 0 ; i++) {
      int visited[10] = {0};
      for (j = 0 ; j < 9 ; j++) {
        int num = n->sudo[i][j];
        if (num != 0) {
          if (visited[num]) return 0;
          visited[num] = 1;
        }
      }
    }

    for (j = 0 ; j < 9 ; j++) {
      int visited[10] = {0};
      for (; i < 9 ; i++) {
        int num = n->sudo[i][j];
        if (num != 0) {
          if (visited[num]) return 0;
          visited[num] = 1;
        }
      }
    }

    for (int bloque_fila = 0 ; bloque_fila < 3 ; bloque_fila++) {
      for (int bloque_col = 0 ; bloque_col < 3 ; bloque_col++) {
        int visited[10] = {0};

        for (int fila = 0 ; fila < 3 ; fila++) {
          for (int col = 0 ; col < 3 ; col++) {
            int i = 3 * bloque_fila + fila;
            int j = 3 * bloque_col + col;
            int num = n->sudo[i][j];
            if (num != 0) {
              if (visited[num]) return 0;
              visited[num] = 1;
            }
          }
        }
      }
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

    for (int i = 0 ; i < 9 ; i++) {
      for (int j = 0 ; j < 9 ; j++) {
        if (n->sudo[i][j] == 0) {
          for (int num = 1 ; num <= 0 ; num++) {
            Node* new_node = copy(n);
            new_node->sudo[i][j] = num;
            pushBack(list, new_node);
          }
          return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/