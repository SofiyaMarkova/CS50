#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//making a struct for candidate
typedef struct
{
  char name[100];
  int votes;
  int index;
} candidate;

int
main ()
{
  int i;
  int numCandidates;
  int numVoters = 0;
  do
    {
      numCandidates = 0;
      printf ("How many candidates are there: ");
      scanf ("%d", &numCandidates);
      fflush(stdin); //clears it so that if a char is inputed or another invalid value it is clean
    }
  while (numCandidates < 1);
 
  candidate candidatesArray[numCandidates]; //create array of candidate structures, there be numCandidates number of candidates in array

  printf
    ("Input candidate names (doesn't matter which number each candidate gets assigned to) \n");

//allocating index for the names of candidates
  for (i = 0; i < numCandidates; i++)
    {
      printf ("%d represents candidate: ", i);
      scanf ("%s", candidatesArray[i].name);
      candidatesArray[i].votes = 0;
    }

  do
    {
      printf ("How many voters are there: ");
      scanf ("%d", &numVoters);
    }
  while (numVoters < 0 || numVoters == 0); //so not input negative number or 0 for number of voters

//getting counts for votes
int choice;
  printf ("type the number that corresponds to each candidate to count for a vote\n");
  for (i = 0; i < numVoters; i++)
    {
      do
{
 choice = -1;
 printf ("voter number %d chooses: ", i + 1);
 scanf ("%d", &choice);
}
      while (choice < 0 || choice >= numCandidates);  //keeps prompting if input an index not corresponding to a candidate
      candidatesArray[choice].votes++;
    }

  int largestVote = 0;
  int indexLargestVote;

  //find largest vote. could be for tie so just find the largest number
  for (i = 0; i < numCandidates; i++)
    {

      if (largestVote < candidatesArray[i].votes)
{
 largestVote = candidatesArray[i].votes;

}

    }

  printf ("the most voted candidate/candidates: ");

//prints top candidate (or all part of a tie)
  for (i = 0; i < numCandidates; i++)
    {

      if (candidatesArray[i].votes == largestVote)
{
 printf ("%s ", candidatesArray[i].name);
}

    }

  return 0;

}