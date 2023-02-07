// main

#include "API.h"

int main()
{
	unsigned int rep;
	unsigned int wait;
	char choice;
	std::cout << "#Monte Carlo Test\n\nPress any key to continue...";
	choice = _getch();
	CLEAR;
	if (choice == 'f')
	{
		montecarlo(100, 50);
		return 0;
	}
	std::cout << "Number of repetitions: ";
	std::cin >> rep;
	std::cout << "\nTime between each repetition in ms: ";
	std::cin >> wait;
	montecarlo(rep, wait);
	return 0;
}