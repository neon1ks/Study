#include <iostream>

using namespace std;

//struct Incognizable
//{
//    int a = 0;
//    int b = 0;
//    Incognizable(int a = 0, int b = 0)
//    {
//        this->a = a;
//        this->b = b;
//    }
//};

// Требует C++ 17

struct Incognizable
{
    int x = 0;
    int y = 0;
};

int main()
{
    Incognizable a;
    Incognizable b = {};
    Incognizable c = { 0 };
    Incognizable d = { 0, 1 };
    return 0;
}

/*
struct Incognizable {
  int x = 0;
  int y = 0;
};
*/
