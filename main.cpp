#include <iostream>
#include <vector>
#include <string>
#include "ATM.h"
using namespace std; 

// about friend
class Rectangle {
    int width, height;
  
  public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    // friend function
    friend Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate (const Rectangle& param) {
  Rectangle res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}

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

  /*---- friend ------------*/
  Rectangle foo;
  Rectangle bar (2,3);
  foo = duplicate (bar);
  cout << foo.area() << '\n';

  /*---- Operatoren überladen ------------*/
  ATM data01(100000, "Dresden, Marktweg 1");
  ATM data02(200000, "Dresden, Am Ufer 12");
  ATM server01(data01+data02, "Dresden (Gesamt)");
  cout << "server01 has : " << server01.get_money() << endl;

  // So geht es auch
  cout << "Gesamt : " << data01 + data02 << endl;
  // Oder so
  unsigned long val = data01 + data02;
  cout << "Gesamt (val) : " << val << endl;

  // So geht es auch
  cout << "Gesamt(add 25000) : " << data01 + 25000 << endl;
  // Oder so
  val = data01 + 25000;
  cout << "Gesamt(add 25000 via val) : " << val << endl;

  // Achtung, hiermit werden Daten geändert !!! (+=)
  data01+=data02;
  cout << "changed data01 : " << data01.get_money() << endl;
  // Auch hier werden Daten geändert (+=)
  data02+=22000;
  cout << "changed data02 : " << data02.get_money() << endl;  

  // E/A-Operatoren überladen
  ATM device_IO;
  cin >> device_IO;
  cout << device_IO;

  return 0;

}

