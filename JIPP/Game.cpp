#include "Game.h"
#include <iostream>

using namespace std;

// Konstruktory
Game::Game() {
	this->title = "not set";
	this->releaseYear = 0;
	this->rate = 0;
	this->price = 0;
}
Game::Game(string title, int releaseYear, float rate, float price) {
	this->title = title;
	this->releaseYear = releaseYear;
	this->rate = rate;
	this->price = price;
}

// Gettery
string Game::getTitle() {
	return this->title;
}
int Game::getReleaseYear() {
	return this->releaseYear;
}
float Game::getRate() {
	return this->rate;
}
float Game::getPrice() {
	return this->price;
}

// Settery
/*void Game::setTitle(string title) {
	this->title = title;
}
void Game::setRealeaseYear(int releaseYear) {
	this->releaseYear = releaseYear;
}
void Game::setRate(float rate) {
	this->rate = rate;
}
void Game::setPrice(float price) {
	this->price = price;
}*/

// Funkcja wyswietlenia wszystkich informacji
void Game::displayGame() {
	cout << "\n------- > GAME < -------\n";
	cout << "Title of the game: " << getTitle() << "\n";
	cout << "Year of release: " << getReleaseYear() << "\n";
	cout << "Rate of the game: " << getRate() << "\n";
	cout << "Price of the game: " << getPrice() << "\n";
	cout << "------------------------\n";
}
