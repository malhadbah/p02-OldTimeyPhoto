#include<iostream>
#include<vector>
#include"bitmap.h"

using namespace std;

int main()
{

Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;

//read the file and convert it to pixel Matrix
image.open("OldTimeyPicture.bmp");
bmp = image.toPixelMatrix();

//nested loop
for(int y=0; y< bmp.size(); y++)
  { 
    for(int x=0; x< bmp[y].size(); x++)
      {
       //for each pixel
       rgb = bmp[y][x];
       //get the average to turn the pixel to grayscale
       int avg = (rgb.red + rgb.blue + rgb.green) / 3;
       //reseting the color on bmp matrix to average
       bmp[y][x].red = avg;
       bmp[y][x].green = avg;
       bmp[y][x].blue = avg;
       }
   }

//Put the changed image back into matrix, update the bitmap and save it
image.fromPixelMatrix(bmp);
image.save("OldTimeyPicture.bmp");
 

//verify that the file opened was a valid image

bool validBmp = image.isImage();
if( validBmp == false)

   return 0;
   }
