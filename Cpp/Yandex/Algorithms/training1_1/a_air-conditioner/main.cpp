#include <iostream>
#include <string>

using namespace std;

int main()
{
    int troom = 0;
    int tcond = 0;
    std::string mode;
    std::cin >> troom >> tcond;
    std::cin >> mode;

    int result = troom;

    if (mode == "freeze") {
        if (troom > tcond) {
            result = tcond;
        }
    } else if (mode == "heat") {
        if (troom < tcond) {
            result = tcond;
        }
    } else if (mode == "auto") {
        result = tcond;
    } else if (mode == "fan") {
        ;
    }

    std::cout << result << std::endl;
    return 0;
}
