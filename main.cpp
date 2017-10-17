#include<iostream>
#include<vector>
#include"bitmap.h"


using namespace std;


int main()

{


Bitmap image;

vector <vector <Pixel> > bmp;

Pixel rgb;
//store the file that the other user wants to use
string j;

//Asks the user for which file he wants
//Read the file and convert it to pixel Matrix

cout<<"what file do you want to open? and make sure it's a bmp file."<<endl;
cin>>j;

bool validBmp=image.isImage();
if(validBmp == true)
{
image.open("j");
//verify that the file opened was a valid image
bmp = image.toPixelMatrix();

}
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

                                                                              

return 0;

       }
