#include <bits/stdc++.h>
using namespace std;
using namespace std;

double f(double x)
{
    return sin(x);
}

double exact(double x)
{
    return cos(x);
}

double d2(double x, double h)
{
    return (f(x + h) - f(x - h)) / (2.0 * h);
}


double d4(double x, double h)
{
    return (-f(x + 2.0 * h) + 8.0 * f(x + h) - 8.0 * f(x - h) + f(x - 2 * h)) / (12 * h);
}
int main()
{
    double x = 1.0;
    double h_start = 0.1;
    int N = 5;
    double exact_val = exact(x);

    
    vector<double> h_values;
    vector<double> approx2_values;

    double current_h = h_start;
    for (int i = 0; i < N; i++)
    {
        h_values.push_back(current_h);
        approx2_values.push_back(d2(x, current_h));
        current_h /= 2.0;
    }
    file << scientific << setprecision(10); 

file << left << setw(10) << "# h"
     << setw(18) << "Error_Oh2"
     << setw(18) << "Error_Oh4"
     << "Error_Richardson" << endl;

    for (int i = 0; i < N - 1; i++)
    {
        double h = h_values[i];

        
        double err2 = fabs(approx2_values[i] - exact_val);

        
        double err4 = fabs(d4(x, h) - exact_val);

        
        double R = (4.0 * approx2_values[i + 1] - approx2_values[i]) / 3.0;
        double errR = fabs(R - exact_val);

        
        file << left << setw(10) << h
             << setw(18) << err2
             << setw(18) << err4
             << errR << endl;
    }

    file.close();
    cout << "Data has been successfully saved to error_data.txt" << endl;

    return 0;
}
