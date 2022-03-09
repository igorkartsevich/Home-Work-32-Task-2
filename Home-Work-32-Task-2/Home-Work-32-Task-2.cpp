#include <iostream>
#include <algorithm>
#include "Home-Work-32-Task-2.h"
#include "nlohmann/json.hpp"

#define FILMCOUNTER_MAX 2

class FilmInfo {
public:
	void setFilmInfo() {
		std::cout << "Enter film's information\n";
		std::cout << "Country: "; std::cin >> country;
		std::cout << "Year: "; std::cin >> year;
		std::cout << "Producer: "; std::cin >> producer;
		std::cout << "Director: "; std::cin >> director;
		std::cout << "Writer: "; std::cin >> writer;
		std::cout << "Main Actor: "; std::cin >> mainActor;
		std::cout << "Main Role: "; std::cin >> mainRole;
		std::cout << std::endl;
	}

	nlohmann::json getFilmInfo() {
		nlohmann::json filmInfo {
			{ "Country: ", country },
			{ "Year: ", year },
			{ "Producer: ", producer },
			{ "Director: ", director },
			{ "Writer: ", writer },
			{ "Main Actor: ", mainActor },
			{ "Main Role: ", mainRole }
		};
		return filmInfo;
	}

private:
	std::string name;
	std::string country;
	int year = 0;
	std::string producer;
	std::string director;
	std::string writer;
	std::string mainActor;
	std::string mainRole;
};

void setFilmCollection(std::map<std::string, nlohmann::json>& filmCollection, const int counterMax) {
	int counter = 0;
	do {
		std::string filmName;
		std::cout << "Enter the name of film: "; std::cin >> filmName;
		FilmInfo filmInfo;
		filmInfo.setFilmInfo();
		filmCollection.emplace(filmName, filmInfo.getFilmInfo());

	} while (++counter != counterMax);
}

void findMainActorInfo(const std::map<std::string, nlohmann::json>& filmCollection, const std::string& name) {
	std::for_each(filmCollection.begin(), filmCollection.end(), [&] (const auto& filmInfo) {
		if (filmInfo.second["Main Actor: "] == name)
			std::cout << "Film: " << filmInfo.first << " and role: " << filmInfo.second["Main Role: "] << std::endl;
	});
}

int main()
{
	std::map<std::string, nlohmann::json> filmCollection;
	
	setFilmCollection(filmCollection, FILMCOUNTER_MAX);

	std::string actorName;
	std::cout << "Enter the name of the main actor to search for: "; std::cin >> actorName;
	findMainActorInfo(filmCollection, actorName);

	return 0;
}
