#include <iostream>
#include <vector>
#include <string>
#include "ATM.h"
using namespace std; 

int main(void) {
  // Objekte können direkt oder mit 'new' dynamisch angelegt werden. 
  // 不用加括號
  ATM *device_ptr = new ATM;
  vector <ATM> vdevice(2);
  ATM device; 
  cout << device.get_money() << endl;

  // Initialisieren
  device_ptr->init(10000, "Bonn, Hauptstrasse 123");
  vdevice[0].init(20000, "Augsburg, Fuggerweg 345");
  vdevice[1].set_money(25000);
  vdevice[1].set_location("Berlin, Berliner Allee 567");
  device.init(123456, "Frankfurt, Goethestrasse 123"); 

  // Ausgabe
  cout << device_ptr->get_money() << endl;
  cout << device_ptr->get_location() << endl;

  for(size_t i=0; i<vdevice.size(); i++) {

    cout << vdevice[i].get_money() << endl;
    cout << vdevice[i].get_location() << endl;
  }

  cout << device.get_money() << endl;
  cout << device.get_location() << endl;
/*---------------------Klassenattribute---------------------------*/
  ATM device01(100000, "Bonn, Marktplatz 1");
  device01.geld_abheben(500);
  device01.geld_abheben(250);
  device01.geld_abheben(1000);
  ATM device02(200000, "New York, Wall Street");
  device02.geld_abheben(990);
  device02.geld_abheben(250); 

  //Welche Werte für die Anzahl der Zugriffe würden
  //hier ausgegeben werden? (結果相同)
  cout << device01.get_zugriffe() << endl;
  cout << device02.get_zugriffe() << endl; 

  /*---- Klassen-Objekte als Rückgabewert von Funktionen ------------*/
  ATM device_compare1(500000, "Klagenfurt");
  ATM device_conpare2(300000, "Dresden");
  // Aufruf der Hilfsfunktion
  ATM device_result = diffMoney(device_compare1, device_conpare2);

  // Auch so kann die Hilfsfunktion verwendet werden
  cout << "Am meisten Geld ist in "
  << device_result.get_location()
  << endl; 

  /*---- Operatoren überladen ------------*/

  return 0;

}

