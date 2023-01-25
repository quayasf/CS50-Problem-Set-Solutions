# CS50-Recover-Solution
My solution for week 4's problem set
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover IMAGE\n");
        return 1;
    }

    // open memory card
    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    // stores data to read
    BYTE buffer[512];

    // tracks number of jpegs generated
    int jpegCount = 0;

    // string to hold file name
    char *fileName = malloc(8 * sizeof(BYTE));

    // make file to write to
    FILE *outputFile = NULL;

    //reads the image's memory until the end of its file
    while (fread(buffer, sizeof(BYTE)*512, 1, inputFile) == 1)
    {
        //checks if a jpeg file is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //checks if the jpeg was already written into
            if (outputFile != NULL)
            {
                fclose(outputFile);
            }

            //writes the filename for the file to write the jpeg in
            sprintf(fileName, "%03i.jpg", jpegCount);
            jpegCount++;

            //opens file to write the jpeg in
            outputFile = fopen(fileName, "w");
        }

        //keeps writing until the next jpeg is found
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, outputFile);
        }
    }

    //closes all files and frees memory 
    fclose(outputFile);
    fclose(inputFile);
    free(fileName);
    return 0;

}
