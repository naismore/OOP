#include <iostream>
#include <array>
#include <fstream>
#include <sstream>

// Батник дописать

using namespace std;

const int MATRIX_HEIGHT = 3;
const int MATRIX_WIDTH = 3;

typedef array<array<float, MATRIX_HEIGHT>, MATRIX_WIDTH> MatrixType;

void PrintErrorToFile(const string& message, const string& path)
{
    ofstream out(path);
    out << message << endl;
}

void PrintMatrixToFile(MatrixType matrix, const string& path)
{
    ofstream out(path);
    for (auto & i : matrix)
    {
        for (double j : i)
        {
            out << j << " ";
        }
        out << endl;
    }
}

void PrintMatrix(MatrixType matrix)
{
    for (auto & i : matrix)
    {
        for (double j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool OpenFile(const string& path, MatrixType& matrix)
{
    ifstream in(path);

    string line;
    for (int i = 0; i < 3; ++i)
    {
        if (getline(in, line))
        {
            istringstream iss(line);
            for (int j = 0; j < 3; ++j)
            {
                string value;
                if (!(iss >> value) || value.find_first_not_of("0123456789.-") != string::npos)
                {
                    return false;
                }

                matrix[i][j] = stof(value);
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void MultiplicationMatrix(MatrixType& matrix1, MatrixType& matrix2, MatrixType& matrix3)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(int argc, char* args[])
{
    if (argc != 3)
    {
        cout << "Usage " << args[0] << "<matrix file1> <matrix file2>\n";
        return 1;
    }

    MatrixType matrix1{};
    MatrixType matrix2{};
    MatrixType matrix3{};

    if (!OpenFile(args[1], matrix1) || !OpenFile(args[2], matrix2))
    {
        cout << "Error to open files\n";
        PrintErrorToFile("Error to open files", "out.txt");
        return 1;
    }

    MultiplicationMatrix(matrix1, matrix2, matrix3);

    PrintMatrixToFile(matrix3, "out.txt");
    PrintMatrix(matrix3);
    return 0;
}