/* ---------------------------------------------
Program 2: Wumpus, version 2 (bats, arrow, and all arrays are dynamic)
Course: CS 211, Fall 2022. Tues 4pm lab
System: Windows using Replit and OnlineGDB
Author: Rafay Khan
---------------------------------------------
*/
#include <stdio.h>		// include the input/output related functions in our program.
#include <stdlib.h>		// for srand and malloc
//--------------------------------------------------------------------------------
void
displayCave ()
{				// displays the cave.
  printf ("       ______18______             \n"
	  "      /      |       \\           \n"
	  "     /      _9__      \\          \n"
	  "    /      /    \\      \\        \n"
	  "   /      /      \\      \\       \n"
	  "  17     8        10     19       \n"
	  "  | \\   / \\      /  \\   / |    \n"
	  "  |  \\ /   \\    /    \\ /  |    \n"
	  "  |   7     1---2     11  |       \n"
	  "  |   |    /     \\    |   |      \n"
	  "  |   6----5     3---12   |       \n"
	  "  |   |     \\   /     |   |      \n"
	  "  |   \\       4      /    |      \n"
	  "  |    \\      |     /     |      \n"
	  "  \\     15---14---13     /       \n"
	  "   \\   /            \\   /       \n"
	  "    \\ /              \\ /        \n"
	  "    16---------------20           \n" "\n");
}				// end displayCave()

//--------------------------------------------------------------------------------
void
displayInstructions ()
{				// displays the instructions of the game.
  printf ("Hunt the Wumpus:                                             \n"
	  "The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
	  "room has 3 tunnels leading to other rooms.                   \n"
	  "                                                             \n"
	  "Hazards:                                                     \n"
	  "1. Two rooms have bottomless pits in them.  If you go there you fall "
	  "and die.   \n"
	  "2. Two other rooms have super-bats.  If you go there, the bats grab "
	  "you and     \n"
	  "   fly you to some random room, which could be troublesome.  Then "
	  "those bats go \n"
	  "   to a new room different from where they came from and from the "
	  "other bats.   \n"
	  "3. The Wumpus is not bothered by the pits or bats, as he has sucker "
	  "feet and    \n"
	  "   is too heavy for bats to lift.  Usually he is asleep.  Two things "
	  "wake       \n"
	  "    him up: Anytime you shoot an arrow, or you entering his room.  "
	  "The Wumpus   \n"
	  "    will move into the lowest-numbered adjacent room anytime you "
	  "shoot an arrow.\n"
	  "    When you move into the Wumpus' room, then he wakes and moves if "
	  "he is in an \n"
	  "    odd-numbered room, but stays still otherwise.  After that, if he "
	  "is in your \n"
	  "    room, he snaps your neck and you die!                            "
	  "           \n"
	  "                                                                     "
	  "           \n"
	  "Moves:                                                               "
	  "           \n"
	  "On each move you can do the following, where input can be upper or "
	  "lower-case:  \n"
	  "1. Move into an adjacent room.  To move enter 'M' followed by a "
	  "space and       \n"
	  "   then a room number.                                               "
	  "           \n"
	  "2. Shoot your guided arrow through a list of up to three adjacent "
	  "rooms, which  \n"
	  "   you specify.  Your arrow ends up in the final room.               "
	  "           \n"
	  "   To shoot enter 'S' followed by the number of rooms (1..3), and "
	  "then the      \n"
	  "   list of the desired number (up to 3) of adjacent room numbers, "
	  "separated     \n"
	  "   by spaces. If an arrow can't go a direction because there is no "
	  "connecting   \n"
	  "   tunnel, it ricochets and moves to the lowest-numbered adjacent "
	  "room and      \n"
	  "   continues doing this until it has traveled the designated number "
	  "of rooms.   \n"
	  "   If the arrow hits the Wumpus, you win! If the arrow hits you, you "
	  "lose. You  \n"
	  "   automatically pick up the arrow if you go through a room with the "
	  "arrow in   \n"
	  "   it.                                                               "
	  "           \n"
	  "3. Enter 'R' to reset the person and hazard locations, useful for "
	  "testing.      \n"
	  "4. Enter 'C' to cheat and display current board positions.           "
	  "           \n"
	  "5. Enter 'D' to display this set of instructions.                    "
	  "           \n"
	  "6. Enter 'P' to print the maze room layout.                          "
	  "           \n"
	  "7. Enter 'X' to exit the game.                                       "
	  "           \n"
	  "                                                                     "
	  "           \n"
	  "Good luck!                                                           "
	  "           \n" " \n\n");
}				// end displayInstructions()

