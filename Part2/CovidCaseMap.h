#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include <iostream>
#include <vector>
#include "CovidCase.h"
using namespace std;

// TODO: your code goes here
class TimeAndCaseData{
private:
vector<TimeAndCaseData> activeCases;
int timeTestedPositive;
public:

  int getTime(){
    return timeTestedPositive;
  }
  int getNumberOfCases(){
    return activeCases.size();
  }

};

class CovidCaseMap{
private:
  vector<TimeAndCaseData> activeCases;
  vector<CovidCase> cases;
public:

    vector<CovidCase> addCase(CovidCase cc){
      cases.push_back(cc);
      return cases;
  }

    vector<TimeAndCaseData> getCasesOverTime(int time){
      for(int i = 0; i < cases.size(); i++){
        if(time > cases[i].getTime()){
          activeCases;
          cout << cases[i].getTime() << endl;
          return activeCases;
        }
      }
    }

    double supportVisitGreedyTSP(double latitude, double longitude, int time, int isolationLength){
      double distance;
      if(time < isolationLength){
      for(int i = 0; i < cases.size(); i++){
        if(time > cases[i].getTime()){
            double PI = 4.0*atan(1.0);

            double dlat1=latitude*(PI/180);
            double dlong1=longitude*(PI/180);
            double dlat2=cases[i].getLatitude()*(PI/180);
            double dlong2=cases[i].getLongitude()*(PI/180);

            latitude=cases[i].getLatitude();
            longitude=cases[i].getLongitude();

            double dLong=dlong1-dlong2;
            double dLat=dlat1-dlat2;

            double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
            double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));

            const int earth=3960;
            distance += earth*cHarv;
          }
        }
      }
    return distance;
    }
};
// don't write any code below this line

#endif
