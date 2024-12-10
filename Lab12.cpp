#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

class ConcertTicket {
private:
    vector<int> seatNumbers;
    vector<int> reservedSeats;

public:
    ConcertTicket(int numberOfSeats) {
        for (int i = 1; i <= numberOfSeats; ++i) {
            seatNumbers.push_back(i);
        }
    }

    // Метод для резервування місця
    void reserveSeat(int seatNumber) {
        auto it = find(seatNumbers.begin(), seatNumbers.end(), seatNumber);
        if (it != seatNumbers.end()) {
            reservedSeats.push_back(seatNumber);
            seatNumbers.erase(it);
            cout << "Місце номер " << seatNumber << " успішно зарезервовано!" << endl;
        } else {
            cout << "Місце номер " << seatNumber << " недоступне для резервування." << endl;
        }
    }

    void displayAvailableSeats() const {
        cout << "Доступні місця: ";
        for (int seat : seatNumbers) {
            cout << seat << " ";
        }
        cout << endl;
    }

    void displayReservedSeats() const {
        if (reservedSeats.empty()) {
            cout << "Зарезервованих місць немає." << endl;
        } else {
            cout << "Зарезервовані місця: ";
            for (int seat : reservedSeats) {
                cout << seat << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int numberOfSeats;
    cout << "Введіть кількість місць: ";
    cin >> numberOfSeats;

    ConcertTicket ticket(numberOfSeats);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Забронювати місце\n";
        cout << "2. Вивести заброньовані місця\n";
        cout << "3. Вийти з програми\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            ticket.displayAvailableSeats();
            int seatToReserve;
            cout << "Введіть номер місця для резервування: ";
            cin >> seatToReserve;
            ticket.reserveSeat(seatToReserve);
            break;
        }
        case 2:
            ticket.displayReservedSeats();
            break;
        case 3:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 3);

    return 0;
}
