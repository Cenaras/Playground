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

printf("The location of var2+1: %x\n", var2+1); //Since var2 points to the beginning of the array, var2+1 points to the first index. Likewise var2[1] is referenced by *(var2 + 1)
//Again we see, that pointers and arrays are very much alike.

}

void pointersAndMemoryBasics()
{
    /*
    Notation used:
     - A value is what is stored in variables
     - A pointer is the memory address of a value

     - &: Takes a value and turns it into a pointer (val -> mem loc)
     - *: Takes a pointer and turns into a value (mem loc -> val)

    int *p is a pointer to where p is stored in memory, i.e. it is a memory location
    int v = &p takes this memory location, and reads the value stored in it, and assigns this value to v

    */
 
    int v = 2; //The value
    int *p = &v; //The memory location, where v lives

    printf("The pointer, pointing to v: %x\nAdding to the value does not change the pointer:\n", p);
    v++;
    printf("After adding 1 to the value: %x\n", p);


    int a[5] = {0, 1, 2, 3, 4};

    /*
        Arrays are very much like pointers. Using the * operator we can access the values of them.
        *a is the first element in the array, *(a+1) is the second element. Notice this, since C implicitly calculates a+1 as 4 bytes after a
        Hence: a+1 is 4 bytes after a, and therefore *(a+1) is the next integer element in a.
        Instead of writing *(a+n) we can write a[n], but this is syntactic sugar for: Jump n times the size of the data type in memory from the start of the array,
            and retrieve the value in there.
    */
    printf("a, a+1 and a+2: %x, %x, %x\n", a, a+1, a+2);
    printf("a, *(a+1): %d, %d\n", *a, *(a+1));

    int c = 5; //Variable with value 5
    int *pc; //Pointer
    pc = &c; //pc now points to where c is stored
    printf("The pointer: %x\n", pc);
    *pc +=1;
    printf("c has value: %d\n", c); /* Notice here, that we never actually touched c, but by increasing the value stored in the location
                                    Given by the pointer, we actually implicitly change c, since c is stored in the same mem location always. */


}

void swapPointers(int* n1, int* n2)
{
    printf("The locations of n1 and n2 before swapping: %x, %x\n", n1, n2);
    printf("The values of n1 and n2 before swapping: %d, %d\n", *n1, *n2);
    int* temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
    printf("The locations of n1 and n2 after swapping: %x, %x\n", n1, n2);
    printf("The values of n1 and n2 after swapping: %d, %d\n", *n1, *n2);

    //Notice again, that we can swap the pointers, meaning that what they're pointing to has been swapped.

}


void funWithMemoryAllocation()
{
    /*
        Recall that arrays are essential allocation of some fixed amount of memory
        Some times we might need more memory than what we initially allocated. To combat that, we can use malloc to allocate more memory
        malloc allocates memory at run-time and is known as dynamic memory allocation
    */

    //Example of memory allocation: malloc reserves a memory block for us. Therefore we must store the result of this in a pointer.
    int* ptr = malloc(10*sizeof(int)); //Here we reserve 10 extra memory spots for ints. ptr points to the first of it. Just like an array. However, the memory is not initialized.
    printf("The location of ptr: %x\n", ptr);
    printf("The location of ptr+1: %x\n", ptr+1);
    //However, the contents here are not initialized and hence something "random":
    printf("The content of the location, which ptr points to: %d\n", *ptr);
   
    //If we use calloc instead, we initialize everything to 0.
    int* c_ptr = calloc(10, sizeof(int));
    printf("The content of the location, which c_ptr points to: %d\n", *c_ptr);


    //Now, however, this memory is forever bound. Since we allocate it runtime, the compiler is not able to free memory after we're done using it...
    //So we must remember to free the memory ourselves, otherwise we can run out...
    free(ptr); //Free's the memory. It can now be used by other stuff. Lastly we can use realloc, if we dynamically need to allocate even more memory than we first did at runtime...


    //A good place where we can use this. If we don't statically know the size of the array we need to store (i.e. user input). We can store the input in a variable
    //and dynamically allocate the memory later on. Here's a quick example.

    /*
        We get the size of the array, n. We also initialize a pointer, *array.
        We then allocate memory for the array dynamically
        We then scan n times and stores the input in the allocated memory.
    */

    int n; int* array;
    printf("Enter size of array: ");
    scanf("%d", &n);
    array = malloc(n*sizeof(int));

    for (int i = 0; i<n; i++)
    {
        scanf("%d", array + i);
    }
    
    printf("The contens of the array: \n");
    for (int i = 0; i<n; i++)
    {
        printf("%d, ", array[i]);
    }

    //Dont forget to free the memory afterwards!
    free(array);

}

int main()
{
    int one = 1; int two = 2;
    int* one_ptr = &one; int* two_ptr = &two;

    //funWithMemoryAndArrays();
    //pointersAndMemoryBasics();
    //swapPointers(one_ptr, two_ptr);
    funWithMemoryAllocation();
    return 0;
}