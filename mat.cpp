
// Complete by searching for **
// NEVER delete my comments!!!
//---------------------------------------
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix 
// Compiler: g++
// Your name: Kayla Le
// FIle Type: matrix implementation file mat.cpp + cilent file?
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VL = 3; // table entry vector length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

//Purpose: converting a char to a number 
//PARAMETER: passing a char from the file text to be converted into a slot number
int convert(char x)
{ 
   return x - 'a';// use a formula to convert a to 0, b to 1, c to 2 etc.

} 

//Purpose: read the input file, convert the column char into a slot number, get the chars for the current row and column entry, fill vector V with the chars and then 
//push the vector V into the table T
// this reads the input file into the matrix table
void readTable()
{  int row, col;
   char col_c; //char from  column in  text file
   ifstream fin ("lines.txt", ios::in);//input filei
   // Read in the file into T
   while (fin >> row)  // per row
     { vector<char> V;
       fin >> col_c; col = convert(col_c);  // to a slot number
       char c; // one char from the file
       for(int i = 0;i < VL;i++){ //  Fill vector V with chars from the file (a for loop)
       fin >> c;//storing char from 

	V.push_back(c); //push char into vector
	T[row][col].push_back(V[i]);//  Put the vector in T[row][col]
     }//end of for loop
  }//end of while
}

//Purpose: display dashes for empty entries, and display the chars if there is an entry from the table
//PARAMETERS: passing chars/entry from table, provide a holder (ost) for the dahes and entries from the table (passed by ref) 
// display the vector nicely to the outstream
void showVector(vector<char> v, ostream& ost)
{if (v.size() == 0)  // empty entry will be dashes
    for (int i = 1; i <= VL; i++) ost << "- ";
  else
    {  // show the content of v separated by blanks
    for(int i =0;i < VL;i++)  ost << v.at(i) << " ";//storing all the chars of that row & column into ost
    }
}

//PURPOSE: display table with th rows  labeled
// display the matrix
void displayTable()
{
  // display T nicely labeled with row numbers
  //    by calling showVector with cout
  //    for each column
  for (int r = 0; r < R; r++)
    {    cout << r << ":";//printing out row number
      for (int c = 0; c < C; c++)
	{ showVector(T[r][c], cout);//show the chars for the current row and column of the table
	  cout << "|"; }//end of for loop
      cout << endl;
    }//end of for loop
}

//PURPOSE: saving the table to an outfile
// save the matrix to the output file
void saveTable()
{
   ofstream fout ("table.txt", ios::out);

  //    output T nicely labeled with row numbers
  //    by calling showVector with fout
  //    for each column
  for(int r = 0;r < R;r++)
   { fout << r << ":";
     for(int c =0;c < C;c++) {
      showVector(T[r][c],fout);
       fout << "|";
      }//end of for loop
    fout << endl;
  }//end of for loop
}

//PURPOSE: read from input file into a matrix of vectors and output the content to a file
//DESIGN: print which input file program is reading from, read table and then display it, print which file the prgram is saving the table to 

int main()
{
  cout << "reading from lines.txt" << endl;
  readTable(); 
  displayTable();
  
  cout << "saving the table in table.txt" << endl;
  saveTable();
}//the end
