#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

//==============================================================================
template<typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p);

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vi);

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s);

template<typename Key, typename Value>
std::ostream &operator<<(std::ostream &out, const std::map<Key, Value> &m);

template<typename Collection>
std::string Join(const Collection &c, char d)
{
    std::stringstream ss;
    bool first = true;
    for (const auto &i : c) {
        if (first) {
            first = false;
        } else {
            ss << d;
        }
        ss << i;
    }
    return ss.str();
}

template<typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p)
{
    return out << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vi)
{
    return out << '[' << Join(vi, ',') << ']';
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s)
{
    return out << '{' << Join(s, ',') << '}';
}

template<typename Key, typename Value>
std::ostream &operator<<(std::ostream &out, const std::map<Key, Value> &m)
{
    return out << '{' << Join(m, ',') << '}';
}
//==============================================================================

unsigned lis(const std::vector<int> &A)
{
    auto N = static_cast<unsigned>(A.size());
    int inf = abs(*max_element(A.begin(), A.end(),
                      [](const int &l, const int &r) -> bool {
                          return abs(l) < abs(r);
                      }))
              + 1;

    std::vector<int> L(N + 2, inf);
    L[0] = -inf;
    std::vector<std::set<unsigned>> M(N + 2);
    ;

    for (unsigned i = 0; i < N; ++i) {
        unsigned left = 0;
        unsigned right = N + 1;
        while (left + 1 < right) {
            unsigned middle = (left + right) / 2;
            if (L[middle] < A[i]) {
                left = middle;
            } else {
                right = middle;
            }
        }
        L[right] = A[i];
        M[right].insert(i);
    }
    std::cout << "L = " << L << std::endl;
    std::cout << "M = " << M << std::endl;
    unsigned index = N + 1;

    while (L[index] == inf) {
        index -= 1;
    }

    std::vector<int> answer(index);
    std::vector<int> answer2;
    std::vector<unsigned> answer_i(index);
    std::vector<unsigned> answer2_i;
    auto now_i = static_cast<unsigned>(index);
    int now = inf;
    for (unsigned t = N; t > 0; --t) {
        unsigned i = t - 1;
        if (A[i] == now) {
            answer2.emplace_back(A[i]);
            answer2_i.emplace_back(i);
        }
        if (M[now_i].count(i) == 1) {
            --now_i;
            answer[now_i] = A[i];
            answer_i[now_i] = i;
            answer2.emplace_back(A[i]);
            answer2_i.emplace_back(i);
            now = A[i];
        }
    }
    std::reverse(answer2.begin(), answer2.end());
    std::cout << "answer   = " << answer << std::endl;
    std::cout << "answer_i = " << answer_i << std::endl;
    std::cout << "answer2   = " << answer2 << std::endl;
    std::cout << "answer2_i = " << answer2_i << std::endl;

    return index;
}

unsigned lds(const std::vector<int> &A)
{
    auto N = static_cast<unsigned>(A.size());
    int inf = abs(*max_element(A.begin(), A.end(),
                      [](const int &l, const int &r) -> bool {
                          return abs(l) < abs(r);
                      }))
              + 1;

    std::vector<int> L(N + 2, -inf);
    L[0] = +inf;
    std::vector<std::set<unsigned>> M(N + 2);

    for (unsigned i = 0; i < N; ++i) {
        unsigned left = 0;
        unsigned right = N + 1;
        while (left + 1 < right) {
            unsigned middle = (left + right) / 2;
            if (L[middle] > A[i]) {
                left = middle;
            } else {
                right = middle;
            }
        }
        L[right] = A[i];
        M[right].insert(i);
    }
    std::cout << "L = " << L << std::endl;
    std::cout << "M = " << M << std::endl;
    unsigned index = N + 1;

    while (L[index] == -inf) {
        index -= 1;
    }

    std::vector<int> answer(index);
    std::vector<unsigned> answer_i(index);
    auto now_i = static_cast<unsigned>(index);
    for (unsigned t = N; t > 0; --t) {
        unsigned i = t - 1;
        if (M[now_i].count(i) == 1) {
            --now_i;
            answer[now_i] = A[i];
            answer_i[now_i] = i;
        }
    }
    std::cout << "answer   = " << answer << std::endl;
    std::cout << "answer_i = " << answer_i << std::endl;
    return index;
}



unsigned lnis(const std::vector<int> &A)
{
    auto N = static_cast<unsigned>(A.size());
    int inf = abs(*max_element(A.begin(), A.end(),
                      [](const int &l, const int &r) -> bool {
                          return abs(l) < abs(r);
                      }))
              + 1;

    std::vector<int> L(N + 2, -inf);
    L[0] = +inf;
    std::vector<std::set<unsigned>> M(N + 2);

    for (unsigned i = 0; i < N; ++i) {
        unsigned left = 0;
        unsigned right = N + 1;
        while (left + 1 < right) {
            unsigned middle = (left + right) / 2;
            if (L[middle] > A[i]-1) {
                left = middle;
            } else {
                right = middle;
            }
        }
        L[right] = A[i];
        M[right].insert(i);
    }
    std::cout << "L = " << L << std::endl;
    std::cout << "M = " << M << std::endl;
    unsigned index = N + 1;

    while (L[index] == -inf) {
        index -= 1;
    }

    std::vector<int> answer(index);
    std::vector<unsigned> answer_i(index);
    auto now_i = static_cast<unsigned>(index);
    for (unsigned t = N; t > 0; --t) {
        unsigned i = t - 1;
        if (M[now_i].count(i) == 1) {
            --now_i;
            answer[now_i] = A[i];
            answer_i[now_i] = i;
        }
    }
    std::cout << "answer   = " << answer << std::endl;
    std::cout << "answer_i = " << answer_i << std::endl;
    return index;
}

int main()
{
    std::vector<int> A = { 2, 7, 1, 4, 3, 5, 5, 4, 6, 2, 5, 5, 8, 8, 7, 3 };
    std::vector<int> B = A;
    std::reverse(B.begin(), B.end());


    std::cout << "\nlis" << std::endl;
    std::cout << "A = " << A << std::endl;
    auto index = lis(A);
    std::cout << "index = " << index << std::endl;

    std::cout << "\nlds" << std::endl;
    std::cout << "B = " << B << std::endl;
    index = lds(B);
    std::cout << "index = " << index << std::endl;

    std::cout << "\nlnis" << std::endl;
    std::cout << "B = " << B << std::endl;
    index = lnis(B);
    std::cout << "index = " << index << std::endl;

    return 0;
}
