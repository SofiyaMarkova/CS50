#include <stdio.h>
#include <math.h> //include so can use round function

int main()
{
   float num = 0;
   
    printf("Calculates lowest amount of coins can use to make input amount (using 25c, 10c, 5c, 1c)\n");

   
    //prompt user, keep prompting if less than 0 amt $
    do{
    printf("print dollar amount: ");
    scanf("%f", &num);
    }while(num < 0);
   
    //convert to cents, by multiply by 100
   
    num = num *100;
    round(num); //rounds it to nearest integer so can work with exact number now
    int amt = (int)num; //make it so amt be integer to work with
   
     //figure out how many coins need to make that amount of change
     
    //declare vars to use
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int cents = 0;
   
   
    while (amt>=25){
        amt=amt-25;
        quarters++;
    }
     while (amt>=10){
        amt=amt-10;
        dimes++;
    }
     while (amt>=5){
        amt=amt-5;
        nickles++;
    }
   
    cents = amt;
   
   
printf("the minimum amount of coins for this amount of dollars is:\n");
printf("quarters: ");
printf("%i", quarters);
printf("\n");
printf("dimes: ");
printf("%i", dimes);
printf("\n");
printf("nickles: ");
printf("%i", nickles);
printf("\n");
printf("cents: ");
printf("%i", cents);
   
}
