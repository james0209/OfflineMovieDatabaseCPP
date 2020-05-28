#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "MovieDatabase.h"

int main() {

    std::cout << "Task 1: Read in movies, create objects of them, and store them in a MovieDatabase \n";
    MovieDatabase *movieDatabase = new MovieDatabase();
    std::ifstream input_file("films.txt");

    if (input_file.is_open()) { input_file >> *movieDatabase; }

    //Test Default constructor
    //Movie LoTR("Lord of the Rings", 2005, "PG-13", "Action/Adventure/Fantasy",140, 6);
    //movieDatabase->addMovie(LoTR);
    //std::cout << *movieDatabase;

    std::cout << "Task 2: Sort movies in chronological order and display them \n";

    try
    {
        //Lambda sort
        auto sortAscending = [] (Movie const &m1, Movie const &m2) -> bool
                {
                    return (m1.get_year() < m2.get_year());
                };
        movieDatabase->sort(sortAscending);

        std::cout << *movieDatabase;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "Task 3: Display the third longest Film-Noir \n";
    // Get only the movies which are film-noir and then sort them based on duration
    // Waste of resources sorting the entire vector

    try
    {
        MovieDatabase *movieDatabase2 = new MovieDatabase();
        for (auto & movie : movieDatabase->getDB()) {
            if(movie.get_genres().find("Film-Noir") != std::string::npos){
                movieDatabase2->addMovie(movie);
            }
        }

        //Lambda sort
        auto sortDuration = [] (Movie const &m1, Movie const &m2) -> bool
        {
            return (m1.get_duration() < m2.get_duration());
        };
        movieDatabase2->sort(sortDuration);

        std::cout << (movieDatabase2->getDB())[2] << "\n";

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "Task 4: Display the eighth most recent UNRATED film \n";

    try
    {
        MovieDatabase *movieDatabase3 = new MovieDatabase();
        for (auto & movie : movieDatabase->getDB()) {
            if(movie.get_age_certificate().find("UNRATED") != std::string::npos){
                movieDatabase3->addMovie(movie);
            }
        }

        //Lambda sort
        auto sortAscending = [] (Movie const &m1, Movie const &m2) -> bool
        {
            return (m1.get_year() < m2.get_year());
        };
        movieDatabase3->sort(sortAscending);

        std::cout << (movieDatabase3->getDB())[movieDatabase3->getDB().size() - 8] << "\n";

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "Task 5: Display the film with the longest title \n";

    try
    {
        //Lambda sort
        auto sortAscendingTitle = [] (Movie const &m1, Movie const &m2) -> bool
        {
            return (m1.get_title().length() > m2.get_title().length());
        };
        movieDatabase->sort(sortAscendingTitle);

        std::cout << (movieDatabase->getDB())[0] << "\n";

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }


    return 0;
}
