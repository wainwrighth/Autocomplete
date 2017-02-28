// Autocomplete.cpp
// Harrison Wainwright
// 4/16/16
// CS 216
// Purpose: To define Autocomplete class for creating and searching an array of Term objects

#include <vector>
#include "Autocomplete.h"

using namespace std;

// default constructor for Autocomplete
// pre: n/a
// post: vector for Term objects
// purpose: to create a vector for Term objects
Autocomplete::Autocomplete()
{
	// set value
	terms = 0;
}

// insert function for Automplete
// pre: Term object newterm
// post: a term oject in the vector
// purpose: to place a term object in the vector
void Autocomplete::insert(Term newterm)
{
	t.push_back(newterm);
}

void Autocomplete::allMatches(string prefix)
{
	// n/a
}

// search function for Autocomplete
// pre: a key to search for and number of results desired
// post: an array of matching values
// purpose: to search for values that match and return them
void Autocomplete::Search(string key, int num)
{
	// set values
	int index_val = 0;

	cout << "made it here" << endl;
	index_val = BS_helper(key, 0, t.size());

	if(index_val == -1)
	{
		return;
	}

	else
	{
		int index_up = index_val + 1;
		int index_down = index_val - 1;

		while(((t[index_up].getQuery()).substr(0, key.length())) == key)
		{
			matches.push_back(t[index_up]);
			index_up++;
		}

		while(((t[index_down].getQuery()).substr(0, key.length())) == key)
                {
                        matches.push_back(t[index_down]);
                        index_down--;
                }
	}

	// run for loop the size of the terms array
	/*for(int i = 0; i < t.size(); i++)
	{

		// save value from binary search
		index_val = BS_helper(key, i, t.size() - i);

		// assign value based on what you get
		if(index_val == -1)
		{
			for(int i = 0; i < matches.size(); i++)
			{
				t.push_back(matches[i]);
			}

			alphaSort();
			revWeightSort();
			print();
			matches.clear();
			return;
		}

		//if(index_val == -2)
		//{
		//	continue;
		//}

		// if good value is returned increase size of match vector and add it
		else
		{
			// adds to matches vector
			matches.push_back(t[index_val]);

			// erases term from t vector for searching
			t.erase(t.begin() + index_val);

			counter++;
		}

		// if number of desired results is achieved quit
		if(counter == num)
		{
			for(int i = 0; i < matches.size(); i++)
        		{
                		t.push_back(matches[i]);
        		}


			alphaSort();
			revWeightSort();
        		print();
			matches.clear();
			return;
		}
	}*/
}

// BS_helper function for Autocomplete
// pre: a key to look for, a left value, and a right value
// post: returned index of key
// purpose: to return the index value of the key found
int Autocomplete::BS_helper(string key, int left, int right)
{
	// while the left value is less than right continue searching
	if(left > right)
	{
		return -1;
	}
	
	else
	{
		// set middle term based on left and right
		int middle_term = (left + right) / 2;
		cout << middle_term << endl;

		if(left == right)
		{
			if(((t[middle_term].getQuery()).substr(0, key.length())) == key)
			{
				return middle_term;
			}

			//else
			//{
			//	return -2;
			//}
		}

		// compare alphabetically and assign accordingly
		if((t[middle_term]).getQuery() > key)
		{
			return BS_helper(key, left, middle_term - 1);
		}

		// assign otherwise
		else if((t[middle_term]).getQuery() < key)
		{
			return BS_helper(key, middle_term + 1, right);
		}

	}
}

// print function for Autocomplete
// pre: n/a
// post: a printed list of Term objects
// purpose: to print out the Term objects in an ordered fashion
void Autocomplete::print()
{
	// if match vector has no Terms return to not print empty vector
	if(matches.size() == 0)
	{
		return;
	}

	// print Term objects in array
	for(int i = 0; i < matches.size(); i++)
	{
		cout << matches[i] << endl;
	}
}

// alphaSort function for Autocomplete
// pre: t vector
// post: a t vector sorted alphabetically
// purpose: sorts t vector alphabetically
void Autocomplete::alphaSort()
{
	// start first for loop for sorting times
	for(int i = 0; i < t.size() - 1; i++)
	{
		// create second for loop for comparing
		for(int j = 0; j < t.size() - 1; j++)
		{
			// swap based on comparison return
			if((t[j]).getQuery() > (t[j + 1]).getQuery())
			{
				swap(t[j], t[j + 1]);
			}
		}
	}
}

// revWeightSort function
// pre: match vector
// post: a sorted match vector based on weight reversed
// purpose: sorts reversed by weight for matches
void Autocomplete::revWeightSort()
{
	// start first for loop for sorting times
        for(int i = 0; i < matches.size() - 1; i++)
        {
		// create second loop for comparing
                for(int j = 0; j < matches.size() - 1; j++)
                {
			// swap based on comparison return
                        if((matches[j]).getWeight() < (matches[j + 1]).getWeight())
                        {
                                swap(matches[j], matches[j + 1]);
                        }
                }
        }
}
