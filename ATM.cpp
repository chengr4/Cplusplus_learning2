#include <string>
#include "ATM.h"
using namespace std;

// Definition der Konstruktoren
/*ATM::ATM(unsigned long g, string s) {
 set_money(g);
 set_location(s);
}*/

// ----> instead
// usage -> :attribute(assigned value)
ATM::ATM(unsigned long g, string s):money(g),location(s) {}



ATM::ATM(unsigned long g) {
 set_money(g);
 set_location("");
}
ATM::ATM(string s) {
 set_money(0);
 set_location(s);
}
ATM::ATM() {
 set_money(0);
 set_location("");
} 

unsigned long ATM::get_money() {
  return money;
}

void ATM::set_money(unsigned long g){
  money = g;
}

string ATM::get_location() {
  return location;
}

void ATM::set_location(string s){
  location = s;
}

void ATM::init(unsigned long g=0, string s="") {
  set_money(g);
  set_location(s);
} 