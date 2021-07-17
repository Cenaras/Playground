#include <stdio.h>
#include <stdbool.h> //Importing booleans. 0 = false, else is true


//Linked List Exercise
struct Node {
   int head; // Data is simply an integer
   struct Node* tail; // The tail of the element is a pointer to the next element in the list
};


bool isPositive(int number)
{
   if (number >= 0) return true;
   return false;
}

void positiveNumberStuff()
{
   int number;
   printf("Enter a number: ");
   scanf("%d", &number);

   if (isPositive(number))
   {
      printf("%d is positive!", number);
   }
   else if (isPositive(-number))
   {
      printf("%d is negative!", number);
   }
   else 
   {
      printf("You entered 0");
   }
}


void userInputStuff()
{
   char name[5];
   printf("Enter a string: ");
   fgets(name, 5, stdin); //Last element is NULL-Character. Therefore we can only handle input of size x-1
   printf(name);
   
   printf("Size of name: %d\n", sizeof(name));

   for (int i = 0; i < sizeof(name); i++)
   {
      printf("At index %d was char %c\n", i, name[i]);
   }
}


int main() {
   // Since we must refer to these elements as tails, each element must be a pointer to a struct
   //struct Node* first = {NULL};
   //struct Node* second = {NULL};

   //printf("Hello world\n");

   userInputStuff();
   positiveNumberStuff();

}

 