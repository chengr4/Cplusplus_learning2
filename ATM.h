#ifndef _AUTOMAT_H_
#define _AUTOMAT_H_
#include <string>
using namespace std;

class ATM {
  private:
  // Daten der Klasse "Automat"
  unsigned long money;
  string location;

  public:

  // Deklaration der Konstruktoren
  ATM(unsigned long g, string s);
  explicit ATM(unsigned long g);
  ATM(string s);
  ATM();

  // Elementfunktionen der Klasse "Automat"
  unsigned long get_money();
  void set_money(unsigned long g);
  string get_location();
  void set_location(string s);
  void init(unsigned long g, string s);
}; // Semicolon!!!!!

#endif