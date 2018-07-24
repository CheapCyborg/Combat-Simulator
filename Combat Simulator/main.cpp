#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int getNumOrcs();
int getNumHumans();
void printResults(int numOrcs, int numHumans, int startOrcs, int startHumans);
void simulateBattle(int &numOrcs, int &numHumans);

int main()
{
	int startOrcs;
	int startHumans;

	int numOrcs;
	int numHumans;

	cout << "*** Orcs Vs Humans! ***\n\n";

	numOrcs = getNumOrcs();
	startOrcs = numOrcs;

	numHumans = getNumHumans();
	startHumans = numHumans;
		
	simulateBattle(numOrcs, numHumans);

	printResults(numOrcs, numHumans, startOrcs, startHumans);

		system("PAUSE");
		return 0;
}

int getNumOrcs()
{
	// Getting the number of orcs
	int numOrcs;
	cout << "Enter amount of Orcs: ";
	cin >> numOrcs;
	return numOrcs;
}

int getNumHumans()
{
	// Getting the number of orcs
	int numHumans;
	cout << "Enter amount of Huamns: ";
	cin >> numHumans;
	return numHumans;
}

void printResults(int numOrcs, int numHumans, int startOrcs, int startHumans)
{
	cout << "\nThe war has come to an end.\n";

	// Print battle results
	if (numOrcs > 0) {
		cout << "\nThe Orcs have won! ";
		cout << "There are " << numOrcs << " left!\n";
	}
	else {
		cout << "\nThe Humans have won! ";
		cout << "There are " << numHumans << " left!\n";
	}

	// Kiil counter
	cout << startOrcs - numOrcs << " Orcs and " << startHumans - numHumans << " Humans lost their lives\n\n";

}

void simulateBattle(int &numOrcs, int &numHumans)
{
	char turn = 'O';

	static mt19937 randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	// Orc Properties
	float orcAttack = 0.5f;
	float orcHealth = 220.0f;
	float orcDamage = 150.0f;
	float currentOrcHealth = orcHealth;

	// Human Properties
	float humanAttack = 0.5f;
	float humanHealth = 300.0f;
	float humanDamage = 150.0f;
	float currentHumanHealth = humanHealth;

	float attackResult;

	while ((numOrcs > 0) && (numHumans > 0)) {
		//Get attack result
		attackResult = attack(randomEngine);

		// Orcs Turn
		if (turn == 'O') {

			//Check if attack landed
			if (attackResult <= orcAttack) {
				currentHumanHealth -= orcDamage;

				if (currentHumanHealth < 0) {
					numHumans--;
					currentHumanHealth = humanHealth;
				}
			}

			turn = 'H';
		}
		else {

			if (attackResult <= humanAttack)
				currentOrcHealth -= humanAttack;

			if (currentOrcHealth < 0) {
				numOrcs--;
				currentOrcHealth -= orcHealth;
			}

			turn = 'O';
		}
	}
}