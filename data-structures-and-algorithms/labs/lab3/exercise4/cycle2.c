#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define true 1;
#define false 0;

typedef int bool;

struct node {
  char *data; // Useful for debugging purposes
  struct node *next;
};

// Returns true if the linked list is cyclic
// Accepts head of list as argument
int testCyclic(struct node *head) {
  if (head == NULL || head->next == NULL)
    return false;
  
  struct node *current = head;
  struct node *previous = NULL;

  while (current)
  {
    if (current == head && previous != NULL)
      return true;
    
    struct node *swap = current->next;
    current->next = previous;
    previous = current;
    current = swap;
  }
  return false;
}

int main(int argc, char **argv) {

  // Start time
  long start = clock();

  if (argc != 2) {
    printf("Usage: %s <Size of Linked List>\n", argv[0]);
    return 1;
  }

  int N = atoi(argv[1]);

  // Create a linked list with N nodes
  struct node *head = NULL;
  struct node *current = NULL;
  for (int i = 0; i < N; i++) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = malloc(sizeof(int));
    sprintf(newNode->data, "%d", i);
    newNode->next = NULL;
    if (head == NULL)
      head = newNode;
    else 
      current->next = newNode;
    current = newNode;
  }

  // if (testCyclic(head))
  //   printf("cyclic\n");
  // else
  //   printf("not cyclic\n");

  // printf("N = %d\n", N);

  double timeTaken = clock() - start * 1000.0 / CLOCKS_PER_SEC; // in seconds
  // printf("Time taken: %f seconds\n", timeTaken);

  struct mallinfo2 info = mallinfo2();
  long heapSpaceUsed = info.uordblks;
  // printf("Heap space used: %ld bytes\n", heapSpaceUsed);

  printf("%d,%f,%ld\n", N, timeTaken, heapSpaceUsed);
  return 0;
}