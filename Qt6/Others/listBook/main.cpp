#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> Name = { { "Пушкин А.С. «Евгений Онегин»" },
        { "Тургенев И.С. «Отцы и дети»" }, { "Логинов С.В. «Свет в окошке»" },
        { "Пушкин А.С. «Евгений Онегин»" },
        { "Стругацкий Б.Н., Стругацкий А.Н. «Понедельник начинается в "
          "субботу»" },
        { "Янссон Т.С. «Волшебная зима»" }, { "Тургенев И.С. «Отцы и дети»" },
        { "Толстой Л.Н. «Война и мир»" } };
    std::vector<int> A = {};

    auto n = Name.size();
    unsigned int k = 0;

    for (unsigned int i = 0; i < n; ++i) {
        k = 1;
        for (unsigned int j = 0; j < n; ++j) {
            if (i != j) {
                if (Name[i] > Name[j]) {
                    bool isNew = true;
                    for (unsigned int jj = 0; jj < j; ++jj) {
                        if (Name[jj] == Name[j]) {
                            isNew = false;
                            break;
                        }
                    }
                    if (isNew) {
                        ++k;
                    }
                }
            }
        }
        A.push_back(k);
    }

    for (unsigned int i = 0; i < n; ++i) {

        std::cout << A[i] << " : " << Name[i] << std::endl;
    }

    return 0;
}
