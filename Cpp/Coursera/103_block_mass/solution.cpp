#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
    int N{};
    int R{};
    cin >> N >> R;
    uint64_t answer = 0;
    for (int i = 0; i < N; ++i) {
        int W{};
        int H{};
        int D{};
        cin >> W >> H >> D;
        // Если не привести W к типу uint64_t перед умножением,
        // произведение будет иметь тип int и случится переполнение.
        // Альтернативное решение — хранить сами W, H, D в uint64_t
        answer += static_cast<uint64_t>(W) * H * D;
    }
    answer *= R;
    cout << answer << endl;
    return 0;
}
