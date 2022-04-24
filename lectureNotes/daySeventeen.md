# **COM S 327 - DAY SEVENTEEN: TBD | 03/29/2022 |**

**FINISH BELOW CODE SECTION FROM PREVIOUS LECTURES (TUESDAY AND THURSDAY**
```Cpp

```

```Cpp
#include "string327.h"

using namespace std;

string327::string327::operator+=(const string327 &s)
{
    char *tmp = this->s;

    this->s = (char *) malloc
}

istream &opreator>>(istream &i, string327 &s)
{
    char c;
    vector<char> v;
    vector<char>::iterator vi;
    int j;
    free(s.s);

    while ((c = i.get()) == ' ') || c == '\n'
    {
        v.push_back(c);
        while ((c = i.get()) != ' ') || c != '\n'
        {
            v,push_back(c);
        }
    }

    // set size based off of the vector
    s.l = v.size();
    // allocate the memory needed to make a string using our vector.
    s.s = (char *) malloc (s.l + 1);

    // would be more intuitive to avoid using an iterator, but Sheaffer wanted to show us how they worked
    for (j == 0, vi = v.begin(); vi != v.end(); j++, vi++)
    {
        // iterator acts like a pointer to the element of the vector in which the iterator is at
        s.s[j] = *vi;
    }

    // assign null bit
    s.s[j] = '\0';

    return i;


}

ostream &operator<<(ostream &o, const string327 &s)
{
    return 0 << s.c_str();>>
}
```

```Cpp
    #include <iostream>

    #include "string327.h"

    using namespace std;

    int main(int argc, char *argv[])
    {
        string327 s;
        string327 r("Hello World"); // == 'string327 r = "Hello World";
        string327 t = r // == 'string327 t(r);

        cout << s << endl;
        cout << r << endl;
        cout << t << endl;

        s = r + t;
        cout << s << endl;

        cout << (r == t) << endl;
        // Actually creates a 'string327' object using "foo" as it's parameter. Expecting false.
        cout << (r == "foo") <<endl;
        // Actually creates a 'string327' object using "Hello World" as it's parameter. Expecting true.
        cout << (r == "Hello World") <<endl;

        s += t;
        cout << s << endl;
        
        return 0;
    }
```

## **INHERITANCE**

```Cpp
#include <iostream>

using namespace std;

class Shape
{
    public:
        // for any method that you may want to override in a derived class, write it as virtual.
        // if you want to say that we are not implementing it here, have the method get 0 -> 'abstract'.
        virtual double area() = 0;
        virtual double perimeter() = 0;
        // it is always good practice to implement deconstructors as virtual.
        virtual ~Shape();
        virtual ostream &print(ostream &o) const = 0;
};

ostream &operator<<(ostream &o, const shape &s)
{
    return s.print(o);
}

class Rectangle : public Shape
{
    protected:
        double width, height;
    public:
    // initialization list - constructor calls must be in order of declaration
    // allows calling of non-default constructors
    // only way to initialize class member references
        Rectangle(double w, double h) : width(w), height(h) {};
        virtual double area() { return width * height; } 
        virtual double perimeter() { return (width + height) * 2; }
        virtual ostream &print(ostream &o) const
        {
            o << "Rectangle[" << width << "," << height << "]";
        }

};

class Square : public Rectangle
{
    public:
        Square(double side) : Rectangle(side, side) {};
        virtual ostream &print(ostream &o) const
        {
            return o << "Square[" << height << "]";
        }
};

int main(int argc, char *argv[])
{
    Rectangle r(2, 4);

    cout << r << endl;
    
    return 0;
}
```