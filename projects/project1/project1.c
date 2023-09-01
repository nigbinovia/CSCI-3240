#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// the main function is defined with the command line arguments argc and argv.
// argc counts the number of arguments passed by the user to the program, and 
// argv holds character pointers listing all the arguments.
int main(int argc, char *argv[]) 
{
    
//  if the argc doesn't have 2 arguments (preferably the name of the program and 
//  the text file to be read), the program cannot be executed and an error is printed 
    if (argc != 2)
    {
        printf("This program cannot be executed. \n");
    }
    
// if the argc does have 2 arguments, the program can begin
    
// a file pointer is declared to handle the given textfile. In this case, the file 
// is opened and prepped to be read with the "r" character 
    FILE *file = fopen(argv[1], "r");
    
// if there is no text file in the argv[1] space, the file cannot be opened and an 
// error is printed
    if (file == 0) 
    {
        printf("Failed to open the file.\n");
    }

// if there is a text file in argv[1], the text file starts to be processed    

// variables are declared and defined including some int variable holders, a counter, 
// and  a character array pointer. The pointer will allocate 17 bytes of memory. array
// will hold the first address of the first byte of memory
    int count = 0;
    int x, y;
    char* array = (char*)malloc (17 * sizeof(char));
    

// while a character (assigned to the int value x) can still be read in from the file and the end of the file hasn't been reached:    
    while ((x = fgetc(file)) != EOF) 
    {

//the counter is printed as a 7-bit number and the second character read in is set to y
        printf("%07x: ", count);
        y = fgetc(file);

// the first two characters are printed as hexadecimals and are added to the char* array as the first two elements
// any newline characters are read in, the hexadecimal is processed and they're converted into periods when it's time to print the letters. 
        printf("%02x%02x ", x, y);
        
        if (x == '\n')
        {
            x = '.';
        }
        if (y == '\n')
        {
            y = '.';
        }
        
        array[0] = x;
        array[1] = y;

// then the rest of the letters are printed
        
// for every set of 16 characters read in, grouping them in sets of 2
        int i;
        for (i = 2; i < 16; i += 2) 
        {
            
// characters are read in as sets of two
            int a = fgetc(file);
            int b = fgetc(file);

// if either character has reached the end of file, the code ends 
            if (a == EOF || b == EOF) 
            {
                break;
            } 
            
// otherwise the characters are printed as hexadecimals and are added to the char* array
            else 
            {
                printf("%02x%02x ", a, b);
                
                if (a == '\n')
                {
                    a = '.';
                }
                if (b == '\n')
                {
                    b = '.';
                }
                
                array[i] = a;
                array[i + 1] = b;
            }
        }

// when there's no more characters to read in, the space is filled in with spaces until the end of the loop
        for (; i < 16; i += 2) 
        {
            printf("     ");
        }
	
        printf(" ");
        
// after 8 sets of 2 characters are added to the char array, the letters are printed next to the hexadecimals and the count is increased to read in the next 16 characters
        printf("%.*s\n", 16, array);
        count += 16;
    }

// once the entire file has been read through, the file is closed and the char array is deallocated 
    fclose(file);
    free(array);
    return 0;
}
