#include "People.h"
#include <algorithm>

float averageAge(std::vector<People>& clubMembers);
float averageWeight(std::vector<People>& clubMembers);
float averageActivityLevel(std::vector<People>& clubMembers);
void sortFemale(std::vector<People>& clubMembers);
void sortMale(std::vector<People>& clubMembers);

int main() {
    //declaration of members
    People p1("Alex",'M',3,23,150.0);
    People p2("Indigo",'M',0,25,180.5);
    People p3("Johnathan",'M',4,24,171.2);
    People p6("Carolyn", 'F', 0, 20, 150);
    People p4("Ian",'M',2,21,200.1);
    People p5("Cathy", 'F', 1,21,142);

    //pushing to vector
    std::vector<People> clubMembers;
    clubMembers.push_back(p1);
    clubMembers.push_back(p2);
    clubMembers.push_back(p3);
    clubMembers.push_back(p4);
    clubMembers.push_back(p5);
    clubMembers.push_back(p6);

    bool isOnline = false;
    char response;

    std::cout << "welcome to planet fitness" << std::endl;
    std::cout << "Here are some options: \nEnter '1': to see all current members information. \nEnter '2': to see average club member age. "
                 "\nEnter '3': to see average club member activity level. \nEnter '4': to see average club member weight. \nEnter '5': to edit member information."
                 " \nEnter '6': to sort by gender. \nEnter '7': to exit program.\n" << std::endl;

    while (!isOnline) {
        int nestedResponseUser = 0;
        int editResponse = 0;
        int sortGenderResponse = 0;
        float age = 0;
        float actLevel = 0;
        float weight = 0;
        std::cin >> response;
        if (response == '1') {
            for (int i = 0; i < clubMembers.size(); i++) {
                clubMembers[i].printClubMemberInfo();
            }
        }
        else if (response == '2') {
            std::cout << "Average age: " << averageAge(clubMembers);
            std::cout <<std::endl;
        }
        else if (response == '3') {
            std::cout << "Average activity level: " << averageActivityLevel(clubMembers);
            std::cout << std::endl;
        }
        else if (response == '4') {
            std::cout << "Average weight: " << averageWeight(clubMembers);
            std::cout << std::endl;
        }
        else if (response == '5') {
            std::cout << "Which of the following member's information would you like to edit: " << std::endl;
            for (int i = 0; i < clubMembers.size(); i++) {
                std::cout << i << "). " << clubMembers.at(i).getClubMemberName();
                std::cout << std::endl;
            }
            std::cout << "select a user with its corresponding number." << std::endl;
            std::cin >> nestedResponseUser;
            std::cout << "What information would you like to edit for: " << clubMembers.at(nestedResponseUser).getClubMemberName();
            std::cout << "\n1). age \n2). activity level \n3). average weight \nEnter corresponding number for option\n" << std::endl;
            std::cin >> editResponse;
            if (nestedResponseUser <= clubMembers.size()) {
                if (editResponse == 1) {
                    std::cout << "Enter new age: " << std::endl;
                    std::cin >> age;
                    std::cout << std::endl;
                    clubMembers.at(nestedResponseUser).setClubMemberAge(age);
                    std::cout << "User's new age: " << clubMembers.at(nestedResponseUser).getClubMemberAge();
                }
                else if (editResponse == 2) {
                    std::cout << "Enter new activity level: " << std::endl;
                    std::cin >> actLevel;
                    std::cout << std::endl;
                    clubMembers.at(nestedResponseUser).setClubMemberActivityLevel(actLevel);
                    std::cout << "User's new activity level: " << clubMembers.at(nestedResponseUser).getClubMemberActivityLevel();
                }
                else if (editResponse == 3) {
                    std::cout << "Enter new weight: " << std::endl;
                    std::cin >> weight;
                    std::cout << std::endl;
                    clubMembers.at(nestedResponseUser).setClubMemberWeight(weight);
                    std::cout << "User's new weight: " << clubMembers.at(nestedResponseUser).getClubMemberWeight();
                }
            }
        }
        else if (response == '6') {
            std::cout << "Would you like to sort from female to male or male to female?" << std::endl;
            std::cout << "Enter '1': to sort from female - male. \nEnter '2': to sort from male - female.\n" << std::endl;
            std::cout << "Please enter choice: " << std::endl;
            std::cin >> sortGenderResponse;
            if (sortGenderResponse == 1) {
                sortFemale(clubMembers);
            }
            else if (sortGenderResponse == 2) {
                sortMale(clubMembers);
            }
        }
        else if (response == '7') {
            isOnline = true;
        }
        else {
            isOnline = true;
        }
        std::cout << "\nEnter '1': to see all current members information. \nEnter '2': to see average club member age. "
                     "\nEnter '3': to see average club member activity level. \nEnter '4': to see average club member weight. "
                     "\nEnter '5': to edit member information. \nEnter '6': to sort by gender. \nEnter '7': to exit program.\n " << std::endl;
    }

    return 0;
}

float averageAge(std::vector<People>& clubMembers) {
    float averageAge = 0;
    float totalAge = 0;
    for (int i = 0; i < clubMembers.size(); i++) {
        totalAge += clubMembers[i].getClubMemberAge();
    }
    averageAge = totalAge/clubMembers.size();
    return averageAge;
}
float averageWeight(std::vector<People>& clubMembers) {
    float averageWeight = 0;
    float totalWeight = 0;
    for (int i = 0; i < clubMembers.size(); i++) {
        totalWeight += clubMembers[i].getClubMemberWeight();
    }
    averageWeight = totalWeight/clubMembers.size();
    return averageWeight;
}
float averageActivityLevel(std::vector<People>& clubMembers) {
    float averageActivityLevel = 0;
    float totalActivityLevel = 0;
    for (int i = 0; i < clubMembers.size(); i++) {
        totalActivityLevel += clubMembers[i].getClubMemberActivityLevel();
    }
    averageActivityLevel = totalActivityLevel/clubMembers.size();
    return averageActivityLevel;
}

//too dumb to sort objects
void sortFemale(std::vector<People>& clubMembers) {
    std::sort(clubMembers.begin(),clubMembers.end(), std::less<People>());
}
void sortMale(std::vector<People>& clubMembers) {
    std::sort(clubMembers.begin(),clubMembers.end(), std::greater<People>());
}
