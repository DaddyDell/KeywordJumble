//Word Jumbler
#include <iostream>
#include <string>
#include <cstdlib> //random numbers
#include <ctime> //random number generator

using namespace std;

const string Words[10] =
{
    "hardware",
    "software",
    "adobe",
    "microsoft",
    "apple",
    "russia",
    "school",
    "honda",
    "toyota",
    "integrity"
};
const string Hints[10] =
{
    "The physical parts that make up a computer",
    "The magical parts the user plays with on a computer",
    "The company that created Photoshop",
    "The company that created Windows",
    "The company that created iPhone",
    "The USA's #1 enemy in the cold war",
    "The place that gives you homework",
    "The company who created the Accord and the Civic",
    "The company who created the #1 best selling car",
    "The trait anybody should have"
};


int main()
{
    srand(static_cast<unsigned int>(time(0)));
 
    int wins, tries, index, previousIndex1, previousIndex2;
    wins = 0;//Wins is the amount of correctly guessed words
    tries = 0; //tries is the number of attempts the user has given
TOP://The top of the loop. I tried to make this with a bunch of "for" loops and this seemed the best
    string wordToGuess, hint, jWord, guess;
    ///TO DO Add var to make it so there isnt repeats
    index = rand() % 10;//creates a random number between 0-9.
    if(wins == 0)
    {//On the first run through, set the current Index to previousIndex1
       previousIndex1 = index;
    }
    if(wins == 1)
    {//Already been through once
        while(index == previousIndex1)
        {//This makes it so that we don't get the same word.
            index = rand() % 10;//creates a random number between 0-9.
        }
       previousIndex2 = index; //Set it up so that we wont get that word again.
    }
    if(wins == 2)
    {//On the final run through
        while(index == previousIndex1 || index == previousIndex2)
        {//Check and make sure that we aren't repeating any words
            index = rand() % 10;//creates a random number between 0-9.
        }
    }
    
    wordToGuess = Words[index]; //The word we want to guess is in the Words array.
    hint = Hints[index];//The hint associated with the word is in the Hints array
    jWord = ""; //Set the jumbled word to "" for init. (not sure if it's needed, I just do it).
    guess = ""; //Set the guess to "" for init. (not sure if it's needed, I just do it).
    
    
    int length = wordToGuess.size(); //This gets the size of the word
    for(int i = 0; i < length; i++)
    {//Make a for loop that runs for the lenght of the word
        int index1 = (rand() % length);//Choose Random Character in word
        int index2 = (rand() % length);//Choose another random character in word
        
        char temp = wordToGuess[index1]; //Stores the first word so it's not lost.
        wordToGuess[index1] = wordToGuess[index2]; //Moves the character in index1 to index2
        wordToGuess[index2] = temp; //Moves what was in index2 to now be what was in index1
    }

    jWord = wordToGuess;//Jumbled word = word to guess that we just messed with.
    wordToGuess = Words[index]; //Set the word to guess back to the word.
    if(wins == 0)
    {//On the first run through....
        cout << "\n\n\n\t Welcome to Word Jumble! \n\n";
        cout << "Unscramble the letters to correctly guess the word \n";
        cout << "Input 'Hint' for a hint \n";
        cout << "Input 'Quit' to quit the game \n\n";
    }
    cout << "\n\nJumbled Word is " << jWord;
    
    do
    {//Do this while the user is guessing the word.
        cout << "\n\nYour Guess is: ";
        cin >> guess;//User inputs their guess
        
        ++tries;//Add another try, because obviously
        if(guess == "hint")
        {//Looking for hint
            cout << hint;
        }
        else if(guess == "quit")
        {//Looking to quit the game
            cout << "You have chosen to end the game. \n";
            cout << "Thank you for playing! ";
        }
        else if(guess == wordToGuess)
        {//The player guessed correctly
            wins += 1; //Add a win because they guessed the word
            int wordsLeft = 3 - wins; //This calculates how many words is left.
            cout << "Congrats, you have guessed the word in " << tries << " tries \n";
            cout << "There are "<< wordsLeft << " word(s) left" << endl;

            if(wins != 3)//If we have guessed less than 3, goto TOP, otherwise goto END;
                goto TOP;
            else
                goto END;
        }
        else
        {//Guessed incorrectly
            cout << "Sorry, that is not the correct guess.";
        }
    }
    while(guess != wordToGuess);
END:
    int triesToWords = (wins/tries);//This is a calculation just for fun
    cout << "\n\n\n\tHere are your results!" << endl;
    cout << "It took you "<< tries << " attempts to correctly" << endl;
    cout << "Guess 3 Jumbled Words." << endl;
    
    if(triesToWords >= 0.75 && triesToWords != 1)//If they scored 75%-99%
        cout << "You're pretty alright!" << endl;
    else if(triesToWords == 1) //If they scored 100%
        cout << "You're impecable!" << endl;
    else //If they scored anywhere below 75%
        cout << "You can do better and you know it..." << endl;
    
    cout << "Thank you for playing Word Jumble!" << endl;
    
    
    cin.ignore(); //This setup from here to the bottom aparently lets the enter key be hit
    cin.get(); //And everything exit and work fine without kicking the user out of the game.
    return 0;
}

