//I made a Number System Calculator which allows users to convert numbers seamlessly between decimal, binary, octal, and hexadecimal representations. This feature is incredibly handy for programmers, students, and anyone working with different number bases using C++.

#include <iostream>
#include <cmath>
using namespace std;


//function prototype convert binary to decimal
int bintodec(long long);
//function prototype convert decimal to binary
long long dectobin(int);

// function prototype convert Binary to Octal
int convertBinarytoOctal(long long);
// function prototype convert Octal To Binary
long long convertOctalToBinary(int);

// function prototype convert Octal To Decimal
int octalToDecimal(int octalNumber);
// function prototype convert Decimal to Octal
int decimalToOctal(int decimalNumber);


// function definition convert binary to decimal
int bintodec(long long n) {
    float dec = 0.0, i = 0, rem;
    //int i = 0, rem;
    
    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
// function definition convert decimal to binary
long long dectobin(int p) {
  long long bin = 0;
  int rem, i = 1;

  while (p!=0) {
    rem = p % 2;
    p /= 2;
    bin += rem * i;
    i *= 10;
  }
  return bin;
}

// function definition Convert Binary to Octal
int convertBinarytoOctal(long long binaryNumber){
    int octalNumber = 0, decimalNumber = 0, i = 0;
    while(binaryNumber != 0){
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }
    i = 1;
    while (decimalNumber != 0){
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return octalNumber;
}
// function definition convert Octal To Binary
long long convertOctalToBinary(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}

// Function to convert octal number to decimal
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
//function definition convert Decimal to Octal
int decimalToOctal(int decimalNumber)
{
    int rem, i = 1, octalNumber = 0;
    while (decimalNumber != 0)
    {
        rem = decimalNumber % 8;
        decimalNumber /= 8;
        octalNumber += rem * i;
        i *= 10;
    }
    return octalNumber;
}


//main function.
int main() {

    while (1){
        int z;
        cout<<"\n \t\t** SIMPLE NUMBER SYSTEM CONVERSION CALCULATOR ** "<<endl<<"\t\t\t\t\t\tCoded By Priyanshu Garg"<<endl<<"\n"<<"1.Binary to Decimal\t 2.Decimal to Binary\t 3.Binary to Octal\t 4.Octal to Binary\t 5.Octal to Decimal\t 6.Decimal to Octal\t  10.Exit " <<endl;
        cin>>z;
        switch(z)
        {
        case 1:
            long long n;
            cout << "Enter a binary number: ";
            cin >> n;
            cout << n << " in binary = " << bintodec(n) << " in decimal"<<endl;
        break;
        case 2:
            int p, bin;
            cout << "Enter a decimal number: ";
            cin >> p;
            bin = dectobin(p);
            cout << p << " in decimal = " << bin << " in binary" << endl ;
        break;
        case 3:
            long long binaryNumber;
            cout << "Enter a binary number: ";
            cin >> binaryNumber;
            cout << binaryNumber << " in binary = " << convertBinarytoOctal(binaryNumber) << " in octal "<<endl;
        break;
        case 4:
            int octalNumber;
            cout << "Enter an octal number: ";
            cin >> octalNumber;
            cout << octalNumber << " in octal = " << convertOctalToBinary(octalNumber) << "in binary"<<endl;
        break;
        case 5:
            int octNumber;
            cout << "Enter an octal number: ";
            cin >> octNumber;
            cout << octNumber << " in octal = " << octalToDecimal(octNumber) << " in decimal";
        break;
        case 6:
            int decimalNumber;
            cout << "Enter a decimal number: ";
            cin >> decimalNumber;
            cout << decimalNumber << " in decimal = " << decimalToOctal(decimalNumber) << " in octal";
        break;

        case 10:
            exit(0);

        default:
        cout<<"Invalid"<<endl;
            break;
        }
    }
    return 0;
}