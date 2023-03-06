#include <iomanip>
#include <iostream>

using namespace std;

int randomNumber(int min, int max) { return rand() % (max - min + 1) + min; }

void mallocDeck(string ***deck) {
  *deck = new string *[2];
  for (int i = 0; i < 2; i++) {
    (*deck)[i] = new string[52];
  }
}

void populateDeck(string ***deck) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 52; j++) {
      int suit = (j % 4) + 1;      // naipe
      int packNum = (j % 13) + 1;  // num da carta
      string cardName = to_string(suit) +
                        (packNum < 10 ? to_string(0) + to_string(packNum)
                                      : to_string(packNum)) +
                        to_string(i + 1);

      (*deck)[i][j] = cardName;
    }
  }
}

void mallocDSelecteDeck(bool ***deck) {
  *deck = new bool *[2];
  for (int i = 0; i < 2; i++) {
    (*deck)[i] = new bool[52];
  }
}

void populateSelectedDeck(bool ***deck) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 52; j++) {
      (*deck)[i][j] = false;
    }
  }
}

void mallocHands(string ***hands) {
  *hands = new string *[4];
  for (int i = 0; i < 4; i++) {
    (*hands)[i] = new string[52];
  }
}

void populateHands(string ***deck, bool ***selectedDeck, string ***hands) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 11; j++) {
      while (((*hands)[i][j]).empty()) {
        int selectedI = randomNumber(0, 1);
        int selectedJ = randomNumber(0, 51);
        if ((*selectedDeck)[selectedI][selectedJ] == false) {
          (*hands)[i][j] = (*deck)[selectedI][selectedJ];
          (*selectedDeck)[selectedI][selectedJ] = true;
        }
      }
    }
  }
}

void showHands(string **hands) {
  for (int i = 0; i < 4; i++) {
    cout << "Jogador " << (i + 1) << ": " << endl;
    for (int j = 0; j < 11; j++) {
      cout << hands[i][j] << endl;
    }
    cout << "----------" << endl;
  }
}

int main() {
  srand(time(NULL));

  string **deck;
  mallocDeck(&deck);
  populateDeck(&deck);

  bool **deckSelected;
  mallocDSelecteDeck(&deckSelected);
  populateSelectedDeck(&deckSelected);

  string **hands;
  mallocHands(&hands);
  populateHands(&deck, &deckSelected, &hands);
  showHands(hands);

  return 1;
}