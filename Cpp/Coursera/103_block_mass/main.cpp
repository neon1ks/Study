#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
    // Размеры в сантиметрах
    // Плотность - граммы на кубические сантиметры
    // Итоговая массама в граммах

    size_t n{};
    size_t r{};
    cin >> n >> r;

    size_t w{};
    size_t h{};
    size_t d{};

    uint64_t answer{};
    for (size_t i = 0; i < n; ++i) {
        cin >> w >> h >> d;
        answer += w * h * d * r;
    }

    cout << answer << endl;

    return 0;
}
