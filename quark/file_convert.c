#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef uint8_t u8;

// the main function
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
