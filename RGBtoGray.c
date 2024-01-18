#include <stdio.h>

void main() 
{
    FILE *fIn = fopen("C:\\Users\\Poojitha Sai\\Downloads\\snail.bmp","rb");                    //Input File name
    FILE *fOut = fopen("C:\\Users\\Poojitha Sai\\Downloads\\snail1.bmp", "wb");


    int i, j, y;
    unsigned char header[54];

    if (fIn == NULL)   
    {
        printf("The file does not exist.\n");
    }

    for (i = 0; i < 54; i++)               //read the 54 byte header from fIn
    {
        header[i] = getc(fIn);
    }

    fwrite(header, sizeof(unsigned char), 54, fOut);         //write the header back
    // extract image height, width and bit Depth from image Header
    int height = *(int*)&header[18];
    int width = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    printf("Width of the original image: %d\n",width);
    printf("Height of the original image: %d\n",height );
    printf("bitDepth of the original image: %d\n",bitDepth );

    int size = height * width;                        

    unsigned char buffer[size][3];              //to store the image data


    for (i = 0; i < size; i++)                                         //RGB to gray
    {
        y = 0;
        buffer[i][2] = getc(fIn);                                 //blue
        buffer[i][1] = getc(fIn);                                 //green
        buffer[i][0] = getc(fIn);                                 //red

        y = (buffer[i][0] * 0.3) + (buffer[i][1] * 0.59)  + (buffer[i][2] * 0.11);          //conversion formula of rgb to gray

        putc(y,fOut);
        putc(y,fOut);
        putc(y,fOut);
    }

    fclose(fOut);
    fclose(fIn);
}