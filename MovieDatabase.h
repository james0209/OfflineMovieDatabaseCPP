//
// Created by james on 08/04/2020.
//

#include <set>
#include <vector>
#include <functional>
#include "Movie.h"

//#ifndef CW2_MOVIEDATABASE_H
//#define CW2_MOVIEDATABASE_H

class MovieDatabase{
private:
    std::vector<Movie> mdb;

public:
    /*********  Constructors  **********/
    MovieDatabase();
    MovieDatabase(std::string file);
    MovieDatabase(const MovieDatabase &orig);
    MovieDatabase(std::vector<Movie> movie_list);

    /*********  Queries  **********/
    bool addMovie(Movie movie);
    void delete_movie(const Movie& movie);

    /*********  Destructor  **********/
    virtual ~MovieDatabase();

    inline std::vector<Movie> getDB(){
        return this->mdb;
    }

    template <typename Compare>
    void sort(const Compare &comp)
    {
        if (!mdb.empty()){
            std::sort(mdb.begin(), mdb.end(), comp);
        } else {
            std::cerr << "Movie Database is empty - please populate and then sort" << std::endl;
        }
    }

    //Stream based I/O using operator overloading
    friend std::ostream &operator<<(std::ostream &output, MovieDatabase &db);
    friend std::istream &operator>>(std::istream &input, MovieDatabase &db);

};





