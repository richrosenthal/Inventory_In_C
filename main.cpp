//Author: Richard Rosenthal, rnr5142, 11-1-2020
//Class: CMPSC 121
//Project 2
//Purpose: To create an invoicing program that can read and output to files.

/********************************************************************\
* Academic Integrity Affidavit:                                      *                                                                                                                                                     *                                                                    *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *                                                                                                                                                                                                                                                                                                                       *                                                                    *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment,reduced *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of logic assistance:  Textbook/Project 1 assignment readme
// N/A


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printInvoiceHeader(string);
void printReportHeader();
double calcCost(int, double);
double accTotal(double, double);
void printLine(string, string, int, double, double);
void printTotal(double);



//function double calcCost(int, double);

ofstream fout;



int main() {
    //open output file
    fout.open("output.txt");

    ifstream inputFile;
    int items;
    string code;
    string date;
    string name;
    int quantity;
    double unitCost;
    double totalCost;
    double itemCost;
    double invoiceCost;

    inputFile.open("input.txt");
   if (inputFile){
       printReportHeader();

       while(inputFile >> items >> date){

           totalCost = 0; // reset total cost
           invoiceCost = 0; //reset invoice cost

           printInvoiceHeader(date);

           for(int i = 0; i < items; i++){
               inputFile >> code >> name >> quantity >> unitCost;
               itemCost = calcCost(quantity, unitCost);
               invoiceCost += accTotal(itemCost, totalCost);
               printLine(code, name, quantity, unitCost, itemCost);
           }
           printTotal(invoiceCost);

       }


       //Close the file
       fout.close();
       inputFile.close();
       cout << "Done. \n";

   }
   else {
       cout << "Error opening the file. \n";
   }


return 0;

}

//function to multiply the cost per unit times the quantity
double calcCost(int quantity, double unitCost){

    double totalCost = quantity * unitCost;

    return totalCost;
}

//accumulates the total of the line cost
double accTotal(double itemCost, double totalCost){

    totalCost += itemCost;
    return totalCost;

}


void printLine(string code, string name, int quantity, double unitCost, double itemCost){

    fout << code << " " << name << " " << quantity << " "  << unitCost << " " << itemCost << endl;
}


// Function to write invoice date on the output file.
void printInvoiceHeader(string date){

    fout << "Invoice Date: " << date << endl;
}

// function to display coompany name
void printReportHeader(){
  fout << "     Erie Industrial Supply Corporation     " << endl;
}



void printTotal(double invoiceTotal){
    fout <<  "Total ……………………………………………………………………………" << invoiceTotal << endl;
    fout << endl;
}

/* Execution Sample:
 * /Users/richardrosenthal/CLionProjects/Project_2/cmake-build-debug/Project_2
Done.

Process finished with exit code 0

 output file sample:
     Erie Industrial Supply Corporation
Invoice Date: 2/12/2017
134276 Framis-R 8 7.35 58.8
125790 Framis-L 12 15.76 189.1
100086 Aglet 395 0.11 43.45
Total ……………………………………………………………………………291.4

Invoice Date: 1/23/2017
135876 Wrench 12 22.5 270
543287 Henway 4 19.25 77
Total ……………………………………………………………………………347


 *
 *
 * */