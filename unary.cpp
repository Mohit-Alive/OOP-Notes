#include <iostream>
using namespace std;

class inverse {
    int num;
public:
    inverse(int n){
        num=n;
    }
    // Overloading unary operator `-`
    inverse operator-() const {
        return inverse(-num);
    }
    friend ostream& operator<<(ostream& out, const inverse& c) {
        out << c.num<<endl;
        return out;
    }
};

int main() {
    inverse c1(2);

    inverse c2 = -c1;        // Uses overloaded `-` operator
    cout<<"c1: " << c1; 
    cout<<"c2: " << c2; 


    return 0;
}