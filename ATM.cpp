#include <iostream>
#include <string>
#include "ATM.h"
using namespace std;

int ATM::zugriffe = 0; // Initialisierung!!!!!!!

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

// Definition des Dekonstruktors
ATM::~ATM() {
  cout << get_location() << " remove" << endl;
} 


unsigned long ATM::get_money() const {
  return money;
}

void ATM::set_money(unsigned long g){
  money = g;
}

string ATM::get_location() const {
  return location;
}

void ATM::set_location(string s){
  location = s;
}

void ATM::init(unsigned long g=0, string s="") {
  set_money(g);
  set_location(s);
} 

void ATM::geld_abheben(unsigned long g) {
  // Ist noch Geld im Automaten
  if( get_money()-g <= 0 ) {
    cout << "Kein Geld mehr im Automaten\n";
  } else {
    // Neuen Inhalt berechnen und setzen
    set_money(get_money()-g);
  }
  zugriffe++;
} 

int ATM::get_zugriffe() const {
 return zugriffe;
}
// Funktionsdefinition
bool diffATM(const ATM &a1, const ATM &a2) {
  if( a1.get_location() == a2.get_location() ) {
    return true;
  } else {
    return false;
  }
}

ATM diffMoney(const ATM &a1, const ATM &a2) {
  if( a1.get_money() > a2.get_money() ) {
    return a1;
  } else {
    return a2;
  } 
}

// Operatoren überladen
unsigned long ATM::operator+(const ATM& a1) {
  return (money + a1.money);
}
unsigned long ATM::operator+(unsigned long g) {
  return (money + g);
}
unsigned long ATM::operator+=(unsigned long g) {
  return (money += g);
}
unsigned long ATM::operator+=(const ATM& a1) {
  return (money += a1.money);
} 

// I/O-Operatoren überladen
istream& operator >>(istream& is, ATM& a) {
  cout << "Geld : "; is >> a.money;
  cout << "Standort : "; is >> a.location;
  return is;
}

ostream& operator <<(ostream& os, const ATM& a) {
  cout << "Geld : " << a.get_money() << endl;
  cout << "Standort : " << a.get_location() << endl;
  // class attribute
  cout << "Zugriffe : " << a.get_zugriffe() << endl;
 return os;
} 