#include "API.h"

void montecarlo(unsigned int i_rep = 100, unsigned int i_wait = 50)
{
	CLEAR;
	std::cout << "#Monte Carlo Simulation (" << i_rep << " reps) ready: press a key to start...";
	_getch();

	const int nres = 6;
	std::vector<int> v_sum(nres);

	std::random_device rd;		//Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd());		//Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> rnd(1, nres);
	std::normal_distribution<> norm((nres / 2), 1);

	for (unsigned int i = 1; i <= i_rep; i++)
	{
		//int pr = rnd(gen);			//random prob
		int pr = norm(gen);			//gaussian prob
		updateres(v_sum, pr);	//check for result and update v_sum

		CLEAR;
		std::cout << "#Rep n." << i << ", Current Result: " << pr << "\n";
		drawgraph(v_sum);		//call draw func with vector of results sum
		sleep(i_wait);			//sleep
	}
	showres(v_sum, i_rep);

	std::cout << "\n\n#Simulation ended: press a key to exit...";
	_getch();
}

void sleep(unsigned int i_sleep)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(i_sleep));
}

void drawgraph(std::vector<int>& vect)
{
	std::cout << "\n\t### FREQ ###";
	for (unsigned int i = 0; i < vect.size(); i++)	//row
	{
		std::cout << "\n    " << i + 1 << " | ";
		for (int s = 0; s < vect[i]; s++)	//draw bar
		{
			std::cout << "]";
		}
	}
}

void updateres(std::vector<int>& vect, float pres)
{
	round(pres);
	(int)pres;
	pres--;
	//check for OOB
	if (pres < 0) pres = 0;
	if (pres > vect.size()) pres = vect.size() - 1;
	vect[pres]++;
}

void showres(std::vector<int>& vect, unsigned int tot)
{
	std::cout << "\n\n#Final Distribution: ";
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		std::cout << "\n" << i + 1 << ") " << vect[i];
	}

	std::cout << "\n\n#Distribution %: ";
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		std::cout << "\n" << i + 1 << ") " << round(vect[i] * 100 / tot) << "%";
	}
}