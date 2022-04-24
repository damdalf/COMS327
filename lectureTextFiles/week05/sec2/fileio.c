#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
  read_binary,
  write_binary,
  read_text,
  write_text
} action_t;

/* Main program takes a switch and a file name.  Switch options:
 * -rb: read binary
 * -rt: read text
 * -wb: write binary
 * -wt: write text
 */
int main(int argc, char *argv[])
{
  action_t action;
  struct {
    int i;
    float f;
  } s;
  FILE *f;

  srand(time(NULL));

  if (argc != 3) {
    fprintf(stderr, "Usage: %s [-rb|-wb|-rt|-wt] <filename>\n", argv[0]);

    return -1;
  }

  /*  Works, but ugly
  if (argv[1][0] == '-') {
    if (argv[1][1] == 'r') {
      if (argv[1][2] == 't') {
      } else if (argv[1][2] == 'b') {
      } else {
        //error
      }
    } else if (argv[1][1] == 'w') {
      if (argv[1][2] == 't') {
      } else if (argv[1][2] == 'b') {
      } else {
        //error
      }
    } else {
      //error
    }
  } else {
    fprintf(stderr, "Usage: %s [-rb|-wb|-rt|-wt] <filename>\n", argv[0]);

    return -1;    
  }
  */

  if (!strcmp(argv[1], "-rb")) {
    action = read_binary;
  } else if (!strcmp(argv[1], "-rt")) {
    action = read_text;
  } else if (!strcmp(argv[1], "-wb")) {
    action = write_binary;
  } else if (!strcmp(argv[1], "-wt")) {
    action = write_text;
  } else {
    fprintf(stderr, "Usage: %s [-rb|-wb|-rt|-wt] <filename>\n", argv[0]);

    return -1;
  }

  switch (action) {
  case read_binary:
    if (!(f = fopen(argv[2], "r"))) {
      perror(argv[2]);
      return -1;
    }
    fread(&s, sizeof (s), 1, f);
    printf("Read: %d %f\n", s.i, s.f);
    break;
  case write_binary:
    /*
    s.i = rand();
    s.f = rand() / (float) RAND_MAX;
    */
    s.i = 104;
    s.f = -2.75;
    f = fopen(argv[2], "w");
    fwrite(&s, sizeof (s), 1, f);
    printf("Wrote %d %f\n", s.i, s.f);    
    break;
  case read_text:
    if (!(f = fopen(argv[2], "r"))) {
      perror(argv[2]);
      return -1;
    }
    fscanf(f, "%d %f\n", &s.i, &s.f);
    printf("Read: %d %f\n", s.i, s.f);
    break;
  case write_text:
    s.i = rand();
    s.f = rand() / (float) RAND_MAX;
    f = fopen(argv[2], "w");
    fprintf(f, "%d %f\n", s.i, s.f);
    printf("Wrote %d %f\n", s.i, s.f);
    break;
  }

  return 0;
}
