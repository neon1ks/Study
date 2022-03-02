#include <iostream>
#include <filesystem>

using namespace std;

bool createDirectory(const std::filesystem::path &directoryPath) {
    std::error_code ec;
    std::filesystem::create_directories(directoryPath, ec);

    if (static_cast<bool>(ec)) {
        std::cerr << ec.message() << std::endl;
    }

    return !static_cast<bool>(ec);
}

int main()
{
    std::string fileName = "/home/maksim/Temp/test.txt";
    bool status = createDirectory(fileName);

    cout << "status = " << status << endl;
    return 0;
}
