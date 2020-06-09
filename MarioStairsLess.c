#include <stdio.h>

int main()
{
  //  printf("%i", num); //printing. it is printing an integer, and that integer is taken from num (no & when printing)

//check so that in [1,8]
int num = 0;
while (num<1 || num > 8){
    printf("mario stairs builder \n");
   printf("please enter a number between 1 and 8: ");
    scanf("%i", &num);
    //reading an integer so i
    //&num means it will read the integer into num  
   
}  
  int n = 1;
for (int i = 0; i < num; i ++){
   
     for (int k = 0; k < num-n; k++)
    {
       
        printf(" ");
       
    }
   
for(int j = 0; j < n ; j++){
   
 printf("#");
   
}

printf("\n");
n++;

}

}