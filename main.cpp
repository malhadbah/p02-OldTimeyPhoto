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

//In order to repeat the question whenever the user enters invalid image we should beggin with do while loop
//Use this boolean value
bool validBmp;
do
{

//Asks the user for which file he wants
//Read the file and convert it to pixel Matrix

cout<<"what file do you want to open? and make sure it's a bmp file."<<endl;
cin>>j;

//open image (before checking)
image.open(j);

//checking valid or not
validBmp = image.isImage();

if(validBmp == true)
{

//verify that the file opened was a valid image
bmp = image.toPixelMatrix();


//[y] so it will check each row and to adapt to it's shape

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
}
//if validBmp is false, loop will repeat
//if validBmp is true, loop will end after this
}while(validBmp==false);
                                                                             
return 0;

       }
       //we do not exit the loop until validBmp is true
       //we check only after we open the image (main mistake)
