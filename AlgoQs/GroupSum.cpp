#include <cassert>

#include "pch.h"
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

bool groupSum(int start,vector<int> nums,int target)
{
	if (start >= nums.size())
		return target == 0;

	if (target == 0)
		return true;

	if (target < 0)
		return false;

	return groupSum(start + 1, nums, target - nums[start]) ||
		groupSum(start + 1, nums, target);
}
template<typename T1,typename T2,typename T3>
void combine(T1 beginItr1,T1 endItr1,T2 beginItr2,T2 endItr2,T3 outputItr,std::function<int(int,int)> func)
{
	//loop to iterate through each element in container 1 and 2
	while (beginItr1 != endItr1 && beginItr2 != endItr2)
	{
		*outputItr = func(*beginItr1, *beginItr2);
		++outputItr;
		++beginItr2;
		++beginItr1;
	}
}

//exam.h

#include <iostream>

#include <vector>

#include <string>

//#include <unordered_map>

//#include <assert.h>

#ifndef PROBLEM_H_

#define PROBLEM_H_

class Movies {

public:

	/**

	* The two input vector's have the same length, where the i-th

	* element of movies is the name of a movie, and the i-th element of

	* ratings is one rating that it received. Movie names are expected

	* to appear multiple times in the given data.

	*/

	Movies(std::vector<std::string> movies, std::vector<int> ratings) {
		assert(movies.size() == ratings.size());

		myMovies = movies;
		myRatings = ratings;
	}

	/**

	* Given a movie name in the form of a string, this function returns

	* its average rating. If the movie does not exist in the dataset,

	* then return a rating of 0.

	*/

	float get_average_rating(std::string movie) {
		int ratings = 0;
		int times = 0;
		for (size_t i = 0; i < myMovies.size(); i++)
		{
			if (myMovies[i] == movie)
			{
				ratings += myRatings[i];
				++times;
			}
		}

		return times == 0 ? 0 : ratings / times; // DUMMY LINE
	}

	/**

	* Given a movie name in the form of a string, this function returns

	* the number of ratings that the movie received in the data.

	*/

	int get_rating_count(std::string movie) {

		int times = 0;
		for (size_t i = 0; i < myMovies.size(); i++)
		{
			if (myMovies[i] == movie)
			{
				++times;
			}
		}

		return times;
	}

	/**

	* This function returns the movie name with the highest average

	* rating, for movies with at least 300 ratings.

	*/

	std::string highest_rated(int at_least = 0) {
		std::unordered_map<string, vector<int>> umap;
		//Fill the umap.
		for (size_t i = 0; i < myMovies.size(); i++)
		{
			umap[myMovies[i]].push_back(myRatings[i]);
		}

		float avg = 0;
		string movieName = "";
		for (auto pair : umap)
		{
			if (pair.second.size() >= at_least)
			{
				float temp = get_average_rating(pair.first);
				if (temp > avg)
				{
					avg = temp;
					movieName = pair.first;
				}
			}
		}

		return movieName; // DUMMY LINE

	}

private:

	vector<string> myMovies;
	vector<int> myRatings;

};

#endif // PROBLEM_H_

const char* movie_data[30] = {

"Citizen Kane (1941)",

"Lawnmower Man 2: Beyond Cyberspace (1996)",

"Angels in the Outfield (1994)",

"Lawnmower Man 2: Beyond Cyberspace (1996)",

"U Turn (1997)",

"First Wives Club, The (1996)",

"Apostle, The (1997)",

"Lawnmower Man, The (1992)",

"Pulp Fiction (1994)",

"Blade Runner (1982)",

"Citizen Kane (1941)",

"20,000 Leagues Under the Sea (1954)",

"Cliffhanger (1993)",

"Mimic (1997)",

"Citizen Kane (1941)",

"Gone with the Wind (1939)",

"Lawnmower Man 2: Beyond Cyberspace (1996)",

"Absolute Power (1997)",

"Angels and Insects (1995)",

"English Patient, The (1996)",

"Like Water For Chocolate (Como agua para chocolate) (1992)",

"Lost Horizon (1937)",

"Rock, The (1996)",

"Lawnmower Man 2: Beyond Cyberspace (1996)",

"That Thing You Do! (1996)",

"Return of the Pink Panther, The (1974)",

"Foreign Correspondent (1940)",

"Mission: Impossible (1996)",

"Fifth Element, The (1997)",

"Mulholland Falls (1996)",

};

int rating_data[30] = {

3,

3,

1,

2,

1,

4,

2,

5,

3,

3,

2,

5,

5,

3,

3,

3,

5,

2,

4,

2,

4,

4,

4,

2,

4,

2,

5,

2,

4,

5,

};
//ratings.h

/**also assume there is 100,000 int data_length, char* movie_data, and int rating_data.

*Find the average ratings of the movies and count how many reappear.

*The movie "Matrix, The (1999)" will not appear so leave it as 0 but the other two will have

*a few. Also for the highest rated movie with at least 300 ratings,

*///please rate with at least 3 for now with its average rating.

int data_length = 30;

#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <sstream>

//#include "exam.h"

//#include "ratings.h"

void problem_three() {

	std::cout << "=== PROBLEM 3 ===\n";

	std::vector<std::string> movie_vector;

	std::vector<int> rating_vector;

	for (int i = 0; i < data_length; i++) {

		movie_vector.push_back(movie_data[i]);

		rating_vector.push_back(rating_data[i]);

	}

	Movies movies(movie_vector, rating_vector);

	std::string movie_name1("Citizen Kane (1941)");

	std::string movie_name2("Lawnmower Man 2: Beyond Cyberspace (1996)");

	std::string movie_name3("Matrix, The (1999)");

	std::cout << "rating of " << movie_name1 << ": ";

	std::cout << movies.get_average_rating(movie_name1);

	std::cout << " (out of " << movies.get_rating_count(movie_name1);

	std::cout << " ratings)" << std::endl;

	std::cout << "rating of " << movie_name2 << ": ";

	std::cout << movies.get_average_rating(movie_name2);

	std::cout << " (out of " << movies.get_rating_count(movie_name2);

	std::cout << " ratings)" << std::endl;

	std::cout << "rating of " << movie_name3 << ": ";

	std::cout << movies.get_average_rating(movie_name3);

	std::cout << " (out of " << movies.get_rating_count(movie_name3);

	std::cout << " ratings)" << std::endl;

	std::string highest = movies.highest_rated(3);

	std::cout << "highest rated movie with at least 3 ratings: " << highest;

	std::cout << std::endl;

	std::cout << "rating of " << highest << ": ";

	std::cout << movies.get_average_rating(highest);

	std::cout << " (out of " << movies.get_rating_count(highest);

	std::cout << " ratings)" << std::endl;

}

int main() {

	cout << "Enter the value of n : ";
	int n;
	cin >> n;

	const int X = 10, Z = 20;

	float Y = 3.0;

	for (int i = 3;i <= n;i += 3)
	{
		Y += (X + (i + 1) * Z) / (i);
	}

	cout << "\nY = " << Y;

}




