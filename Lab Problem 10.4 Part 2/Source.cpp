
#include <iostream>
#include <string>

using namespace std;

bool is_card_valid(int digits[], int size);
bool is_numeric(string s);
bool is_correct_length(string s);

int main() {
    string input;
    int digits[16];

    while (true) {
        cout << "Enter 16-digit card # or Q to quit: ";

        getline(cin, input);
        if (input == "Q") break;

        for (int i = 0; i < 16; i++) {
            digits[i] = input[i] - 48;
        }

        if (is_numeric(input) == false) {
            cout << "Error - card number must contain only digits" << endl << endl;
        }
        else {
            if (is_correct_length(input) == false) {
                cout << "Error - card number must contain 16 digits." << endl << endl;
            }
            else {
                if (is_card_valid(digits, 16) == true)
                    cout << "Card is valid." << endl << endl;
                else
                    cout << "Card is not valid." << endl << endl;
            }
        }
    }
}

bool is_numeric(string s) {
    bool numeric_check = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 48 && s[i] <= 57)  numeric_check = true;
        else return false;
    }
    return numeric_check;
}

bool is_correct_length(string s) {
    if (s.length() == 16) return true;
    else return false;
}

bool is_card_valid(int digits[], int size) {
    int first_sum = 0;
    int second_sum = 0;
    int third_sum;
    int digi[8];
    int x = 0;

    for (int i = 0; i < 16; i++) {
        if (i % 2 != 0) {
            first_sum += digits[i];
        }
        if (i % 2 == 0) {
            digi[x] = digits[i] * 2;
            x++;
        }
    }

    for (int i = 0; i < 8; i++) {
        while (digi[i] > 0) {
            int digit = digi[i] % 10;
            digi[i] /= 10;
            second_sum += digit;
        }
    }

    third_sum = first_sum + second_sum;
    if (third_sum % 10 == 0) return true;
    else return false;
}

