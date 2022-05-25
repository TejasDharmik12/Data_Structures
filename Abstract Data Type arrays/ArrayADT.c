//Creating an array of this data type
//Printing the contents of this array
//Setting value in an arry

#include<stdio.h>
#include<stdlib.h>
struct myArray          //struct myArray Abstract data type
{                       //array memory is still not reserved
    int total_size;
    int used_size; 
    int *ptr;      //ptr points at the address of first element     //heap ke memory
    //thats why we use createarray function
};
void createArray(struct myArray * a, int tsize, int uSize){
    a->total_size = tsize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tsize*sizeof(int)); //give memory in heap
//assign the integer pointer ptr, the address of the reserved memory location using malloc.
}
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
       printf("%d\n", (a->ptr[i])); //(a->ptr[i]) to access each element
    }
    
}
void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d",i);
        scanf("%d",&n);
        a->ptr[i] = n;
    }
    
}

int main(){
    struct myArray marks;    //makes the structure and stores memory for tot_size,used and ptr
    createArray(&marks, 10, 2);
    printf("We are running setVAL\n");
    setVal(&marks);
    printf("We are running show\n");
    show(&marks);
    return 0;
}
