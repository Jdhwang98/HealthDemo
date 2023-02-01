//
// Created by Johnny on 1/30/2023.
//

#include "People.h"


People::People() = default;

People::People(std::string Name, char Gender, float ActivityLevel, float Age,
               float Weight) {
   this->clubMemberName = Name;
   this->clubMemberGender = Gender;
   this->clubMemberActivityLevel = ActivityLevel;
   this->clubMemberAge = Age;
   this->clubMemberWeight = Weight;
}

void People::setClubMemberName(std::string name) {
    clubMemberName = name;
}

void People::setClubMemberGender(char gender) {
    clubMemberGender = gender;
}

void People::setClubMemberActivityLevel(float activityLevel) {
    clubMemberActivityLevel = activityLevel;
}

void People::setClubMemberAge(float age) {
    clubMemberAge = age;
}

void People::setClubMemberWeight(float weight) {
    clubMemberWeight = weight;
}

std::string People::getClubMemberName() {
    return clubMemberName;
}

char People::getClubMemberGender() const {
    return clubMemberGender;
}

float People::getClubMemberActivityLevel() const {
    return clubMemberActivityLevel;
}

float People::getClubMemberAge() const {
    return clubMemberAge;
}

float People::getClubMemberWeight() const {
    return clubMemberWeight;
}

void People::printClubMemberInfo() {
    std::cout << "\nClub member name: " << getClubMemberName();
    std::cout << "\nClub member gender: " << getClubMemberGender();
    std::cout << "\nClub member activity level: " << getClubMemberActivityLevel();
    std::cout << "\nClub member age: " << getClubMemberAge();
    std::cout << "\nClub member weight: " << getClubMemberWeight();
    std::cout << std::endl;
}

bool People::operator<(const People &people) const {
    return this->clubMemberGender < people.clubMemberGender;
}

bool People::operator>(const People &people) const {
    return this->clubMemberGender > people.clubMemberGender;
}
