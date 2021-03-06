// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Huiqing Wu

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main()
{
	//variable definition
	ifstream inputfile;
	ofstream outputfile;
	string magic_number, infoldername;
	int image_width, image_height, max_colorvalue;//width and height of the image(pixel)
	short int img[10][60][33][3];
	short int file_num=0, r=0, c=0;// the file number, row of pixel, colomn of pixel, coordinate of color of RGB 
	short int R, G, B;//the R,G,B value of each pixel
	int avg_R, avg_G, avg_B;//average color value of all the same coordinate pixel in each file
	
	int total_R, total_G, total_B;//SUM OF color value of all the same coordinate pixel in each file
	
	
	//ask user to input folder name
	cout << "Enter image set folder name(ppm): ";
	cin >> infoldername;
	//open first image file under the user input folder
	inputfile.open("C:\\Users\\leeson\\Desktop\\watermelon\\MSCS\\first semester\\CS201\\assignment\\assignment 2\\imagestacker\\ppms\\" + infoldername + "\\" + infoldername + "_001" + ".ppm");
	//get header data from inputfile
	inputfile >> magic_number >> image_width >> image_height >> max_colorvalue;

	//open outputfile and rename it plus_good
	outputfile.open(infoldername + "_good.ppm");
	//output header data into outputfile
	outputfile << magic_number << endl << image_width << " " << image_height << endl << max_colorvalue << endl;
	
	//read pixel data into array
	//for loop to open image file under the user input file one by one
	for (file_num = 0; file_num < 10; file_num++)
	{
		if (file_num < 10)
		{
			inputfile.open("C:\\Users\\leeson\\Desktop\\watermelon\\MSCS\\first semester\\CS201\\assignment\\assignment 2\\imagestacker\\ppms\\" + infoldername + "\\" + infoldername + "_00" + to_string(file_num + 1) + ".ppm");
			inputfile >> magic_number >> image_width >> image_height >> max_colorvalue;
		}
		else(file_num == 10);
		{
			inputfile.open("C:\\Users\\leeson\\Desktop\\watermelon\\MSCS\\first semester\\CS201\\assignment\\assignment 2\\imagestacker\\ppms\\" + infoldername + "\\" + infoldername + "_0" + to_string(file_num + 1) + ".ppm");
			inputfile >> magic_number >> image_width >> image_height >> max_colorvalue;
		}


		//for loop each pixel from row to row
		for (r = 0; r < image_height; r++)
		{
			for (c = 0; c < image_width; c++)
			{
				inputfile >> R >> G >> B;
				img[file_num][r][c][0] = R;
				img[file_num][r][c][1] = G;
				img[file_num][r][c][2] = B;
			}
		}
		//close inputfile;
		inputfile.close();
	}

	

	//output average color value of all the same coordinate pixel in each file into outputfile;
	for (r = 0; r < image_height; r++)
	{
		for (c = 0; c < image_width; c++)
		{
			total_R = total_G = total_B = 0;
			avg_R = avg_G = avg_B = 0;
			for (int file_num = 0; file_num < 10; file_num++)
			{
				total_R += img[file_num][r][c][0];
				total_G += img[file_num][r][c][1];
				total_B += img[file_num][r][c][2];

			}
			avg_R = total_R / 10;
			avg_G = total_G / 10;
			avg_B = total_B / 10;
			outputfile << avg_R << avg_G << avg_B;
		}
	}

	outputfile.close();


	return 0;

}
////void inputfileopen(string infordername, int file_num, string magic_number, int image_width, int image_height, int  max_colorvalue)
//{
//	for (int file_num = 0; file_num < 10; file_num++)
//	{
//		ifstream inputfile;
//		string infoldername;
//		inputfile.open("C:\\Users\\leeson\\Desktop\\watermelon\\MSCS\\first semester\\CS201\\assignment\\assignment 2\\imagestacker\\ppms\\" + infoldername + "\\" + infoldername + "_00" + to_string(file_num+1) + ".ppm");
//		inputfile >> magic_number >> image_width >> image_height >> max_colorvalue;
//
//	}
//
//
//}

