#include <iostream>
// namespace std == std::
using namespace std;
#include <vector>
#include <string>

#include "myHeader.h"
using namespace PLZ;



int main() {
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    // endl == end line == \n
    // cout == c output
    cout << endl;

    return 0;
}