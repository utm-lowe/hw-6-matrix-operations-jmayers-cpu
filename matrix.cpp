#include "matrix.h"
#include <iomanip>

// Constructor: allocate m x n
Matrix::Matrix(unsigned int rows, unsigned int cols)
{
    m = static_cast<int>(rows);
    n = static_cast<int>(cols);

    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n];
        // optional init to 0 so tests are stable
        for (int j = 0; j < n; j++)
            ar[i][j] = 0.0;
    }
}

// Copy constructor: deep copy
Matrix::Matrix(const Matrix& rhs)
{
    m = rhs.m;
    n = rhs.n;

    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n];
        for (int j = 0; j < n; j++)
            ar[i][j] = rhs.ar[i][j];
    }
}

// Destructor: free memory
Matrix::~Matrix()
{
    if (ar != nullptr)
    {
        for (int i = 0; i < m; i++)
            delete[] ar[i];
        delete[] ar;
    }
    ar = nullptr;
    m = 0;
    n = 0;
}

int Matrix::getRows() const
{
    return m;
}

int Matrix::getCols() const
{
    return n;
}

double& Matrix::at(unsigned int row, unsigned int col)
{
    return ar[row][col];
}

const double& Matrix::at(unsigned int row, unsigned int col) const
{
    return ar[row][col];
}

// Assignment operator: deep copy (handle self-assign + reallocate)
Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs) return *this;

    // if dimensions differ, reallocate
    if (m != rhs.m || n != rhs.n)
    {
        // free current
        for (int i = 0; i < m; i++)
            delete[] ar[i];
        delete[] ar;

        // copy dims and allocate new
        m = rhs.m;
        n = rhs.n;

        ar = new double*[m];
        for (int i = 0; i < m; i++)
            ar[i] = new double[n];
    }

    // copy values
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ar[i][j] = rhs.ar[i][j];

    return *this;
}

// ---------- Non-member operators ----------

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    Matrix out(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); i++)
        for (int j = 0; j < m1.getCols(); j++)
            out.at(i, j) = m1.at(i, j) + m2.at(i, j);
    return out;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    Matrix out(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); i++)
        for (int j = 0; j < m1.getCols(); j++)
            out.at(i, j) = m1.at(i, j) - m2.at(i, j);
    return out;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    Matrix out(m1.getRows(), m2.getCols());

    for (int i = 0; i < m1.getRows(); i++)
    {
        for (int j = 0; j < m2.getCols(); j++)
        {
            double sum = 0.0;
            for (int k = 0; k < m1.getCols(); k++)
            {
                sum += m1.at(i, k) * m2.at(k, j);
            }
            out.at(i, j) = sum;
        }
    }

    return out;
}

Matrix operator*(double scalar, const Matrix& m)
{
    Matrix out(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getCols(); j++)
            out.at(i, j) = scalar * m.at(i, j);
    return out;
}

Matrix operator*(const Matrix& m, double scalar)
{
    return scalar * m;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            // GOTCHA: setw(10) + trailing space after every number
            os << std::setw(10) << m.at(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m)
{
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getCols(); j++)
            is >> m.at(i, j);
    return is;
}