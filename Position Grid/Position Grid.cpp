// Position Grid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>    // std::cin, std::cout, std::endl;
#include <limits>      // std::numeric_limits
#include "Position.h"  // the entire Position class
using std::cin;
using std::cout;
using std::endl;

/**
 * Get a direction from the user and return it.
 * 7 8 9
 *  \|/
 * 4-+-6
 *  /|\
 * 1 2 3
 * 5 is valid for resetting the home position to the current
 * 0 is valid for returning the bot to its home position
 *
 * \return int the selected direction
 */
int getDirection();

/**
 * Perform "bot navigation" with he provided bot.
 *
 * \param	Position& the position object representing the bot to be moved
 * \post	the provided bot has updated position and origin information
 */
void botNavigation(Position& bot);

int main() {

	/// test constructors	
	cout << "Construct two, default Position objects (bot1, bot2) at 0,0 on 10x10 grid... ";
	Position bot1, bot2;
	cout << "success" << endl;

	cout << "Construct one Position object (bot3) at 5,5 on a default 10x10 grid... ";
	Position bot3(5, 5);
	cout << "success" << endl;

	cout << "Construct one Position object (bot4) at 10,10 on a 20x20 grid... ";
	Position bot4(10, 10, 20, 20);
	cout << "success" << endl;

	// test comparison operator
	cout << "bot1 and bot 2 are at the same location on a matching grid (bot1 == bot2)...";
	cout << ((bot1 == bot2) ? "true\n" : "false\n") << endl;

	cout << "bot1 and bot 5 are at the same location on a matching grid (bot1 == bot5)...";
	cout << ((bot1 == bot3) ? "true\n" : "false\n") << endl;

	// show bot1 position
	cout << "Bot1 map:" << endl;
	bot1.display();

	// show bot4 position
	cout << "Bot4 map:" << endl;
	bot4.display();

	// test bot movement
	cout << "\nTesting navigation with bot1" << endl;
	botNavigation(bot1);
	cout << "Bot1 navigation complete" << endl;

	cout << "All tests complete";
	return 0;
}

int getDirection() {
	int d = 10;
	while (d > 9) {
		// display instructions
		cout << "\n7 8 9\n \\|/\n4-+-6\n /|\\\n1 2 3\n";
		cout << "5 - set the current position as 'home'\n";
		cout << "0 - return to 'home' position\n";
		cout << "Enter a number for a direction (negative to stop): ";

		// attempt to get a valid integer
		cin >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			d = 10;
		}
	}
	return d;
}

void botNavigation(Position& bot) {
	// take commands and move the bot1 around
	int direction;
	cout << "\n\n" << endl;
	bot.display(); /// provides a guide and prompts for a direction

	// Get a direction from the user until the direction is less than 0
	while ((direction = getDirection()) >= 0) {
		switch (direction) {
		case 0: // reset to origin
			bot.reset(); break;
		case 5: // move the origin location to current
			bot.rehome(); break;
		default: // perform a move
			bot.move(direction);
		}
		cout << "\n\n" << endl;
		bot.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
