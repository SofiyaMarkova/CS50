#include <stdio.h>
#include <math.h> //include so can use power function and log function (the math)

int
main ()
{

  long long int num = 0;

//get input
  if (num <= 0)
    {
      printf ("credit card identifier\n");
      printf ("input the credit card number: ");
      scanf ("%lld", &num);
    }


//checksum
  long long int workNum = num; //copies original number to work with it (it gets truncated away at the end)
  int digitCounter = (int) log10 (num) + 1; //finds the amount of digits in the number
  int digitToAdd = 0; //be current digit to add
  int sum = 0; //keeps track of all the digits added (to find if they all then /10 can be == valid)

  for (int i = 1; i <= digitCounter; i++)
    {

      digitToAdd = workNum % 10;

      if (i % 2 == 0)
{ //even numbers (every other if started from 1) be the ones that *2  and then add

 digitToAdd = digitToAdd * 2;

 if (digitToAdd > 10)
   { //if greater than 10 (max 18 anyways = 9*9) need to split the digits of the created number to be added

     digitToAdd = digitToAdd % 10 + 1;

   }

}
      sum = sum + digitToAdd;
      workNum = workNum / 10;

    }

//if check sum successful
  if (sum % 10 == 0)
    {

      //finding what type of card

      long long int checkOne = 0;
      int changedOne = 0;
      long long int checkTwo = 0;
      int changedTwo = 0;


      printf ("the credit card is ");

//American Express check
      if (digitCounter == 15)
{
 //have to do because int and long long int can't be compared
 checkOne = num / pow (10, 13);
 changedOne = checkOne;


 if (changedOne == 34 || changedOne == 37)
   {
     printf ("AMEX");
   }

}

//MasterCard check
      if (digitCounter == 16)


{

 //have to do because int and long long int can't be compared
 checkOne = num / pow (10, 14);
 changedOne = checkOne;



 if (changedOne == 51 || changedOne == 52
     || changedOne == 53 || changedOne == 54 || changedOne == 55)
   {


     printf ("MASTERCARD");
   }

}

//Visa check
      if (digitCounter == 13 || digitCounter == 16)

{

 //have to do because int and long long int can't be compared
 checkOne = num / pow (10, 15);
 changedOne = checkOne;
 checkTwo = num / pow (10, 12);
 changedTwo = checkTwo;

 if (changedOne == 4 || changedTwo == 4)
   {
     printf ("VISA");
   }

}

//neither of those cards according to number of digits in card
      if (digitCounter != 13 && digitCounter != 15 && digitCounter != 16)
{

 printf ("INVALID");
}

    }
  else //checksum not valid so not a valid card
    {
      printf ("INVALID");
    }

} //end main