// Term.cpp
// Harrison Wainwright
// CS216
// 4/16/16
// Purpose: to create a Term object and give it functions so it can work within an array for sorting search terms

#include "Term.h"

// default constructor for Term object
// pre: n/a
// post: a term oject with given values
// purpose: to create a term ojects when no arguements are given
Term::Term()
{
	// initialize values
	query = "Term";
	weight = 0;
}

// constructor for Term object with parameters
// pre: n/a
// post: a term object with specified values
// purpose: to create a term object when arguements are given
Term::Term(string queryy, long weightt)
{
	// initialize values
	query = queryy;
	weight = weightt;
}

// byReverseWeightOrder function for Term object
// pre: two weight values
// post: a number (-1,0,1) that shows their order
// purpose: to return a number for their order so they can be ordered
int Term::byReverseWeightOrder(Term term1, Term term2)
{
	// if this' weight is higher return a 1
	if(term1.getWeight() > term2.getWeight())
	{
		return 1;
	}

	// if this' weight is lower return a -1
	if(term1.getWeight() < term2.getWeight())
	{
		return -1;
	}

	// else they are equal return 0
	else
	{
		return 0;
	}
}

// compareTo fucntion for Term object
// pre: two query values
// post: a number (-1,0,1) that shows their order
// purpose: to return a number to display order so they be ordered
int Term::compareTo(Term term1, Term term2)
{
	// if this' query is higher return a 1
	if(term1.getQuery() > term2.getQuery())
	{
		return 1;
	}

	// if this' query is lower return a -1
	if(term1.getQuery() < term2.getQuery())
	{
		return -1;
	}

	// else they are the same return 0
	else
	{
		return 0;
	}
}

// byPrefixOrder function for Term object
// pre: two queries and an r value for number of places
// post: a number (-1,0,1) to show order so they can be arranged
// purpose: to compare two values but only up to r places of the string
int Term::byPrefixOrder(Term term1, Term term2, int r)
{
	// get substring values
	string substring_term1 = (term1.getQuery()).substr(0, r);
	string substring_term2 = (term2.getQuery()).substr(0, r);

	// if this' substring is higher return a 1
	if(substring_term1 > substring_term2)
	{
		return 1;
	}

	// if this' substring is lower retrun a -1
	if(substring_term1 < substring_term2)
	{
		return -1;
	}

	// else they are equal return a 0
	else
	{
		return 0;
	}
}

// print function for Term object
// pre: n/a
// post: an output of the terms values
// purpose: to print a term objects values
void Term::print()
{
	cout << query << "        " << weight << endl;	
}

// getQuery function for Term object
// pre: n/a
// post: query string
// purpose: to return query value for comparisons
string Term::getQuery()
{
	return query;
}

// getWeight function for Term object
// pre: n/a
// post: weight int
// purpose: to return weight value for comparisons
int Term::getWeight()
{
	return weight;
}

ostream &operator<<(ostream &out, Term &T)
{
	return out << T.getWeight() << "        " << T.getQuery();
}
