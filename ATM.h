#ifndef _AUTOMAT_H_
#define _AUTOMAT_H_
#include <string>
using namespace std;

// use for friend class(maybe)
class Operator; 

class ATM {
  private:
  // Daten der Klasse "Automat"
  unsigned long money;
  string location;

  // Klassenattribute
  static int zugriffe; 

  public:
  // Deklaration der Konstruktoren
  ATM(unsigned long g, string s);
  explicit ATM(unsigned long g);
  ATM(string s);
  ATM();

  // Deklaration des Destruktors
  ~ATM(); 

  // Elementfunktionen der Klasse "Automat"
  unsigned long get_money() const;
  void set_money(unsigned long g);
  string get_location() const;
  void set_location(string s);
  void init(unsigned long g, string s);

  // functions for class attributes
  int get_zugriffe() const;
  void geld_abheben(unsigned long g);

  // friend
  friend void print_location(ATM&);
  friend class Operator;

  unsigned long operator+(const ATM& a1);
  unsigned long operator+(unsigned long g);
  unsigned long operator+=(const ATM& a1);
  unsigned long operator+=(unsigned long g);

}; // Semicolon!!!!!

// Funktionsdeklaration
bool diffATM(const ATM&, const ATM&); 

ATM diffMoney(const ATM&, const ATM&);

#endif