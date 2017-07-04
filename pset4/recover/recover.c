#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(void)
{

    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
       fprintf(stderr, "Cannot create card.raw.\n");
        return 1;
    }
    
    FILE* outptr = NULL;

    typedef uint8_t  BYTE;
    BYTE buffer[512];

    BYTE firstfour[4];
    
    BYTE jpgsig[4] = {0xff, 0xd8, 0xff, 0xe0};

    int jpgnumber = 0;
    char jpgfilename[8];

    while (fread(&buffer, sizeof(buffer), 1, inptr) > 0)
    {
	for (int i = 0; i < 4; i++)
	{
	    firstfour[i] = buffer[i];
	}

	firstfour[3] = (firstfour[3] >> 4) << 4;

        if (memcmp(firstfour, jpgsig, sizeof(jpgsig)) == 0)
        {
            if (outptr == NULL)
            {
                sprintf(jpgfilename, "%03d.jpg", jpgnumber);
                outptr = fopen(jpgfilename, "a");
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
            
            else
            {
                fclose(outptr);
                jpgnumber++;
                sprintf(jpgfilename, "%03d.jpg", jpgnumber);
                outptr = fopen(jpgfilename, "a");
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        }
        
        else
        {
            if (outptr != NULL)
            {
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        }
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}