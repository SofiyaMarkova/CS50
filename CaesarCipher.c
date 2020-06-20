#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
main ()
{
   
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
   
//prompt for cipher key    
int key = 0;
  printf ("Enter the key to cipher with: ");
  scanf ("%d", &key);

printf("The ciphertext is: ");

//ciphering

  int length = (int) strlen (text);
  //loop through plaintext to do work on each char. loop as much as there is length on string (last NULL no matter it just wont do anything with it: no letter so no change)
  for (int i = 0; i < length; i++)
    {


//if alphabet letter can do operation on it. if not alphabet letter it just stays same (no ops)
      if (isalpha (text[i]))
{

 if (isupper (text[i]))
   { //[65-90] //need to set so that it starts index from 0. not the 65 == upper as usual (so formula works)
     char c = ((((int) text[i] - 65) + key) % 26) + 65; //to ascii so val, change val to new letter with cipher, back to regular code so + normal again
     printf ("%c", c); //print as a letter (not ascii val of letter)
   }

 if (islower (text[i]))
   { //[97-122] //need to set so that starts index from 0. not the 97 == lower as usual (so formula works)
     char c = ((((int) text[i] - 97) + key) % 26) + 97; //to ascii so val, change val to new letter with cipher, back to regular code so + normal again
     printf ("%c", c); //print as a letter (not ascii val of letter)
   }

}
      else
{ char c = (int) text[i];
 printf ("%c", c);
 //the case when not alphabet letter so nothing to be done to the char. just print as is
}

    }



  return 0; //because the main function returns an int must (its there as a rule that needs be done)
}
