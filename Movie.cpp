//
// Created by james on 18/03/2020.
//

#include "Movie.h"
#include <string>
#include <sstream>
#include <iostream>
#include <utility>


// Default constructor
Movie::Movie() = default;

Movie::Movie(const Movie &orig)
{
    this->title = orig.title;
    this->year = orig.year;
    this->age_certificate = orig.age_certificate;
    this->genre = orig.genre;
    this->duration = orig.duration;
    this->avg_rating = orig.avg_rating;
}

Movie::Movie(std::string title, int year, std::string age_certificate, std::string genres,
             int duration, float avg_rating) {
    this->title = title;
    // Check if year of movie is viable
    if (year < 1800 || year > 2100) {
        throw "ERROR: Couldn't create '" + title + "'. Invalid date.";
    }
    this->year = year;
    this->age_certificate = std::move(age_certificate);
    this->genre = std::move(genres);
    this->duration = duration;
    this->avg_rating = avg_rating;
}

//Destructor
Movie::~Movie(){}

//Stream based I/O using operator overloading
std::ostream &operator<<(std::ostream &output, Movie &mov) {
    return output << std::quoted(mov.get_title()) << ','
              << mov.get_year() << ','
              << std::quoted(mov.get_age_certificate()) << ','
              << std::quoted(mov.get_genres()) << ','
              << mov.get_duration() << ','
              << std::setprecision(2) << std::fixed << mov.get_avg_rating();
}

std::istream &operator>>(std::istream &input, Movie &mov){
    int date, duration;
    float avg_rating;
    std::string title, ageRating, genres;
    char c;

    // Checks if the inputs are correct, then tries to create a movie
    if (input >> quoted(title) >> c >> date >> c >> quoted(ageRating) >>
    c >> quoted(genres) >> c >> duration >> c >> avg_rating){
        try{

            mov = Movie(title, date, ageRating, genres, duration, avg_rating);

            //Switch statement in c++ uses int value, so used if statements instead

            if (ageRating == "PG-13")
            {
                mov.age_rating.PG13 = true;
            }
            if (ageRating == "R")
            {
                mov.age_rating.R = true;
            }
            if (ageRating == "PG")
            {
                mov.age_rating.PG = true;
            }
            if (ageRating == "N/A")
            {
                mov.age_rating.NA = true;
            }
            if (ageRating == "NOT RATED")
            {
                mov.age_rating.NR = true;
            }
            if (ageRating == "UNRATED")
            {
                mov.age_rating.UR = true;
            }
            if (ageRating == "PASSED")
            {
                mov.age_rating.PASS = true;
            }
            if (ageRating == "G")
            {
                mov.age_rating.G = true;
            }
            if (ageRating == "APPROVED")
            {
                mov.age_rating.APPR = true;
            }
            if (ageRating == "M")
            {
                mov.age_rating.M = true;
            }
            if (ageRating == "X")
            {
                mov.age_rating.X = true;
            }
            if (ageRating == "TV-14")
            {
                mov.age_rating.TV14 = true;
            }

        } catch (const std::exception &exc) {
            std::cerr << "Error: Failed to create " + title + exc.what() << std::endl;
        }
    } else {
        input.clear(std::ios_base::failbit);
    }

    return input;
}


