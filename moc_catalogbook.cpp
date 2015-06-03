/****************************************************************************
** Meta object code from reading C++ file 'catalogbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "catalogbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'catalogbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_catalogbook_t {
    QByteArrayData data[22];
    char stringdata[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_catalogbook_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_catalogbook_t qt_meta_stringdata_catalogbook = {
    {
QT_MOC_LITERAL(0, 0, 11), // "catalogbook"
QT_MOC_LITERAL(1, 12, 7), // "stopAll"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "closed"
QT_MOC_LITERAL(4, 28, 6), // "string"
QT_MOC_LITERAL(5, 35, 4), // "what"
QT_MOC_LITERAL(6, 40, 27), // "slot_SearchQueryTextChanged"
QT_MOC_LITERAL(7, 68, 4), // "text"
QT_MOC_LITERAL(8, 73, 20), // "threadSearchFinished"
QT_MOC_LITERAL(9, 94, 14), // "vector<string>"
QT_MOC_LITERAL(10, 109, 9), // "listBooks"
QT_MOC_LITERAL(11, 119, 28), // "threadSearchBookInfoFinished"
QT_MOC_LITERAL(12, 148, 30), // "slot_TimerStayConnectedTimeout"
QT_MOC_LITERAL(13, 179, 32), // "slot_TimerVisibleProgressTimeout"
QT_MOC_LITERAL(14, 212, 21), // "slot_TimerHideTimeout"
QT_MOC_LITERAL(15, 234, 17), // "slot_delayChanged"
QT_MOC_LITERAL(16, 252, 17), // "slot_limitChanged"
QT_MOC_LITERAL(17, 270, 22), // "slot_timerBoostChanged"
QT_MOC_LITERAL(18, 293, 25), // "slot_filterAddressChanged"
QT_MOC_LITERAL(19, 319, 17), // "slot_TableClicked"
QT_MOC_LITERAL(20, 337, 20), // "slot_doneDownloadPic"
QT_MOC_LITERAL(21, 358, 14) // "QNetworkReply*"

    },
    "catalogbook\0stopAll\0\0closed\0string\0"
    "what\0slot_SearchQueryTextChanged\0text\0"
    "threadSearchFinished\0vector<string>\0"
    "listBooks\0threadSearchBookInfoFinished\0"
    "slot_TimerStayConnectedTimeout\0"
    "slot_TimerVisibleProgressTimeout\0"
    "slot_TimerHideTimeout\0slot_delayChanged\0"
    "slot_limitChanged\0slot_timerBoostChanged\0"
    "slot_filterAddressChanged\0slot_TableClicked\0"
    "slot_doneDownloadPic\0QNetworkReply*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_catalogbook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   88,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      16,    1,  103,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    1,  109,    2, 0x08 /* Private */,
      19,    1,  112,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, 0x80000000 | 21,    2,

       0        // eod
};

void catalogbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        catalogbook *_t = static_cast<catalogbook *>(_o);
        switch (_id) {
        case 0: _t->stopAll(); break;
        case 1: _t->closed((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->slot_SearchQueryTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->threadSearchFinished((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 4: _t->threadSearchBookInfoFinished((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 5: _t->slot_TimerStayConnectedTimeout(); break;
        case 6: _t->slot_TimerVisibleProgressTimeout(); break;
        case 7: _t->slot_TimerHideTimeout(); break;
        case 8: _t->slot_delayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slot_limitChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slot_timerBoostChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slot_filterAddressChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slot_TableClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 13: _t->slot_doneDownloadPic((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (catalogbook::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&catalogbook::stopAll)) {
                *result = 0;
            }
        }
        {
            typedef void (catalogbook::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&catalogbook::closed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject catalogbook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_catalogbook.data,
      qt_meta_data_catalogbook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *catalogbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *catalogbook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_catalogbook.stringdata))
        return static_cast<void*>(const_cast< catalogbook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int catalogbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void catalogbook::stopAll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void catalogbook::closed(string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
