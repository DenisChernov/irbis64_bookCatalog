/* 
 * File:   engine.cpp
 * Author: demiin
 * 
 * Created on April 16, 2015, 2:24 PM
 */

#include "engine.h"

engine::engine() {
}

engine::~engine() {
}

void engine::login_unlogin(string codeAPM, string codeCommand) 
{
    boost::asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream.clear();
   
    string prepareRequest = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                            + MAGIC_CODE + '\n' + boost::lexical_cast<string>(reqCounter++) + '\n'
                            + irbis64_password + '\n' + irbis64_login + "\n\n\n\n"
                            + irbis64_login + '\n' + irbis64_password;

    prepareRequest.insert(0, boost::lexical_cast<string>(prepareRequest.length()) + '\n');
    
    request_stream << prepareRequest;
    
    sendRequest(&request);
}

string engine::sendRequest(boost::asio::streambuf* request) 
{
    tcp::resolver resolver(io_service) ;
    tcp::resolver::query query(server64, "6666");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;
    tcp::socket socket(io_service);
        
    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && endpoint_iterator != end)
    {
        socket.close();
        socket.connect(*endpoint_iterator++, error);
    }
    
    if (error)
        throw boost::system::system_error(error);
    
//    cout << "sended: " << boost::asio::write(socket, *request) << " bytes" << endl;
    boost::asio::write(socket, *request);
    /*******************************************/
    boost::asio::streambuf response;
    
    istream response_stream(&response);
    error = boost::asio::error::host_not_found;
    
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
    {
        //cout << &response;
    }
        
    if (error != boost::asio::error::eof)
        throw boost::system::system_error(error);
        
    boost::asio::streambuf::const_buffers_type bufs = response.data();
    return string(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + response.size());
}

void engine::makeRequest(string codeAPM, string codeCommand, string request)
{
    std::ostream request_stream(&_request);
    request_stream.clear();
   
    string prepareRequest = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                            + MAGIC_CODE + '\n' + boost::lexical_cast<string>(reqCounter++) + '\n'
                            + irbis64_password + '\n' + irbis64_login + "\n\n\n\n"
                            + request;
    
    prepareRequest.insert(0, boost::lexical_cast<string>(prepareRequest.length()) + '\n');
    request_stream << prepareRequest;
}

void engine::stop() {
    cout << "stop" << endl;
}

void engine::working() {
    map<string, vector<string>> tmp;
    
    switch (_curWork) {
        case AUTH: {
            if (findReader(_readerNumb)) {
                vector<string> ticket;
                ticket.push_back(_readerNumb);
                tmp["ticket"] = ticket;
            }
          
            break;
        }
        
        case ALL_DATA: {
            tmp = getReaderData();
            break;
        }
        
        
    }
    
    emit finished(tmp);
}

bool engine::findReader(string number) {
    parser pars;
    login_unlogin("C", "A");
    makeRequest("C", "K", "RDR\nRI=" + number + "\n1\n1\nmpl,'&&&&&',v30");
    vector<string> result = pars.split(sendRequest(&_request), '\n');
    if (result.size() >= 12){
        if (result.at(11) == "1"){
            _readerNumb = pars.getAuthID(result.back());
            login_unlogin("C", "B");
            return true;
        }
        else {
            login_unlogin("C", "B");
            return false;
        }
    }
    login_unlogin("C", "B");
    return false;
}

