#include <iostream>
using namespace std;

class matrix
{
    int mat[50][50], transpMat[50][50], firstDiagSum, secondDiagSum;
    bool squareMat, uppTriMat = true;

public:
    void inputMatrix(int nCols, int nRows)
    {
        for (int j = 0; j < nRows; j++)
        {
            for (int i = 0; i < nCols; i++)
            {
                cout << "enter element number [" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }

        for (int j = 0; j < nRows; j++)
        {
            for (int i = 0; i < nCols; i++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void squareCheck(int nCols, int nRows)
    {
        if (nRows == nCols)
        {
            squareMat = true;
        }
        else
        {
            squareMat = false;
        }
    }

    void upperTriangularCheck(int nCols, int nRows)
    {
        squareCheck(nCols, nRows);

        if (squareMat == false)
        {
            uppTriMat = false;
        }
        else
        {
            for (int j = 1; j < nRows; j++)
            {
                for (int i = 0; i < j; i++)
                {
                    if (mat[i][j] != 0)
                    {
                        uppTriMat = false;
                    }
                }
            }
        }

        if (uppTriMat == true)
        {
            cout << "\nit is an upper triangular matrix.\n";
        }
        else
        {
            cout << "\nit is not an upper triangular matrix.\n";
        }
    }

    void diag1Sum(int nCols, int nRows)
    {
        squareCheck(nCols, nRows);

        if (squareMat == false)
        {
            cout << "\nleft diagonal do not exist.\n";
        }
        else
        {
            firstDiagSum = 0;
            for (int i = 0; i < nCols; i++)
            {
                firstDiagSum += mat[i][i];
            }

            cout << "\nsum of left diagonal elements is: " << firstDiagSum << endl;
        }
    }

    void diag2Sum(int nCols, int nRows)
    {
        squareCheck(nCols, nRows);

        if (squareMat == false)
        {
            cout << "\nright diagonal do not exist.\n";
        }
        else
        {
            secondDiagSum = 0;
            for (int i = 0; i < nCols; i++)
            {
                secondDiagSum += mat[nCols - i - 1][i];
            }

            cout << "\nsum of right diagonal elements is: " << secondDiagSum << endl;
        }
    }

    void transposeMat(int nCols, int nRows)
    {
        cout << "\nthe transposed matrix is:\n";
        for (int j = 0; j < nRows; j++)
        {
            for (int i = 0; i < nCols; i++)
            {
                transpMat[j][i] = mat[i][j];
            }
        }

        for (int j = 0; j < nCols; j++)
        {
            for (int i = 0; i < nRows; i++)
            {
                cout << transpMat[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    int nCols, nRows;
    matrix m;

    cout << "enter the numbers of columns: ";
    cin >> nCols;
    cout << "enter the numbers of row: ";
    cin >> nRows;

    m.inputMatrix(nCols, nRows);
    m.upperTriangularCheck(nCols, nRows);
    m.diag1Sum(nCols, nRows);
    m.diag2Sum(nCols, nRows);
    m.transposeMat(nCols, nRows);
    return 0;
}