README File:

Project Title:
Hangman Game

Description:
# This project is a command-line implementation of the classic Hangman game written in C. 
# The game randomly selects a word from a predefined dictionary file or allows two players to input their own word and hint.
# Players have to guess the word by entering letters, with a limited number of attempts allowed.

Features:
1.Single-player and two-player modes
2.Random word selection from a dictionary file
3.Custom word input with hints
4.ASCII art representation of the Hangman figure
5.Visual feedback on guessed letters and remaining attempts

Setup:
1.Clone the repository to your local machine.
2.Compile the hangman.c file using a C compiler.
3.Run the compiled executable file to start the game.

Usage:
1.Follow the on-screen instructions to play the game.
2.For single-player mode, enter the number of players as 1 and guess the word provided with the hint.
3.For two-player mode, enter the number of players as 2, and each player should input a word and hint in turn.
4.Guess letters to uncover the word, and avoid exceeding the maximum allowed attempts.

Dependencies:
1.Standard C libraries: stdio.h, stdlib.h, string.h, time.h .
2.Windows-specific libraries: windows.h, conio.h .


Libraries Included:
<stdio.h>: For standard input and output functions.
<stdlib.h>: For memory allocation, process control, and other general utilities.
<time.h>: For time-related functions, used for generating random numbers.
<string.h>: For string manipulation functions like strlen, strcpy, etc.
<windows.h>: Windows-specific library for console input/output and other system-related functions.
<conio.h>: Windows-specific library for console input/output functions.

Global Variables:
word: Array to store the word to be guessed.
hint: Array to store the hint for the word.
guessed_letters: Array to store the letters guessed by the user.
user_guess: Array to store the user's current guess.
blank: Array with a single dash character, used for printing blanks.
random_number: Variable to store a randomly generated number.
word_len: Variable to store the length of the word.
user_input: Variable to store user input for menu options.
attempts: Variable to store the number of attempts remaining.

Function Declarations:
void intro(): Displays the game introduction.
void start_game(): Initializes the game.
void get_input(): Gets user input for guessing letters.
void print_blanks(): Prints blanks and fills in guessed letters.
void draw_platform(): Draws the hangman platform based on the number of attempts remaining.
void get_word(): Retrieves a word from a file or takes input from the user.
void print(char c[]): Prints characters with a slight delay.
void extro(): Displays the outro message and exits the game.
void add_to_file(): Adds a word and its hint to the dictionary file.

Main Function:
Initiates the game loop and handles menu options for playing again or exiting.
Calls functions like intro(), start_game(), print_blanks(), get_input(), etc., within the game loop to manage gameplay.

Other:
The code uses escape sequences for color formatting in the console output.
The hangman platform is drawn using ASCII art stored in the platform array.
The game reads words and hints from a file named "dictionary.txt" or takes input from the user if playing with two players.

#######################  How to Play Hangman:  #######################

Objective: Guess the hidden word before running out of attempts.

Getting Started:
Launch the Hangman game.
You'll be provided with a hint to help you guess the word. Pay attention to it as it offers valuable clues.

Guessing Letters:
Enter a lowercase letter as your guess and press Enter.
Correct guesses reveal the letter's positions in the word.
Incorrect guesses result in losing one attempt and drawing part of the hangman figure.

Hangman Figure:
With each incorrect guess, a new part of the hangman figure is drawn.
The hangman figure represents your progress and remaining attempts.

Word Completion:
Continue guessing letters until you've correctly guessed the entire word.
Win the game by guessing all the letters before running out of attempts.

Running Out of Attempts:
Be cautious with your guesses! If you use up all your attempts before guessing the word, you lose the game.

End of Game:
Winning: Celebrate your victory if you correctly guess the word!
Losing: Don't worry if you don't guess the word in time. You can always try again for another chance at victory.

Menu Options:
After each game, you'll see menu options:
Enter '0' to exit the game.
Enter any other digit to play again.

#########################################################  END ############################################3

