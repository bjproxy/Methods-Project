#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include "inventory.h"

using namespace std;

class ShoppingCart{
private:
  vector<ShoppingCart> cartItems;
  string email;
  string pass;
  string ISBN;
  string price;

public:
  ShoppingCart();
  ShoppingCart(string email, string pass, string ISBN, string price);
  void additem(string ISBN);
  bool removeItem(string name);
  void getTotalCost();
  void printTotalCost();
  string getUser(string email);
  void viewCart();
  void checkout();
  float getPrice();
};

#endif