map<string, vector<string>> engine::getReaderData() {
    parser pars;
    login_unlogin("C", "A");
    makeRequest("C", "K", "RDR\nRI=" + _readerNumb + "\n1\n1\nmpl,'&&&&&v51#', "
                                                                                            "(if p(v51) then v51^C';'v51^D|#| fi),&uf('+7'),"
                                                                                            "(if p(v40) then if v40^f:'*' then v40^d';'v40^v';'if v40^g :'OLDEK' or v40^g:'RETRO' then         &uf('+7W4#'&uf('D'v40^g,',/INVNUMB='v40^b,'/,v200^f')),&uf('+7W5#'&uf('D'v40^g,',/INVNUMB='v40^b,'/,v461^F')), if &uf('+7R5,0')='' then &uf('+7R4,0') else &uf('+7R5,0') fi';'        &uf('+7W2#'&uf('D'v40^g,',/INVNUMB='v40^b,'/,v200^a')),&uf('+7W3#'&uf('D'v40^g,',/INVNUMB='v40^b,'/,v461^c')), if &uf('+7R3,0')='' then &uf('+7R2,0') else &uf('+7R2,0') fi';'else        &uf('+7W4#'&uf('D'v40^g',!I='&uf('D'v40^g',!I='v40^a'!,v933')'!,v200^a')),&uf('+7W5#'&uf('G2/'&uf('D'v40^g',!I='v40^a,'!,v903'))),&uf('+7R4,0')';'&uf('+7R5,0') ';'fi if p(v40^l) then &uf('+7W1#'v40^l) else if p(v40^m) then &uf('+7W1#'v40^m) else &uf('+7W1#'v40^e) fi fi, &uf('3C'&uf('+7R1,0')'/'&uf('3')) '@'/fi fi)%"
                                                                                            "(if p(v40) then if v40^f <> '******' and p(v40^g) then v40^d';', v40^v';',if v40^g='OLDEK' or v40^G = 'RETRO' then  &uf('+7W4#'&uf('D'v40^g',!I='v40^a,'!,v200^f')),&uf('+7W5#'&uf('D'v40^g',!I='v40^a'!,v461^f')),if &uf('+7R5,0')='' then &uf('+7R4,0') else &uf('+7R5,0') fi';' &uf('+7W7#'&uf('D'v40^g'!I='v40^a'!,v461^c')),&uf('+7W2#'&uf('D'v40^g',!I='v40^a,'!,v200^a')),&uf('+7W3#'&uf('D'v40^g',!I='v40^a'!,v461^c')),if &uf('+7R7')<>'' then &uf('+7R7,0')else  if &uf('+7R3,0')='' then &uf('+7R2,0') else &uf('+7R3,0') fi fi';' else  &uf('+7W4#'&uf('D'v40^g',!I='&uf('D'v40^g',!I='v40^a'!,v933')'!,v200^a')),&uf('+7W5#'&uf('G2/'&uf('D'v40^g',!I='v40^a,'!,v903'))),&uf('+7R4,0')';'&uf('+7R5,0') fi '%' fi fi) ");
    string lineResult = pars.split(sendRequest(&_request), '\n').at(12);
    map<string, vector<string>> result;
    
    result["regs"] = pars.getGetFIlialsReg(lineResult);
    result["books_owned"] = pars.getBooksJournalsOwned(lineResult);
    result["books_returned"] = pars.getBookJournalReturned(lineResult);
    
    login_unlogin("C", "B");
    return result;
}

void engine::makeReturn() {
    fullrecords record;
    parser pars;
    vector<string> result;
    string userMFN;
    string bookMFN;
    string codeInBase;
    string base;
    
    _invNumber = "00018864";
    login_unlogin("B", "A");
//    makeRequest("B", "I", "RQST\n0\n1\n\nH=" + _invNumber);   /*  1. запрос   */
    makeRequest("B", "I", "RDR\n0\n1\n\nH=" + _invNumber);   /*  2. запрос  - ответ: выдает mfn читателя за которым числится данный ИНВ */    
    result = pars.split(sendRequest(&_request), '\n');
    userMFN = pars.getMFN(result.back());
    
    makeRequest("B", "C", "RDR\n" + userMFN + "\n1\n\n");   /*  3. запрос  - ответ: выдал целиком запись читателя  */    
    result = pars.split(sendRequest(&_request), '\n');
    record.reader = result;
    size_t i = 0;
    for(string &line: result) {
        codeInBase = pars.getCodeInBase(line, _invNumber);
        base = pars.getBase(line, _invNumber);
        if (codeInBase != "") {
            break;
        }
    }
   
    makeRequest("B", "I", base + "\n1\n1\n\nI=" + codeInBase);   /*  4. запрос используя шифр издания в БД - ответ:  выдает mfn книги*/    
    result = pars.split(sendRequest(&_request), '\n');
    bookMFN = pars.getMFN(result.back());

    makeRequest("B", "C", base + "\n" + bookMFN + "\n1\n\n");   /*  5. запрос  - ответ: выдал целиком запись книги */    
    result = pars.split(sendRequest(&_request), '\n');    
    record.book = result;
    string newBookRecord = pars.makeReturn_book(record.book, _invNumber);
    makeRequest("B", "D", base + "\n0\n1\n" + newBookRecord);   /*  12. запрос на обновление записи книги*/    
    result = pars.split(sendRequest(&_request), '\n');    
    
    string newReaderRecord = pars.makeReturn_reader(record.reader, _invNumber);
    makeRequest("B", "D", "RDR\n0\n1\n" + newReaderRecord);   /*  13. запрос на обновление записи читателя  */    
    result = pars.split(sendRequest(&_request), '\n');    
    
//    makeRequest("B", "E", "RDR\n60283");   /*  6. запрос - ответ: единица??????  */    
//    makeRequest("B", "I", "RQST\n0\n1\n\nH=00018864");   /*  7. запрос  повтор запроса 1 */
//    makeRequest("B", "I", "RDR\n0\n1\n\nH=00018864");   /*  8. запрос  повтор запроса 2 */    
//    makeRequest("B", "C", "RDR\n60283\n1\n\n");   /*  9. запрос  повтор запроса 3  */    
//    makeRequest("B", "I", "OLDEK\n1\n1\n\nI=82.3(2Рос=Рус)-6/Т67-940114");   /*  10. запрос повтор запроса 4*/    
//    makeRequest("B", "C", "OLDEK\n47155\n1\n\n");   /*  11. запрос  повтор запроса 5 */    

//    makeRequest("B", "D", "OLDEK\n0\n1\n" + record.book);   /*  12. запрос на обновление записи книги*/    
//    makeRequest("B", "I", "RDR\n0\n1\n" + record.reader);   /*  13. запрос на обновление записи читателя  */    
//    makeRequest("B", "H", "RDR\nVS=20150428/Ф 6 АБ\n1");   /*  14. запрос  теоритически должен обновлять посещения */
//    makeRequest("B", "L", "10.OLDEK.BRIEF.PFT");   /*  15. запрос  выдача брифа OLDEK */    
//    makeRequest("B", "L", "10.OLDEK.org.mnu");   /*  16. запрос  выдача OLDEK */        
//    makeRequest("B", "L", "10.RDR.BRIEF.PFT");   /*  17. запрос  выдача брифа RDR */        
//    makeRequest("B", "H", "RDR\nRI=\n90");   /*  18. запрос  - ответ: список словаря списка ФИО и UID */        
//    makeRequest("B", "H", "RDR\nRI=ф00022962ф\n90");   /*  19. запрос  - ответ: список словаря списка ФИО и UID */        

    login_unlogin("B", "B");
    emit finishReturnBook(true);
}

