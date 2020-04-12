#include "pch.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Book 
{

	//Variable declaration

	string title, genre, plot, release_year, publisher;

	list<string> authors;

	//Constructor
public:
	 Book(string titleR, string genreR, string plotR, string release_yearR, string publisherR, list<string> authorR) {

		title = titleR;

		genre = genreR;

		plot = plotR;

		publisher = publisherR;

		release_year = release_yearR;

		authors = authorR;

	}

	 string getTitle() const {

		return title;

	}

	 string getGenre() const {

		return genre;

	}

	 string getPlot() const {

		return plot;

	}

	 string getRelease_Year() const {

		return release_year;

	}

	 list<string> getAuthors() const{

		return authors;

	}

	string getPublisher() const{

		return publisher;

	}



	 void setTitle(string T) {

		title = T;

	}



	void setPublisher(string P) {

		publisher = P;

	}



	 void setGenre(string G) {

		genre = G;

	}

	 void setPlot(string P) {

		plot = P;

	}

	 void setYear(string R_Y) {

		release_year = R_Y;

	}



	 void setAuthor(string firstN, string lastN) 
	 {

		authors.push_back(firstN +" " + lastN);

	}

};