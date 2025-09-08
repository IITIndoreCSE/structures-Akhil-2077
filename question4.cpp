#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct Taylorterm {
int order;
double coeff;
double value;
};// TODO: Define TaylorTerm struct
// struct TaylorTerm {
// };

void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}
double factorial(int n) {
double result = 1;
for (int i = 1; i <= n; i++) result *= i;
return result;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    double x;
    int terms;
    input >> x >> terms;

    TaylorTerm* series = new TaylorTerm[terms];
    // TODO: Create an array of TaylorTerm
    // TaylorTerm series[terms];

    double approximation = 0.0;

    for (int k = 0; k < terms; k++) {
        series[k].order = k;
        series[k].coeff = 1.0 / factorial(k);
        series[k].value = series[k].coeff * pow(x, k);
        print_taylor_term(k + 1, series[k].order, series[k].coeff, series[k].value);
        approximation += series[k].value;
    }
    print_taylor_result("e^x", x, terms, approximation);
    delete[] series;// TODO: Compute each Taylor term and store in array
    // for (int k = 0; k < terms; k++) {
    // }

    // TODO: Print final approximation


    return 0;
}