//--------------------------------------------------------------------------------
int
main (void)
{
//Dynamic array allocation for the 2d array.
  int **caveRooms = malloc (sizeof (int *) * 21);
  for (int i = 0; i < 21; i++)
    {
      caveRooms[i] = malloc (sizeof (int) * 3);
    }
  // hard coded room numbers
  caveRooms[0][0] = 0;   caveRooms[6][0] = 5;   caveRooms[12][0] = 3;   caveRooms[18][0] = 9;
  caveRooms[0][1] = 0;   caveRooms[6][1] = 7;   caveRooms[12][1] = 11;  caveRooms[18][1] = 17;
  caveRooms[0][2] = 0;   caveRooms[6][2] = 15;  caveRooms[12][2] = 13;  caveRooms[18][2] = 19;
  caveRooms[1][0] = 2;   caveRooms[7][0] = 6;   caveRooms[13][0] = 12;  caveRooms[19][0] = 11;
  caveRooms[1][1] = 5;   caveRooms[7][1] = 8;   caveRooms[13][1] = 14;  caveRooms[19][1] = 18;
  caveRooms[1][2] = 8;   caveRooms[7][2] = 17;  caveRooms[13][2] = 20;  caveRooms[19][2] = 20;
  caveRooms[2][0] = 1;   caveRooms[8][0] = 1;   caveRooms[14][0] = 4;   caveRooms[20][0] = 13;
  caveRooms[2][1] = 3;   caveRooms[8][1] = 7;   caveRooms[14][1] = 13;  caveRooms[20][1] = 16;
  caveRooms[2][2] = 10;  caveRooms[8][2] = 9;   caveRooms[14][2] = 15;  caveRooms[20][2] = 19;
  caveRooms[3][0] = 2;   caveRooms[9][0] = 8;   caveRooms[15][0] = 6;
  caveRooms[3][1] = 4;   caveRooms[9][1] = 10;  caveRooms[15][1] = 14;
  caveRooms[3][2] = 12;  caveRooms[9][2] = 18;  caveRooms[15][2] = 16;
  caveRooms[4][0] = 3;   caveRooms[10][0] = 2;  caveRooms[16][0] = 15;
  caveRooms[4][1] = 5;   caveRooms[10][1] = 9;  caveRooms[16][1] = 17;
  caveRooms[4][2] = 14;  caveRooms[10][2] = 11; caveRooms[16][2] = 20;
  caveRooms[5][0] = 1;   caveRooms[11][0] = 10; caveRooms[17][0] = 7;
  caveRooms[5][1] = 4;   caveRooms[11][1] = 12; caveRooms[17][1] = 16;
  caveRooms[5][2] = 6;   caveRooms[11][2] = 19; caveRooms[17][2] = 18;
  
   // srand(time(0)); // Seed the random number generator un comment it if you
  // wanna play with the random number room spawn.
  srand (1);			// to test with the designated rooms for each hazzards, player and arrow. .
  int randomValue =		// How to get a random number
    rand () % 20 + 1;		// Using +1 gives random number 1..20 rather than 0..19.
  int number = 0;		// to use the input that the person enter to move.
  char direction;		// its used to take characters as an input eg: D,P,X, etc.
  int count = 1;		// used to count the number of time it says enter your move.
  int gameOver = 0;		// to end the game and exit.
  int killWumpus;		// to guess the wumpus and catch em.
  int pit1 = randomValue;	// for the pit1 and to be at random room.
  int pit2 = randomValue;	// for the pit2 and to be at random room.
  int wumpus = randomValue;	// for the wumpus and to be at random room.
  int player = randomValue;	// for the player and to be at random room.
  int bats1 = randomValue;	// for the bats1 and to be at random room.
  int bats2 = randomValue;	// for the bats2 and to be at random room.
  int arrow = randomValue;	// for the arrow and to be at random room.
  int shootRoom = 0;		// number of rooms to shoot in.
  int shoot1 = 0;		// if player wanna shoot in 1 room
  int shoot2 = 0;		// if player wanna shoot in 2 rooms
  int shoot3 = 0;		// if player wanna shoot in 3 rooms
  while (wumpus == player)
    {				// loop for the wumpus to not be the same as player b/c
      // we cant have same rooms in the begining.
      wumpus = rand () % 20 + 1;
    }

  while (pit1 == player || pit1 == wumpus)
    {				// loop for the pit1 to not be the same as player or wumpus
      // b/c we cant have same rooms in the begining.
      pit1 = rand () % 20 + 1;
    }

  while (pit2 == player || pit2 == wumpus || pit2 == pit1)
    {				// loop for the pit2 to not be the same as player
      // or wumpus or pit1 b/c we cant have same rooms in the begining. 
      pit2 = rand () % 20 + 1;
    }
  while (bats1 == player || bats1 == wumpus || bats1 == pit1 || bats1 == pit2)
    {				// loop for the bats1 to not be the same as player
      // or wumpus or pit1 or pit2 b/c we cant have same rooms in the begining.
      bats1 = rand () % 20 + 1;
    }
  while (bats2 == player || bats2 == wumpus || bats2 == pit1 || bats2 == pit2
	 || bats2 == bats1)
    {				// loop for the bats2 to not be the same as player
      // or wumpus or pit1 or pit2 or bats1 b/c we cant have same rooms in the begining.
      bats2 = rand () % 20 + 1;
    }
  while (arrow == pit1 || arrow == pit2 || arrow == bats1 || arrow == bats2 ||
	 arrow == wumpus || arrow == player)
    {				// loop for the arrow to not be the same as pit1 or pit2 or bats1 or bats2 or wumpus or player
      // b/c we cant have same rooms in the begining.
      arrow = rand () % 20 + 1;
    }
  while (gameOver == 0)
    {				// loop which has all the functions.

      printf ("You are in room %d. ", player);	// print which room you are in.
      if (wumpus == caveRooms[player][0] || wumpus == caveRooms[player][1] ||
	  wumpus == caveRooms[player][2])
	{			// if you are next to a room which has
	  // wumpus in it.
	  printf ("You smell a stench. ");
	}
      if (pit1 == caveRooms[player][0] || pit1 == caveRooms[player][1] ||
	  pit1 == caveRooms[player][2])
	{			// if you are next to a room which has
	  // pit1 in it.
	  printf ("You feel a draft. ");
	}

      if (pit2 == caveRooms[player][0] || pit2 == caveRooms[player][1] ||
	  pit2 == caveRooms[player][2])
	{			// if you are next to a room which has
	  // pit2 in it.
	  printf ("You feel a draft. ");
	}
      if (bats1 == caveRooms[player][0] || bats1 == caveRooms[player][1] ||
	  bats1 == caveRooms[player][2])
	{			// if you are next to a room which has
	  // bats1 in it.
	  printf ("You hear rustling of bat wings. ");
	}
      if (bats2 == caveRooms[player][0] || bats2 == caveRooms[player][1] ||
	  bats2 == caveRooms[player][2])
	{			// if you are next to a room which has
	  // bats2 in it.
	  printf ("You hear rustling of bat wings. ");
	}
      printf ("\n\n%d. Enter your move (or 'D' for directions): ", count);	// prompt for user to enter their move.
      scanf (" %c", &direction);
      if (direction == 'D' || direction == 'd')
	{			// takes character input to show directions.
	  printf ("\n");
	  displayCave ();
	  displayInstructions ();
	}
      else if (direction == 'P' || direction == 'p')
	{			// takes character input to print maze.
	  printf ("\n");
	  displayCave ();
	}
      else if (direction == 'X' || direction == 'x')
	{			// takes character input to exit.
	  gameOver = 1;
	  printf ("\nExiting Program ...\n");
	}

      else if (direction == 'C' || direction == 'c')
	{			// takes character input and print the cheat.
	  printf ("Cheating! Game elements are in the following rooms: \n");
	  printf ("Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow \n");
	  printf ("%4d %5d %6d %5d %5d %5d %5d \n\n", player, wumpus, pit1,
		  pit2, bats1, bats2, arrow);
	}
      if (direction == 'M' || direction == 'm')
	{			// takes character input and room number to move the
	  // player to.
	  scanf (" %d", &number);
	  if (number == caveRooms[player][0] || number == caveRooms[player][1]
	      || number == caveRooms[player][2])
	    {
	      player = number;
	      count++;
	    }
	  else
	    {
	      printf ("Invalid move.  Please retry. \n");
	    }

	}

      else if (direction == 'R' || direction == 'r')
	{			// takes character input to reset the player
	  // room, wumpus, pit1, pit2, bats1, bats2, arrow.
	  int *resplayer, reswumpus, respit1, respit2, resbats1, resbats2,
	    resarrow;
	  printf
	    ("Enter the room locations (1..20) for player, wumpus, pit1, pit2, "
	     "bats1, bats2, and arrow: \n");
	  printf ("\n");
	  scanf (" %d %d %d %d %d %d %d", &resplayer, &reswumpus, &respit1,
		 &respit2, &resbats1, &resbats2, &resarrow);
	  player = resplayer;
	  wumpus = reswumpus;
	  pit1 = respit1;
	  pit2 = respit2;
	  bats1 = resbats1;
	  bats2 = resbats2;
	  arrow = resarrow;
	}
      else if (direction == 'G' || direction == 'g')
	{			// takes character input to guess the wumpus.
	  printf ("Enter room (1..20) you think Wumpus is in: ");
	  scanf (" %d", &killWumpus);
	  if (killWumpus == wumpus)
	    {
	      printf ("You won!\n");
	      gameOver = 1;
	      printf ("\nExiting Program ...\n");
	    }
	  else
	    {
	      printf ("You lost.\n");
	      gameOver = 1;
	      printf ("\nExiting Program ...\n");
	    }
	}
      else if (direction == 'S' || direction == 's')
	{			// takes character input to shoot the arrow.
	  if (arrow == -1)	// to see if the player has the arrow then run the conditions.
	    {
	      printf
		("Enter the number of rooms (1..3) into which you want to shoot, "
		 "followed by the rooms themselves: ");
	      scanf (" %d", &shootRoom);
	      if (shootRoom == 1)	// if player want to shoot in 1 room.
		{
		  scanf (" %d", &shoot1);
		  if (shoot1 == caveRooms[player][0] ||
		      shoot1 == caveRooms[player][1] ||
		      shoot1 == caveRooms[player][2] || shoot1 == player)
		    {		// if the rooom enter is adjacent to where the player is already in then shoot arrow to that room.
		      arrow = shoot1;
		      if (arrow == wumpus)
			{	// if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot1 != caveRooms[player][0] ||
			   shoot1 != caveRooms[player][1] ||
			   shoot1 != caveRooms[player][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room. 
		      printf ("Room %d is not adjacent.  Arrow ricochets...\n", shoot1);	// if it moves to adjacent it ricocheted.
		      arrow = caveRooms[player][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  wumpus = caveRooms[wumpus][0];	// if arrow misses the wumpus then wumpus move to the lowest adjacent room of itself.
		}

	      else if (shootRoom == 2)
		{		// if player wanna shoot in 2 rooms.
		  scanf (" %d %d", &shoot1, &shoot2);
		  if (shoot1 == caveRooms[player][0] ||
		      shoot1 == caveRooms[player][1] ||
		      shoot1 == caveRooms[player][2])
		    {		// if the rooom enter is adjacent to where the player is already in then shoot arrow to that room.
		      arrow = shoot1;
		      if (arrow == wumpus)
			{	// if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot1 != caveRooms[player][0] ||
			   shoot1 != caveRooms[player][1] ||
			   shoot1 != caveRooms[player][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room.
		      printf ("Room %d is not adjacent.  Arrow ricochets...\n", shoot1);	// if it moves to adjacent it ricocheted.
		      arrow = caveRooms[player][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  if (shoot2 == caveRooms[arrow][0]
		      || shoot2 == caveRooms[arrow][1]
		      || shoot2 == caveRooms[arrow][2])
		    {		// if the rooom enter is adjacent to where the arrow is already in then shoot arrow to that room.
		      arrow = shoot2;
		      if (arrow == wumpus)
			{	//if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot2 != caveRooms[arrow][0] ||
			   shoot2 != caveRooms[arrow][1] ||
			   shoot2 != caveRooms[arrow][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room.
		      printf
			("Room %d is not adjacent.  Arrow ricochets...\n",
			 shoot2);
		      arrow = caveRooms[arrow][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if it ricochets and hit player display accidentaly shot yourself and died and exit.
			  printf ("You just shot yourself, and are dying.\n"
				  "It didn't take long, you're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  wumpus = caveRooms[wumpus][0];	// if arrow misses the wumpus then wumpus move to the lowest adjacent room of itself.
		}
	      else if (shootRoom == 3)
		{		// if player wanna shoot in 3 rooms.
		  scanf (" %d %d %d", &shoot1, &shoot2, &shoot3);
		  if (shoot1 == caveRooms[player][0] ||
		      shoot1 == caveRooms[player][1] ||
		      shoot1 == caveRooms[player][2])
		    {		// if the rooom enter is adjacent to where the player is already in then shoot arrow to that room.
		      arrow = shoot1;
		      if (arrow == wumpus)
			{	//if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot1 != caveRooms[player][0] ||
			   shoot1 != caveRooms[player][1] ||
			   shoot1 != caveRooms[player][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room.
		      printf
			("Room %d is not adjacent.  Arrow ricochets...\n",
			 shoot1);
		      arrow = caveRooms[player][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  if (shoot2 == caveRooms[arrow][0]
		      || shoot2 == caveRooms[arrow][1]
		      || shoot2 == caveRooms[arrow][2])
		    {		// if the rooom enter is adjacent to where the arrow is already in then shoot arrow to that room.
		      arrow = shoot2;
		      if (arrow == wumpus)
			{	//if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot2 != caveRooms[arrow][0] ||
			   shoot2 != caveRooms[arrow][1] ||
			   shoot2 != caveRooms[arrow][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room.
		      printf
			("Room %d is not adjacent.  Arrow ricochets...\n",
			 shoot2);
		      arrow = caveRooms[arrow][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if it ricochets and hit player display accidentaly shot yourself and died and exit.
			  printf ("You just shot yourself, and are dying.\n"
				  "It didn't take long, you're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  if (shoot3 == caveRooms[arrow][0]
		      || shoot3 == caveRooms[arrow][1]
		      || shoot3 == caveRooms[arrow][2])
		    {		// if the rooom enter is adjacent to where the arrow is already in then shoot arrow to that room.
		      arrow = shoot3;
		      if (arrow == wumpus)
			{	//if arrow hits wumpus display you won and exit.
			  printf
			    ("Wumpus has just been pierced by your deadly arrow! \n"
			     "Congratulations on your victory, you awesome hunter you.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if arrow hits player display you died and exit.
			  printf ("You just shot yourself.  \n"
				  "Maybe Darwin was right.  You're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  else if (shoot3 != caveRooms[arrow][0] ||
			   shoot3 != caveRooms[arrow][1] ||
			   shoot3 != caveRooms[arrow][2])
		    {		// if room entered is not adjacent then arrow moves to lowest adjacent room.
		      printf
			("Room %d is not adjacent.  Arrow ricochets...\n",
			 shoot3);
		      arrow = caveRooms[arrow][0];
		      if (arrow == wumpus)
			{	// if it ricochets and hit wumpus display accidental victory and exit.
			  printf
			    ("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
			     "Accidental victory, but still you win!\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		      else if (arrow == player)
			{	// if it ricochets and hit player display accidentaly shot yourself and died and exit.
			  printf ("You just shot yourself, and are dying.\n"
				  "It didn't take long, you're dead.\n");
			  gameOver = 1;
			  printf ("\nExiting Program ...\n");
			}
		    }
		  wumpus = caveRooms[wumpus][0];	// if arrow misses the wumpus then wumpus move to the lowest adjacent room of itself.
		}
	      else
		{		// if you enter more than 3 rooms to shoot in.
		  printf
		    ("Sorry, the max number of rooms is 3.  Setting that value to "
		     "3.\n");
		}
	    }
	  else
	    {			// if you try to shoot arrow when you dont have it.
	      printf
		("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
	    }
	  count++;
	}
      if (player == wumpus)
	{			// if a player gets in the even room where the
	  // wumpus is in.(ps: you dieeeeeeee)
	  if (player % 2 == 0)
	    {
	      printf
		("You briefly feel a slimy tentacled arm as your neck is snapped. \n"
		 "It is over.\n");
	      gameOver = 1;
	      printf ("\nExiting Program ...\n");

	    }
	  else if (player % 2 != 0)
	    {			// if a player gets in the odd room where
	      // the wumpus is in then the wumpus move to
	      // the least room.(ps: you got lucky..)
	      wumpus = caveRooms[player][0];
	      printf
		("You hear a slithering sound, as the Wumpus slips away. \n"
		 "Whew, that was close! \n");
	    }
	}
      else if (player == arrow && gameOver == 0)
	{
	  printf
	    ("Congratulations, you found the arrow and can once again shoot.\n");
	  arrow = -1;
	}
      else if (player == pit1)
	{			// If you get in the room where the pit1 is in.
	  printf ("Aaaaaaaaahhhhhh....   \n");
	  printf ("    You fall into a pit and die. \n");
	  gameOver = 1;
	  printf ("\nExiting Program ...\n");
	}
      else if (player == pit2)
	{			// If you get in the room where the pit2 is in.
	  // (ps: you trip and die...)
	  printf ("Aaaaaaaaahhhhhh....   \n");
	  printf ("    You fall into a pit and die. \n");
	  gameOver = 1;
	  printf ("\nExiting Program ...\n");
	}
      else if (player == bats1)
	{			// if you get in the room where the bats1 is then you fly and get moved to a random room.
	  int batSame = bats1;
	  printf ("Woah... you're flying!   \n");
	  player = rand () % 20 + 1;
	  printf ("You've just been transported by bats to room %d. \n",
		  player);
	  bats1 = rand () % 20 + 1;
	  while (bats1 == player || batSame == bats1)	//after dropping the player bats also goes to a new random room.
	    bats1 = randomValue;
	}
      else if (player == bats2)
	{			// if you get in the room where the bats2 is then you fly and get moved to a random room.
	  int batSame = bats2;
	  printf ("Woah... you're flying!   \n");
	  player = rand () % 20 + 1;
	  printf ("You've just been transported by bats to room %d. \n",
		  player);
	  bats2 = rand () % 20 + 1;
	  while (bats2 == player || batSame == bats1)	//after dropping the player bats also goes to a new random room.
	    bats2 = randomValue;
	}
    }
  // freeing the dynamic allocated array.
  for (int i = 0; i < 21; i++)
    {
      free (caveRooms[i]);
    }
  free (caveRooms);
  return 0;			// the function doesn't return any value.
}