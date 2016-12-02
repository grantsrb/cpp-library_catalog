/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: Book Class inherits from LibraryItem Class. It describes a book
    in the library inventory.
*/

#ifndef BOOK_HPP
#define BOOK_HPP

#include "LibraryItem.hpp"
#include <string>
#include <vector>

class Book: public LibraryItem {
private:
  std::string author;
public:
  Book(std::string idc, std::string t, std::string authorName);
  static const int CHECK_OUT_LENGTH; // Days till overdue
  std::string getAuthor(); // Returns author's name
  void setAuthor(std::string authorName); // Sets author's name
  virtual int getCheckOutLength();
};

#endif
