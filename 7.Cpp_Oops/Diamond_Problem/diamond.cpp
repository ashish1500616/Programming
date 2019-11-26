#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    void walk()
    {
        cout << "animal walks" << endl;
    }
};
class Tiger : virtual public Animal
{
};
class Lion : virtual public Animal
{
};
class Liger : public Tiger, public Lion
{
};

int main()
{
    Liger ob;
    ob.walk();
    return 0;
}

/*

When we call the class Liger 
it throws an error multiple instance .
using virtual keyword solves this .

*/