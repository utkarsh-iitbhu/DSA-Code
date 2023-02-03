#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    public:
    int r; 
    int im;
    ComplexNumbers(int r, int im){
        this->r = r ; 
        this->im = im ;
    }
    
void print(){
    cout << this->r << " + i" << this->im << endl;
}

void plus(ComplexNumbers c){
    // r and im to pahle se diya rahega 
    int r = this->r + c.r; 
    int im = this->im + c.im; 
    this->r = r; 
    this->im = im ; 
    
}

void multiply(ComplexNumbers c){
    // r and im to pahle se diya rahega
    // ComplexNumbers temp(r * c.r - im * c.im, r * c.im + im * c.r);
    int r = this->r*c.r - this->im*c.im; 
    int im = this->r*c.im + this->im*c.r;; 
    // Naye r and im ko update karenge 
    this->r = r; 
    this->im = im ; 
    
}
    

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}