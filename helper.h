#ifndef JNP1_ZADANIE5_HELPER_H
#define JNP1_ZADANIE5_HELPER_H

#include <iostream>

int randomNumber();

class Price {
private:
    int value;

public:
    explicit Price(int n);

    Price operator+(const Price& other) const;
    bool operator<(const Price& other) const;
    const Price& operator-=(const Price& other);

    // format: 1234 PLN
    friend std::ostream& operator<<(std::ostream& os, const Price& price);
};

class Date {
    int totalMinutes;

public:
    Date(int day, int hour, int minute);

    // + 1 minuta
    Date& operator++();
    int operator-(const Date& other);
    bool operator<(const Date& other);

    // format: December, 20, 13:04
    friend std::ostream& operator<<(std::ostream& os, const Date& Date);
};

// Funkcja currentDate zwracająca bieżący czas symulacji. Symulacja zaczyna się
// 18.12.2017 o godzinie 16:00 i kończy 24.12.2017 o godzinie 18:00.
Date currentDate();
#endif //JNP1_ZADANIE5_HELPER_H
