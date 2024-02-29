#pragma once

#include <string>

using namespace std;

class Game {
private:
	string title;
	int releaseYear;
	float rate;
	float price;

public:
	Game();
	Game(string title, int releaseYear, float rate, float price);

	string getTitle();
	int getReleaseYear();
	float getRate();
	float getPrice();

	/* Settery - chcia�em ich u�y� w edycji, ale podczas przekazywania (vector[index].set...(arg)) obiektu 
	// przekazywana jest jedynie kopia obiektu, co nie zmienia oryginalnych warto�ci obiektu... A wi�c s� zb�dne :/
	void setTitle(string title);
	void setRealeaseYear(int releaseYear);
	void setRate(float rate);
	void setPrice(float price);
	*/

	void displayGame();
};