#include <iostream>
#include <vector>
using namespace std;

#include "shoppingCart.h"
#include "inventory.h"

ShoppingCart::ShoppingCart() {
  ISBN = "";
  email = "";
  pass = "";
  price = "";
  }

ShoppingCart::ShoppingCart(string email, string pass, string ISBN, string price) {
  this->ISBN = ISBN;
  this->email = email;
  this->pass = pass;
  this->price = price;
}

void ShoppingCart::additem(string ISBN){
  return;
}

bool ShoppingCart::removeItem(string name) {
  bool found = false;
  if(!found)
    cout << "Item not found in cart. Nothing removed." << endl;
  return 1;
}


void ShoppingCart::getTotalCost() {
  int total = 0;
  for(int i = 0; i < cartItems.size(); i++)
  {
    cartItems.at(i).getPrice();
  }
  return;
}

float ShoppingCart::getPrice(){
  return;
}

void ShoppingCart::printTotalCost(){
  if(cartItems.size() == 0)
  {
    cout << "SHOPPING CART IS EMPTY" << endl;
  }
  
  for(int i = 0; i < cartItems.size(); i++)
  {
    cartItems.at(i).printTotalCost();
  }
  return;
}
