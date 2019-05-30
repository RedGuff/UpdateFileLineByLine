#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string funktion ( string str = "" )
{
    return str + "."; // Stupid example!
}

int main()
{
    string FileIn = "";
NewFileIn:
    FileIn = "";
    while ( FileIn == "" )
        {
        // FileIn  = "In.txt";
        cout << "FileIn?" << endl;
        getline ( cin, FileIn );
        }
/*
    string FileOut = "";
NewFileOut:
    FileOut = "";
    while ( FileOut == "" )
        {
        // FileOut  = "Out.txt";
        cout << "FileOut?" << endl;
        getline ( cin, FileOut );
        }
*/
    ifstream fileI ( FileIn.c_str(), ios::in );
    if ( !fileI )
        {
        cerr << "Impossible to open " << FileIn << "!" << endl;
        goto NewFileIn;

        }
                else
            {

                    string FileOut = "";
NewFileOut:
    FileOut = "";
    while ( FileOut == "" )
        {
        // FileOut  = "Out.txt";
        cout << "FileOut?" << endl;
        getline ( cin, FileOut );
        }



    ofstream fileO ( FileOut.c_str(), ios::app ); // Open to append.
    if ( !fileO )
        {
        cerr << "Impossible to open " << FileOut << "!" << endl;
        goto NewFileOut;
        }
    else
        {


            string line1 = "";
            string line2 = "";
            while ( getline ( fileI, line1 ) )
                {
                line2 = funktion ( line1 );
                // cout << ligne << endl; // Tests ok.
                fileO << line2 << endl; // append file.
                }
            }
        fileO.close();
        fileI.close();
        }
    cout << "Ok." << endl;
    return 0;
}
