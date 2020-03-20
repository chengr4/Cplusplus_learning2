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
    /*--------------Reference------------------------*/
    int var=0;
    // reference rvar
    int& rvar = var;
    var = 123;
    cout << "var : " << var << '\n';
    cout << "rvar : " << rvar << '\n';
    rvar = 456;
    cout << "var : " << var << '\n';
    cout << "rvar : " << rvar << '\n';
 

    return 0;
}