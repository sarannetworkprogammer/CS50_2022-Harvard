#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])

{
    int avg;
    //printf("height =%i\n", height);

    //printf("width = %i\n", width);

    for(int i =0; i < height  ; i++)
    {
        for(int j = 0; j < width  ; j++)
        {
            avg = lround(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0));

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;


        }
    }





    //average of 3 colours, each
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

     for(int i =0; i < height ; i++)
    {
        for(int j = 0; j < width ; j++)

        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = lround(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = lround(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = lround(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed ;

            }
            else

            {
                 image[i][j].rgbtRed = 255;
            }

            if(sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }


        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp1, temp2, temp3;

    int n = width ;
    for(int i =0; i < height ; i++)
    {
         for(int j = 0; j < n/2 ; j++)
         {
            temp1 = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][n-j-1].rgbtRed;
            image[i][n-j-1].rgbtRed = temp1;


            temp2 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][n-j-1].rgbtGreen;
            image[i][n-j-1].rgbtGreen = temp2;


            temp3 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][n-j-1].rgbtBlue;
            image[i][n-j-1].rgbtBlue= temp3;


        }

    }









    //










    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    sumRed += temp_image[i + k][j + l].rgbtRed;
                    sumGreen += temp_image[i + k][j + l].rgbtGreen;
                    sumBlue += temp_image[i + k][j + l].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = (int)round(sumRed / count);
            image[i][j].rgbtGreen = (int)round(sumGreen / count);
            image[i][j].rgbtBlue = (int)round(sumBlue / count);
        }
    }
}

int cap255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        return color;
    }
}

