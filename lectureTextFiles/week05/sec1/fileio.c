#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void usage(const char *argv0)
{
  fprintf(stderr, "Usage: %s [-rt|-wt|-rb|-wb] <filename>\n", argv0);

  exit(-1);
}

typedef enum {
  read_binary,
  write_binary,
  read_text,
  write_text,
} action_t;

/* Main program takes one of 4 switches:
 * -rt: read text
 * -wt: write text
 * -rb: read binary
 * -wb: write binary
 */
int main(int argc, char *argv[])
{
  action_t action;
  FILE *f;
  struct {
    int i;
    float f;
  } s;

  srand(time(NULL));

  if (argc != 3) {
    usage(argv[0]);
  }

  /* Ugly, but works
  if (argv[1][0] == '-') {
    if (argv[1][1] == 'r') {
      if (argv[1][1] == 'b') {
      } else if (argv[1][1] == 't') {
      } else {
        usage(argv[0]);
      }
    } else if (argv[1][1] == 'w') {
      if (argv[1][1] == 'b') {
      } else if (argv[1][1] == 't') {
      } else {
        usage(argv[0]);
      }
    } else {
      usage(argv[0]);
    }
  } else {
    usage(argv[0]);
  */

  if (!strcmp(argv[1], "-rt")) {
    action = read_text;
  } else if (!strcmp(argv[1], "-wt")) {
    action = write_text;
  } else if (!strcmp(argv[1], "-rb")) {
    action = read_binary;
  } else if (!strcmp(argv[1], "-wb")) {
    action = write_binary;
  } else {
    usage(argv[0]);

    return -1;
  }

  switch (action) {
  case read_text:
    if (!(f = fopen(argv[2], "r"))) {
      perror(argv[2]);
      return -1;
    }
    fscanf(f, "%d %f\n", &s.i, &s.f);
    printf("Read in %d %f\n", s.i, s.f);
    break;
  case read_binary:
    if (!(f = fopen(argv[2], "r"))) {
      perror(argv[2]);
      return -1;
    }
    fread(&s, sizeof (s), 1, f);
    printf("Read in %d %f\n", s.i, s.f);
    break;
  case write_text:
    f = fopen(argv[2], "w");
    s.i = rand();
    s.f = rand() / (float) RAND_MAX;
    printf("Writing %d %f\n", s.i, s.f);
    fprintf(f, "%d %f\n", s.i, s.f);
    break;
  case write_binary:
    f = fopen(argv[2], "w");
    /*
    s.i = rand();
    s.f = rand() / (float) RAND_MAX;
    */
    s.i = -66;
    s.f = 6.125;
    printf("Writing %d %f\n", s.i, s.f);
    fwrite(&s, sizeof (s), 1, f);
    break;
  }

  

  return 0;
}
