#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


//Global Strings
char word [50];
char hint[50];
char guessed_letters[20];
char user_guess[] = "";
char blank[1] = "-";

//Global Integers
int random_number;
int word_len;
int user_input;
int attempts = 10;

//Function Declarations
void intro();
void start_game();
void get_input();
void print_blanks();
void draw_platform();
void get_word();
void print();
void extro();
void add_to_file();

int main(void)
{
    intro();
    //Game Loop
    while(1)
    {

        start_game();

        while(attempts > 0)
        {
            system("cls");

            //If they have guessed all the letters they win
            if(strlen(guessed_letters) == word_len )
            {
                print_blanks();
                break;
            }
            //Else, decr attempts and try again
            else
            {
                printf("Attempts Remaining: %i\n", attempts);
                printf("here is hint: %s\n",hint);
                printf("the length of word is : %i\n",strlen(word));
                print_blanks();
                get_input();
            }
        }

        system("cls");

        //If they won
        if(attempts > 0)
        {
            print_blanks();
            printf("\033[90m");
            print("YES,THE WORD IS ");
            printf("%s\n",word);
            printf("\033[1;32;5m");
            print("You Won !\n ");
            printf("\033[0m");
            Sleep(1500);
            printf("\033[36m");
            print(" Do you wanna Play again?\n");
            print("{0 - to exit;\n ");
            print(" 1 or any digit - play again}\n");
            printf("\033[0m");
        }
        //If they lost
        else
        {
            draw_platform();
            printf("\033[1;31;5m"); 
            print("You Lost!");
            printf("\033[0m");
            printf("\033[36m");
            print(" THE WORD WAS ");
            printf("%s\n",word);
            Sleep(1500);
            print("wanna Play again?\n");
            print("{0 - to exit;\n ");
            print(" 1 or any digit - play again}\n");
            printf("\033[0m");
        }

        scanf("%i", &user_input);

        switch(user_input)
        {
            case 0:
                system("cls");
                extro();
                return 0;
            default:
                continue;
        }
    }
}

void intro()
{
    printf("\033[0;32m"); // green color
    printf("****************************************************************\n");
    printf("############ WELCOME TO THE GAME HANG MAN ######################\n");
    printf("****************************************************************\n");

    printf("\033[36m");  //cyan colour
    printf("press 'Enter' to skip intro's \n");
    print("entering...");
    for(int i=0;i<5;i++)
    {
        printf(".");
        Sleep(1000);
    }

    // Clear the screen
    system("cls");

    printf("\033[0;31m"); // red color
    print("hahahahahahahahah............\n"
      " Haha, Player, you're funny! But hey, maybe you can show us how smart you are by playing a game?\n"
      "Yeah, Player, Let's play a game to see how clever you are!\n"
      "Alright, Player, let's see if you can guess the word in Hangman. It's a fun game, and you'll be great at it!\n");
    printf("\033[36m"); //cyan color
    print("press Enter");
    getchar();

    system("cls");

    printf("\033[0;32m"); // green color

    print("Alright, Player, here's the deal: you've got to guess a word\n"
       "but I'll give you a little hint to get you started. Every time you guess a wrong letter, things get a bit trickier\n"
       " But don't worry, you've got 10 chances to get it right\n"
       "So, think carefully and let's see if you can crack the code! Ready to give it a go?\n");
    printf("\033[0;31m"); // red
    print(":KINDLY ENTER LOWER CASE LETTERS ONLY :\n");
    printf("\033[36m"); // cyan
    print("press Enter");
   
    printf("\033[0m"); // default
    getchar();


    system("cls");

}

void extro()
{
    printf("\033[1;31m");
    print("Thank you for playing our game\n");
    Sleep(1000);
    system("cls");
    print("exiting...");
    for(int i=0;i<5;i++)
    {
        printf(".");
        Sleep(1000);
    }
    system("cls");
    printf("\033[0m");
}

void print(char c[])
{
    int n=strlen(c);
    for(int i=0;i<n;i++)
    {
        printf("%c",c[i]);
        Sleep(30);

        // Check if user pressed Enter
        if (_kbhit()) 
        {
            char ch = _getch();
            if (ch == '\r') 
            { // '\r' represents Enter key
                printf("%s", c + i + 1); // Print the remaining message without pauses
                break;
            }
        }
    }
}

void start_game()
{
    //Initializes Game
    get_word();
    word_len = strlen(word);
    memset(guessed_letters, 0, sizeof guessed_letters);
    attempts = 10;
}



