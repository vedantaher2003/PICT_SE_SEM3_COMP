//============================================================================
// Name        : Assignment_01.cpp
// Author      : Ritanshu Koul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Complex {
    int real,imaginary;
public:
    Complex(){
        real = 0;
        imaginary = 0;
    }
    Complex(int r, int i){
        real = r;
        imaginary = i;
    }
    void showComplexNumber(){
        cout << "The complex number is " << real << " + i" << imaginary << endl;
    }
    void showrealpart(){
        cout << "The real part is " << real << endl;
    }
    void showImaginarypart(){
        cout << "The imaginary part is " << imaginary << endl;
    }
    void set(){
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> imaginary;
    }
    Complex operator +(Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    Complex operator -(Complex c){
        Complex temp;
        temp.real = real - c.real;
        temp.imaginary = imaginary - c.imaginary;
        return temp;
    }
    Complex operator *(Complex c){
        Complex temp;
        temp.real = real*c.real - imaginary*c.imaginary;
        temp.imaginary = real*c.imaginary + imaginary*c.real;
        return temp;
    }
};

int main()
{
    Complex c1(4,5);
    Complex c2(5,5);
    Complex c3 = c1 + c2;
    c3.showComplexNumber();
    Complex c4;
    c4.set();
    Complex c5 = c4-c2;
    c5.showComplexNumber();
    Complex c6 = c1*c2;
    c6.showComplexNumber();
    return 0;
}
