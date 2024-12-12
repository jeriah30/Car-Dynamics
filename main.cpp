#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "State.h"
#include "Input.h"
using namespace std;
//add more libraries and header files that you use

void readFile(const string& fileName, vector<Input>& inputs) {
    ifstream inFS(fileName);
    string vdLine;
    double velocity, deltaDot;
    char comma;
    
    if (!inFS.is_open()) {                                    
        cout << "Could not open input file: " << fileName << endl;
        return;
    }
    
    while (getline(inFS,vdLine)) {
        istringstream inSS(vdLine);
        if (inSS >> velocity >> comma >> deltaDot) {
            inputs.push_back(Input(velocity, deltaDot));
        }
    }
    inFS.close();
}

// 1) uncomment this part since zyBooks use it.
int main(int argc, const char* argv[]) {
    if (argc != 3)
    {
        std::cout << "./project3 inputFile outputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    
    ///////////////////// uncomment above before submitting on zyBooks /////////////////
//2) Comment the next 3 lines below
    
/*int main(void) {
    string inputFileName = "inputFile1.txt";
    string outputFileName = "outFile1.txt"; */
    State state(0, 0, 0, 0);
    
   //README
   //For inputFile 1, set the initial state (values of x, y, delta, theta) to (0,0,0.125,0)
   //For inputFile 2, set the initial state (values of x, y, delta, theta) to (0,0,0.076,0)
   //For inputFile 3 and 4, set the initial state (values of x, y, delta, theta) to (0,0,0,0)
   
    if (inputFileName == "inputFile1.txt") {
        state.setDelta(0.125);
    }
    else if (inputFileName == "inputFile2.txt") {
        state.setDelta(0.076);
    }
    
    vector<Input> inputs;
    readFile(inputFileName, inputs);
    
    ofstream outFS(outputFileName);
    if (!outFS.is_open()) {                                    
        cout << "Could not open output file: " << outputFileName << endl;
        return EXIT_FAILURE;
    }
    
    double t = 0;
    outFS << fixed << setprecision(4);
    
    for (size_t i = 0; i < inputs.size(); i++) {
        Input input = inputs.at(i);
        
        double velocity = input.getV();
        double deltaDot = input.getDeltaDot();
        
        outFS << t << ",";
        outFS << state.getX() << ",";
        outFS << state.getY() << ",";
        outFS << state.getDelta() << ",";
        outFS << state.getTheta();
        
        outFS << "," << velocity << "," << deltaDot << endl;
        
        state.updateState(velocity, deltaDot);
        t += 0.1;
    }
    outFS << t << ",";
    outFS << state.getX() << ",";
    outFS << state.getY() << ",";
    outFS << state.getDelta() << ",";
    outFS << state.getTheta();
    
    outFS.close(); 
    
    return 0;   
}