#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>
#include <iostream>
#include "Term.h"

using namespace std;

// creates initial capacity for defauly constructors for Autocomplete
const int INITIAL_CAPACITY = 5;

class Autocomplete
{
	public:
		 // inserts the newterm to the sequence
		 void insert(Term newterm);

		 // returns all terms that start with the given prefix,
		 // in descending order of weight
		 void allMatches(string prefix);

		 // first: the index of the first query that equals
		 // the search key, or -1 if no such key
		 // last: the index of the last query that equals
		 // the search key, or -1 if no such key
		 void Search(string key, int num);

		 // return the index number of the search key using binary search algorithm
		 int BS_helper(string key, int left, int right);

		 // display all the terms
		 void print();

		 // default constructor for Autocomplete
		 Autocomplete();

		 // alphaSort function
		 void alphaSort();
		
		 // revWeightSort function
		 void revWeightSort();
 
		 // deleteMatches function
		 void deleteMatches();
		
		 // other member functions you need…

	private:

		int terms; // terms to return for matches
		vector <Term> t; // pointer pointing to the first element in the list
		vector <Term> matches; // pointer for matches array
};

#endif
