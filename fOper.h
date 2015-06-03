/* 
 * File:   fOper.h
 * Author: demiin
 *
 * Created on March 28, 2015, 1:14 PM
 */

#ifndef FOPER_H
#define	FOPER_H

#include <fstream>
#include <string>

using namespace std;

class fOper {
public:
    fOper(string filename): _filename(filename){};
    virtual ~fOper();
    
    bool openW();
    bool openR();
    void closeW();
    void closeR();
    bool write(string data);
    string read();
    
private:
    string _filename;
    ofstream fout;
    ifstream  fin;
};

#endif	/* FOPER_H */

