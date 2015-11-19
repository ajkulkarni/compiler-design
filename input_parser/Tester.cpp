/**
 *
 * @author Ajay
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern "C" {
#include "lexer.h"
}

using namespace std;

struct node {
  token_type t_type;
  char current_token[MAX_TOKEN_LENGTH];
  int line;
  struct node *next;
};

struct node *first;

void addnode(token_type ttype, char currenttoken[MAX_TOKEN_LENGTH], int lineNo) {
  node *temp =(node*)malloc(sizeof(node));
  temp->t_type=ttype;
  strcpy(temp->current_token,currenttoken);
  temp->line=lineNo;

  if(first == NULL) {
    first = temp;
    first->next = NULL;
  }

  else {
    temp->next=first;
    first=temp;
  }
}

void printList() {
  node *temp1;
  temp1=first;
  while(temp1 != NULL){
    if((int)(temp1->t_type) == 24)
    printf("%d NUM %s\n" , temp1->line , temp1->current_token);
    else
    printf("%d ID %s\n" , temp1->line , temp1->current_token);
    temp1=temp1->next;
  }
}

void cleanUp() {
  node *temp2;
  if (first == NULL) return;
  while(first->next != NULL){
    temp2=first;
    first=temp2->next;
    free(temp2);
  }
  free(first);
}

int main() {
  first = NULL;
  int int_type = 0;

  do {
    t_type = getToken();
    int_type = (int)t_type;
    if(int_type==24)
      addnode(t_type, current_token, line);
    if(int_type==25 && (strcmp(current_token,"cse340")==0 || strcmp(current_token,"programming")==0 || strcmp(current_token,"language")==0))
      addnode(t_type, current_token, line);
  }
  while(t_type != EOF);
  printList();
  cleanUp();
  return 0;
}
