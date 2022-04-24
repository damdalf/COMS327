# **COM S 327 - DAY FOURTEEN: NCURSES LIBRARY | 03/10/2022 |**

## **NCURSES BASIC:**
* ncurses is a libary for C which allows for multiple different functionalities, mainly the greater ability to customize what is displayed in the terminal, allowing our program to move from a simple CLI program to a more 'lively' game with an actual UI.
* Any printing with color that has been done using ASCII values up to this point will have to be abandoned and completed using ncurses.
* Actual lecture notes (.txt files) from this lecture which contain a ton of information about ncurses will be posted later today.

---

## **TIPS FOR ASSIGNMENT 1.05:**
* Print the contents of the map once you have popped the PC from the priority queue, and then get the input from the user to move the PC.
    * Then, put the PC back into the priority queue and return to the top of the loop. 

---

## **FINISHING UP C:**
* Keywords:
    * register - Doesn't affect lifetime or scope. The compiler will try to put the variable in a register, which means that it will not have an address. Thus, it is an error to take an address of a register.
    * volatile - Tells the compiler that this value could change outside of the control of normal program flow, such as something along the lines of multi-threaded programming.
    * inline - **ASK PROFESSOR ABOUT THIS!**
    * goto - ```goto labelName``` - put labels in reverse order, deinit things that initialized without error.
        * Use ```goto labelName``` for exception handling, since C does not allow exception handling.
            * If you use it, get ready to justify your choice... lol.
            * Exception handling unwinds the Stack, so sometimes ```goto labelName``` is preferred.
            * Fun ```goto``` History:
                * "Structured Programming with goto Statements", Don Knuth.
                * "Go To Statement Considered Harmful", Edsger Dijkstra.

---