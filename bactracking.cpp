/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


    }#include <iostream>
#include <cmath>
using namespace std;
 
void tiparesteSolutie(int *x, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (x[i] == j)
                cout<<'x';
            else
                cout<<'o';
        cout<<endl;
    }
    cout<<endl;
}
 
int main() {
    int n, k, eSolutie;
    int *x;
    int solutii = 0;
 
    cout<<"Numarul de dame (dimensiunea tablei): ";
    cin>>n;
    x = new int[n];
 
    k = 0;
    x[k] = -1;
    while (k >= 0) {
        eSolutie = 0;
        while ((x[k] < n - 1) && (! eSolutie)) {
            eSolutie = 1;
            x[k]++;
            for (int i = 0; (i < k) && eSolutie; i++)
                if ((x[k] == x[i]) || (k - i == abs((float)x[k] - x[i])))
                    eSolutie = 0;
        }
        if (! eSolutie)
            k--;
        else
            if (k == n - 1) {
               solutii++;
               tiparesteSolutie(x, n);
            }
            else {
               k++;
               x[k] = -1;
            }
    delete x;
    cout<<"Am gasit in total "<<solutii<<" solutii."<<endl;
}