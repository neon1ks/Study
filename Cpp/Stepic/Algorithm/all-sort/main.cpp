#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <random>
#include <functional>
#include <queue>

namespace Libre {

template<typename Type>
class VectorView
{
public:
    VectorView(std::vector<Type> &obj) : m_data(&obj)
    {
        m_begin = 0;
        m_size = obj.size();
    }
    VectorView(std::vector<Type> &obj, size_t pos) : m_data(&obj)
    {
        assert(pos >= 0);
        assert(pos <= obj.size());
        m_begin = pos;
        m_size = obj.size();
    }
    VectorView(std::vector<Type> &obj, size_t pos, size_t n) : m_data(&obj)
    {

        assert(pos >= 0);
        assert(n >= 0);
        assert(pos + n <= obj.size());
        m_begin = pos;
        m_size = n;
    }

    VectorView(const VectorView<Type> &obj)
    {
        m_data = obj.m_data;
        m_begin = obj.m_begin;
        m_size = obj.m_size;
    }

    VectorView<Type> &operator=(const VectorView<Type> &obj)
    {
        if (this == &obj) {
            return *this;
        }

        m_data = obj.m_data;
        m_begin = obj.m_begin;
        m_size = obj.m_size;

        return *this;
    }

    VectorView sliced(size_t pos) const noexcept
    {
        assert(pos >= 0);
        assert(pos <= m_size);
        return VectorView<Type>(*m_data, m_begin + pos, m_size - pos);
    }
    VectorView sliced(size_t pos, size_t n) const noexcept
    {
        assert(pos >= 0);
        assert(n >= 0);
        assert(pos + n <= m_size);
        return VectorView<Type>(*m_data, m_begin + pos, n);
    }

    std::size_t size() const noexcept { return m_size; }
    std::size_t begin() const noexcept { return m_begin; }

    Type &operator[](size_t i) noexcept
    {
        assert(i >= 0);
        assert(i < m_size);
        return (*m_data)[m_begin + i];
    }

    Type const &operator[](size_t i) const noexcept
    {
        assert(i >= 0);
        assert(i < m_size);
        return (*m_data)[m_begin + i];
    }

private:
    std::vector<Type> *m_data;
    size_t m_begin;
    size_t m_size;
};

} // namespace Libre

