/*
USEFUL RESOURCES:
 - https://flaviocopes.com/

*/


#include <stdio.h>
#include <stdbool.h> //Importing booleans. 0 = false, else is true


//Linked List Exercise
struct Node {
   int head; // Data is simply an integer
   struct Node* tail; // The tail of the element is a pointer to the next element in the list
};


void printSizeOfDataTypes()
{

   int n = 1;
   char a = 'a';
   double d = 2.0;

   printf("Size of Int: %d byte(s)\n", sizeof(n));
   printf("Size of Char: %d byte(s)\n", sizeof(a));
   printf("Size of Double: %d byte(s)\n", sizeof(d));
}

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

//Note: Sizeof is wrong here... It computes byte size...
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

/*Char* is basically just a string
Since strings are arrays of chars, we return a pointer to the first char...
*/
const char* reverse(char* string)
{
   int size = sizeof(string);
   char* rev[sizeof(string)];
   
   printf("Size of the string: %d", size);
   
   /*for (int i = 0; i < size ; i++)
   {
      rev[i] = string[size - i];
   }
   */
   return "Fix this";
}


int main() {
   // Since we must refer to these elements as tails, each element must be a pointer to a struct
   //struct Node* first = {NULL};
   //struct Node* second = {NULL};

   //printf("Hello world\n");

   //userInputStuff();
   //positiveNumberStuff();
   //reverse("Hellof");
   printSizeOfDataTypes();
   //printf("String was: %c", reverse("hello"));

}

 