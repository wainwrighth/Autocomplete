// Harrison Wainwright
// CS 216
// 4/8/16
// Purpose: to allow the searching of lists of items for autocompletion of search queries entered in by the user

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Term.h"
#include "Autocomplete.h"

using namespace std;

int main(int argc, char** argv)
{
	ifstream in_file;

	// checks the amount of arguments
	if(argc != 3)
	{
		cout << "It needs three command line arguments!" << endl;
		return 1;
	}

	bool search = true;
	string search_val;
	int results = atoi(argv[2]);

	in_file.open(argv[1]);

        // if file fails to open tell user and return
        if(in_file.fail())
        {
                cout << "File not found!";
                return 2;
        }

	string line;

	// creates autocomplete object to allow use of its functions
	Autocomplete autocomp;

	do
	{
		// run through file
		while(getline(in_file, line))
		{
			
			long weight_value;
			string query_value;

			// pulls weight and query value from each line
			weight_value = atol(line.substr(0, line.find('\t')).c_str());
			query_value = line.substr(line.find('\t'), line.find('\n')).c_str();
			query_value = query_value.erase(query_value.find('\t'), query_value.find_first_not_of(" \t\r\n"));

			// creates object with values and inserts it
			Term term(query_value, weight_value);
        	    	autocomp.insert(term);
		}

		// gets user input on search value
		cout << "Enter search value (\"exit\" to quit):" << endl;
		cin >> search_val;

		// exits if "exit" is given
		if(search_val == "exit")
		{
			search = false;
			continue;
		}

		cout << "before sort" << endl;
		autocomp.alphaSort();
		cout << "after sort" << endl;

		// runs search function to look for matches
		autocomp.Search(search_val, results);

	}while(search);

	in_file.close();

	return 0;
}
