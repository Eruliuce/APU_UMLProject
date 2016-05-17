#include <iostream>
#include "LearningManagementSystem.h"

using namespace std;

int main()
{
    LearningManagementSystem lms;
    cout << "Creation admin : " << lms.signin("admin", "admin", "Admi", "Nistor", "admi.nistor@mail.com", "0123456789", true) << endl;
    cout << "Creation user already registered : " << lms.signin("admin", "a", "a", "a", "a", "a", 0) << endl;
    cout << "Creation new user : " << lms.signin("user1", "user1", "a", "a", "a", "a", 0) << endl;

    cout << "Login correct : " << lms.login("admin", "admin") << endl;
    cout << "Password incorrect : " << lms.login("admin", "trololo") << endl;
    cout << "Login inexistant : " << lms.login("Lololo", "lilili") << endl;

    return 0;
}
