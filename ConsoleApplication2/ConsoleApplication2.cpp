#include <math.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <windows.h>
#include <tchar.h>
using namespace std;

int main(int argc, char* argv[])
{

    if (argc != 4)
    {
        std::cerr << "Usage: child.exe <a> <b> <c>" << std::endl;
        return 1;
    }
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    int n = std::atoi(argv[3]);
    double step = (b - a) / n;
    double result;

    for (double x = a; x <= b; x += step)
    {
        result = x + x*(sin(x) + cos(x));
        cout << std::fixed << std::setprecision(4);
        cout << x << "\t|\t" << result << std::endl;

    }
   
    return 0;
}