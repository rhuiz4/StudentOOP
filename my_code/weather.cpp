#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {

}

// destructor
Image::~Image() {
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}



Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}


double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
}


/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

ostream& operator<<(ostream& os, const Weather& w) {
    os << "Name: " << w.station_nm << ", Rating: " << w.rating << ", "
    << w.my_loc << endl;
    return os;
}

ostream& operator<<(ostream& os, const GPS& gps) {
    os << "Longitude: " << gps.longitude << ", Latitude: " << gps.latitude;
    return os;
}

string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const { return rating; }

void Weather::set_rating(int new_rating) { rating = new_rating; }

void Weather::add_reading(WReading wr) {
    wreadings.push_back(wr);
}
