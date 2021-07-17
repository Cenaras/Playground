/*
USEFUL RESOURCES:
 - https://flaviocopes.com/

*/


#include <stdio.h>
#include <stdbool.h> //Importing booleans. 0 = false, else is true
#include <string.h>
#include <stdlib.h>

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
   // [a][b][c] -> [c][b][a]
   int size = strlen(string);   
   char *rev = malloc(size*sizeof(char)); //Allocate a string (subsequent memory) with size equal to "length of input * size of a single char"
   printf("Size of the string: %d\n", size);
   
   for (int i = 0; i < size ; i++)
   {
      rev[i] = string[size - i - 1];
      //printf("%c", *(rev+i)); Prints out the message. Note that rev[i] is the same as dereferencing the the pointer at index: *(rev + i)
   }
   
   /*Brief explanation: 
      A look at memory: ...[][][H][e][l][l][o][][]...
      We get pointer to [H] from input - Char* is a pointer to the address of [H]
      We then create an array of the appopiate size: rev: [][][][][]. 
      We let rev* be a pointer, pointing to the first input here.
      Then we fill this in and lastly we return it

   */
   return rev;
}


int fib(int num) //0, 1, 1, 2, 3, 5, 8,...
{
   if (num == 0) return 0;
   if (num == 1) return 1;
   else return fib(num-1) + fib(num-2);
}

//For each element: Scan all elements; if any element is bigger than the element, swap them.
void bubblesort(int list[], int amountOfNumbers)
{ //2, 5, 1, 3
   int temp;
   int size = amountOfNumbers;
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         if (list[i] < list[j])
         {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
         }
      }
   }
   for (int i = 0; i < size; i++) printf("%d, ", list[i]);

}


int main() {

   //printf("Hello world\n");
   //userInputStuff();
   //positiveNumberStuff();
   //printf("\nReverse of 'Hello': %s\n", reverse("Hello"));
   //printSizeOfDataTypes();
   //printf("String was: %c", reverse("hello"));
   //printf("Fib: %d", fib(8));
   int array[] = {2, 1, 5, 6, 12, 762, 3, 2};
   bubblesort(array, 8);
}

 