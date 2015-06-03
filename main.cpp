/*
 * File:   main.cpp
 * Author: demiin
 *
 * Created on February 25, 2015, 4:03 PM
 */

#include <QApplication>
#include "catalogbook.h"
#include "form_apmSelect.h"
#include "form_GetListReturnBooks.h"
#include <vector>
#include <string>
#include <curl/curl.h>


using namespace std;

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

#ifdef _WIN32
	QCoreApplication::addLibraryPath(".");
#endif    
    
    setlocale(LC_ALL, "UTF-8");
    
    QApplication app(argc, argv);
    std::ios::sync_with_stdio(false);
    // обязательно регистрируем тип, который будем передавать\принимать в сигнале\слоте
    qRegisterMetaType<vector<string> >("vector<string>");
    qRegisterMetaType<bool>("bool");
    qRegisterMetaType<map<string,vector<string>> >("map<string,vector<string>>");
    
    form_apmSelect frmApmSelect;
    frmApmSelect.showMaximized();
    
//    catalogbook catalogWnd;
//    catalogWnd.showMaximized();
    
//    form_GetListReturnBooks getListReturnBooks;
//    getListReturnBooks.showMaximized();
  
    return app.exec();
}
