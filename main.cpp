#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

void PrintCharacterStats(Character* inputCharacter) { //show stats of character

    cout << "\tCharacter Name: " << inputCharacter->GetName() << endl;

    if (inputCharacter->GetType() == WARRIOR) {
        cout << "\tCharacter Type: " << "Warrior" << endl;
        Warrior* warriorCharacter = dynamic_cast<Warrior*>(inputCharacter);
        cout << "\tAllegiance: " << warriorCharacter->GetAllegiance() << endl;
    }
    else if (inputCharacter->GetType() == ELF) {
        cout << "\tCharacter Type: " << "Elf" << endl;
        Elf* elfCharacter = dynamic_cast<Elf*>(inputCharacter);
        cout << "\tFamily: " << elfCharacter->GetFamily() << endl;
    }
    else {  //userCharacter.GetType() == Wizard
        cout << "\tCharacter Type: " << "Wizard" << endl;
        Wizard* wizardCharacter = dynamic_cast<Wizard*>(inputCharacter);
        cout << "\tRank: " << wizardCharacter->GetRank() << endl;
    }

    cout << "\tHealth: " << inputCharacter->GetHealth() << endl << endl;
}

bool GuessingGame(string keyword) {
    //write outside of the function the rules to guess correctly
    string guessAttempt;

    cin >> guessAttempt;
    for (unsigned int i = 0; i < guessAttempt.size(); ++i) {
        guessAttempt.at(i) = toupper(guessAttempt.at(i));
    }

    for (unsigned int i = 0; i < 3; ++i) {
        if (guessAttempt == keyword) { //return true if correct
            cout << "CORRECT!" << endl;
            return true;
        }
        else if (i <= 1) {
            cout << "INCORRECT! Try Again:" << endl;
            cin >> guessAttempt;
            for (unsigned int i = 0; i < guessAttempt.size(); ++i) {
                guessAttempt.at(i) = toupper(guessAttempt.at(i));
            }
        }
        else {
            return false;
        }
    }
    return false;
}

    Character* StartMenu(string & ally) {
    cout << "Welcome to Medieval Fight Simulator!" << endl;

    cout << "Please enter your name: ";
    string userName;
    getline(cin, userName);

    cout << "Please Create your character by answering the prompts below:" << endl;
    cout << "Choose a Character Type:" << endl;
    cout << "\t 1. Warrior" << endl;
    cout << "\t 2. Elf" << endl;
    cout << "\t 3. Wizard" << endl;

    cout << "Choose an option: ";

    unsigned int characterType;
    cin >> characterType;
    cout << endl;

    while (characterType != 1 && characterType != 2 && characterType != 3) {    //characterType != (1 && 2 && 3)
        cout << "Please choose a valid numerical option:" << endl;
        cin >> characterType;
    }

    cin.ignore();

    ally = "The Joes";

    Character* userCharacter = nullptr;

    if (characterType == 1) { //Warrior
        
        cout << "Choose a name for your Warrior's Allegiance (e.g. Prince Wales, Queen Victoria, Sir Nottinghham, etc.):" << endl;
        string userAllegiance;
        getline(cin, userAllegiance);

        cout << "Choose a number between from 1 to 10" << endl;

        int baseAttack;
        cin >> baseAttack;
        cin.ignore();

        int userAttackStrength = baseAttack + rand() % 11;

        cout << "Your attack strength is " << userAttackStrength << "." << endl;

        cout << "Please enter your character's name:" << endl;

        string characterName;
        getline(cin, characterName);
        cout << endl;

        Warrior* warriorCharacter = new Warrior(characterName, 100, userAttackStrength, userAllegiance);
        userCharacter = warriorCharacter;

        cout << endl;  
        cout << userName << "'s character:" << endl;
        PrintCharacterStats(userCharacter);

        ally = userAllegiance;
    }
    else if (characterType == 2) {//Elf
        cout << "Choose a name for your Elf's family:" << endl;

        string userElfFamily;
        getline(cin, userElfFamily);

        cout << "Choose a number between from 1 to 10" << endl;

        int baseAttack;
        cin >> baseAttack;
        cin.ignore();

        int userAttackStrength = baseAttack + rand() % 11;

        cout << "Your attack strength is " << userAttackStrength << "." << endl;

        cout << "Please enter your character's name:" << endl;

        string characterName;
        getline(cin, characterName);
        cout << endl;

        Elf* elfCharacter = new Elf(characterName, 100, userAttackStrength, userElfFamily);
        userCharacter = elfCharacter;

        cout << endl << endl;      
        cout << userName << " 's character:" << endl << endl;
        PrintCharacterStats(userCharacter);

        ally = userElfFamily;

    }
    else { //if characterType == 3 => Wizard
        cout << "When creating a new wizard character, Your rank starts at 1. If fighting a wizard character, " << endl;
        cout << "the ratio between your rank and your opponents rank will determine your attack strength. " << endl;
        cout << "To receive an additonal starting bonus added to your rank, guess my favorite cheese. You get 3 tries." << endl << endl;
        cout << "Enter your attempt:" << endl;

        string favoriteCheese = "CHEDDAR";
       
        bool correctGuess = GuessingGame(favoriteCheese);

        int rankBonus;

        if (correctGuess) {
            cout << endl << "Congratulations! You get to roll the dice, to which your rank bonus will be randomly added. " << endl; 
            cout << "You will receive additional 1 to 6 points added to your rank." << endl << endl;

            cout << "Rolling...." << endl << endl;

            this_thread::sleep_for(chrono::seconds(3));

            rankBonus = (rand() % 7) + 1;
            cout << "You rolled a " << rankBonus << "! This is your additonal points." << endl;
        }
        else { //incorrect Guess
            cout << endl << "Sorry, you did not guess the correct answer within the allotted tries." << endl;
            rankBonus = 0;
        }

        int userRank = rankBonus + 1;

        cout << "Your wizard now has a starting rank of 1 + " << rankBonus << ", for a total of " << userRank << "." << endl << endl;

        cout << "Now, choose a number from 1 to 10" << endl;

        int baseAttack;
        cin >> baseAttack;

        int userAttackStrength = baseAttack + rand() % 11;

        cout << "Your attack strength is " << userAttackStrength << "." << endl;

        cout << "Please enter your character's name:" << endl;

        string characterName;
        cin >> characterName;
        getline(cin, characterName);
        cout << endl;

        Wizard* wizardCharacter = new Wizard(characterName, 100, userAttackStrength, userRank);
        userCharacter = wizardCharacter;

        cout << endl << endl;      
        cout << userName << " 's character:" << endl << endl;
        PrintCharacterStats(userCharacter);
    }

    return userCharacter;
}

