#include <iostream>
#include <random>

using namespace std;

void promptDisplay(int userScore, int computerScore, int roundCount);
int logic(int userChoice, int computerChoice);

int main()
{
	// Main variables for the game
	int userScore = 0;
	int computerScore = 0;
	int userChoice;
	int computerChoice;
	int roundCount = 0;
	bool gameOver = 0;
	
	// Main loop that runs until a winner is determined or until the user decides to quit
	while (gameOver != 1) {
		std::cout << "Hello World!\n";
	}
	
	
}

// Function to display the game prompt and current scores
void promptDisplay(int userScore, int computerScore, int roundCount) {
	if (userScore == 0 && computerScore == 0) {
		cout << "Welcome to Rock, Paper, Scissors!" << endl;
		cout << "You will be playing against the computer to score points, and the first to 3 points wins!" << endl;
	}
	cout << endl << "------------------------------" << endl;
	cout << "Round: " << roundCount << endl;
	cout << "Your Score: " << userScore << endl;
	cout << "Computer Score: " << computerScore << endl;
	cout << "The computer is ready to make their move, please enter your choice between: " << endl;
	cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl;
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