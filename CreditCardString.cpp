#include <iostream>
using namespace std;

int main() {
  string cardNo;
  cout << "Type your card number: ";
  cin >> cardNo;

  int digits = 0;
  while (cardNo[digits] != '\0') {
    digits++;
  }
  cout << digits;

  int total = 0;
  for (int i = digits; cardNo[i] >= 0; i--) {
    if (i % 2 == 1) {
      total += cardNo[i] - '0';
    } else {
      if ((cardNo[i] - '0') * 2 >= 10) {
        total += (cardNo[i] - '0') * 2 % 10 + 1;
      } else {
        total += (cardNo[i] - '0') * 2;
      }
    }
  }
  cout << total;
  
  if (total % 10 == 0) {
    cout << "This card number is valid.";
    if (digits == 15 && cardNo[0] == 3) {
      if (cardNo[1] == 4 || cardNo[1] == 7) {
        cout << "This card is from American Express.";
      }
    } else if (digits == 16 && cardNo[0] == 5) {
      if (cardNo[1] >= 1 && cardNo[1] <= 5) {
        cout << "This card is from MasterCard.";
      }
    } else if (digits == 13 || digits == 16) {
      if (cardNo[1] >= 1 && cardNo[1] <= 5) {
        cout << "This card is from VISA.";
      }
    } else {
      cout << "The manufacturer of the card is unknown.";
    }
  } else {
    cout << "This card number is invalid.";
  }

}