void engine::sendProlongRequest() {
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;
   
    map<string, vector<string> >::const_iterator it = _booksToProlong.begin();
    while (it != _booksToProlong.end()) {
  
        upload_ctx.lines_read = 0;
        upload_ctx.data.clear();
        recipients = NULL;
        
        curl = curl_easy_init();
        if(curl) {
            string _filial = it->first + "@murmanlib.ru";
            //string _filial = "oa@murmanlib.ru";
      
            curl_easy_setopt(curl, CURLOPT_USERNAME, "user_prolong@murmanlib.ru");
            curl_easy_setopt(curl, CURLOPT_PASSWORD, "wFb7RHbT");
            curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.mail.ru");
            curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
            curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "user_prolong@murmanlib.ru");
            recipients = curl_slist_append(recipients, _filial.c_str());
            curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
            string date = "Date: " + pars.getCurDayWeek() + ", " + pars.getCurDay() + " " + pars.getCurMonYear() + " " + pars.getCurYear() + " " + pars.getCurTime(":") + " +0400\r\n";
            //cout << date << endl;
            //upload_ctx.data.push_back("Date: Mon, 19 May 2015 21:54:29 +1100\r\n");
            upload_ctx.data.push_back(date);
            upload_ctx.data.push_back("To: <" + _filial + ">\r\n");
            upload_ctx.data.push_back("From: <user_prolong@murmanlib.ru> (" + _readerNumb + ")\r\n");
            upload_ctx.data.push_back("Content-type: text/html; charset=UTF-8\r\n");
            upload_ctx.data.push_back("Subject: Запрос продления через АРМ Пользователь\r\n");
            upload_ctx.data.push_back("\r\n\r\n");
            upload_ctx.data.push_back("Пользователь с идентификационным номером: <b>" + _readerNumb + "</b><br>\r\n");
            upload_ctx.data.push_back("Поступил запрос на продление следующих книг: <br>\r\n");
            for (size_t i = 0; i < it->second.size(); i++) {
                upload_ctx.data.push_back(boost::lexical_cast<string>(i+1) + ". " + it->second.at(i) + "<br>\r\n");
            }
            upload_ctx.data.push_back("\r\n.");
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
            curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
            //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            res = curl_easy_perform(curl);
 
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
           curl_slist_free_all(recipients);
           curl_easy_cleanup(curl);
        }      
        it++;
  
    }
    emit sendProlongRequestComplited();
}

size_t engine::payload_source(void* ptr, size_t size, size_t nmemb, void* userp) {
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;
 
  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
  
  if (upload_ctx->data.size() <= upload_ctx->lines_read) {
    return 0;  
  }
  else {
    data = upload_ctx->data.at(upload_ctx->lines_read).c_str();
  }
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
 
    return len;
  }
 
  return 0;
}
