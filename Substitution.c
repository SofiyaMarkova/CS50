#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int
main ()
{
  //make an array for "ASCII"
  int array[255];
  int array2[255];

  //populate array. [65,90] & [97,122] be 0
  //all rest be 2
  for (int p = 0; p < 255; p++)
    {

      if ((p >= 65 && p <= 90) || (p >= 97 && p <= 122))
{
 array[p] = 0;
 array2[p] = 0;
}

      else
{
 array[p] = 2;
 array2[p] = 2;
}

    }

//fill 2 arrays the same
//every time new loop. copy the clean array into the used to use again.


//make all into case

  char key[26];
  //prompt user for key until get appropriate key
  bool validation = true;
  do
    {
      validation = true;
      memcpy (array, array2, 1020); //set both array (to work with) and array2 (to reset array working with to clean as before so can do checks again)

      printf
("input a 26 letter key to cipher with (no repeating letters, only letters). case-insensitive: \n");
      scanf ("%s", key);

      if ((int) strlen (key) != 26)
{

 validation = false;
}

      for (int j = 0; j < 26; j++)
{

 int b = (int) key[j];
 
 switch(array[b]){
   
    case 2:
    //key is the letter value at the point. checking if on the array at the value that the key is saying the number is
     validation = false;
    break;
   
    case 1:
    validation = false;
    break;
   
    case 0:
   
   
     if (b <= 'Z')
{

 if (array[b + 32] == 1)
   {
     validation = false;
   }

}
     if (b >= 'a')
{

 if (array[b - 32] == 1)
   {
     validation = false;
   }
}
     array[b] = 1;
   
    break;
   
     
 }



}

    }
  while (validation == false);

//enciphering

//getting plaintext (process this way so can get any length string)
  unsigned int len_max = 128;
  unsigned int current_size = 0;

  char *text = malloc (len_max);
  current_size = len_max;

  printf ("Enter the plaintext to cipher:");


  if (text != NULL)
    {
      int c = EOF;
      unsigned int i = 0;

      //accept user input until hit enter or end of file
      c = getchar ();
      while ((c = getchar ()) != '\n' && c != EOF)
{
 text[i++] = (char) c;

 //if i reached maximize size then realloc size
 if (i == current_size)
   {
     current_size = i + len_max;
     text = realloc (text, current_size);
   }
}

      text[i] = '\0'; //end of string must have NULL so it puts it there

    }


printf("the enciphered text is: ");
  int length = (int) strlen (text);
  //loop through plaintext to do work on each char. loop as much as there is length on string (last NULL no matter it just wont do anything with it: no letter so no change)
  for (int i = 0; i < length; i++)
    {
       
//if alphabet letter can do operation on it. if not alphabet letter it just stays same (no ops)
      if (isalpha (text[i]))
{

 if (isupper (text[i]))
   {
int c = (int) text[i] - 65;
printf("%c", key[c]);

   }

 if (islower (text[i]))
   {
int c = ((int) text[i]) - 97;  
printf("%c", key[c]);        

   }
}
      else
{
 char c = (int) text[i];
 printf ("%c", c);
 //the case when not alphabet letter so nothing to be done to the char. just print as is
}

    }

  return 0;
}
