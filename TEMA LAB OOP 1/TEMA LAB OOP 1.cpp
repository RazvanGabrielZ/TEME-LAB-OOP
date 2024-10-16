#include <iostream>
using namespace std;


double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;           //Formula for conversion FAHRENHEIT to CELSIUS
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;              //Formula for conversion CELSIUS to FAHRENHEIT
}

int main()
{
    double temp;
    int choice;

    cout << "Temperature Converter" << endl;
    cout << "1 --> Convert Fahrenheit to Celsius" << endl;                  
    cout << "2 --> Convert Celsius to Fahrenheit" << endl;
    cout << "Input your choice: ";
    cin >> choice;                                                       //Here we will choose one of the options depending on what conversion we need

    if (choice == 1) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        double celsius = fahrenheitToCelsius(temp);
        cout << "Temperature in Celsius: " << celsius << " C" << endl;
    }
    else if (choice == 2) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        double fahrenheit = celsiusToFahrenheit(temp);
        cout << "Temperature in Fahrenheit: " << fahrenheit << " F" << endl;
    }
    else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
    return 0;
}