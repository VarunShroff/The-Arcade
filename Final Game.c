/**
* Authors: Varun Shroff
* Assignment Name: The Ultimate Arcade
* Date: June 9th, 2020
* Assignment Description:  This program allows the user to play not one, not two, but five different games with all the games taking advantage of the 8x8 Matrix display.
* 
*/

// Including Packages
#include <stdio.h> // Includes input output library
#include <stdlib.h> // Includes the standard library
#include <time.h> // Includes the time library
#include <unistd.h> // Includes the standard library
#include <string.h> // includes the string library that includes string compare
#include </usr/include/sys/io.h> // Includes the baseport library
#include <curses.h> // Included the curses library (Specifically the getch command we need)


// Defining Baseports
#define row 0x378
#define rowSelect 0x37A

// Defining Function Prototype
void Introduction();
int rollDice();
int pickImage();
int mathQuiz();
int guessNumber();
void choosGame();

// Defining Function Prototype Of Characters
void X();
void house();
void heart();
void person();
void crown();
void face();

// Global Varaibles
int numDisplay = 0;
int guess;
int userGuess;
char UserChoice;

// Charcter Display Arrays
unsigned char checkMark[8] = {0xFF, 0xFE, 0xFC, 0xF9, 0x73, 0x27, 0x8F, 0xDF}; 
unsigned char one[8] = {0xEF, 0xE7, 0xEB, 0xEF, 0xEF, 0xEF, 0xEF, 0x00}; 
unsigned char two[8] = {0x00, 0x7F, 0x7F, 0x7F, 0x00, 0xFE, 0xFE, 0x00}; 
unsigned char three[8] = {0x80, 0x7F, 0x7F, 0x7F, 0x80, 0x7F, 0x7F, 0x80}; 
unsigned char four[8] = {0x00, 0xFE, 0xFE, 0xFE, 0x00, 0x7F, 0x7F, 0x00}; 
unsigned char five[8] = {0xEF, 0xE7, 0xEB, 0xEF, 0xEF, 0xEF, 0xEF, 0x00}; 
unsigned char six[8] = {0x81, 0x7E, 0xFE, 0xFE, 0x00, 0x7E, 0x7E, 0x00}; 
unsigned char seven[8] = {0x00, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE}; 
unsigned char eight[8] = {{0x81, 0x7E, 0x7F, 0x81, 0x81, 0x7E, 0x7E, 0x81}; 
unsigned char nine[8] = {0x00, 0x7E, 0x7E, 0x00, 0x7F, 0x7F, 0x7F, 0x7F}; 
unsigned char house[8] = {0xC3, 0x81, 0x00, 0x00, 0x7E, 0x66, 0x66, 0x00};   // JUST PUT REAL COORDS AND WE DONE
unsigned char person[8] = {0xFF, 0xE7, 0xE7, 0x81, 0xE7, 0xE7, 0xDB, 0xBD}; 
unsigned char heart[8] = {0xFF, 0x99, 0x00, 0x00, 0x00, 0x81, 0xC3, 0xE7}; 
unsigned char face[8] = {0xDB, 0xDB, 0xDB, 0xDB, 0x7E, 0xBD, 0xDB, 0xE7}; 
unsigned char crown[8] = {0xA5, 0xA5, 0xA5, 0x81, 0x81, 0x81, 0x81, 0x81}; 


int main() {
	
	ioperm(row, 3, 1); // Requesting access to the baseport
	
	choosGame();
	
}
 int RollDice() {
     
	while(1) {
		// Getting the user's input
		printf("Roll Dice (Y or N)?\n");
		char ans = getchar();
		if (ans == 'y') {
			// If the user says 'y', the program calculates a new random integer and displays it
			numDisplay = rand() % 9 + 1;
			printf("You rolled a : %d\n", numDisplay);
			
			if (numDisplay == 1) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(one, row);
                        usleep(500);
                    }
                }
			} else if (numDisplay == 2) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(two, row);
                        usleep(500);
                    }
                }
			} else if (numDisplay == 3) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(three, row);
                        usleep(500);
                    }
                }
            } else if (numDisplay == 4) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(four, row);
                        usleep(500);
                    }
                }
			} else if (numDisplay == 5) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(five, row);
                        usleep(500);
                    }
                }
			} else if (numDisplay == 6) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(six, row);
                        usleep(500);
                    }
                }
			}
			else if (numDisplay == 7) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(seven, row);
                        usleep(500);
                    }
                }
			}
			else if (numDisplay == 8) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(eight, row);
                        usleep(500);
                    }
                }
			}
			else if (numDisplay ==9) {
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(nine, row);
                        usleep(500);
                    }
                }
			}
		
			// Waiting 1 second
			usleep(1000000);
			// Asking if the user wants to randomize again
			printf("Would You Like To Roll Again (Y Or N)?\n");
		} else if (ans == 'n') {
			// If the user answers 'n', then the program exits
			ioperm(row, 3, 0);
			return 0;			
		} else if (ans != '\n') {
			// If the user answers anything other than 'y','n', or '/n', then the program informs the user that their input was invalid
			printf("Invalid input, (y/n)\n");		
		}
		else if(ans == 'm') {
		    choosGame();
		}
	}
 }
 int pickImage() {
     printf("Pick A Number To Display the Corresponding Image on the Board (1-5)");
     while(1) {
     char ans = getchar();
     if(ans == 'm') {
         choosGame();
     }
     if(ans < 10) {
         
            if (ans == 1) { // Displays the house on matrix
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(house, row);
                        usleep(500);
                        }
                    }
                }
			else if (ans == 2) { // Displays the person on matrix
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(person, row);
                        usleep(500);
                        }
                    }
                }
			else if (ans == 3) { // Displays the heart on matrix
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(heart, row);
                        usleep(500);
                        }
                    }
                }
			else if (ans == 4) { // Displays the face on matrix
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(face, row);
                        usleep(500);
                        }
                    }
                }
			else if (ans == 5) { // Displays the crown on the matrix
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(crown, row);
                        usleep(500);
                    }
                }
         usleep(1000000);
         printf("Pick Another Number!, Or Press M To EXIT");
         
     }
     else {
         printf("Invalid Input!, Pick From (1-5)");
         X();
     }
     }
 }
 int mathQuiz() {
     
     // Local Varaibles
    int i;
    int response;
    int correctAnswers = 0;
    int incorrectAnswers = 0;

    printf("\nMath Quiz\n");
    printf("Please enter # of problems you would wish to try:");
    scanf("%d", &response);

    if(response == 0)
    {
        printf("\nThanks for playing!\n");
        choosGame();
        return 0;
    }

    for(i=0; i<response; i++)
    {
        int answer = 0;
        srand(time(NULL));
        int a = rand() % 12;
        int b = rand() % 12;
        printf("\n%d * %d = ",a ,b);
        scanf("%d", &answer);
        if((a * b) == answer){
            printf("\nCongratulations You are correct!\n");
            printf("**********************************");
            while(1){
                for(int i=0; i<8; i++) {
                    outb(i^0xB, rowSelect);
                    outb(checkMark, row);
                    usleep(500);
                }
            }
            correctAnswers++;
        }
        else{
            printf("Sorry you were incorrect!\n");
            printf("**********************************");
            while(1){
                for(int i=0; i<8; i++) {
                    outb(i^0xB, rowSelect);
                    outb(X, row);
                    usleep(500);
                }
            }
            incorrectAnswers++;
        }

    }
    printf("\n\nYour Results:\n\n\n");
    printf("Number Incorrect: %d\n", incorrectAnswers);
    printf("Number Correct: %d\n", correctAnswers);
    if(correctAnswers > incorrectAnswers){
        printf("You Passed!\nGood work!\n\n");
        printf("**********************************");
        while(1){
            for(int i=0; i<8; i++) {
                outb(i^0xB, rowSelect);
                outb(checkMark, row);
                usleep(500);
            }
        }
        choosGame();
        } else {
            printf("You did not pass!\nYou need more work!\n\n");
            printf("**********************************");
                while(1){
                    for(int i=0; i<8; i++) {
                        outb(i^0xB, rowSelect);
                        outb(X, row);
                        usleep(500);
                    }
                }
            choosGame();
            }
    return 0;
    }

 
 int guessNumber() {
     
     // Local Varaibles
	int counter;
	userGuess = rand() % 10 + 1;;
	
	while (guess != userGuess) {
		printf("Guess a number between 0 and 25\n");
		refresh();
		scanw("%i", guess);
		printf("%i", userGuess);

	//checks number when the numbers don't match
	
	if (guess == userGuess) {
		printf("Congrats, That's The Right Number!\n");
        while(1){
            for(int i=0; i<8; i++) {
                outb(i^0xB, rowSelect);
                outb(checkMark, row);
                usleep(500);
                }
            }
		choosGame();
        } else if (guess > 25 || guess < 1){
            printf("The number doesn't fall into the range! Try Again!\n");
            counter++;
            while(1){
                for(int i=0; i<8; i++) {
                    outb(i^0xB, rowSelect);
                    outb(X, row);
                    usleep(500);
                    }
                }
        } else {
            printf("Try again!");
            counter++;
            while(1){
                for(int i=0; i<8; i++) {
                    outb(i^0xB, rowSelect);
                    outb(X, row);
                    usleep(500);
                    }
                }
		
            }
	
	counter++;
	printf("Number of tries:%i", counter);
	
        }
	return 0;
     
 }
 void Introduction() {
     
     printf(" Welcome To The Arcade!\n");
     printf("**********************************");
     printf("* Pick Your Own Image  : Press 1 *");
     printf("* Dice Roll Game       : Press 2 *");
     printf("* mathQuiz Game        : Press 3 *");
     printf("* Guess The Number     : Press 4 *");
     printf("* Exit Perfection      : Press 5 *");
     printf("**********************************");
     
     
 }
 
 void choosGame() { // Main menu function to choose options
     
     Introduction(); // Calling Introduction Function
     
     UserChoice = getchar();
	
	switch (UserChoice) { // Switch statemnet
	    
	    case '1' : pickImage(); // If input is '1', runs pickImage()
	    break;
	    
	    case '2' : rollDice();  // If input is '2', runs rollDice
	    break;
	    
	    case '3' : mathQuiz();  // If input is '3', runs mathQuiz()
	    break;
	    
	    case '4': guessNumber();  // If input is '4', runs guessNumber()
	    break;
	    
	    case '5' : ioperm(row, 3 , 0);  // If input is '5', removes i/o permsission
	    break;
	    
	    default : printf("Invalid Option"); // Default input if user doesn't use one of the following
	    choosGame();
	   
	   
	}
     
 }

