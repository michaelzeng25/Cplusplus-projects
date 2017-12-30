// fstream for product.cpp : Defines the entry point for the console application.
//
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;
#include <vector>
int main()
{
	//1
	string *ProductId, Description;
	double counter, numitems, stock, price, total, grandtotal;


	//2
	ifstream inFile; //input file stream variable
	ofstream outFile; //output file stream variable
	inFile.open("products.txt"); //open a txt file with data                   
	outFile.open("productsOut.txt"); //output the processed file in the same location 
	//excel to excel or excel to txt wont work


	//4
	//without these twpro together, the decimal will not match, like 13.30 ane 12.45, without these two line codes, 13.30 become 13.3
	outFile << fixed << showpoint;   //without this, the numbers will mess up and round up               
	outFile << setprecision(2); //without this, decimall places will mess up, a lot of decimal place. the 2 means 2 decimal place

	//3
	//setw mean how far each from each other, this line of code is to give title of each colume of data in infile and to output it 
	outFile << setw(10) << "ProductID" << setw(15) << "Description" << setw(10) << "Price" << setw(10) << "Stock" << setw(10) << "Total" << "\n";
	//inFile >> numitems; // the infile has a number 5 mean how many different types of datas. how to get rid of this fixd size?
	counter = 1;
	grandtotal = 0; 
	
	int numitems = 100;
	ProductId = new string [numitems];
	//ProductID = new int[]; dont know how many rows
	for (int x = 0; x < numitems; x++)//numitems has 5 rows in the infile

	{
	
		inFile >> ProductId[x] >> Description >> price >> stock;//data could be in the same colume or in order. 
		if (ProductId[x] == ProductId[x+1])//productId is mess up
			break;
		total = price*stock;
		grandtotal += total;//similar to grandtotal+total. gives the sum of total
		//while loop will set up the data 
		outFile << setw(10) << ProductId << setw(15) << Description << setw(10) << price << setw(10) << stock << setw(10) << total << "\n";

		counter += 1;//counter is nessacery but not quiet sure why, maybe it is used to remember hwo many time it counts
		
	}
	outFile << setw(50) <<"grandtotal "<< grandtotal << "\n";
	

	//here try to print the data out in the debug window
	for (int x = 0; x < 100; x++)//only output the last value 5 times.
	{
		cout << ProductId[x] << endl;;//only the buttom one show up
		if (ProductId[x] == ProductId[x + 1])
			break;
	}


	//5
	inFile.close();
	outFile.close();
	system("pause");
}

//how to prin out the whole thing?
//how to print out the totals and the highest total?