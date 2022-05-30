#include "fight.h"
#include <iostream>
#include <fstream>

//Specifics: It is assumed that the input file's name wont have any spaces in between

int main(int argc, char **argv)
{
    fight mainFight;
    string fileName;

    if (argc == 2)
    {
        fileName = argv[1];
        cout << "Generando archivo..." << endl;
        mainFight.output.open("OUTPUT_" + fileName + ".txt");
        mainFight.readInputFile(fileName + ".csv");
        mainFight.applyBuffs();
        mainFight.beginFight();
        mainFight.output.close();
        cout << "Programa terminado." << endl;
        return 0;
    }
    return 1;
}

/* TODO:
-write output file
-get argv for file name input
*/