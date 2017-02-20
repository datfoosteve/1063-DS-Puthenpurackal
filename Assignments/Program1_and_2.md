```cpp
/**
* @ProgramName: Program-1 and 2
* @Author:Stephen Puthenpurackal
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 02 18 2017
*/

#include <iostream>
#include <fstream>
#include <string>

/**
* TXT Image Manipulation Starter
*
* This code is a simple way to read in color information stored in a space
* delimited txt format. The expected file format is:
*                ---------------------------
*                | width height            |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                ---------------------------
* So a 10x10 img would have 11 total rows, 10 rows of data, with 30 values in row.
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb {
	int r;
	int g;
	int b;
};

class ImageManip {
private:
	rgb** image;
	int width;
	int height;
	ifstream infile;
	ofstream ofile;
	string ifile_name;
	string ofile_name;
public:
	void readFile(string filename) {
		infile.open(filename);
		infile >> width >> height;   //Read in width and height from top of input file
									 //We need this so we can make the array the right 
									 //size. After we get these two values, we can
									 //now allocate memory for our 2D array.

		image = new rgb*[height];    //This array points to every row

		for (int i = 0; i<height; i++) {
			image[i] = new rgb[width]; //Now allocate each row of rgb's
		}

		//Read the color data in from our txt file
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				infile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
			}
		}
	}


	void writeFile(string filename) {
		ofile.open(filename);
		//Write out our color data to a new file
		ofile << width << " " << height << endl;
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
			}
			ofile << endl;
		}
	}

	/**
	* @FunctionName: grayScale
	* @Description:
	*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
	* @Params:
	*    rgb** image - 2D array holding rgb values
	*    int width - width of image
	*    int height - height of image
	* @Returns:
	*    void
	*/

	void grayScale() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
				image[i][j].r = gray;
				image[i][j].g = gray;
				image[i][j].b = gray;
			}

		}
	}


	/**
	* @FunctionName: grayScale
	* @Description:
	*     Loops through a 2D array and switches the values horizontally
	* @Params:
	*    rgb** image - 2D array holding rgb values
	*    int width - width of image
	*    int height - height of image
	* @Returns:
	*    void
	*/
	void flipHorizontal() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width/2; j++) {
				int red, green, blue;
				red = image[i][j].r;
				green = image[i][j].g;
				blue = image[i][j].b;
				image[i][j].r = image[i][width - 1 - j].r;
				image[i][j].g = image[i][width - 1 - j].g;
				image[i][j].b = image[i][width - 1 - j].b;
				image[i][width - 1 - j].r = red;
				image[i][width - 1 - j].g = green;
				image[i][width - 1 - j].b = blue;


			}
		}
	}


	/**
	* @FunctionName: flipVertical
	* @Description:
	*     Loops through a 2D array and switches the values upside down
	* @Params:
	*    rgb** image - 2D array holding rgb values
	*    int width - width of image
	*    int height - height of image
	* @Returns:
	*    void
	*/
		void flipVertical() {
			for (int i = 0; i < height/2; i++) {
				for (int j = 0; j < width; j++) {
					int red, green, blue;
					red = image[i][j].r ;
				green = image[i][j].g;
				blue = image[i][j].b;
				image[i][j].r = image[height - 1 - i][j].r;
				image[i][j].g = image[height - 1 - i][j].g;
				image[i][j].b = image[height - 1 - i][j].b;
				image[height - 1 - i][j].r = red;
				image[height - 1 - i][j].g = green;
				image[height - 1 - i][j].b = blue;

				}

			}
		}

};

int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;


	ImageManip theImage;
	theImage.readFile("bot.txt");
	
	//theImage.grayScale();
	//theImage.flipVertical();
	theImage.flipHorizontal();
	theImage.writeFile("newbotfile.txt");



	// int width;               //width of image
	// int height;              //height of image

	// rgb **imgArray;         //Pointer var for our 2D array because we         
	//                         //don't know how big the image will be!

	// ifile>>width>>height;   //Read in width and height from top of input file
	//                         //We need this so we can make the array the right 
	//                         //size. After we get these two values, we can
	//                         //now allocate memory for our 2D array.

	// imgArray = new rgb*[height];    //This array points to every row

	// for(int i=0;i<height;i++){
	//     imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	// }

	// //Read the color data in from our txt file
	// for(int i=0;i<height;i++){
	//     for(int j=0;j<width;j++){
	//         ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
	//     }
	// }

	// //We could make any changes we want to the color image here




	return 0;
}
```
