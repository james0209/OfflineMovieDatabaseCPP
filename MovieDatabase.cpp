//
// Created by james on 08/04/2020.
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include <ostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>
#include <tgmath.h>
#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {}

MovieDatabase::MovieDatabase(const MovieDatabase &orig)
{
    mdb = orig.mdb;
}

MovieDatabase::~MovieDatabase()
{
    mdb.clear();
}

bool MovieDatabase::addMovie(Movie mov){
    try{
        this->mdb.push_back(mov);
        return true;
    }catch (const std::exception &exc){
        std::cout << "An error occurred adding the movie." << std::endl;
        return false;
    }
}

void MovieDatabase::delete_movie(const Movie& movie) {
    if (mdb.empty()) return;
}

//Stream based I/O using operator overloading
std::istream &operator>>(std::istream &input, MovieDatabase &db) {
    std::string line;
    //std::getline(input, line);
    line.append("\n");
    //capture each line of the txt file
    while (getline(input, line))
    {

        Movie movie;

        std::istringstream iss(line);

        iss >> movie;
        //add movie to the database
        db.addMovie(movie);
    }
    std::cout << "Movies successfully read in \n";
    return input;
}

std::ostream &operator<<(std::ostream &output, MovieDatabase &db){
    for(Movie mov : db.mdb){
        output << mov << std::endl;
    }
    return output;
}


