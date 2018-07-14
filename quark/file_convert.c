#include<stdio.h>
#include<stdlib.h>

// the main function
int main(int argc, char* argv[])
{
  // essential variables
  long file_size;

  // read the file
  if(argc > 1)
  {
    FILE *file_pointer;
    file_pointer = fopen(argv[1], "rb");

    fseek(file_pointer, 0, SEEK_END);
    file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);


    char *file_contents = malloc(file_size + 1);
    fread(file_contents, file_size, 1, file_pointer);

    printf("%c", file_contents);


    /*
    // convert to hex
    for(i=0; i<file_size; ++i)
    {
      
    }
    */
  }

  return 0;
}
