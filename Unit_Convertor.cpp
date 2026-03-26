#include <iostream>
#include <limits>
using namespace std;

// --------- Base Class ---------
class Converter {
protected:
    float value;
public:
    Converter(float v = 0) { value = v; }
    void setValue(float v) { value = v; }
    virtual void selectUnits() = 0;
    virtual void convert() = 0;
};

// --------- Length Conversion ---------
class LengthConverter : public Converter {
private:
    int from, to;
public:
    LengthConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. Centimeter  2. Meter  3. Kilometer\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. Centimeter  2. Meter  3. Kilometer\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = value / 100;
        else if (from == 1 && to == 3) result = value / 100000;
        else if (from == 2 && to == 1) result = value * 100;
        else if (from == 2 && to == 3) result = value / 1000;
        else if (from == 3 && to == 1) result = value * 100000;
        else if (from == 3 && to == 2) result = value * 1000;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "Centimeter\n"; break;
            case 2: cout << "Meter\n"; break;
            case 3: cout << "Kilometer\n"; break;
        }
    }
};

// --------- Weight Conversion ---------
class WeightConverter : public Converter {
private:
    int from, to;
public:
    WeightConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. Gram  2. Kilogram  3. Pound\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. Gram  2. Kilogram  3. Pound\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = value / 1000;
        else if (from == 1 && to == 3) result = value * 0.00220462;
        else if (from == 2 && to == 1) result = value * 1000;
        else if (from == 2 && to == 3) result = value * 2.20462;
        else if (from == 3 && to == 1) result = value * 453.592;
        else if (from == 3 && to == 2) result = value * 0.453592;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "Gram\n"; break;
            case 2: cout << "Kilogram\n"; break;
            case 3: cout << "Pound\n"; break;
        }
    }
};

// --------- Temperature Conversion ---------
class TemperatureConverter : public Converter {
private:
    int from, to;
public:
    TemperatureConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. Celsius  2. Fahrenheit  3. Kelvin\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. Celsius  2. Fahrenheit  3. Kelvin\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = (value * 9 / 5) + 32;
        else if (from == 1 && to == 3) result = value + 273.15;
        else if (from == 2 && to == 1) result = (value - 32) * 5 / 9;
        else if (from == 2 && to == 3) result = (value - 32) * 5 / 9 + 273.15;
        else if (from == 3 && to == 1) result = value - 273.15;
        else if (from == 3 && to == 2) result = (value - 273.15) * 9 / 5 + 32;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "Celsius\n"; break;
            case 2: cout << "Fahrenheit\n"; break;
            case 3: cout << "Kelvin\n"; break;
        }
    }
};

// --------- Currency Conversion ---------
class CurrencyConverter : public Converter {
private:
    int from, to;
public:
    CurrencyConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. Rs.  2. Dollar  3. Euro\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. Rs.  2. Dollar  3. Euro\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = value / 83;
        else if (from == 1 && to == 3) result = value / 90;
        else if (from == 2 && to == 1) result = value * 83;
        else if (from == 2 && to == 3) result = value * 0.92;
        else if (from == 3 && to == 1) result = value * 90;
        else if (from == 3 && to == 2) result = value * 1.08;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "Rs.\n"; break;
            case 2: cout << "Dollar\n"; break;
            case 3: cout << "Euro\n"; break;
        }
    }
};

// --------- Storage Conversion ---------
class StorageConverter : public Converter {
private:
    int from, to;
public:
    StorageConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. KB  2. MB  3. GB\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. KB  2. MB  3. GB\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = value / 1024;
        else if (from == 1 && to == 3) result = value / 1048576;
        else if (from == 2 && to == 1) result = value * 1024;
        else if (from == 2 && to == 3) result = value / 1024;
        else if (from == 3 && to == 1) result = value * 1048576;
        else if (from == 3 && to == 2) result = value * 1024;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "KB\n"; break;
            case 2: cout << "MB\n"; break;
            case 3: cout << "GB\n"; break;
        }
    }
};

// --------- Time Conversion ---------
class TimeConverter : public Converter {
private:
    int from, to;
public:
    TimeConverter(float v = 0) : Converter(v) {}

    void selectUnits() override {
        while (true) {
            cout << "Convert from: 1. Second  2. Minute  3. Hour\nYour choice: ";
            cin >> from;
            if (cin.fail() || from < 1 || from > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Convert to: 1. Second  2. Minute  3. Hour\nYour choice: ";
            cin >> to;
            if (cin.fail() || to < 1 || to > 3) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1, 2, or 3.\n";
                continue;
            }
            break;
        }
    }

    void convert() override {
        float result = 0;

        if (from == 1 && to == 2) result = value / 60;
        else if (from == 1 && to == 3) result = value / 3600;
        else if (from == 2 && to == 1) result = value * 60;
        else if (from == 2 && to == 3) result = value / 60;
        else if (from == 3 && to == 1) result = value * 3600;
        else if (from == 3 && to == 2) result = value * 60;
        else result = value;

        cout << "Result: " << result << " ";
        switch (to) {
            case 1: cout << "Second\n"; break;
            case 2: cout << "Minute\n"; break;
            case 3: cout << "Hour\n"; break;
        }
    }
};

// --------- Main Program ---------
int main() {
    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        // Main menu
        while (true) {
            cout << "\n------ UNIT CONVERTER ------\n";
            cout << "1. Length\n2. Weight\n3. Temperature\n4. Currency\n5. Digital Storage\n6. Time\n7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter 1-7.\n";
            } else break;
        }

        if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }

        Converter* conv = nullptr;
        float value;

        // Input value
        while (true) {
            cout << "Enter value: ";
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter numeric value.\n";
            } else break;
        }

        // Create appropriate converter
        switch (choice) {
            case 1: conv = new LengthConverter(value); break;
            case 2: conv = new WeightConverter(value); break;
            case 3: conv = new TemperatureConverter(value); break;
            case 4: conv = new CurrencyConverter(value); break;
            case 5: conv = new StorageConverter(value); break;
            case 6: conv = new TimeConverter(value); break;
        }

        conv->selectUnits();
        conv->convert();
        delete conv;

        // Ask to continue
        string input;
        while (true) {
            cout << "Do you want to convert again? (y/n): ";
            cin >> input;
            if (input.length() == 1 && (input[0]=='y'||input[0]=='Y'||input[0]=='n'||input[0]=='N')) {
                cont = input[0];
                break;
            } else {
                cout << "Invalid! Enter y/n.\n";
            }
        }
    }

    return 0;
}