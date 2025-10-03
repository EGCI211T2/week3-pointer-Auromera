#include <iostream>
#include <iomanip>
#define SIZE 10

using namespace std;

int main(int argc, char *argv[]) {
  int *pa, *pb, i, temp, *p;
   /*  int n;

    cout << "How many numbers? ";
    cin >> n;

    pa = new int[n];
    p = pa;  // Save original pointer for safe deletion and reference

    // Input values
    for (i = 0; i < n; i++) {
        cout << "Input no. ";
        cin >> pa[i];
    }
*/
 int n =argc-1;

  pa=new int[n];
  p = pa;

  for(i=0;i<n;i++){

    *pa=atoi(argv[i+1]);

    pa++;

  }


    // Reset pointer to beginning for printing
    pa = p;

    cout << "Original: ";
    for (i = 0; i < n - 1; i++, pa++) {
        cout << setw(3) << *pa;
    }
    cout << setw(3) << *pa << endl;  // last element

    // Reverse using pointers
    pb = p + (n - 1);        // pb at last element (current pa is at end)
    pa = p;          // reset pa to first element

    for (i = 0; i < n / 2; i++) {
        temp = *pa;
        *pa = *pb;
        *pb = temp;
        pa++;
        pb--;
    }

    // Reset pointer for output
    pa = p;

    cout << "Reversed: ";
    for (i = 0; i < n - 1; i++, pa++) {
        cout << setw(3) << *pa;
    }
    cout << setw(3) << *pa << endl;

    delete[] p;  // safely delete the allocated memory

    return 0;
}