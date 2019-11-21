#include <iostream>
#include <time.h>
#include "llrbt.h"

using std::endl;
using std::cout;

#define AMNT 10
#define RANDRANGE 100

int main() {
	int ins = 0; // Number to insert
	int	del = 0; // Number to delete
	LeftLeaningRedBlackTree<int> llrbt;
	srand(time(NULL));

	for (int i = 0; i < AMNT; i++) {
		ins = (std::rand() % RANDRANGE + 1); // Random number range is 1 - 100
		if (i == 3) { // Remove the 4th variable inserted 
			del = ins;
		}
		cout << "Inserting Value: " << ins << endl;
		llrbt.add(ins);
		llrbt.preorderTraverse();
		cout << endl;
	}

	cout << "Deleting value: " << del << endl;
	llrbt.remove(del);
	llrbt.preorderTraverse();

	return 0;
}