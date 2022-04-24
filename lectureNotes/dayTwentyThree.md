# **COM S 327 - DAY TWENTY-THREE: FUNCTION OVERLOADING | 04/12/2022 |**

## ASSIGNMENT 1.08 INFORMATION:
* Many of the equations are incorrect and need further context.
* If not using new, need to have a working copy constructor for capturing a wild Pokemon.
* Since the number of Pokemon in our game is dynamic, it is technically better to use new when generating our Pokemon.

---
## USING C FUNCTIONS IN CPP:
* When using a C coded user-defined header in CPP files, should prefix it like so: ```C_HEADER_H```.
* Name mangling - exists to allow function overloading. 

C Header File:
```c
#ifndef
#define C_HEADER_H

// When the CPP compilers sees this, it doesn't name-mangle.
extern "C" {
    void c_function(void);
}

#endif
```

C File:
```c
#include "c-header.h"

#include <stdio.h>

void c_function(void) {
    printf("Hello");
}
```

CPP Header File:
```cpp
#ifndef CPP_HEADER_H
#define CPP_HEADER_H

#ifdef __cplusplus
// All C++ only code must occur within these conditional blocks
// Because the C compiler sses this file and the preprocessor 
// removes this code.
extern "C" {
    void cpp_function(void);
    #ifndef __cplusplus
}
#endif

#endif
```

C File:
```c
#include "c-header.h"
#include "cpp-header.h"

int main(int argc, char* argv[])
{
    c_function();
    cpp_function();

    return 0;
}
```
---
## USING CPP FUNCTIONS IN C:

CPP File:
```cpp
#include "c-header.h"
#include "cpp-header.h"

int main(int argc, char* argv[])
{
    c_function();
    cpp_function();

    return 0;
}
```

---
## WRITING CPP INTERFACES:

cpp-io-stream.cpp
```CPP
#include <iostream>
#include "c-io-stream.h"

using namespace std;

istream *new_ostream()
{
    return &cout;
}

void use_ostream(istream *i, const char *msg)
{
    *i << msg;
}

```

c-io-stream.h:
```c
#ifndef C_IO_STREAM_H
#define C_IO_STREAM_H

#ifdef __cplusplus
#include <iostream>

extern "C" {
#else
// Only C compiler sees things in here
#define ostream void 
#endif

istream *new_ostream();
void use_ostream(ostream *i, const char *msg);

#ifdef __cplusplus
}
#endif

#endif
```

iostream.c
```c
#include "c-iostream.h"

int main(int argc, char *argv[])
{
    ostream *i;

    i = new_ostream();
    use_ostream(i, "Hello World\n");

    return 0;
}

```

* "Opaque handle" - refers to allowing a user to use a library without allowing them to be able to view the code / take a peek at it.

---
## STATIC VARIABLES IN CPP:

num_examples.cpp
```cpp
#include <iostream>

using namespace std;

// Symbol is not exported from compilation unit... Same as C.
// Global to only this file. However, could return the address of this variable to access it outside of this file.
static int foo; 

// Also same as C. Cannot call bar() outside of this file.
// "Kind of" allows for the creation of private methods for an abstract data type. Not as useful in CPP as it is in C.
static int baz()
{
    // Also same as C. num_calls persists across calls to baz().         Lifetime == lifetime of program.
    static int num_calls = 0;
    
    return num_calls++;
}

class static_example {
    private:
        static int num_instances;
    public:
        static_example()
        {
            num_instances++;
        }

        static_example(static_example &s)
        {
            num_instances++;
        }

        ~static_example()
        {
            num_instances--;
        }

        static int get_num_instances()
        {
            return num_instances;
        }
};

// Static class variables msut be declared outside of the class.
int static_example::num_instances = 0;

int main(int argc, char* argv[])
{
    int i;

    for (i = 0; i < 10; i++) {
        cout << baz() << end;
    }

    // Static methods allow them to be used without an instance of the class existing.
    cout << static_example::get_num_instances() << endl;

    static_example se;

    cout << static_example::get_num_instances() << endl;
}
```

singleton.cpp
```cpp
#include <iostream>

using namespace std;

// The world and Pc from our game would be a great example of this.
// Or, a shared resource in a multi-threaded program.
// To prevent the user frm creating multiple instances, we have to make the constructor private, as well as a private copy constructor.
class singleton {
    private:
        static singleton *the_instance = 0;
        singleton() {}
        singleton(const singleton &s) {}
    public: 
        static singleton *get_instance()
        {
            if (!the_instance) the_instance = new singleton();
            return the_instance;
        }
};

singleton *singleton::the_instance = 0;

int main(int argc, char* argv[])
{
    singleton *s1;

    s1 = singleton::get_instance();

    return 0;
}
```