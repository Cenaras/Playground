#include <stdio.h>
#include <stdlib.h>


void printSizeOfDataTypes()
{

   int n;
   char a;
   double d;
   int b[3];

   printf("Size of Int: %d byte(s)\n", sizeof(n));
   printf("Size of int[1]: %d byte(s)\n", sizeof(b));
   //printf("Size of Char: %d byte(s)\n", sizeof(a));
   //printf("Size of Double: %d byte(s)\n", sizeof(d));
}


void funWithMemoryAndArrays()
{
    /*
        Each variable lives somewhere in memory and therefore has an address, which we can get with &var.
        Variables such as arrays are stored sequentially in memory, where each entry start at a location and ends after its size
        Remember that the stack grows down, so higher memory locations are "older" than newer ones
        Let's look at an example
    */

   int var1 = 2;
   int var2[2];
   char var3[4];

   printSizeOfDataTypes();

   printf("Location of var1: %x\n", &var1);
   printf("Location of var2: %x\n", &var2);
   printf("Location of var3: %x\n", &var3);

    /*
        Notice how "var1" has a higher location than the other variables, since the stack grows downwards. Higher addresses are accessed first...
        After this, "var2" has been allocated. Since var1 is an int, and ints are 4 bytes, var2 can begin 4 bytes after var1's address.
            Example: &var1 = 61ff0c. 4 bytes are used, and stack grows down, so next 4 bytes after this is 0x61ff0c - 0x4 = 0x61ff08
            Arrays are stored using their later value higher in memory. This means that since var2 is 2 * 4 bytes = 8 bytes, the location of var2 (i.e. the start of the array) is
            at location 0x61ff0c - 0x8 = 0x61ff04
        Lastly var7 is 4 bytes, meaning that it starts at memory location 0x61ff04 - 0x4 = 0x61ff00
        
        Always remember this: Arrays have their last index in the highest memory, and &var retrieves the location of the first element in the array
    */

}

int main()
{
    funWithMemoryAndArrays();
    return 0;
}