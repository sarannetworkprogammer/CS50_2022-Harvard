#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int BLOCK_SIZE = 512;
    int count = 0;
    char outfilename[100];
    FILE *img = NULL;

    if (argc != 2)
    {
        // it checks for two arguments
        printf(" Usage: ./recover IMAGE\n");
        return 1;
    }
    else
    {
        //opens the file
        FILE *file = fopen(argv[1], "r");


        if (file != NULL)
        {
            //char c; it checkt the null file

            typedef uint8_t BYTE;
            BYTE buffer[6000];


            while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
            {
                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xe0) == 0xe0))

                {
                    printf("start of new jpeg found\n");
                    // it closes the previous file
                    if (!(count == 0))
                    {
                        fclose(img);
                    }

                    //it opens the new file

                    sprintf(outfilename, "%03i.jpg", count);

                    printf("outfilename = %s\n", outfilename);
                    img = fopen(outfilename, "w");

                    count = count + 1;
                }

                // once the new file is opened write the data


                if (!(count == 0))
                {
                    fwrite(buffer, 512, 1, img);
                }

            }


        }

        fclose(img);
        fclose(file);
        return 0;



    }



}

