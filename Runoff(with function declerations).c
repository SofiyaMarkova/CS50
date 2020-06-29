/*does a runoff vote election.
WILL NOT WORK IF THERE IS A TIE

fixed with function declarations now
*/
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>

//creates structure for candidate
typedef struct
{

  char name[100];

  int votes;

  int index;

  bool eliminated;

} candidate;

//function declarations
bool roundWinner (bool, int, int, candidate *, int **, int, int);

void countVotes (int, int, int **, candidate *, int);

int **alloc_2d (int, int);


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

      fflush (stdin);

    }

  while (numCandidates < 1);



  candidate candidatesArray[numCandidates];



  printf
    ("Input candidate names (doesn't matter which number each candidate gets assigned to) \n");



//allocating index for the names of candidates

  for (i = 0; i < numCandidates; i++)

    {

      printf ("%d represents candidate: ", i);

      scanf ("%s", candidatesArray[i].name);

      candidatesArray[i].votes = 0;

      candidatesArray[i].eliminated = false;

      candidatesArray[i].index = i;

    }


  do

    {

      printf ("How many voters are there: ");

      scanf ("%d", &numVoters);

    }

  while (numVoters <= 0);


  int **ranking = alloc_2d (numVoters, numCandidates);	//declaring a 2D array. need to use malloc so that proper memory alloction. so no crash


//getting counts for votes

  int choice;

  printf
    ("type the number that corresponds to each candidate to count for a vote\n");

  for (int i = 0; i < numVoters; i++)

    {

      printf ("voter number %d choices\n", i + 1);

      for (int j = 0; j < numCandidates; j++)

	{

	  do

	    {

	      choice = -1;

	      printf ("choice %d: ", j + 1);
	      scanf ("%d", &choice);

	    }

	  while (choice < 0 || choice >= numCandidates);

	  ranking[i][j] = choice;

	}

    }

//vars to use declared
  int numDivideByNumCandidates = numCandidates + 1;
  int candidateIndexToEliminate = -1;
  bool foundWinner = false;

//loops until went through as much if there is still candidates left and foundWinner is false so winner not found yet
  for (int j = 0; j < numCandidates && foundWinner == false; j++)
    {
      countVotes (numVoters, numCandidates, ranking,
		  candidatesArray, numDivideByNumCandidates);

//returns foundWinner from the function to set if winner was found or not. so it knows to loop again or not
      foundWinner =
	roundWinner (foundWinner, numVoters, numCandidates, candidatesArray,
		     ranking, numDivideByNumCandidates,
		     candidateIndexToEliminate);
    }

  return 0;			//always with main function. because main function by tradition is return int
}

//checks if there is a winner.
bool
roundWinner (bool foundWinner, int numVoters, int numCandidates,
	     candidate * candidatesArray, int **ranking,
	     int numDivideByNumCandidates, int candidateIndexToEliminate)
{

  //loops through array
  for (int i = 0; i < numCandidates && foundWinner == false; i++)

    {
//finds the percent of votes for the candidate on
      float numerator = (float) candidatesArray[i].votes;
      float denominator = (float) numVoters;
      float answer = numerator / denominator;

//if more or equal to 0.50 (so 50% votes)
      if (answer >= 0.50)

	{			//found winner so print the winner
	  printf ("the winner is %s ", candidatesArray[i].name);
	  //foundWinner is not true
	  //return true. the return stament is sent to variable foundWinner in main
	  return true;

	}
    }



  //find the one with the lowest number of votes 
  //runs if winner not found yet
  if (foundWinner == false)
    {
      int lowestVote = 1000;	//set to big number so that certainly the number of votes for lowest be lower than that and continue looking for lowest

//for going through as mcuh as there is candidates
      for (int i = 0; i < numCandidates; i++)
	{

	  //finding if it is the lowest number of votes
	  if (candidatesArray[i].votes < lowestVote)
	    {
	      //saves number to compare for lowest votes
	      lowestVote = candidatesArray[i].votes;

//sets candidateIndexToEliminate to be the index of the candidate with lowest votes
	      candidateIndexToEliminate = candidatesArray[i].index;

	    }

	}
//eliminates the candidate with lowest vote that found
      candidatesArray[candidateIndexToEliminate].eliminated = true;
      //false returned to foundWinner. because winner is not found. so loop will go again looking
      return false;
    }


}

//adds up the votes for the candidates based on the column on (accounts for eliminated candidates by not counting votes since those places have null)

void
countVotes (int numVoters, int numCandidates,
	    int **ranking, candidate * candidatesArray,
	    int numDivideByNumCandidates)
{
  for (int i = 0; i < numCandidates; i++)

    {

      candidatesArray[i].votes = 0;
    }

  int colNow;

  for (int row = 0; row < numVoters; row++)

    {
      colNow = 0;
      int indexHave = ranking[row][colNow];	//number seen in position (the number corresponds to an index for a candidate)


      while (candidatesArray[indexHave].eliminated == true)
	{
	  colNow++;
	  indexHave = ranking[row][colNow];
	}


      candidatesArray[indexHave].votes++;

    }

}

//function made to allocate memory (malloc) for 2D array so it is done controlled and accesible  

int **
alloc_2d (int m, int n)
{
  int **arr = malloc (m * sizeof (*arr));
  int i;
  for (i = 0; i < m; ++i)
    {
      arr[i] = malloc (n * sizeof (**arr));
    }
  return arr;
}
