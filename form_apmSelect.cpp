/*
 * File:   form_apmSelect.cpp
 * Author: demiin
 *
 * Created on April 16, 2015, 11:13 AM
 */

#include "form_apmSelect.h"

form_apmSelect::form_apmSelect() {
    frmApmSelect.setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint | Qt::WindowType::WindowStaysOnTopHint);
//    this->showMaximized();
    

    connect(frmApmSelect.pbBookCatalog, SIGNAL(clicked()), this, SLOT(slot_bookCatalog()));
    connect(frmApmSelect.pbGetListReturnBooks, SIGNAL(clicked()), this, SLOT(slot_GetListReturnBooks()));
    
}

form_apmSelect::~form_apmSelect() {
}

void form_apmSelect::slot_bookCatalog() {
    this->setVisible(false);
    catalogWnd = new catalogbook();
    connect(catalogWnd, SIGNAL(closed(string)), this, SLOT(slot_closed(string)));
    catalogWnd->showMaximized();
}

void form_apmSelect::slot_closed(string what) {
    this->setVisible(true);
    if (what == "catalog") {
        delete catalogWnd;
    }
    else if (what == "lk") {
        delete getListReturnBooksWnd;
    }
}

void form_apmSelect::slot_GetListReturnBooks() {
    getListReturnBooksWnd = new form_GetListReturnBooks();
    connect(getListReturnBooksWnd, SIGNAL(closed(string)), this, SLOT(slot_closed(string)));
    getListReturnBooksWnd->showMaximized();
    this->setVisible(false);
}

void form_apmSelect::resizeEvent(QResizeEvent*) {
    frmApmSelect.pbBookCatalog->move(this->width() - frmApmSelect.pbBookCatalog->width() - 80, frmApmSelect.pbBookCatalog->y());
    frmApmSelect.pbGetListReturnBooks->move(this->width() - frmApmSelect.pbGetListReturnBooks->width() - 80, frmApmSelect.pbGetListReturnBooks->y());
    frmApmSelect.line->setGeometry(frmApmSelect.pbBookCatalog->x() - 20, 20, frmApmSelect.line->width(), this->height() - 40);
    frmApmSelect.gbInstruction->setGeometry(frmApmSelect.gbInstruction->x(), frmApmSelect.gbInstruction->y(), frmApmSelect.line->x() - 30, this->height() - 60);
    frmApmSelect.tbHelpOffline->setGeometry(frmApmSelect.tbHelpOffline->x(), frmApmSelect.tbHelpOffline->y(), frmApmSelect.gbInstruction->width() - 10, frmApmSelect.gbInstruction->height() - 40);
    setInstruction();
}

