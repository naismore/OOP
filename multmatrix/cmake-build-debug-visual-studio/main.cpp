#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* args[])
{
    if (argc != 3)
    {
        cout << "Usage " << args[0] << "<matrix file1> <matrix file2>\n";
        return 1;
    }

    ifstream inMatrix1(args[1]);
    ifstream inMatrix2(args[2]);

    if (!inMatrix1.is_open() || !inMatrix2.is_open())
    {
        cout << "Error to open files\n";
        return 1;
    }

    double matrix1[3][3];
    double matrix2[3][3];
    double matrix3[3][3];

    string line;
    for (int i = 0; i < 3; ++i) {
        if (getline(inMatrix1, line)) {
            istringstream iss(line);
            for (int j = 0; j < 3; ++j) {
                string value;
                if (!(iss >> value) || value.find_first_not_of("0123456789.-") != string::npos) {
                    cerr << "Error reading matrix element\n";
                    return 1;
                }
                matrix1[i][j] = stof(value);
            }
        }
        else
        {
            cout << "Error reading line: Empty line\n";
            return 1;
        }
    }

    line.clear();
    for (int i = 0; i < 3; ++i) {
        if (getline(inMatrix2, line)) {
            istringstream iss(line);
            for (int j = 0; j < 3; ++j) {
                string value;
                if (!(iss >> value) || value.find_first_not_of("0123456789.-") != string::npos) {
                    cerr << "Error reading matrix element at position (" << i << ", " << j << ")." << endl;
                    return 1;
                }
                matrix2[i][j] = stof(value);
            }
        }
        else
        {
            cout << "Error reading line: Empty line\n";
            return 1;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix3[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (auto & i : matrix3) {
        for (double j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}