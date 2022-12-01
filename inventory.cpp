#include "inventory.h"
using namespace std;

Inventory::Inventory() {
  ISBN = "";
  int quantity;
}

Inventory::Inventory(string ISBN, int quantity, float price) {
  this->ISBN = ISBN;
  this->quantity = quantity;
  this->price = price;
}

string Inventory::getISBN() {
  return ISBN;
}

void Inventory::setISBN(string ISBN) {
  this -> ISBN = ISBN;
}

int Inventory::getQuantity(){
  return quantity;
}

void Inventory::setQuantity(int quantity){
  this -> quantity = quantity;
}

float Inventory::getPrice(){
  return price;
}

void Inventory::setPrice(float price){
  this -> price = price;
}

