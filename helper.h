#ifndef JNP1_ZADANIE6_HELPER_H
#define JNP1_ZADANIE6_HELPER_H

#include <iostream>

int randomNumber();

class Price {
private:
    int value;

public:
    explicit Price(int n = 0);

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
    int operator-(const Date& other) const;
    bool operator<(const Date& other) const;

    // format: December, 20, 13:04
    friend std::ostream& operator<<(std::ostream& os, const Date& Date);
};

// Julia: Funkcja currentDate zwracająca bieżący czas symulacji. Symulacja zaczyna się
// 18.12.2017 o godzinie 16:00 i kończy 24.12.2017 o godzinie 18:00.
// w sumie to troche nie rozumiem, czy ta obecna data ma się jakoś zmieniać?
// Tien: W przykładzie jest auto& czyli chyba zmiana czasu jest symulowana przez pętle i odbywa się przez referencję.
Date& currentDate();

#endif //JNP1_ZADANIE6_HELPER_H
