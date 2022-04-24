# **COM S 327 - DAY EIGHTEEN: EXAM REVIEW AND INHERITANCE CONTINUED | 03/31/2022 |**

## **EXAM REVIEW**
1) swapchar
```C
void swap(char *c1, char *c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
```
2) strdup
```C
char *strdup(int n, char *s)
{
    char *out = malloc(n + 1);
    int i;
    for (i = 0; i < n && s[i]; i++)
    {
        out[i] = s[i];
    }
    out[i] = "\0";

    return out;
}
```
3)
```C
a. int
b. void *
c. int
d. int
e. int (*cmp)(const void *, const void *)
```

4) **ASK FOR CREDIT FOR THIS**
```C
We cannot have arrays of void because the compiler does not know how much space to allocate for the array. Void does not have size.
```

5)
```C
There is no bounds checking, and we never know how large the buffer is. Because of this, if the buffer is too small, we can begin to overwrite parts of the program's memory as the result of buffer overflow attacks. This then begins to write code in random places, which can then be used to understand the system and gain access to the system. Surprisingly, buffer overflow attacks are still commonly used today.
```

6) **ASK IF THERE IS ANYWAY COULD RECEIVE MORE POINTS**
```C
void *memcpy(void *dest, void *src, size_t n)
{
    // Must cast to character pointers to ensure handling memory sizes of any kind.
    char *to = dest;
    char *from = src;
    int i;

    for (i = 0; i < n; i++)
    {
        to[i] = dest[i];
    }

    return dest;
}
```

7)
```C
*s1 = 'c'; // error
s1 = s2; // okay
*s2 = "c"; // okay
s2[i] = 'c'; // okay
```

## **BACK TO C++**
* abstract and 'pure virtual' are the same thing.
* base classes must have a virtual deconstructor.
* to use a base class's constructor, we must use an initialization list.
    * constructor calls must be in the order of declaration.
```Cpp
```Cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
            return o << "Rectangle[" << width << "," << height << "]";
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

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        virtual double area() { return (radius * radius) * M_PI; } 
        virtual double perimeter() { return M_PI * (2 * radius); }
        virtual ostream &print(ostream &o) const
        {
            return o << "Circle[" << radius << "]";
        }
};

int main(int argc, char *argv[])
{
    Rectangle r(2, 3);
    r.perimeter();

    // Invoking polymorphism.
    shape &s = r;
    s.perimeter();
    /*
    * Polymorphism only works (and makes sense) on pointers
    * and references!
    */

    cout << r << endl;

    // Has to be a pointer because if not, we would be instantiating 
    // shapes which we cannot due.
    Shape *a[100];
    int i;

    for (i = 0; i < 100; i++)
    {
        // new and delete use a different heap than malloc and free.
        switch(rand() % 3)
        {
            case 0:
                a[i] = new Rectangle(rand() / (RAND_MAX + 1.0),
                                     rand() / (RAND_MAX + 1.0));
                break;
            case 1:
                a[i] = new Square(rand() / (RAND_MAX + 1.0);
                break;
            case 2:
                a[i] = new Circle(rand() / (RAND_MAX + 1.0);
                break;
        }
    }
    
    for (i = 0; i < 100; i++)
    {
        // Simply printing an object will print its memory address.
        // You must dereference them to print their contents.
        cout << *a[i] << "P: " << a[i]->perimeter() 
                      << "A: " << a[i].area() << endl;
    }

    // Polymorphism only works on pointers and references.
    // Polymorhpism is not a static trait, it is a dynamic one.
    for (i = 0; i < 100; i++)
    {
        delete(a[i]);
    }

    return 0;
}
```