/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: The cpp file for the Album Class.
*/


#include "Album.hpp"
#include <string>
#include <vector>

Album::Album(std::string idc, std::string t, std::string artistName):LibraryItem(idc,t) {
  artist = artistName;
}

const int Album::CHECK_OUT_LENGTH = 14; // Days till overdue

std::string Album::getArtist() { // Returns Artist's Name
  return artist;
}

void Album::setArtist(std::string artistName) { // Sets Artist's Name
  artist = artistName;
}

int Album::getCheckOutLength() { return CHECK_OUT_LENGTH;}
