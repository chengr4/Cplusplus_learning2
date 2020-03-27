#include <iostream>
#include <vector>
#include <string>
#include "ATM.h"
using namespace std; 

int main(void) {
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
  return 0;

}

