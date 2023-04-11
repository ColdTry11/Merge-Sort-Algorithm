#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

void merge(Employee** A, int const p, int const q, int const r, int n, int& comparison)
{

    auto const nL = q - p + 1;    //length of A[p : q]
    auto const nR = r - q;       //length of A[q + 1 : r]

    // Temporary arrays
    auto* L = new Employee * [nL];
    auto* R = new Employee * [nR];

    // Copy A[p : q] into L[0 : nL - 1]
    for (auto i = 0; i < nL; i++)
        L[i] = A[p + i];

    // Copy A[p + 1 : r] into L[0 : nR - 1]
    for (auto j = 0; j < nR; j++)
        R[j] = A[q + 1 + j];

    auto i = 0; // Smallest remaining element in L
    auto j = 0; // Smallest remaining element in R
    int k = p; // Location in A to fill

    // As long as each of the arrays L and R contains an unmerged element, 
    // copy the smallest unmerged element back into A[p : r].

    while (i < nL && j < nR) {
        if (L[i]->getID() <= R[j]->getID()) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
        comparison++;
    }
    // Having gone through one of L and R entirely, copy the 
    // remainder of the other to the end of A[p : r].

    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
        comparison++;
    }
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
        comparison++;
    }

    // Print IDs
    for (int z = 0; z < n; z++) {
        cout << A[z]->getID() << " ";
    }
    cout << endl;
}

void mergeSort(Employee** A, int const p, int const r, int n, int& comparison)
{
    if (p >= r) {
        return;
    }
    auto q = p + (r - p) / 2;                 // midpoint of A[p : r]
    mergeSort(A, p, q, n, comparison);        // recursively sort A[p : q]
    mergeSort(A, q + 1, r, n, comparison);     // recursively sort A[q + 1 : r]

    // Merge A[p : q] and A[q + 1 : r] into A[p : r]
    merge(A, p, q, r, n, comparison);
}

int main(int argc, char** argv)
{
    //Check for command line error
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    //Check for file
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    //Get how many lines
    string line;
    getline(ifs, line);
    int n = stoi(line);

    //initializing an array
    Employee** employee = new Employee * [n];

    //loop through file
    for (int i = 0; i < n; i++) {
        int age;
        int id;
        int year;
        string name;
        string job;
        string ids;
        string a;
        string y;
        getline(ifs, name, '|');
        getline(ifs, ids, '|');
        getline(ifs, a, '|');
        getline(ifs, job, '|');
        getline(ifs, y);
        id = stoi(ids);
        age = stoi(a);
        year = stoi(y);
        Employee* emp = new Employee(name, id, age, job, year);

        //Add to array
        employee[i] = emp;


    }

    // MERGE SORT
    int comparison = 0;
    mergeSort(employee, 0, n - 1, n, comparison);

    cout << "It took " << comparison << " comparisons to sort this list." << endl;

}