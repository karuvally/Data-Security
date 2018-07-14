/*
   Quark reference C implementation

   Copyright (c) 2010-2014 Jean-Philippe Aumasson <jeanphilippe.aumasson@gmail.com>

   To the extent possible under law, the author(s) have dedicated all copyright
   and related and neighboring rights to this software to the public domain
   worldwide. This software is distributed without any warranty.

   You should have received a copy of the CC0 Public Domain Dedication along with
   this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXDIGEST 48

// yeah, the type defintions :D
typedef uint64_t u64;
typedef uint8_t u8;

int quark( u8 *out, const u8 *in, u64 inlen );


// test quark hashing
int test_vectors()
{
  u8 out[MAXDIGEST];

  // quark( out, NULL, 0 );

  // return memcmp( out, digest_empty, sizeof( digest_empty ) );
}


int main(int argc, char* argv[])
{
  // essential variables
  long file_size;
  int i;

  // read the file
  if(argc > 1)
  {
    // create the file pointer
    FILE *file_pointer;
    file_pointer = fopen(argv[1], "rb");

    // find the file length
    fseek(file_pointer, 0, SEEK_END);
    file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    // read the file contents
    char *file_contents = malloc(file_size + 1);
    fread(file_contents, file_size, 1, file_pointer);

    // convert contents to integer array
    u8 *digest_input = malloc(file_size + 1);
    for(i = 0; i < file_size; ++i)
    {
      digest_input = file_contents;
      ++file_contents;
      ++digest_input;
    }
  }

  return 0;
}
