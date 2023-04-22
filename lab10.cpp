#include <iostream>
#include <string>

using namespace std;

struct PastryCategory{
    string categoryName;
    int numAwards;
};

struct Chef{
    string name, hometown;
    int numCategories;
};

int main(){
    int numChefs, highestNumAwards = 0, highestAwardIndex;

    cout << "\nHow many chefs are competing? ";
    cin >> numChefs;
    cin.ignore();

    Chef chefArr[numChefs];
    PastryCategory** awardsArr;
    awardsArr = new PastryCategory*[numChefs];

    cout << "\nPlease enter in information about each chef.\n";

    //loop for each chef to get entered
    for(int i = 0; i < numChefs; i++){
        int awardCount = 0;

        //getting input for chefs names, hometown, and number of awards
        cout << "\n***Chef " << i + 1 << "***" << endl;
        cout << "       NAME: ";
        getline(cin, chefArr[i].name);
        cout << "       HOMETOWN: ";
        getline(cin, chefArr[i].hometown);
        cout << endl << "       How many categories has " << chefArr[i].name << " won awards in? ";
        cin >> chefArr[i].numCategories;
        cin.ignore();

        //getting inputs for the awards and category of awards
        for(int j = 0; j < chefArr[i].numCategories; j++){
            cout << "       For category " << j + 1 << ":" << endl;
            cout << "               Name of category - ";
            getline(cin, awardsArr[i][j].categoryName);
            cout << "               Number of awards in " << awardsArr[i][j].categoryName << " - ";
            cin >> awardsArr[i][j].numAwards;
            cin.ignore();

            awardCount += awardsArr[i][j].numAwards;
        }
 
        if(awardCount > highestNumAwards){
            highestNumAwards = awardCount;
            highestAwardIndex = i;
        }
    }

    //outputting chef with the most awards
    cout << "\n\nThe pastry chef who has won the most awards (" << highestNumAwards << " awards) is " << chefArr[highestAwardIndex].name << endl;
    cout << "with awards in the following categories: " << endl;
    for(int i = 0; i < chefArr[highestAwardIndex].numCategories; i++){
        cout << "       " << awardsArr[highestAwardIndex][i].categoryName << "  (" << awardsArr[highestAwardIndex][i].numAwards << ")" << endl;
    }

    //deleting the arrays;
    for(int i = 0; i < numChefs; i++){
        delete[] awardsArr[i];
    }
    delete[] awardsArr;
    delete chefArr;

    return 0;
}