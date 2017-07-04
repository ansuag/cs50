
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    
    if (n < 1 || n > 100)
    {
        printf("Factor must be between 1 and 100\n");
        return 1;
    }
    char* infile = argv[2];
    char* outfile = argv[3];
 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;

    out_bi.biWidth *= n;
    out_bi.biHeight *= n;

    int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    out_bi.biSizeImage = abs(out_bi.biHeight) * (out_bi.biWidth * sizeof(RGBTRIPLE) + out_padding);
    out_bf.bfSize = (out_bi.biSizeImage + 54);

    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fseek(inptr, 54 + (bi.biWidth * 3 + in_padding) * i, SEEK_SET);
            
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                RGBTRIPLE triple;
        
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int l = 0; l < n; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            for (int y = 0; y < out_padding; y++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    return 0;
}