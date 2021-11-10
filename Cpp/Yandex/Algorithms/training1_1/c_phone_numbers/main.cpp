#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 3;

std::string normal_phone(const string &phone)
{
    std::string result;
    size_t start = 0;
    if (phone[0] == '+' && phone[1] == '7') {
        start = 2;
        result.push_back('8');
    }
    for (size_t i = start; i < phone.size(); ++i) {
        if (phone[i] != '-' && phone[i] != '(' && phone[i] != ')') {
            result.push_back(phone[i]);
        }
    }
    if (result.size() == 7) {
        result = "8495" + result;
    }
    return result;
}

int main()
{
    std::string new_phone;
    std::vector<std::string> phones(N);
    std::cin >> new_phone;
    new_phone = normal_phone(new_phone);
    for (auto &phone : phones) {
        std::cin >> phone;
    }
    for (const auto &phone : phones) {

        if (new_phone == normal_phone(phone)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
