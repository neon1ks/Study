#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstdint>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
private:
    vector<vector<int>> data;
    size_t m_num_rows;
    size_t m_num_cols;

public:
    Matrix()
    {
        m_num_rows = 0;
        m_num_cols = 0;
    };
    Matrix(int num_rows, int num_cols) { Reset(num_rows, num_cols); }
    Matrix(size_t num_rows, size_t num_cols) { Reset(num_rows, num_cols); }

    void Reset(size_t num_rows, size_t num_cols)
    {
        m_num_rows = num_rows;
        m_num_cols = num_cols;
        if (num_rows == 0 || num_cols == 0) {
            m_num_rows = 0;
            m_num_cols = 0;
        }
        data = vector<vector<int>>(m_num_rows, vector<int>(m_num_cols, 0));
        // elements_.assign(static_cast<size_t>(num_rows),
        //         vector<int>(static_cast<size_t>(num_columns)));
    }

    void Reset(int num_rows, int num_cols)
    {
        if (num_rows < 0) {
            throw out_of_range("num_rows is negative");
        }
        if (num_cols < 0) {
            throw out_of_range("num_cols is negative");
        }
        Reset(static_cast<size_t>(num_rows), static_cast<size_t>(num_cols));
    }

    [[nodiscard]] int At(size_t row, size_t col) const
    {
        return data.at(row).at(col);
    }
    int &At(size_t row, size_t col) { return data.at(row).at(col); }

    [[nodiscard]] size_t GetNumRows() const { return m_num_rows; }
    [[nodiscard]] size_t GetNumColumns() const { return m_num_cols; }
};

ostream &operator<<(ostream &stream, const Matrix &value)
{
    stream << value.GetNumRows() << ' ' << value.GetNumColumns() << endl;
    for (size_t i = 0; i < value.GetNumRows(); ++i) {
        for (size_t j = 0; j < value.GetNumColumns(); ++j) {
            if (j != 0) {
                stream << ' ';
            }
            stream << value.At(i, j);
        }
        stream << endl;
    }
    return stream;
}

istream &operator>>(istream &stream, Matrix &value)
{
    int num_rows{};
    int num_cols{};
    stream >> num_rows >> num_cols;
    value.Reset(num_rows, num_cols);
    for (size_t i = 0; i < static_cast<size_t>(num_rows); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(num_cols); ++j) {
            stream >> value.At(i, j);
        }
    }
    return stream;
}

Matrix operator+(const Matrix &l, const Matrix &r)
{
    if (l.GetNumRows() != r.GetNumRows()) {
        throw invalid_argument("Num of Row is difference");
    }
    if (l.GetNumColumns() != r.GetNumColumns()) {
        throw invalid_argument("Num of Columns is difference");
    }

    Matrix result(l.GetNumRows(), l.GetNumColumns());
    for (size_t i = 0; i < l.GetNumRows(); ++i) {
        for (size_t j = 0; j < l.GetNumColumns(); ++j) {
            result.At(i, j) = l.At(i, j) + r.At(i, j);
        }
    }

    return result;
}

bool operator==(const Matrix &l, const Matrix &r)
{
    if (l.GetNumRows() != r.GetNumRows()
            || l.GetNumColumns() != r.GetNumColumns()) {
        return false;
    }
    for (size_t i = 0; i < l.GetNumRows(); ++i) {
        for (size_t j = 0; j < l.GetNumColumns(); ++j) {
            if (l.At(i, j) != r.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    try {

        Matrix one;
        Matrix two;

        cin >> one >> two;
        cout << one + two << endl;

    } catch (const exception &e) {
        cout << e.what() << endl;
        std::cout << "Type:    " << typeid(e).name() << "\n";
    }
    return 0;
}
