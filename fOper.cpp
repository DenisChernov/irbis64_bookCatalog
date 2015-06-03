/* 
 * File:   fOper.cpp
 * Author: demiin
 * 
 * Created on March 28, 2015, 1:14 PM
 */

#include "fOper.h"

//fOper(string filename): _filename(filename){

//};


fOper::~fOper() {
}

bool fOper::openW() 
{
    fout.open(_filename.c_str(), ios_base::app);
    return fout.is_open();
}

bool fOper::openR() {
    fin.open(_filename.c_str());
    return fin.is_open();
}

string fOper::read() 
{
    return "";
}

bool fOper::write(string data) 
{
    if (!fout.is_open())
        return false;
    else
    {
        fout << data;
        return true;
    }
}

void fOper::closeR() {
    fin.close();
}

void fOper::closeW() {
    fout.close();
}

