#include<iostream>

using namespace std;

class Person {
    private: 
    string name; 
    int age; 
    
    public: 
    int get_age(){
        return this->age;
    }
    void set_age(int age){
        this->age = age; 
    }
    string get_name(){
        return this->name;
    }
    void set_name(string name){
        this->name = name; 
    }
    void print(){
        cout<<"The name of the person is "<<this->name<<" and the age is "<<this->age<<"."<<endl;
    }

};

int main() {

    string s ;
    int n ; 
    cin>>s>>n; 
    
    Person p; 
    p.set_age(n);
    p.set_name(s);
    p.print();
    

    return 0;
}