void GameOver(Character* &userPerson, vector<Character*> &opponentList) {
    cout << userPerson->GetName() << " died!" << endl;
    cout << "Play Again?" << endl;

    cout << "Please Enter Yes or No (Y/N):" << endl;
    char ynInput;
    cin >> ynInput;

    while (ynInput != 'y' && ynInput != 'n' && ynInput != 'Y' && ynInput != 'N') {
        cout << "Please enter a valid input (Y/N):" << endl;
        cin >> ynInput;
    }

    if (ynInput == 'y' || ynInput == 'Y') {
        // Reset the protagonist/userPerson
        string emptyString = "";
        delete userPerson;
        userPerson = StartMenu(emptyString);

        // Reset the health of each opponent in the opponentList vector
        for (auto& opponent : opponentList) {
            opponent->ResetHealth();
        }
    } 
    else { //yninput is 'n' or 'N'
        // User chose not to play again
        // Clean up resources (optional)
        delete userPerson;
        for (auto& opponent : opponentList) {
            delete opponent;
        }
    }
}

int main() {

    srand(20);

    string allyString = "";

    Character* Protagonist = StartMenu(allyString);

    cout << "Welcome to the Land of Medievality!" << endl;
    cout << "Here, you will take on opponents in battle and fight until you defeat them all! (or die trying)." << endl << endl; 

    vector<Character*> adventurers;
    adventurers.push_back(new Warrior("Arthur", 100, 5, "King George"));
    adventurers.push_back(new Warrior("Jane", 100, 6, "King George"));
    adventurers.push_back(new Warrior("Bob", 100, 4, "Queen Emily"));
    adventurers.push_back(new Elf("Longear", 100, 79, allyString));
    adventurers.push_back(new Elf("Raegron", 100, 4, "Sylvarian"));
    adventurers.push_back(new Elf("Cereasstar", 100, 3, "Sylvarian"));
    adventurers.push_back(new Warrior("Caesar", 100, 49, allyString));
    adventurers.push_back(new Elf("Melimion", 100, 4, "Valinorian"));
    adventurers.push_back(new Wizard("Merlin", 100, 5, 10));
    adventurers.push_back(new Wizard("Adali", 100, 5, 8));
    adventurers.push_back(new Wizard("Vrydore", 100, 4, 6));


    unsigned int i = 0;  // Index of the opponent
    Character* opponent = nullptr;

    while (Protagonist->IsAlive() && i < adventurers.size()) {

         // Set the current opponent
        opponent = adventurers.at(i);

        // Print battle information only before the protagonist's first attack
        if (opponent->GetHealth() == 100.0) { //meaning protagonist has not attacked this opponent yet
            cout << "Battle Number " << i + 1 << ". FIGHT!!!:" << endl << endl;
        }

        // Protagonist's turn
        Protagonist->Attack(*opponent);

        // Check if opponent is still alive
        if (!opponent->IsAlive()) {
            opponent->PrintDeathMessage();
            cout << endl << endl;
            ++i;  // Move to the next opponent
        } else {
            // Opponent's turn
            opponent->Attack(*Protagonist);
            cout << endl;
            cout << "-----Health Remaining-----" << endl;
            cout << Protagonist->GetName() << ": "; 
            cout << Protagonist->GetHealth() << endl;

            cout << opponent->GetName() << ": ";
            cout << opponent->GetHealth() << endl << endl;

            // Check if protagonist is still alive
            if (!Protagonist->IsAlive()) {
                break;  // End the loop, game over
            }
        }
    }

    GameOver(Protagonist, adventurers); //FIXME: make it so user can rety infinitely many times, I think it will only let user try again one more time

    //FIXME: also make it so useers cant enter a nubmer higher than 10


    return 0;
}

    