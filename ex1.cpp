#include <iomanip>
#include <iostream>

using namespace std;

#define COL 5
#define LIN 3

void showArr(char **array) {
  // shows collumn index
  cout << "   | ";
  for (int i = 0; i < LIN; i++) {
    cout << setw(2) << i << ((i != LIN - 1) ? " | " : "");
  }
  cout << endl;

  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      // shows line index
      if (j == 0) {
        cout << setw(2) << i << " | ";
      }
      cout << setw(2) << array[i][j] << ((j != LIN - 1) ? " | " : "");
    }
    cout << endl;
  }
}

void mallocArr(char ***array) {
  *array = new char *[COL];
  for (int i = 0; i < COL; i++) {
    (*array)[i] = new char[LIN];
  }
}

void allocDefaultArr(char ***array) {
  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      (*array)[i][j] = '-';
    }
  }
}

int main() {
  char **arr;
  mallocArr(&arr);
  allocDefaultArr(&arr);
  showArr(arr);

  return 1;
}
