#include <iostream>
// namespace std == std::
using namespace std;
#include <vector>
#include <string>

#include "myHeader.h"
using namespace PLZ;

// Application 2: References as the return value of a function
int& test_referenz() {
    // here should be always "static" -> static space instead of stack -> won't disappear
    static int iwert = 10;
    return iwert;
}

// Globale Deklarationen
void funktion( void );
int iwert_Globale = 1;


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

    int var1 = 100;
    int var2 = 200;
    int& rvar1 = var1;
    cout << rvar1 << endl;
    //... und was passiert jetzt? (don't understand here)
    rvar1 = var2;
    cout << rvar1 << endl;

    /*--------------Reference application------------------------*/
    int* iptr=0L; // iptr = null
    int wert=0; 

    // Wert von "iwert" an "wert" zuweisen
    wert = test_referenz();
    // "iptr" auf "iwert" zeigen lassen
    iptr = &test_referenz();

    cout << "iptr : " << *iptr << '\n';
    cout << "wert : " << wert << '\n';

    // ... entspricht ++iwert
    ++test_referenz();
    cout << "iptr : " << *iptr << '\n';
    cout << "wert : " << wert << '\n';

    // iwert verdoppeln
    test_referenz() = test_referenz() * 2;

    cout << "iptr : " << *iptr << '\n';
    cout << "wert : " << wert << '\n'; 

    /*--------------Container vector------------------------*/
    vector<int> ivec (10); // size = 10
    cout << "Anzahl Elemente : " << ivec.size() << endl;
    ivec[0] = 123; // erstes Element
    ivec.at(1) = 234; // zweites Element
    ivec.push_back(456); // letztes Element (angehängt als neues Element)
    ivec.resize(ivec.size()+2); // Vektor um 2 Elemente vergrößern

    cout << "Wert für 7. Element : ";
    // cin >> ivec.at(6);

    // Elemente ausgeben
    for(size_t i=0; i < ivec.size(); i++) {
    cout << ivec[i] << endl;
    }

    /*--------------Container String------------------------*/
    string str1("String Nr. 1");
    string str2 = str1; //  einfache Zuweisung ist möglich
    string str3;
    cout << "str1: " << str1 << endl;

    cout << "String eingeben: ";
    getline(cin, str3);  // eine komplette Zeile einlesen
    cout << "Ihre Eingabe: " << str3 << endl; // print out

    str1.assign(str3); // replace str1 with str3
    cout << "str1: "<< str1 << endl; 

    cout << "Zeichen in str1: " << str1.size() << endl;

    str1.append(str2); // zwei Strings aneinander hängen
    cout << "str1: "<< str1 << endl;  

   /*--------------Dynamische Speicherverwaltung------------------------*/
    int *iptr_DS = new int;
    int *iptr_DS2 = new int [50]; 

    vector<int>* vptr = new vector<int>(20);
    (*vptr)[0] =3;
    (*vptr)[1] =4;
    vptr->push_back(5);

    // release
    delete iptr_DS;
    delete [] iptr_DS2;

    /*--------------Namensräume deklarieren------------------------*/
    int gesamt;

    VIP_Bereich::funktion();
    User_Bereich::funktion();
    funktion(); // oder: ::funktion();
    VIP_Bereich::iwert = 66;
    VIP_Bereich::funktion();

    // Rechnung mit Werten aus mehreren Namensbereichen
    gesamt = VIP_Bereich::iwert + User_Bereich::iwert + ::iwert_Globale;
    cout << "Summe aus allen Namensbereichen : " << gesamt << '\n';

    return 0;
}

// --- Defintionen ---
void funktion( void ) {
 cout << "Globale funktion() : "
 << "Wert von iwert : " << iwert_Globale << endl;
}
void VIP_Bereich::funktion( void ) {
 cout << "VIP_Bereich::funktion() : "
 << "Wert von iwert : " << iwert << endl;
}
void User_Bereich::funktion( void ) {
 cout << "User_Bereich::funktion() : "
 << "Wert von iwert : " << iwert << endl;
} 

