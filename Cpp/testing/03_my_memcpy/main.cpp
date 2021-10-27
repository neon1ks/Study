#include <iostream>

using namespace std;

void myMemcpy(char *dst, const char *src, int nBytes)
{
    // Try to be fast and copy a word at a time instead of byte by byte
    int *wordDst = (int *)dst;
    int *wordSrc = (int *)src;
    int numWords = nBytes >> 2;
    for (int i = 0; i < numWords; i++) {
        *wordDst++ = *wordSrc++;
    }
    int numRemaining = nBytes - (numWords << 2);
    dst = (char *)wordDst;
    src = (char *)wordSrc;
    for (int i = 0; i < numRemaining; i++) {
        *dst++ = *src++;
    }
}

int main()
{
    const size_t N = 19;
    char *src = new char[N];
    char *dst = new char[N];
    for (size_t i = 0; i < N; ++i) {
        src[i] = static_cast<char>(i + 100);
        dst[i] = ' ';
    }
    myMemcpy(dst, src, N);

    for (size_t i = 0; i < N; ++i) {
        cout << dst[i] << " ";
    }
    cout << endl;
    return 0;
}

// for (int i = 0; i <= numRemaining; i++);
// лищняя ; в конце — это сразу бросается в глаза

// мы ничего не знаем о dst, сколько там памяти,
// может там вообще ничего не выделено

// int может быть не равен 4. В стандарте указано,
// что int должно быть минимум 2 байт или больше
// Данная проблема встречается в двух строчках:
// int numWords = nBytes >> 2;
// int numRemaining = nBytes - (numWords << 2);

// int *wordDst = (int *)dst;
// можно заменить на
// int *wordDst = reinterpret_cast<int *>(dst);

// for (int i = 0; i <= numRemaining; i++) {
// <= заменить на <

// *wordDst++ = *wordSrc++;
// Так немного понятнее
// *(wordDst++) = *(wordSrc++);

// Мне не нравится работать с исходными данными через char и int,
// на мой взгляд лучше использовать unsigned char и unsigned int
// В C++ 17 появился std::byte

// i++ можно заменить на ++i
