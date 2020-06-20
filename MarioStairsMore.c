#include <stdio.h>

int main()
{
  //  printf("%i", num); //printing. it is printing an integer, and that integer is taken from num (no & when printing)

//check so that in [1,8]
int num = 0;
while (num<1 || num > 8){
    printf("mario two stairs builder \n");
   printf("please enter a number between 1 and 8: ");
    scanf("%i", &num);
    //reading an integer so i
    //&num means it will read the integer into num  
   
}  
  int n = 1;
for (int i = 0; i < num; i ++){
   
   //add
     for (int k = 0; k < num-n; k++)
    {
       
        printf(" ");
       
    }

//print as many # as on what number of n
for(int j = 0; j < n ; j++){
   
 printf("#");
   
}

//at end print the 2 spaces
printf("  ");

for (int m = 0; m <n ; m++){
   
  printf("#");  
}


//print new line to make next # be on new line
printf("\n");


//to encrement to next amount of steps
n++;

}

}