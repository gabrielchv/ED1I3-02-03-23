#include <iomanip>
#include <iostream>

using namespace std;

#define COL 40
#define LIN 15

void selectOption(int *selectedOption) {
  cout << "0.	Finalizar" << endl;
  cout << "1.	Reservar poltrona" << endl;
  cout << "2.	Mapa de ocupacao" << endl;
  cout << "3.	Faturamento" << endl;
  cout << "Selecione uma opcao: ";
  cin >> *selectedOption;
  cout << endl;
}

void showArr(char **arr) {
  // shows collumn index
  cout << endl << "   | ";
  for (int i = 0; i < LIN; i++) {
    cout << setw(2) << (i + 1) << ((i != LIN - 1) ? " | " : "");
  }
  cout << endl;

  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      // shows line index
      if (j == 0) {
        cout << setw(2) << (i + 1) << " | ";
      }
      cout << setw(2) << arr[i][j] << ((j != LIN - 1) ? " | " : "");
    }
    cout << endl;
  }
  cout << endl;
}

void mallocArr(char ***arr) {
  *arr = new char *[COL];
  for (int i = 0; i < COL; i++) {
    (*arr)[i] = new char[LIN];
  }
}

void allocDefaultArr(char ***arr) {
  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      (*arr)[i][j] = '-';
    }
  }
}

void selectSeat(char ***arr, int *profit, int *seatsTaken) {
  int i;
  int j;
  cout << "Selecione sua fileira (1-14): ";
  cin >> j;
  j--;
  cout << "Selecione sua poltrona (1-40): ";
  cin >> i;
  i--;
  cout << (*arr)[i][j];
  if ((*arr)[i][j] == '-') {
    (*arr)[i][j] = '#';
    *profit += j < 5 ? 50 : j < 10 ? 30 : 15;
    (*seatsTaken)++;
  }
}

int main() {
  int profit = 0;
  int seatsTaken = 0;

  char **arr;
  mallocArr(&arr);
  allocDefaultArr(&arr);

  int selectedOption = 5;
  while (selectedOption != 0) {
    selectOption(&selectedOption);
    switch (selectedOption) {
      case 1:
        selectSeat(&arr, &profit, &seatsTaken);
        break;
      case 2:
        showArr(arr);
        break;
      case 3:
        cout << "Qtde de lugares ocupados: " << seatsTaken << endl;
        cout << "Valor da bilheteria: RS " << profit << ",00" << endl;
        break;
    }
  }

  cout << endl << "Obrigado por usar :D" << endl;

  return 1;
}
