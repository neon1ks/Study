#include <iostream>

using namespace std;

int algorithm(int code, int interactor, int cheker)
{
    if (interactor == 0) {
        if (code != 0) {
            return 3;
        }
        return cheker;
    }
    if (interactor == 1) {
        return cheker;
    }
    if (interactor == 4) {
        if (code != 0) {
            return 3;
        }
        return 4;
    }
    if (interactor == 6) {
        return 0;
    }
    if (interactor == 7) {
        return 1;
    }
    return interactor;
}

int main()
{
    int code = {};
    int interactor = {};
    int cheker = {};
    cin >> code >> interactor >> cheker;
    int result = algorithm(code, interactor, cheker);
    cout << result << endl;
    return 0;
}
