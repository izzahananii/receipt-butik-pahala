#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Constants for prices
const double prices[] = {189.0 ,169.0 ,249.0 ,259.0};

// Function declaration
void calcdiscount(double totalpurchase, int totalquantity, double &discount, double &finalprice);

int main() {
    // Display welcome message
    cout << "\n================================" << endl;
    cout << "     Welcome to Butik Pahala    " << endl;
    cout << "================================" << endl;

    string name, hnum, street, city, state, zipcode, gender, fonnum;

    // Collect customer information
    cout << "\nEnter your full name: " << endl;
    getline(cin, name);

    bool validfonnum = false;
    while (!validfonnum) {
        cout << "\nEnter your phone number (0123456789): " << endl;
        getline(cin, fonnum);

        // Check if the length is valid
        size_t length = fonnum.length();
        if (length == 10 || length == 11) {
            validfonnum = true;
            break;
        } else {
            cout << "Invalid phone number length. Please re-enter." << endl;
        }
    }

    cout << "\nEnter your full address (house number, street address, city, zipcode, state) : " << endl;
    cout << "House number: "; getline(cin, hnum);
    cout << "Street address: "; getline(cin, street);
    cout << "City: "; getline(cin, city);
    cout << "Zipcode: "; getline(cin, zipcode);
    cout << "State: "; getline(cin, state);
    cout << "\n" << hnum << ", " << street << ",\n";
    cout << city << ", " << zipcode << ", " << state << ".\n";

    bool validgender = false;
    while (!validgender) {
        cout << "\nEnter your gender (M/F): ";
        cin >> gender;

        if (gender == "m" || gender == "M") {
            validgender = true;
        } else if (gender == "f" || gender == "F") {
            validgender = true;
        } else {
            cout << "Invalid gender.";
        }
    }

    // Variables for item selection and calculation
    string typeclothes, typecolor, size;
    int quantity, totalquantity = 0;
    double price, totalprice, totalpurchase = 0.0;
    char more;

    // Loop to add items to the cart
    do {
        // Choose type of clothes
        char clothes;
        bool validclothes = false;
        while (!validclothes) {
            cout << "\n==================================================" << endl;
            cout << "|           Choose your type of clothes:          |" << endl;
            cout << "|             m = Cekak Musang, RM 189            |" << endl;
            cout << "|            t = Teluk Belanga, RM 169            |" << endl;
            cout << "|             b = Baju Kurung, RM 249             |" << endl;
            cout << "|             k = Baju Kebaya, RM 259             |" << endl;
            cout << "==================================================" << endl;
            cout << "Enter the alphabet corresponding to your choice: ";
            cin >> clothes;

            if (clothes == 'm' || clothes == 'M') {
                typeclothes = "Cekak Musang";
                price = prices[0];
                validclothes = true;
            } else if (clothes == 't' || clothes == 'T') {
                typeclothes = "Teluk Belanga";
                price = prices[1];
                validclothes = true;
            } else if (clothes == 'b' || clothes == 'B') {
                typeclothes = "Baju Kurung";
                price = prices[2];
                validclothes = true;
            } else if (clothes == 'k' || clothes == 'K') {
                typeclothes = "Baju Kebaya";
                price = prices[3];
                validclothes = true;
            } else {
                cout << "Invalid choice. Please enter alphabet m, t, b or k only. ";
            }
        }

        int color;
        bool validcolor = false;
        while (!validcolor) {
            // Choose color
            cout << "\n===============================================" << endl;
            cout << "|        Choose your color of clothes:         |" << endl;
            cout << "|               1 = Light Grey                 |" << endl;
            cout << "|                 2 = Black                    |" << endl;
            cout << "|                3 = Maroon                    |" << endl;
            cout << "|                4 = Lilac                     |" << endl;
            cout << "|              5 = Baby Blue                   |" << endl;
            cout << "=================================================" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> color;

            if (color == 1) {
                typecolor = "Light Grey";
                validcolor = true;
            } else if (color == 2) {
                typecolor = "Black";
                validcolor = true;
            } else if (color == 3) {
                typecolor = "Maroon";
                validcolor = true;
            } else if (color == 4) {
                typecolor = "Lilac";
                validcolor = true;
            } else if (color == 5) {
                typecolor = "Baby Blue";
                validcolor = true;
            } else {
                cout << "Invalid color. Please enter number 1 to 5 only. " << endl;
            }
        }

        // Choose size
        bool validsize = false;
        while (!validsize) {
            cout << "\nChoose your size (XS, S, M, L, XL): ";
            cin >> size;

            if (size == "xs" || size == "XS") {
                validsize = true;
            } else if (size == "s" || size == "S") {
                validsize = true;
            } else if (size == "m" || size == "M") {
                validsize = true;
            } else if (size == "l" || size == "L") {
                validsize = true;
            } else if (size == "xl" || size == "XL") {
                validsize = true;
            } else {
                cout << "Invalid size. Please enter XS, S, M, L, XL only." << endl;
            }
        }

        // Enter quantity
        cout << "\nEnter the quantity: ";
        cin >> quantity;

        // Calculate total price for the current item based on type price and quantity
        totalprice = price * quantity;
        cout << "\nTotal price for this item: RM" << fixed << setprecision(2) << totalprice << endl;

        // Update total purchase and item count
        totalpurchase += totalprice;
        totalquantity += quantity;

        // Ask if the user wants to continue buying
        cout << "\nDo you want to continue buying? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');

    // Calculate discount and final price
    double discount = 0.0;
    double finalprice = totalpurchase;
    calcdiscount(totalpurchase, totalquantity, discount, finalprice);

    // Declare payment method variable before using it
    string typepayment;
    char proceed;
    cout << "\nDo you want to proceed to checkout? (y/n): ";
    cin >> proceed;
    if (proceed == 'y' || proceed == 'Y') {
        // Ask for payment method only once
        int payment;
        bool validpayment = false;
        while (!validpayment) {
            cout << "\nSelect payment method: " << endl;
            cout << "1. Online Payment" << endl;
            cout << "2. COD" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> payment;

            if (payment == 1) {
                typepayment = "Online Payment";
                validpayment = true;
            } else if (payment == 2) {
                typepayment = "COD";
                validpayment = true;
            } else {
                cout << "Invalid payment method. Please enter number 1 or 2 only." << endl;
            }
        }

        cout << "\nThank you for your purchase! Proceeding to payment." << endl;

    } else {
        cout << "Order cancelled. Thank you for visiting Butik Pahala!" << endl;
    }

    // Output to a file
    ofstream receipt("Receipt.txt");
    if (receipt.is_open()) {
        receipt << "\n================================" << endl;
        receipt << "           Butik Pahala          " << endl;
        receipt << "        Joy in Every Stitch      " << endl;
        receipt << "================================" << endl;
        receipt << "Customer Name: " << name << endl;
        receipt << "Customer Phone No: " << fonnum << endl;
        receipt << "Customer Address: " << hnum << ", " << street << ", " << city << ", " << zipcode << ", " << state << ".\n";

        // Total at receipt
        receipt << "\n=====================================\n";
        receipt << "Total purchase: RM " << fixed << setprecision(2) << totalpurchase << endl;

        // Only print discount message if applicable
        if (discount > 0) {
            receipt << "You are eligible for a 10% discount!" << endl;
            receipt << "Discount: RM " << fixed << setprecision(2) << discount << endl;
        }

        receipt << "Final Price: RM " << fixed << setprecision(2) << finalprice << endl;
        receipt << "Type of payment: " << typepayment << endl;

        receipt << "\nDon't forget to follow and tag us at @butikpahala .See you again!!" << endl;
        receipt << "www.butikpahala.com" << endl;
        receipt << "Thank you for shopping with us" << endl;
        receipt.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}

// Function to calculate discount
void calcdiscount(double totalpurchase, int totalquantity, double &discount, double &finalprice) {
    discount = 0.0;
    if (totalquantity >= 4) {
        discount = totalpurchase * 0.10;
        cout << "You are eligible for a 10% discount!" << endl;
    }

    finalprice = totalpurchase - discount;
}
