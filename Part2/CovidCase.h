#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
using std::ostream;
using std::string;
using std::cout;
using std::endl;
using namespace std;
// TODO: your code  goes here

class CovidCase{
    double latitude;
    double longitude;
    string name;
    int age;
    int timeTestedPositive;
  public:
    CovidCase(double latitude, double longitude, string name, int age, int timeTestedPositive)
    {
      this->latitude = latitude;
      this->longitude = longitude;
      this->name = name;
      this->age = age;
      this->timeTestedPositive = timeTestedPositive;
    }
    CovidCase(string input){
      vector<string> result;
        stringstream s_stream(input); //create string stream from the string
        while(s_stream.good()) {
          string substr;
          getline(s_stream, substr, ','); //get first string delimited by comma
          s_stream.ignore();
          result.push_back(substr);
        }

        string temp_name = result[2];
        temp_name.erase(0, 1);
        temp_name.erase(temp_name.size() - 1);

        latitude = stod(result[0]);
        longitude = stod(result[1]);
        name = temp_name;
        age = stoi(result[3]);
        timeTestedPositive = stoi(result[4]);


  }
    friend ostream& operator<<(ostream& os, const CovidCase& cc);

    // Getters
    double getLatitude() {
      return latitude;
    }
    double getLongitude() {
      return longitude;
    }
    string getName() {
      return name;
    }
    int getAge() {
      return age;
    }
    int getTime() {
      return timeTestedPositive;
    }

    double distanceTo(const CovidCase& cc)
    {
      double PI = 4.0*atan(1.0);

      double dlat1=latitude*(PI/180);
      double dlong1=longitude*(PI/180);
      double dlat2=cc.latitude*(PI/180);
      double dlong2=cc.longitude*(PI/180);

      double dLong=dlong1-dlong2;
      double dLat=dlat1-dlat2;

      double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
      double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));

      const int earth=3960;
      double distance=earth*cHarv;
      return distance;
    };
    bool operator==(const CovidCase& other)
    {
      return latitude==other.latitude
      && longitude==other.longitude
      && name==other.name
      && age==other.age
      && timeTestedPositive==other.timeTestedPositive;
    };
  };

    ostream& operator<<(ostream& os, const CovidCase& cc)
    {
        os << "{" << cc.latitude << ", " << cc.longitude << ", " << '"' << cc.name << '"' << ", " << cc.age << ", " << cc.timeTestedPositive << "}";
        return os;
    };



// don't write any code below this line

#endif
