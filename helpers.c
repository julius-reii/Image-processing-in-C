#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][(width - 1) - j].rgbtRed = temp;

            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][(width - 1) - j].rgbtBlue = temp;

            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            image[i][(width - 1) - j].rgbtGreen = temp;
        }
    }

    return;
}

// Convert image to negative
void negative(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 255 - image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = 255 - image[i][j].rgbtGreen;
            image[i][j].rgbtRed = 255 - image[i][j].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;

            int count = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentY < 0 || currentX > (height - 1) ||
                        currentY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    count++;
                }
            }
            copy[i][j].rgbtRed = round(totalRed / count);
            copy[i][j].rgbtGreen = round(totalGreen / count);
            copy[i][j].rgbtBlue = round(totalBlue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }

    return;
}