void get_input()
{
    //Gets guess from user and checks
    //To see if that letter is in the word

    int i;
    int letter_hit = 0; //Used to tell if the guess letter is in the word

    printf("\033[36m");
    printf("\nYour guess: \n");
    printf("\033[0m");
    scanf(" %c", user_guess);

    for(i=0; i < word_len; i++)
    {
        if(user_guess[0] == word[i])
        {
            guessed_letters[i] = user_guess[0];
            letter_hit ++;
        }
    }

    if(letter_hit > 0)
    {
        return;
    }
    else
    {
        attempts --;
    }
}

void print_blanks()
{
    /////////////////////////////////////////////////
    /// Prints out a number of blanks equal to the
    /// Length of the word
    /// Then fills the blanks with the guessed letters
    /////////////////////////////////////////////////

    draw_platform();
    for (int i = 0; i < word_len; i++)
    {
        char display_char = '_';
        for (int j = 0; j < word_len; j++)
        {
            if (guessed_letters[j] == word[i])
            {
                display_char = guessed_letters[j];
                break;
            }
        }
        printf("%c ", display_char);
    }
    printf("\n");
}

void draw_platform()
{
    /////////////////////////////////////////////////
    /// Draws a new segment onto
    /// The platform every time
    /// The user gets a wrong guess
    /////////////////////////////////////////////////

    char *platform[]={

                     "      ===\n",

                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "   =====|\n"
                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "  |     |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "  |-    |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     "  |     |\n"
                     "       ===\n",

                     "   |=====|\n"
                     "   O     |\n"
                     "  -|-    |\n"
                     "  //     |\n"
                     "       ===\n"

    };

    switch(attempts)
    {
    case 9:
        printf("\n\n%s\n", platform[0]);
        break;
    case 8:
        printf("\n\n%s\n", platform[1]);
        break;
    case 7:
        printf("\n\n%s\n", platform[2]);
        break;
    case 6:
        printf("\n\n%s\n", platform[3]);
        break;
    case 5:
        printf("\n\n%s\n", platform[4]);
        break;
    case 4:
        printf("\n\n%s\n", platform[5]);
        break;
    case 3:
        printf("\n\n%s\n", platform[6]);
        break;
    case 2:
        printf("\n\n%s\n", platform[7]);
        break;
    case 1:
        printf("\n\n%s\n", platform[8]);
        break;
    case 0:
        printf("\n\n%s\n", platform[9]);
        break;
    }
}

void get_word()
{
    /////////////////////////////////////////////////
    /// Scans a file to get the total number of lines
    /// The line total is then used as a max range
    /// For the random number
    /// The word that is on the random line is the word
    /// That will be used for the game
    /////////////////////////////////////////////////

    int num_players;

    printf("\033[36m");
    print("Enter the no of players(1 or 2):\n");
    printf("\033[0m");
    scanf("%d",&num_players);

    if(num_players != 1)
    {
        if(num_players != 2)
        {
            print("enter valid number : 1 or 2");
        }
        else{
        print("player2 please enter the word:\n");
        scanf("%s",word);
        print("player2 please also provide a hint :\n");
        scanf("%s",hint);
        add_to_file();
        }

    }

    else if(num_players==1)
    {
        
        FILE *fp;
      int line_number = 0;
       char current_word[50];

        fp = fopen("dictionary.txt","r");

       if(fp == NULL)
      {
        perror("Error in opening file");
      }

      //While not end of file, incr line number
      while(fgets(current_word, 50, fp) != NULL)
      {
        line_number++;
      }

      srand(time(NULL));
      random_number = rand() % line_number;

      //Start from top of file
      rewind(fp);

      //Goes to whatever line the random number equals to find the
      //Random word
      for(line_number = 0; line_number != random_number; line_number++)
      {
        fgets(current_word, 50, fp);
      }

      int e;

      int len;
      len=strlen(current_word);

      char *comma_position = strchr(current_word, ',');
      if (comma_position != NULL) {
          // Copy word
          strncpy(word, current_word, comma_position - current_word);
          word[comma_position - current_word] = '\0';
          // Copy hint
          strcpy(hint, comma_position + 1);
          // Remove trailing newline character from hint
          hint[strcspn(hint, "\n")] = '\0';
      } else {
        // Handle case where comma is not found
        printf("Invalid format in line %d: No comma found.\n", random_number);
      }
      fclose(fp);
    }
}

void add_to_file()
{  
    FILE *fp;
    fp = fopen("dictionary.txt", "r+");
    if (fp == NULL) 
    {
        print("Error opening file.\n");
        return; // Return non-zero to indicate failure
    }

    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // Writing word and hint to the file
    fprintf(fp, "%s,%s\n", word, hint);

    fclose(fp);
    return ;
}