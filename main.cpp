// ADAM MCKNIGHT
// CIS 1111 FINAL PROJECT
// AUG 08 2021
// FOR PROGRAM OUTPUT, PLEASE SEE THE DOCUMENTATION.
// IF AN ERROR HAPPENS AT RUNTIME PLEASE OPEN AN ISSUE ON THE
// REPO, SO IT CAN BE ADDRESSED. PROJECT, IS OPEN SOURCE WITH 
// COPYRIGHT LIMITATIONS, SEE LICENCE.MD FOR MORE.



#include <iostream>
#include <fstream>
#include <string>


using namespace std;




int addAsset(){
    string assetTitle;
    double assetPrice;

    cout << "\n" << endl;
    cout << "NEW ASSET ---" << endl;
    cout << "\n" << endl;

    cout << "Please Enter the Name of the Asset: ";
    cin >> assetTitle;

    if (assetTitle.size() <= 5 )
    {
       cout << "Please enter a more descriptive title. Greater than 5 characters." << endl;
       cout << "\n";
       
       cout << "Please Enter the Name of the Asset: ";
       cin >> assetTitle;

       cout << "Please Enter the Amount of the Asset: $ ";
       cin >> assetPrice;

       // WRITES TO DB FILE

       ofstream outputFile;
       outputFile.open("./data/db.txt");

       cout << "Adding Asset to the Database, one moment..." << endl;

       outputFile << assetTitle;
       outputFile << assetPrice;

      cout << "ADDED NEW ASSET: " << assetTitle << "\n" << "VALUED AT: $" << assetPrice << endl;

    }
    else
    {
      cout << "Please Enter the Amount of the Asset: $ ";
      cin >> assetPrice;


      cout << "\n" << endl;

      // WRITES TO DB FILE

         ofstream outputFile;
         outputFile.open("./data/db.txt");

         cout << "Adding Asset to the Database, one moment..." << endl;

         outputFile << assetTitle;
         outputFile << " ";
         outputFile << assetPrice;

         cout << "ADDED NEW ASSET: " << assetTitle << "\n" << "VALUED AT: $" << assetPrice << endl;

         cout << "\n" << endl;
    }
    
    

    


    return 0;
}

int assetDetails(){
   cout << "Asset Details" << endl;


   string savedDataToString;
   int SAVED_DATA_SIZE = 100;

   ifstream savedData("./data/saved.txt");

   string readData[SAVED_DATA_SIZE];

   while(savedData >> savedDataToString)
   {
      string readData = savedDataToString;
      cout << "\n";
      cout << "\n " << " " <<readData;
   }



   return -1;
}

int insuranceReport(){
   string companyName;
   string saveReportSelection;
   double numberOfAssets;
   double assetDetails;
   double assetAmountTotal;

   cout << "\n";
   cout << "\n";

   cout << "Insurance Report" << endl;

   cout << "This tool was intended to generate an insurance report, if assets become damaged, lost, stolen or destroyed." << endl;

   cout << "\n";
   cout << "\n";

   cout << "Please Enter the Company Name: ";
   cin >> companyName;

   cout << "Please Enter the Amount of Assets in USD $ ";
   cin >> assetAmountTotal;

   cout << "Please Enter the Total Number of Assets: ";
   cin >> numberOfAssets;

   cout << "Would you like to save the generated report? Y / N: ";
   cin >> saveReportSelection; 

   if(saveReportSelection == "Y" || saveReportSelection == )
   {
      // save report to file
      // show report data

      ofstream outputFile;
      outputFile.open("./reports/generatedReports.txt");

      cout << "INSURANCE REPORT FOR: " << companyName << endl;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "TOTAL NUMBER OF ASSETS REPORTED: " << numberOfAssets;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "TOTAL COST OF ASSETS REPORTED: $" << assetAmountTotal;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "ESTIMATED COST OF RECOVERY OF ASSETS REPORTED: $" << numberOfAssets/assetAmountTotal*100 << endl;

      outputFile << "INSURANCE REPORT FOR: " << companyName << endl;
      outputFile << "\n";

      outputFile << "\n";
      outputFile << "\n";

      outputFile << "TOTAL NUMBER OF ASSETS REPORTED: " << numberOfAssets;
      outputFile << "\n";

      outputFile << "\n";
      outputFile << "\n";

      outputFile << "TOTAL COST OF ASSETS REPORTED: $" << assetAmountTotal;
      outputFile << "\n";

      outputFile << "\n";
      outputFile << "\n";

      outputFile << "ESTIMATED COST OF RECOVERY OF ASSETS REPORTED: $" << numberOfAssets/assetAmountTotal*100 << endl;

      cout << "\n";

      cout << "REPORT GENERATED IN ./REPORTS/";
   }
   else
   {
      // show report data
      cout << "INSURANCE REPORT FOR: " << companyName << endl;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "TOTAL NUMBER OF ASSETS REPORTED: " << numberOfAssets;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "TOTAL COST OF ASSETS REPORTED: $" << assetAmountTotal;
      cout << "\n";

      cout << "\n";
      cout << "\n";

      cout << "ESTIMATED COST OF RECOVERY OF ASSETS REPORTED: $" << numberOfAssets/assetAmountTotal*100 << endl;
   }

   return 0;
}



int menu(){
    cout << "\n" << endl;
    cout << "invtor -- An Inventory Tracking System" << endl;
    cout << "(C) 2021, Adam McKnight" << endl;
    cout << "\n";

    cout << "\n";
    cout << "MAIN MENU ---" << endl;
    cout << "\n";

    cout << "\n";
    cout << "1 - ADD A NEW ASSET" << endl;
    cout << "2 - RUN AN INSURANCE REPORT" << endl;
    cout << "3 - VIEW SAVED ASSET DETAILS" << endl;
    cout << "4 - EXIT THE PROGRAM" << endl;
    cout << "\n";


   int selection;
   cout << "Enter Selection:";
   cin >> selection;

   switch (selection) {
      case 1:
        addAsset();
        break;
      case 2:
         insuranceReport();
         break;
      case 3:
         assetDetails();
         break;
      case 4:
         cout << "\n";
         cout << "EXITING NOW...";
         cout << "\n";
         return 0;
         break;
   }


   return -1;
}

int main() {

   menu();

   return 0;
}