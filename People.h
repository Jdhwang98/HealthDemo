//
// Created by Johnny on 1/30/2023.
//

#ifndef HEALTHPROGRAM_PEOPLE_H
#define HEALTHPROGRAM_PEOPLE_H

#include <iostream>
#include <vector>
#include <string>

class People {
private:
    std::string clubMemberName;
    char clubMemberGender;
    float clubMemberActivityLevel = 0;
    float clubMemberAge;
    float clubMemberWeight;

public:
    //constructors
    People();
    People(std::string Name, char Gender, float ActivityLevel, float Age, float Weight);

    //setters
    void setClubMemberName(std::string name);
    void setClubMemberGender(char clubMemberGender);
    void setClubMemberActivityLevel(float clubMemberActivityLevel);
    void setClubMemberAge(float age);
    void setClubMemberWeight(float weight);

    //getters
    std::string getClubMemberName();
    char getClubMemberGender() const;
    float getClubMemberActivityLevel() const;
    float getClubMemberAge() const;
    float getClubMemberWeight() const;

    //functions
    void printClubMemberInfo();

    //overloaded operators
    bool operator < (const People& people) const;
    bool operator > (const People& people) const;
};


#endif //HEALTHPROGRAM_PEOPLE_H
