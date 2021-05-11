// Includes
#include <iostream>
#include <fstream>
#include <cmath>
#include "date.h"
#include "Vector.h"
#include "BST.h"
#include <map>

//-------------------------------------------------------------------------
// Struct that store date and sensor data of windlogType
typedef struct
{
    date *d;
} WindlogType;

//-------------------------------------------------------------------------
//declare functions
using std::cout;
using std::endl;
using std::string;

BST<date> dateTree;
BST<int> intTree;

//-------------------------------------------------------------------------
// Converts month number to month name
string month_num_to_name(int month_num)
{
    switch (month_num)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "wrong_month";
        break;
    }
}

void print(date &data)
{
    cout << data.getDay()
         << month_num_to_name(data.getMonth())
         << data.getYear() << endl;
}

//-------------------------------------------------------------------------
// Insert data from vector into BST
void IndexMonthYear(Vector<WindlogType> &windlog, BST<date> &dateTree, std::map<int, int> &IndexMap)
{
    bool month_changed = false;
    int var_year = 0, var_month = 0;
    var_year = windlog.at(0).d->getYear();
    var_month = windlog.at(0).d->getMonth();
    // cout << "var_month: " << var_month << " var_year: " << var_year << endl;
    date dateobj(windlog.at(0).d->getDay(), windlog.at(0).d->getMonth(), windlog.at(0).d->getYear());

    // cout << "." << endl;

    //add 1st rows in Vector to BST
    dateTree.insert(dateobj);
    // dateTree.InOrder(dateobj);

    IndexMap.insert(std::pair<int, int>(dateobj.getDateAsInt(), 0));
    // cout << " windlog.Size(): " << windlog.Size() << endl;

    for (int i = 1; i < windlog.Size(); i++)
    {
        // cout << "\nInside forloop" << endl;

        if (var_month != windlog.at(i).d->getMonth() || var_year != windlog.at(i).d->getYear())
        {
            month_changed = true;

            dateobj.setDate(windlog.at(i).d->getDay(), windlog.at(i).d->getMonth(), windlog.at(i).d->getYear());
            dateTree.insert(dateobj);
            IndexMap.insert(std::pair<int, int>(windlog.at(i).d->getDateAsInt(), i));
        }
        var_year = windlog.at(i).d->getYear();
        var_month = windlog.at(i).d->getMonth();
        // cout << "mid var_month: " << var_month << " var_year: " << var_year << endl;
    }

    cout << endl
         << "INORDER: " << endl
         << endl;
    dateTree.inorderTraversal(print);

    cout << endl
         << "PREORDER: " << endl
         << endl;
    dateTree.preorderTraversal(print);

    cout << endl
         << "POSTORDER: " << endl
         << endl;
    dateTree.postorderTraversal(print);

    // cout << "var_year" << var_year << endl;
}

//-------------------------------------------------------------------------
// Search the matching row based on user input
void Process_data(Vector<WindlogType> &windlog, BST<date> &dateTree, std::map<int, int> &IndexMap)
{

    // Search BST
    int search_from = 0, search_length = windlog.Size();
}

//-------------------------------------------------------------------------
// converts the string into compatible type by avoiding unuseful chars (delimeter, null, etc..)
void SplitString(std::string singleLine, WindlogType &StructWind)
{
    // Declear and initilize date and time attributs to store data
    int t_day, t_month, t_year;
    std::string sDay = "", sMonth = "", sYear = "", sHH = "", sMM = "";

    sDay = singleLine.substr(0, singleLine.find("/"));
    singleLine = singleLine.substr(singleLine.find("/") + 1, singleLine.size());
    sMonth = singleLine.substr(0, singleLine.find("/"));
    singleLine = singleLine.substr(singleLine.find("/") + 1, singleLine.size());
    sYear = singleLine.substr(0, singleLine.find(" "));

    //change date string into int
    t_day = stoi(sDay);
    t_month = stoi(sMonth);
    t_year = stoi(sYear);

    // File input Testing *****
    // std::cout << "sday: " << t_day << std::endl;
    // std::cout << "smoth: " << month_num_to_name(t_month) << std::endl;
    // std::cout << "syear: " << t_year << std::endl;
    // std::cout << endl;

    date *datePtr = new date(t_day, t_month, t_year);
    StructWind.d = datePtr;
}

//-------------------------------------------------------------------------
// Read metdata files from met_index file
void ReadFile(Vector<WindlogType> &windlog)
{
    string fileName = "data/date.txt";
    std::ofstream output_file;
    Vector<std::string> fileList;
    std::string singleLine;

    std::ifstream input(fileName);

    std::cout << "files name in " << fileName << std::endl;

    while (!input.eof())
    {
        WindlogType StructWind;

        getline(input, singleLine);
        cout << singleLine << " singleLine data inside loop" << endl;

        if (singleLine == "" || singleLine == " ")
        {
            break;
        }
        //add to data structure
        SplitString(singleLine, StructWind);

        // Add into windlog Vector
        windlog.push_back(StructWind);
    }
    input.close();

    input.clear();                 // clear stream flags and error state
    input.seekg(0, std::ios::beg); // reset read position
}

//-------------------------------------------------------------------------
// Main routine
int main()
{
    Vector<WindlogType> windlog;
    std::map<int, int> IndexMap;
    std::map<int, int>::iterator itrr;

    ReadFile(windlog);
    IndexMonthYear(windlog, dateTree, IndexMap);
    return 0;
}
