#include <iostream>
#include <cmath>
#include "LLRBT.h"

#define RAND_COUNT 10
#define MY_RAND_MAX 50

using std::cout;

int main(int argc, char const *argv[])
{
    int arr[RAND_COUNT];

    cout << "INSERTING: ";

    for (int i = 0; i < RAND_COUNT; i++) {
        int val = rand() % MY_RAND_MAX;
        cout << val << ' ';
        arr[i] = val;
    }

    cout << "\nRESULTANT TREE:\n";
    
    LLRBT<int> tree;
    for (int i = 0; i < RAND_COUNT; i++)
    {
        tree.insert(arr[i]);
    }
    
    tree.print();
    
    cout << "\n TREE AFTER REMOVING " << arr[3] << ": \n";

    tree.remove(arr[3]);

    tree.print();

    cout << "\n";

    return 0;
}
