#include <iostream>
#include <random>

using namespace std;


void set_min_max(int &min, int &max) {
    cout << "Enter the range of numbers in which the guessing number should be included" << endl;
    cout << "Please provide minimum:" << endl;
    cin >> min;
    cout << "Great, now enter the maximum number" << endl;
    cin >> max;

    if (min >= max) {
        cout << "Enter a valid number range. Max must be greater than min" << endl;
        set_min_max(min, max);
    }
}

int generate_int(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min) + min;
}

int get_guess_number(int min, int max) {
    int guess_number;
    cout << "Enter the drawn number: " << endl;
    cin >> guess_number;
    if (guess_number < min || guess_number >= max) {
        cout << "The given number is out of range <" << min << ',' << max << ")"<<endl;
        return get_guess_number(min, max);
    }
    return guess_number;
}

void compare_results(int &guess_number, int random_number, int min, int max) {
    if (guess_number == random_number) {
        cout << "Congratulations, you guessed the number" << endl;
        return;
    }
    if (guess_number < random_number) {
        cout << "The random number is bigger than your number" << endl;
    } else {
        cout << "The random number is smaller than your number"<< endl;
    }
    guess_number = get_guess_number(min, max);
    compare_results(guess_number, random_number, min, max);
}

int main() {
    int min, max;

    bool play_again = true;

    while (play_again) {
        set_min_max(min, max);

        int random_number = generate_int(min, max);

        int guess_number = get_guess_number(min, max);

        compare_results(guess_number, random_number, min, max);

        cout << "Do you want play again ? 0. No 1. Yes" << endl;

        cin >> play_again;
    }

    return 0;
}

