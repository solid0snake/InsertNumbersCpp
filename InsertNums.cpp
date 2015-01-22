/*
 * InsertNums.cpp
 * By Pedro Garate on 10/03/2014
 * Description	: Given a file that contains a formatted list of
 *                integers, where each integer occupies one single
 *                line and takes 4 characters' space per line. This
 *                file currently contains 1 through 24, and 71 through
 *                99. This C++ program inserts the numbers 25 through
 *                70 into this file while maintaining the original
 *                format (i.e., each integer occupies a single line
 *                and takes 4 characters' space).
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	//name of file
	fstream file("file1.txt", ios::in|ios::out);

	if (!file.is_open())
		cout << "ERROR!"; // just finish execution if file does not exist.
	else {
		string line; // to save each line of the file in turn
		int position = 0; // character position in file

		// assuming the file has data line by line,
		// each line has 4 spaces total including the integer
		// total of 5 bytes with the new line character.
		// so the starting position for each line is a multiple
		// of 5.

		getline(file,line); // gets first line

		while (line != "  24"){
			getline(file,line);
		}// end while

		position = file.tellg(); // get insertion point

		vector<string> rest; // stores rest of the file
		                     // line by line
		while (getline(file, line))
		{
		   rest.push_back(line);
		}// end while

		file.clear(); // removes flags and allows
		              // further operations
		file.seekp(position); // go back to insertion
		                      // position

		// insert from 25 to 70
		for (int i=25;i<71;i++) {
			file << setw(4) << i << endl;
		}// end for

		// insert rest of the file
		for (unsigned int i=0; i<rest.size(); i++) {
			file << rest[i] << endl;
		}// end for
	}// end if/else
	
	cout << "Done!\nCheck your file." << endl;
	return 0;
}// end main()
