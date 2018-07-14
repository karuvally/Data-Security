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


// the quark function definition
int quark( u8 *out, const u8 *in, u64 inlen );


// the main function
int main(int argc, char* argv[])
{
  // essential variables
  u8 out[MAXDIGEST];
  long file_size;
  int i;

  // read the file
  if(argc > 1)
  {
    // create the file pointer
    FILE *file_pointer = fopen(argv[1], "rb");

    // find the file length
    fseek(file_pointer, 0, SEEK_END);
    file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    // read the file contents
    u8 *file_contents = malloc(file_size + 1);
    fread(file_contents, file_size, 1, file_pointer);
    fclose(file_pointer);

    // debug
    u8 dummy_data[5] = {0x03, 0x25, 0x62, 0x14, 0xb9};
    quark(out, dummy_data, 5);

    // try to create hash
    // quark(out, file_contents, file_size + 1);
    
    for(i=0; i<MAXDIGEST; ++i)
    {
        printf("%d", out[i]);
    }
    printf("\n");
  }

  return 0;
}
