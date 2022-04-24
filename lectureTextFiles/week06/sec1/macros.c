#include <stdio.h>



#define MAX_VAL 10  // Value-type macro


#define max(x, y) x > y ? x : y   // Function-type macro

//In C, a basic block has the value of the expression in the last line
/*
{
  line 1;
  line 2;
  line 3;
  ...;
  line n;
}
*/
//You can turn a basic block into an expression by wrapping it in ()

#define min(x, y) ({ \
  typeof (x) _x = x; \
  typeof (y) _y = y; \
  _x < _y ? _x : _y; \
})

/*
int max(int x, int y)
{
  return x > y : x : y;
}
*/

#define ONE 1
#define TWO (ONE + ONE)
#define THREE (TWO + TWO)
#define FOUR (THREE + THREE)
#define FIVE (FOUR + FOUR)
#define SIX (FIVE + FIVE)
#define SEVEN (SIX + SIX)
#define EIGHT (SEVEN + SEVEN)
#define NINE (EIGHT + EIGHT)
#define TEN (NINE + NINE)
#define ELEVEN (TEN + TEN)
#define TWELVE (ELEVEN + ELEVEN)
#define THIRTEEN (TWELVE + TWELVE)
#define FOURTEEN (THIRTEEN + THIRTEEN)
#define FIFTEEN (FOURTEEN + FOURTEEN)
#define SIXTEEN (FIFTEEN + FIFTEEN)
#define SEVENTEEN (SIXTEEN + SIXTEEN)
#define EIGHTEEN (SEVENTEEN + SEVENTEEN)
#define NINETEEN (EIGHTEEN + EIGHTEEN)
#define TWENTY (NINETEEN + NINETEEN)
#define TWENTYONE (TWENTY + TWENTY)
#define TWENTYTWO (TWENTYONE + TWENTYONE)
#define TWENTYTHREE (TWENTYTWO + TWENTYTWO)
#define TWENTYFOUR (TWENTYTHREE + TWENTYTHREE)
#define TWENTYFIVE (TWENTYFOUR + TWENTYFOUR)

#define concat_example(x) x ## FOO

#define BIT_x
#define BIT_y
#define BIT_z

#define check_bit(b, bitfield) (BIT_ ## b & bitfield)

#define stringify(x) #x


typedef int(*fptr)(void);

int foo(void)
{
  return 0;
}

fptr f = foo;

f(f);

#define lu_table_entry(n) { #n, n }

typedef struct {
  char *name;
  fptr func;
} lu_entry;

lu_entry lookup_table[] = {
  lu_table_entry(bar),
  lu_table_entry(baz),
  lu_table_entry(foo),
};

((lu_entry *) bsearch("foo", lookup_table, 3,
                      sizeof (lookup_table[0]),
                      compare_lu_names))->func();

int main(int argc, char *argv[])
{
  printf("%d\n", MAX_VAL);

  printf("%d\n", max(5, 9));

  printf("%f\n", max(1.414, 3.142));

  /*
  printf("%f", max(expensive_function1(x, y, z), expensive_function2(a,b,c)));

  if (min(foo(x), bar(x)) < MAX_VAL) {
    do something;
  }
  */

  //  printf("%d\n", TWENTYFOUR);


  concat_example(bar);


  stringify(foo);


}
