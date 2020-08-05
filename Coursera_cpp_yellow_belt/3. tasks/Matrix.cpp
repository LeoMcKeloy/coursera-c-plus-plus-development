#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
    }

    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_cols < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_cols == 0) {
            num_rows = num_cols = 0;
        }
        rows = num_rows;
        cols = num_cols;

        matrix.assign(num_rows, vector<int>(num_cols));
    }

    int& At(int row, int col) {
        return matrix.at(row).at(col);
    }

    int At(int row, int col) const {
        return matrix.at(row).at(col);
    }

    int GetNumRows() const {
        return rows;
    }

    int GetNumColumns() const {
        return cols;
    }

private:
    int rows;
    int cols;
    vector<vector<int>> matrix;
};

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows()) {
        return false;
    }

    if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < lhs.GetNumRows(); ++row) {
        for (int column = 0; column < lhs.GetNumColumns(); ++column) {
            if (lhs.At(row, column) != rhs.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }
    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int col = 0; col < result.GetNumColumns(); ++col) {
            result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
        }
    }
    return result;
}

istream& operator >> (istream& is, Matrix& m) {
    int r, c;

    is >> r >> c;
    m.Reset(r, c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            is >> m.At(i, j);
        }
    }
    return is;
}

ostream& operator << (ostream& os, const Matrix& m) {
    os << m.GetNumRows() << " " << m.GetNumColumns() << endl;
    for (int i = 0; i < m.GetNumRows(); ++i) {
        for (int j = 0; j < m.GetNumColumns(); ++j) {
            if (j > 0) {
                os << " ";
            }
            os << m.At(i, j);
        }
        os << endl;
    }
    return os;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}