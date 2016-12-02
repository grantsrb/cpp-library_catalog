/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: The cpp file for the Book Class.
*/

#include "Book.hpp"
#include <string>
#include <vector>

Book::Book(std::string idc, std::string t, std::string authorName): LibraryItem(idc,t) {
  author = authorName;
}

const int Book::CHECK_OUT_LENGTH = 21; // Days till overdue

std::string Book::getAuthor() { // Returns author's name
  return author;
}

void Book::setAuthor(std::string authorName) { // Sets author's name
  author = authorName;
}

int Book::getCheckOutLength() { // Returns Check Out Length
  return CHECK_OUT_LENGTH;
}
