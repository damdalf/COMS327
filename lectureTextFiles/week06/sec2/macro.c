#include <stdio.h>

#define MAX_VAL 10  // Value-type macro

#define max(x, y) (x > y ? x : y) // Function-type macro
#define max3(x, y, z) max(max(x, y), z)

// In C, basic blocks have the value of their last statement
// If you wrap a basic block in (), it becomes an expression
#define min(x, y) ({ \
  typeof (x) _x = x; \
  typeof (y) _y = y; \
  _x < _y ? _x : _y; \
})

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

#define concatenate(x) x ## bar

#define BIT_x a_bit_value1
#define BIT_y a_bit_value2
#define BIT_z a_bit_value3

#define get_bit(x, bitfield) BIT_ ## x & bitfield

#define stringify(x) #x

typedef void (*fptr)(void)

#define lu_entry(x) { #x, x }

typedef struct {
  char *name;
  fptr func;
} lu_table_entry;

lu_table_entry lu_table[] = {
  lu_entry(bar),
  lu_entry(baz),
  lu_entry(bif),
  lu_entry(foo),
};

((lu_table_entry *) bsearch("bif", lu_table,
                            sizeof (lu_table) / sizeof (lu_table[0]),
                            sizeof (lu_table[0]), compare_lu_entries))->func();

int main(int argc, char *argv[])
{
  printf("%d\n", MAX_VAL);

  printf("%d\n", max(5, 17));

  /*
  printf("%d\n", min(expensive_function(x,y,z), function_with_side_effects(a,b)));  

  max3(a,b,c);

  if (min(a,b) < x) {
    do something
  }
  */

  concatenate(foo);

  //  printf("%d\n", TWENTYFOUR);

  get_bit(y, bf)

    stringify(foo)

  return 0;
}
