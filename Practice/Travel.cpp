
#include "pch.h"
/**

   * func: compare(Node*, Node*)

   * desc: private utilty function for comparing two options given as

   * Node pointers.

   *

   * status: DONE

   *

   * COMMENT: depends on public compare(double,double,double,double) being implemented.

   * You might find this version handy when manipulating lists

   */

static Relationship compare(Node *a, Node *b) {

	if (a == nullptr || b == nullptr) {

		std::cout << "ERR: compare(Node*,Node*); null pointer passed!!! Whoops!" << std::endl;

		return incomparable;

	}

	return compare(a->price, a->time, b->price, b->time);

}



public:







	/**

	* func: push_front

	* desc: Adds a <price,time> option to the front of the list (simple primitive for building lists)

	* status: DONE

	*/

	void push_front(double price, double time) {

		front = new Node(price, time, front);

		_size++;

	}

	/**

	* func: from_vec

	* desc: This function accepts a C++ standard libary vector of pair<double,double>.

	* Each pair is interpreted as a <price,time> option and a TravelOptions object

	* is containing exactly the same options as in the vector (and in the same order).

	*

	* returns: a pointer to the resulting TravelOptions object

	* status: DONE

	*/

	static TravelOptions * from_vec(std::vector<std::pair<double, double> > &vec) {

		TravelOptions *options = new TravelOptions();

		for (int i = vec.size() - 1; i >= 0; i--) {

			options->push_front(vec[i].first, vec[i].second);

		}

		return options;

	}

	/**

	* func: to_vec

	* desc: Utility function which creates a C++ standard libary vector of pair<double,double>.

	* and populates it with the options in the calling object (in the same order).

	* As in from_vec the "first" field of each pair maps to price and the "second"

	* field maps to time.

	*

	* returns: a pointer to the resulting vector

	* status: DONE

	*/

	std::vector<std::pair<double, double>> * to_vec() const {

		std::vector<std::pair<double, double>> *vec = new std::vector<std::pair<double, double>>();

		Node *p = front;

		while (p != nullptr) {

			vec->push_back(std::pair<double, double>(p->price, p->time));

			p = p->next;

		}

		return vec;

	}

	/**

	* func: is_sorted

	* desc: we consider an option list sorted under the following conditions:

	*

	* - the options are in non-decreasing order of price AND

	* - time is used as a tie-breaker for options with identical price.

	*

	* For example, using the notation <price, time> to represent an option:

	*

	* <5.1, 10.0> must be before <5.6, 9.0> (price is less, so time ignored)

	* <6.2, 4.1> must be AFTER <6.2, 3.9> (identical price; tie broken by

	* smaller time (3.9 in this case)).

	*

	* If two or more options are identical in BOTH price and time, they are

	* indistinguishible and must appear as a consecutive "block" if the list is

	* to be considered sorted.

	*

	* returns: true if sorted by the rules above; false otherwise.

	*

	* Examples:

	*

	* The option list below is sorted by our rules:

	* [ <1, 7>, <2, 8>, <2, 9>, <3, 5>, <5, 8>, <5, 8>, <5, 9>, <6, 12> ]

	*

	* The option list below is NOT sorted by our rules:

	* [ <1, 7>, <2, 8>, <4, 3>, <3, 7>]

	* ^^^^^^ must be before <4,3>

	*

	* The option list below is also NOT sorted by our rules:

	* [ <1, 7>, <2, 8>, <2, 5>, <3, 7>]

	* ^^^^^^ must be before <2,8>

	* status: TODO

	*/

	bool is_sorted()const {

		return false;

	}

	/**

	* func: is_pareto

	* desc: returns true if and only if:

	*

	* all options are distinct (no duplicates) AND

	* none of the options are 'suboptimal' (i.e., for each option X, there DOES NOT EXIST

	* any other option Y such that Y dominates X). There are several equivalent

	* ways of stating this property...

	*

	* status: TODO

	*

	* REQUIREMENTS:

	* - the list must be unaltered

	* - no memory allocation, arrays, etc. allowed

	* - RUNTIME: quadratic in number of options n (i.e., O(n^2)).

	*

	* REMEMBER: the list does not need to be sorted in order to be pareto

	*/

	bool is_pareto() const {

		return false;

	}