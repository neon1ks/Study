#include <stdexcept>
#include <iostream>
#include <typeinfo>

class X : public std::runtime_error  // I use runtime_error a lot
{                                    // its derived from std::exception
public:                              // And has an implementation of what()
    explicit X(std::string const &msg) : runtime_error(msg) { }
};

int main()
{
    try {
        throw X("Test");
    } catch (std::exception const &e) {
        std::cout << "Message: " << e.what() << "\n";

        /*
         * Note this is platform/compiler specific
         * Your milage may very
         */
        std::cout << "Type:    " << typeid(e).name() << "\n";
    }
}