void form_apmSelect::setInstruction() {
    QPixmap pix_1; pix_1.load(":/1.png");
    QPixmap pix_2; pix_2.load(":/2.png");
    QPixmap pix_3; pix_3.load(":/3.png");
    QPixmap pix_4; pix_4.load(":/4.png");
    QPixmap pix_5; pix_5.load(":/5.png");
    QPixmap pix_6; pix_6.load(":/6.png");
    QPixmap pix_7; pix_7.load(":/7.png");
    
    string text = boost::str(boost::format("<html><head/><body><p><span style=\" font-size:20pt;\">Для начала работы, выберите интересующий вас модуль - «Электронный каталог» либо «Личный кабинет».</span></p><p><br/></p>"
        "<p><span style=\" font-size:24pt; font-weight:600;\">Модуль «Электронного каталога»</span></p>"
        "<p><img src=\":/1.png\" width=\"%s\" height=\"%s\"/></p>"
        "<p><br/><span style=\" font-size:20pt;\">Для поиска интересующего вас издания, необходимо указать в строке ввода, обозначенного как «Поиск», часть или полностью заглавие книги, либо автора, либо серию, в которую входит данная книга. Поисковый запрос начинает обрабатываться, при наличии не менее трех символов из запрашиваемого фильтра:</span></p>"
        "<p><br/></p>"
        "<p><img src=\":/2.png\" width=\"%s\" height=\"%s\"/></p>"
        "<p><span style=\" font-size:20pt;\">Для уточнения местонахождения искомого издания, можно воспользоваться выпадающим списком, расположенного справа от строки поиска. Для сброса уточнения местоположения, нужно выбрать пустую строку.</span></p>"
        "<p><img src=\":/3.png\" width=\"%s\" height=\"%s\"/></p><p><span style=\" font-size:20pt;\">Для того, чтобы узнать дополнительные сведения о найденной книге, необходимо выделить книгу щелчком мыши по ней и перейти на вкладку «Описание книги», расположенной слева от списка книг.</span></p>"
        "<p><img src=\":/4.png\" width=\"%s\" height=\"%s\"/></p><p><br/></p>"
        "<p><span style=\"font-size:24pt; font-weight:600;\">Модуль «Личного кабинета читателя»</span></p>"
        "<p><img src=\":/5.png\" width=\"%s\" height=\"%s\"/></p><p><span style=\" font-size:20pt;\">Для того, чтобы попасть в личный кабинет, вам необходимо воспользоваться читательским билетом. Поднесите ваш ЧБ  к, стоящему рядом, ручному сканеру, стороной, на которой нарисован полосковый код. Убедитесь что он появился в поле ввода и нажмите кнопку «Войти».</span> </p>"
        "<p><span style=\" font-size:20pt;\">При неверном вводе данных, появится визуальное уведомление и потребуется повторный ввод кода ЧБ.В личном кабинете вам доступны следующие функции:просмотр списка книг и журналов на руках, и количество дней до возврата;просмотр списка взятых ранее книг и журналов;продление срока, на который выдана книга (доступно только 2 продления);</span></p>"
        "<p><span style=\" font-size:20pt;\">Список книг выданных изданий и список находящихся на руках;</span></p>"
        "<p><span style=\" font-size:20pt;\">С помощью ползунка слева, можно корректировать вид отображения списка (делать больше первый или второй список).</span></p>"
        "<p><img src=\":/6.png\" width=\"%s\" height=\"%s\"/></p><p><span style=\" font-size:20pt;\">При нажатии кнопки «Продлить», появится окошко со списком изданий, находящихся на руках. Галочками необходимо отметить те книги или журналы, которые вы хотите продлить и нажать кнопку «Продлить».</span></p>"
        "<p><img src=\":/7.png\" width=\"%s\" height=\"%s\"/></p><p><span style=\" font-size:20pt;\">Библиотекарь получит уведомление о запросе на продление книг и отреагирует соответствующим образом.</span></p></body></html>") 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_1.width(), pix_1.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_1.width(), pix_1.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_2.width(), pix_2.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_2.width(), pix_2.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_3.width(), pix_3.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_3.width(), pix_3.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_4.width(), pix_4.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_4.width(), pix_4.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_5.width(), pix_5.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_5.width(), pix_5.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_6.width(), pix_6.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_6.width(), pix_6.height()) 
        % newWidth(frmApmSelect.tbHelpOffline->width(), pix_7.width(), pix_7.height()) % newHeight(frmApmSelect.tbHelpOffline->width(), pix_7.width(), pix_7.height()));
    frmApmSelect.tbHelpOffline->setText(QString::fromStdString(text));
}

string form_apmSelect::newHeight(int mainWndWidth, int oldPixWidth, int oldPixHeight) {
    if (mainWndWidth <= 1024) {
        if (oldPixWidth > 1024) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixHeight = oldPixHeight + minus;
        }
    }
    else if (mainWndWidth <= 1280) {
        if (oldPixWidth > 1280) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixHeight = oldPixHeight + minus;
        }
    }
    else if (mainWndWidth <= 1920) {
        if (oldPixWidth > 1920) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixHeight = oldPixHeight + minus;
        }
    }
    return boost::lexical_cast<string>(oldPixHeight);
}

string form_apmSelect::newWidth(int mainWndWidth, int oldPixWidth, int oldPixHeight) {
    if (mainWndWidth <= 1024) {
        if (oldPixWidth > 1024) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixWidth = oldPixWidth + minus;
        }
    }
    else if (mainWndWidth <= 1280) {
        if (oldPixWidth > 1280) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixWidth = oldPixWidth + minus;
        }
    }
    else if (mainWndWidth <= 1920) {
        if (oldPixWidth > 1920) {
            int minus = mainWndWidth - oldPixWidth;
            oldPixWidth = oldPixWidth + minus;
        }
    }
    return boost::lexical_cast<string>(oldPixWidth);
}
