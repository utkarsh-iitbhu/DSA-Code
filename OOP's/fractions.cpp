#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {
    public: 
    int num; 
    int den; 
    
    Fraction(int num, int den){
        this->num = num; 
        this->den = den; 
    }
    
    void add(Fraction f){
        num = this->num*f.den + this->den*f.num;
        den = this->den * f.den;        
        // this->num = num;
        // this->den = den;
    }
    
    void mul(Fraction f){
        num = this->num*f.num;
        den = this->den * f.den;        
        this->num = num;
        this->den = den;
    }
    
    void simplify(Fraction f){
        int g = __gcd(f.num,f.den);
        this->num = num/g;
        this->den = den/g; 
    }
    
    void print(){
        cout<<this->num<<"/"<<this->den<<endl;
    }
    
    

};

int main() {

    int a,b;
    cin>>a>>b;
    int q; cin>>q;
    Fraction f1(a,b);
    
    while(q--){
        int op ; cin>>op; 
        int c,d; 
        cin>>c>>d; 
        Fraction f2(c,d);
        
        if(op==1){
            f1.add(f2);
            f1.simplify(f1);
            f1.print();
        }
        else{
            f1.mul(f2);
            f1.simplify(f1);
            f1.print(); 
        }
        
    }
    
    
    
    

    return 0;
}