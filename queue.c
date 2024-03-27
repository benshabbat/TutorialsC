#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node
{
  int value;
  struct Node *next;
} Node;
typedef struct
{
  Node *head;
  Node *tail;
  int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);



int main(void)
{

  Queue *queue = create_queue();
  
  if (is_empty(queue)) printf("Queue is empty.\n");
  
  enqueue(queue, 4);
 
  if (!is_empty(queue)) printf("Queue is not empty.\n");
  
  enqueue(queue, 5);
  enqueue(queue, 6);
  
  // The queue size should now be 3
  printf("Queue size: %d\n", size(queue));
  
  bool status = false;
  int value = 0;
  
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  

  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);

  value = peek(queue, &status);
  if (!status) printf("Peek unsuccessful.\n");
  
  value = dequeue(queue, &status);
  if (!status) printf("Dequeue unsuccesful.\n");

  destroy_queue(queue);
  
  return 0;
}


// Returns a pointer to a new empty queue on the heap
Queue *create_queue()
{

  Queue *queue = malloc(sizeof(Queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  
  return queue;
}

int size(Queue *queue)
{
  return queue->size;
}


// Returns true if the queue is empty and false if it is not
bool is_empty(Queue *queue)
{
  return (queue->size == 0);
}

int peek(Queue *queue, bool *status)
{

  if (is_empty(queue))
  {
    *status = false;
    return NULL;
  }
  

  *status = true;
  return queue->head->value;
}



void enqueue(Queue *queue, int value)
{

  Node *newNode = malloc(sizeof(Node));

  newNode->value = value;
  newNode->next = NULL;

  if (is_empty(queue))
  {
    queue->head = newNode;
    queue->tail = newNode;
  }

  else
  {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
  
  // Increment size to acknowledge the Queue now stores another element
  queue->size++;
}


int dequeue(Queue *queue, bool *status)
{
  // If the queue is empty set the bool variable pointed to by status to false
  // and return NULL.
  if (is_empty(queue))
  {
    *status = false;
    return NULL;
  }

  *status = true;

  int value = queue->head->value;
  
  Node *oldHead = queue->head;
    
  if (queue->size == 1)
  {
    queue->head = NULL;
    queue->tail = NULL;
  }
  // Otherwise set the head pointer to point to the next node in list as this
  // as the new head of the queue.
  else
  {
    queue->head = queue->head->next;
  }
  
  // Use the pointer to the old head that we saved to delete the head
  free(oldHead);
  
  // Decrement the queue size to acknowledge we have removed an element from
  // the queue.
  queue->size--;
  
  // Return the value of the old head node that we saved into the value variable
  return value;
}


void destroy_queue(Queue *queue)
{

  Node *currentNode = queue->head;

  while (currentNode != NULL)
  {

    Node *temp = currentNode;

    // Set currentNode to point to the next node in the list using the next
    // member.
    currentNode = currentNode->next;

    // Now free the "current node of this loop iteration" that we kept a 
    // temporary pointer to.
    free(temp);
  }

  free(queue);
}