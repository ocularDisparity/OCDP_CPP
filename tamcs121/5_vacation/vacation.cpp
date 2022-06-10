#include <iostream>
#include <string>

#include "provided.h"
#include "functions.h"

using std::cout; using std::cin; using std::endl;

int main() {
	int ngames;
	int duration;
	
	std::string titles;
	std::string gameTitles[MAX_NB_GAMES];
	
	std::string preferences;
	int prefs[MAX_NB_GAMES];
	
	std::string planName;
	int plan[366];
	
	cout << "Please enter the number of games and the duration: ";
	cin >> ngames;
	cin >> duration;
	
	if (ngames <= 0 || ngames > 200) {
		cout << "Invalid input." << endl;
		return 0;
	}
	if (duration <= 0 || duration > 365) {
		cout << "Invalid input." << endl;
		return 0;
	}
	
	cout << "Please enter name of file with titles: ";
	cin >> titles;
	
	cout << "Please enter name of file with preferences: ";
	cin >> preferences;
	
	cout << "Please enter name of file with plan: ";
	cin >> planName;
	
	try {
		readGameTitles(titles, ngames, gameTitles);
    } catch (std::runtime_error& e) {
		std::cerr << e.what() << endl;
		return 0;
    }
	
	try {
		readPrefs(preferences, ngames, prefs);
    } catch (std::runtime_error& e) {
		std::cerr << e.what() << endl;
		return 0;
    }
	
	try {
		readPlan(planName, plan);
    } catch (std::runtime_error& e) {
		std::cerr << e.what() << endl;
		return 0;
    }
	
	int bestDay = findBestVacation(duration, prefs, plan);
	
	cout << "Best start day is " << bestDay << endl;
	
	cout << "Games to be played:" << endl;
	
	printGamesPlayedInVacation(bestDay, duration, plan, gameTitles, ngames);
	
	return 0;
}