namespace Sort {

template<class Item>
size_t InsertionSort(std::vector<Item> &items, size_t count = 0)
{
    for (size_t i = 1; i < items.size(); ++i) {
        size_t j = i;
        while (j > 0 && items[j] < items[j - 1]) {
            std::swap(items[j], items[j - 1]);
            ++count;
            --j;
        }
    }
    return count;
}

template<class Item>
std::vector<Item> Merge(Libre::VectorView<Item> first,
        Libre::VectorView<Item> second, size_t *count)
{
    //for (int i = 0; i < first.size(); ++i) {
    //    std::cout << first[i] << " ";
    //}
    //std::cout << "+ ";
    //for (int i = 0; i < second.size(); ++i) {
    //    std::cout << second[i] << " ";
    //}

    std::vector<Item> result;
    result.reserve(first.size() + second.size());
    size_t f = 0;
    size_t s = 0;
    while (f < first.size() && s < second.size()) {
        ++(*count);
        if (first[f] < second[s]) {
            result.push_back(first[f]);
            ++f;
        } else {
            result.push_back(second[s]);
            ++s;
        }
    }
    //std::cout << "= (";
    //for (int i = 0; i < result.size(); ++i) {
    //    std::cout << result[i] << " ";
    //}
    //std::cout << ")" << std::endl;

    while (f < first.size()) {
        result.push_back(first[f]);
        ++f;
    }
    while (s < second.size()) {
        result.push_back(second[s]);
        ++s;
    }

    //std::cout << "= ";
    //for (int i = 0; i < result.size(); ++i) {
    //    std::cout << result[i] << " ";
    //}
    //std::cout << std::endl;
    return result;
}

template<class Item>
std::vector<Item> MergeSort(Libre::VectorView<Item> items, size_t *count)
{

    if (items.size() > 1) {
        std::vector<Item> result;
        size_t m = items.size() / 2;

        auto first = MergeSort(items.sliced(0, m), count);
        Libre::VectorView<Item> firstView = first;

        auto second = MergeSort(items.sliced(m, items.size() - m), count);
        Libre::VectorView<Item> secondView = second;

        result = Merge(firstView, secondView, count);
        return result;
    }
    std::vector<Item> result;
    result.push_back(items[0]);

    return result;
}

template<class Type>
std::vector<Type> Merge(const std::vector<Type> &first,
        const std::vector<Type> &second, size_t *count)
{
    std::vector<Type> result;
    result.reserve(first.size() + second.size());
    size_t f = 0;
    size_t s = 0;
    while (f < first.size() && s < second.size()) {
        ++(*count);
        if (first[f] < second[s]) {
            result.push_back(first[f++]);
        } else {
            result.push_back(second[s++]);
        }
    }

    while (f < first.size()) {
        result.push_back(first[f++]);
    }
    while (s < second.size()) {
        result.push_back(second[s++]);
    }

    return result;
}

template<class Type>
std::vector<Type> IterativeMergeSort(
        const std::vector<Type> &items, size_t *count = nullptr)
{
    size_t c = 0;
    std::queue<std::vector<Type>> q;
    for (const auto &i : items) {
        q.push(std::vector<Type>{ i });
    }
    while (q.size() > 1) {
        q.push(Merge(q.pop(), q.pop(), &c));
    }

    if (!count) {
        *count = c;
    }
    return q.pop();
}

} // namespace Sort

void test1()
{

    std::mt19937 gen{ std::random_device()() };
    std::uniform_int_distribution<int> uid(0, 100);
    auto roll = std::bind(uid, gen);

    const size_t N = 10;
    std::vector<int> v(N);

    std::generate(v.begin(), v.begin() + N,
            [&uid, &gen]() -> int { return uid(gen); });

    void *p1 = static_cast<void *>(&v);
    auto it = v.begin();
    void *p2 = static_cast<void *>(&it);
    void *p3 = static_cast<void *>(&(*it));

    std::cout << "&v =     " << p1 << std::endl;
    std::cout << "&it =    " << p2 << std::endl;
    std::cout << "&(*it) = " << p3 << std::endl;

    void *p4 = static_cast<void *>(&(v[0]));
    void *p5 = static_cast<void *>(&(v[1]));

    std::cout << "&v[0] =  " << p4 << std::endl;
    std::cout << "&v[1] =  " << p5 << std::endl;

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    size_t m = v.size() / 2;
    Libre::VectorView<int> view1 = v;
    view1 = view1.sliced(0, m);
    for (int i = 0; i < view1.size(); ++i) {
        std::cout << view1[i] << " ";
    }
    std::cout << std::endl;

    Libre::VectorView<int> view2 = v;
    view2 = view2.sliced(m, v.size() - m);
    for (int i = 0; i < view2.size(); ++i) {
        std::cout << view2[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //test1();
    //return 0;

    std::mt19937 gen{ std::random_device()() };
    std::uniform_int_distribution<int> uid(0, 10);
    auto roll = std::bind(uid, gen);

    const size_t N = 50;
    std::vector<int> v(N);

    std::generate(v.begin(), v.begin() + N,
            [&uid, &gen]() -> int { return uid(gen); });

    std::copy(v.begin(), v.begin() + N,
            std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    size_t count = 0;
    //count = Sort::InsertionSort(v);

    //Libre::VectorView<int> view = v;
    //v = Sort::MergeSort(view, &count);
    v = Sort::IterativeMergeSort(v, &count);

    std::cout << "count = " << count << std::endl;

    std::copy(v.begin(), v.begin() + N,
            std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    return 0;
}
