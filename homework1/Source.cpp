#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char** argv) {

		int UserInput, SpacesNeededInRow, HashtagsInRow, HashtagsNeededInRow, Row = 1;
	
		 cout << "Enter a positive integer: ";
	     cin >> UserInput;
	
		while (cin.fail() || UserInput < 1) {
		if (cin.fail()) {
			cout << "You didn't enter an integer. Enter a positive integer: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> UserInput;
			
		}
		else {
			cout << "You entered zero or a negative integer. Enter a positive integer: ";
			cin.clear();
			cin.ignore(256, '\n');
		    cin >> UserInput;
			
				
		}
		
	}
	
		 cout << "Thank you!" << endl;
	
		 while (Row <= UserInput) {
		
			 HashtagsInRow = 0;
		     HashtagsNeededInRow = 2 * Row - 1;
		     SpacesNeededInRow = UserInput - Row;
		
			 while (SpacesNeededInRow > 0) { 
				 cout << " ";
			     SpacesNeededInRow--;
			 }

	       	 while (HashtagsInRow < HashtagsNeededInRow) {
				 cout << "#";
			     HashtagsInRow++;
			
		     }
		     cout << endl;
	       	 Row++;
		
	     }
#if 0
		 //Everything is going to be backwards now. We will be counting the Row
		//down to zero instead of up from 1 as before. The second half of this code
		//is similar but different to the first half.
#endif
		Row = UserInput - 1;
	while (Row > 0) {
		
			 HashtagsInRow = 0;
	
			 HashtagsNeededInRow = 2 * Row - 1;
		     SpacesNeededInRow = UserInput - Row;
		
			 while (SpacesNeededInRow > 0) {
			cout << " ";
			SpacesNeededInRow--;
			
		}
	 while (HashtagsInRow < HashtagsNeededInRow) {
			 cout << "#";
			 HashtagsInRow++;
			
		}
		cout << endl;
	 Row--;
		
	}
	
}