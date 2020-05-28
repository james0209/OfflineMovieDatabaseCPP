//
// Created by james on 18/03/2020.
//

#ifndef CW2_MOVIE_H
#define CW2_MOVIE_H
#include <string>
#include <iomanip>

class Movie {

private:
    /*********  Private fields  **********/

    std::string title;
    float avg_rating{};
    int year{}, duration{};
    std::string  age_certificate;
    std::string  genre;

    struct Age_ratings // Bit field for age ratings
    {
        bool PG13 : 1, R : 1, PG : 1,
                NA : 1, NR : 1, UR : 1,
                PASS : 1, G : 1, APPR : 1,
                M : 1, X : 1, TV14 : 1;
    };
    Age_ratings age_rating = {0};


public:
    /*********  Constructors  **********/
    Movie();
    Movie(std::string title, int year, std::string age_rating, std::string genres,
          int duration, float avg_rating);
    Movie(const Movie &orig);
    /*********  Destructor  **********/
    virtual ~Movie();

    //Stream based I/O using operator overloading
    friend std::istream &operator >>(std::istream &input, Movie &mov);
    friend std::ostream &operator <<(std::ostream &output, Movie &mov);

    //operators to sort Movie attributes
    friend bool operator <(Movie &mov1, Movie &mov2);
    friend bool operator >(Movie &mov1, Movie &mov2);
    friend bool operator >=(Movie &mov1, Movie &mov2);
    friend bool operator <=(Movie &mov1, Movie &mov2);

    inline std::string get_title() const { return this->title; }
    inline int get_year() const { return this->year; }
    inline std::string get_age_certificate() const { return this->age_certificate; }
    inline std::string get_genres() const { return this->genre; }
    inline int get_duration() const { return this->duration; }
    inline float get_avg_rating() const { return this->avg_rating; }
    inline std::string get_age_rating() const;

    static void setTitle(std::string title) {
        title = title;
    }


};

inline std::string Movie::get_age_rating() const
{
    std::string age_rating_out;
    if (age_rating.PG13)
        age_rating_out.assign("PG-13");
    if (age_rating.R)
        age_rating_out.assign("R");
    if (age_rating.PG)
        age_rating_out.assign("PG");
    if (age_rating.NA)
        age_rating_out.assign("N/A");
    if (age_rating.NR)
        age_rating_out.assign("NOT RATED");
    if (age_rating.UR)
        age_rating_out.assign("UNRATED");
    if (age_rating.PASS)
        age_rating_out.assign("PASSED");
    if (age_rating.G)
        age_rating_out.assign("G");
    if (age_rating.APPR)
        age_rating_out.assign("APPROVED");
    if (age_rating.M)
        age_rating_out.assign("M");
    if (age_rating.X)
        age_rating_out.assign("X");
    if (age_rating.TV14)
        age_rating_out.assign("TV-14");
    return age_rating_out;
}

#endif //CW2_MOVIE_H
