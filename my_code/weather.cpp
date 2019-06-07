#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

ostream& operator<<(ostream& os, const GPS& gps) {
    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude << endl;
    return os;
}

Weather::Weather(std::string nm, GPS loc) :
station_nm(nm), my_loc(loc) {
}

string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating() const{
    return rating;
}

void Weather::set_rating(int new_rating) {
    rating = new_rating;
}

ostream& operator<<(ostream& os, const Weather& w) {
    os << w.get_name() << ": rating" << w.get_rating() << " " << w.my_loc <<endl;
    return os;
}

//using namespace std;
//
///*
// * A constructor for weather class.
// * */
//Weather::Weather(std::string nm, GPS loc) :
//    station_nm(nm), my_loc(loc) {
//}
//
//ostream& operator<<(ostream& os, const Weather& w) {
//    os << "Name: " << w.station_nm << ", Rating: " << w.rating << ", "
//    << w.my_loc << endl;
//    return os;
//}
//
//ostream& operator<<(ostream& os, const GPS& gps) {
//    os << "Longitude: " << gps.longitude << ", Latitude: " << gps.latitude;
//    return os;
//}
//
//string Weather::get_name() const {
//    return station_nm;
//}
//
//int Weather::get_rating() const { return rating; }
//
//void Weather::set_rating(int new_rating) { rating = new_rating; }
