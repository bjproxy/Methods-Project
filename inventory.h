#include <string>
#include "book.h"

using std::string;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory 
{
  private:
  string ISBN;
  int quantity;
  float price;
  public:  
  Inventory();
  Inventory(string ISBN, int quantity, float price);

  //getters
  string getISBN();
  int getQuantity();
  float getPrice();

  //setters
  void setISBN(string ISBN);
  void setQuantity(int quantity);
  void setPrice(float price);

};

#endif
