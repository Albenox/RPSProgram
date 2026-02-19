#include <iostream>
#include <cstdlib>

using namespace std;

void promptDisplay(int userScore, int computerScore, int roundCount);
int userInput(int userChoice);
int computerInput(int computerChoice);
int logic(int userChoice, int computerChoice);
void postgame(int computerChoice, int userScore, int computerScore, int winner);

int main()
{
	// Main variables for the game
	int userScore = 0;
	int computerScore = 0;
	int userChoice = 0;
	int computerChoice = 0;
	int winner;
	int roundCount = 0;
	bool gameOver = 0;
	
	// Main loop that runs until a winner is determined or until the user decides to quit
	while (gameOver != 1) {
		promptDisplay(userScore, computerScore, roundCount);
		cin >> userChoice;
		userChoice = userInput(userChoice);
		computerChoice = computerInput(computerChoice);
		winner = logic(userChoice, computerChoice);
		postgame(computerChoice, userScore, computerScore, winner);
	}
	
	
}

// Function to display the game prompt and current scores
void promptDisplay(int userScore, int computerScore, int roundCount) {
	if (userScore == 0 && computerScore == 0) {
		cout << endl << "Welcome to Rock, Paper, Scissors!" << endl;
		cout << "You will be playing against the computer to score points, and the first to 3 points wins!" << endl;
	}
	cout << endl << "------------------------------" << endl;
	cout << "Round: " << roundCount << endl;
	cout << "Your Score: " << userScore << endl;
	cout << "Computer Score: " << computerScore << endl;
	cout << "The computer is ready to make their move, please enter your choice between: " << endl;
	cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl << endl;
}

// Function to allow the user to input their choice and validate it
int userInput(int userChoice) {
	int firstCheck = 1;
	while(userChoice < 1 || userChoice > 3 || firstCheck == 1){
		switch (userChoice) {
		case 1:
			return 1; // Rock
			firstCheck = 0;
		case 2:
			return 2; // Paper
			firstCheck = 0;
		case 3:
			return 3; // Scissors
			firstCheck = 0;
		default:
			cout << "Invalid input, please enter a number between 1 and 3." << endl << endl;
			cin >> userChoice;
			firstCheck = 0;
		}
	}
}

// Function to randomly generate computer choice
int computerInput(int computerChoice) {
	computerChoice = rand() % 3 + 1; // Generates a random number between 1 and 3
	return computerChoice;
}

// Function that holds logic for determining the winner of each round
int logic(int userChoice, int computerChoice) {
	// Logic for determining the winner of each round
	if (userChoice == computerChoice) {
		return 0; // Tie
	}
	else if ((userChoice == 1 && computerChoice == 3) || 
			 (userChoice == 2 && computerChoice == 1) || 
			 (userChoice == 3 && computerChoice == 2)) {
		return 1; // User wins
	}
	else {
		return -1; // Computer wins
	}
}

// Function to display and update scores after each round and determine if the game is over
void postgame(int computerChoice, int userScore, int computerScore, int winner) {
	cout << "The computer chose " << computerChoice << ", which means " << endl;
	switch (winner) {
	case 0:
		cout << "It's a tie!" << endl;
		break;
	case 1:
		cout << "You win this round!" << endl;
		userScore++;
		break;
	case -1:
		cout << "The computer wins this round!" << endl;
		computerScore++;
		break;
	}
}