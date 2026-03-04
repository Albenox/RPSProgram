#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void promptDisplay(int userScore, int computerScore, int roundCount);
int userInput(int userChoice);
int computerInput(int computerChoice);
int logic(int userChoice, int computerChoice);
void postgame(int computerChoice, int& userScore, int& computerScore, int winner);
void tournamentWinner(int userScore, int computerScore);

int main()
{
	// Initialize random seed
	srand(time(0));

	// Main variables for the game
	int userScore = 0;
	int computerScore = 0;
	int userChoice = 0;
	int computerChoice = 0;
	int winner = 0;
	int roundCount = 0;
	bool gameOver = false;

	// Main loop that runs until a winner is determined or until the user decides to quit
	while (!gameOver) {

		roundCount++;

		// Displays the prompt and current scores
		promptDisplay(userScore, computerScore, roundCount);

		// Takes the user's input as an integer, then validates it
		cin >> userChoice;
		userChoice = userInput(userChoice);

		// If user chooses quit
		if (userChoice == 4) {
			gameOver = true;
			break;
		}

		// Randomly generates the computer's choice 
		computerChoice = computerInput(computerChoice);

		// Decides the winner
		winner = logic(userChoice, computerChoice);
		postgame(computerChoice, userScore, computerScore, winner);

		// Ends game if someone reaches 3 points
		if (userScore >= 3 || computerScore >= 3) {
			gameOver = true;
		}
	}

	// Display final scores and winner
	tournamentWinner(userScore, computerScore);

	return 0;
}


// Function to display the game prompt and current scores
void promptDisplay(int userScore, int computerScore, int roundCount) {
	if (userScore == 0 && computerScore == 0 && roundCount == 1) {
		cout << endl << "Welcome to Rock, Paper, Scissors!" << endl;
		cout << "You will be playing against the computer to score points, and the first to 3 points wins!" << endl;
	}
	cout << endl << "------------------------------" << endl;
	cout << "Round: " << roundCount << endl;
	cout << "Your Score: " << userScore << endl;
	cout << "Computer Score: " << computerScore << endl;
	cout << "The computer is ready to make their move, please enter your choice between: " << endl;
	cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl << "4. Quit" << endl << endl;
}


// Function to allow the user to input their choice and validate it
int userInput(int userChoice) {
	while (true) {
		switch (userChoice) {
		case 1:
			return 1; // Rock
		case 2:
			return 2; // Paper
		case 3:
			return 3; // Scissors
		case 4:
			return 4; // Quit
		default:
			cout << "Invalid input, please enter a number between 1 and 4." << endl << endl;
			cin >> userChoice;
		}
	}
}


// Function to randomly generate computer choice
int computerInput(int computerChoice) {
	computerChoice = rand() % 3 + 1;
	return computerChoice;
}


// Function that holds logic for determining the winner of each round
int logic(int userChoice, int computerChoice) {

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


// Function to display and update scores after each round
void postgame(int computerChoice, int& userScore, int& computerScore, int winner) {

	string computerTranslation;

	if (computerChoice == 1) {
		computerTranslation = "Rock";
	}
	else if (computerChoice == 2) {
		computerTranslation = "Paper";
	}
	else {
		computerTranslation = "Scissors";
	}

	cout << endl << endl << "The computer chose " << computerTranslation << ", which means..." << endl << endl;

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

	cout << endl << "Current Score -> You: " << userScore << " | Computer: " << computerScore << endl;
}


// Function to determine and display the tournament winner
void tournamentWinner(int userScore, int computerScore) {

	cout << endl << "==============================" << endl;
	cout << "Final Scores:" << endl;
	cout << "You: " << userScore << endl;
	cout << "Computer: " << computerScore << endl << endl;

	if (userScore > computerScore) {
		cout << "Tournament Winner: You!" << endl;
	}
	else if (computerScore > userScore) {
		cout << "Tournament Winner: Computer!" << endl;
	}
	else {
		cout << "Tournament Result: It's a draw!" << endl;
	}

	cout << "==============================" << endl;
}