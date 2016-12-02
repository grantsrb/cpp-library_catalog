/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: Movie Class inherits from LibraryItem Class. It describes a movie
    in the library inventory.
*/

#include "Movie.hpp"
#include <string>
#include <vector>

Movie::Movie(std::string idc, std::string t, std::string directorName): LibraryItem(idc,t) {
  director = directorName;
}

const int Movie::CHECK_OUT_LENGTH = 7; // Days till overdue

std::string Movie::getDirector() { // Returns Director's Name
  return director;
}

void Movie::setDirector(std::string directorName){ // Set's director's name
  director = directorName;
}

int Movie::getCheckOutLength() { // Returns static check out length
  return CHECK_OUT_LENGTH;
}
