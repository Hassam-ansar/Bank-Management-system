#ifndef BANKGRAPH_H
#define BANKGRAPH_H

#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

class BankGraph {
private:
    static const int V = 10;
    string divisions[V] = {
        "Rawalpindi", "Gujrat", "Sargodha", "Gujranwala", "Lahore", 
        "Faisalabad", "Sahiwal", "Multan", "Bahawalpur", "Dera Ghazi Khan"
    };
    int adjMatrix[V][V];

public:
    BankGraph();
    void displayDivisions();
    string getCityName(int index);
    int getCityIndex(string cityName);
    void findShortestPath(string startCity, string endCity);
};

#endif

