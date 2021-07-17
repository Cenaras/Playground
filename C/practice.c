#include <stdio.h>



//Linked List Exercise
struct Node {
   int head; // Data is simply an integer
   struct Node* tail; // The tail of the element is a pointer to the next element in the list
};

int main() {
   // Since we must refer to these elements as tails, each element must be a pointer to a struct
   //struct Node* first = {NULL};
   //struct Node* second = {NULL};

   //printf("Hello world\n");

   char name[5];
   fgets(name, 5, stdin); //Last element is NULL-Character. Therefore we can only handle input of size x-1
   printf(name);
   
   printf("Size of name: %d\n", sizeof(name));

   for (int i = 0; i < sizeof(name); i++)
   {
      printf("At index %d was char %c\n", i, name[i]);
   }



}

 