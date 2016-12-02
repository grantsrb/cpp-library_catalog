/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: Movie Class inherits from LibraryItem Class. It describes a movie
    in the library inventory.
*/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "LibraryItem.hpp"
#include <string>
#include <vector>

class Movie: public LibraryItem {
private:
  std::string director;
public:
  Movie(std::string idc, std::string t, std::string directorName);
  static const int CHECK_OUT_LENGTH; // Days till overdue
  std::string getDirector(); // Returns Director's Name
  void setDirector(std::string directorName); // Set's director's name
  virtual int getCheckOutLength();
};
#endif
