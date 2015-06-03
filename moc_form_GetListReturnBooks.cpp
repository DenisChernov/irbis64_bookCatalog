/****************************************************************************
** Meta object code from reading C++ file 'form_GetListReturnBooks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_GetListReturnBooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_GetListReturnBooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_GetListReturnBooks_t {
    QByteArrayData data[13];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form_GetListReturnBooks_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form_GetListReturnBooks_t qt_meta_stringdata_form_GetListReturnBooks = {
    {
QT_MOC_LITERAL(0, 0, 23), // "form_GetListReturnBooks"
QT_MOC_LITERAL(1, 24, 6), // "closed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "string"
QT_MOC_LITERAL(4, 39, 7), // "stopAll"
QT_MOC_LITERAL(5, 47, 21), // "slot_timerIdleTimeout"
QT_MOC_LITERAL(6, 69, 20), // "slot_authentificated"
QT_MOC_LITERAL(7, 90, 20), // "slot_changeSizeValue"
QT_MOC_LITERAL(8, 111, 21), // "slot_ShowReturnDialog"
QT_MOC_LITERAL(9, 133, 19), // "slot_showProlongDlg"
QT_MOC_LITERAL(10, 153, 24), // "threadLoadReaderFinished"
QT_MOC_LITERAL(11, 178, 27), // "map<string,vector<string> >"
QT_MOC_LITERAL(12, 206, 21) // "slot_closeWithoutAuth"

    },
    "form_GetListReturnBooks\0closed\0\0string\0"
    "stopAll\0slot_timerIdleTimeout\0"
    "slot_authentificated\0slot_changeSizeValue\0"
    "slot_ShowReturnDialog\0slot_showProlongDlg\0"
    "threadLoadReaderFinished\0"
    "map<string,vector<string> >\0"
    "slot_closeWithoutAuth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_GetListReturnBooks[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,

       0        // eod
};

void form_GetListReturnBooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_GetListReturnBooks *_t = static_cast<form_GetListReturnBooks *>(_o);
        switch (_id) {
        case 0: _t->closed((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->stopAll(); break;
        case 2: _t->slot_timerIdleTimeout(); break;
        case 3: _t->slot_authentificated(); break;
        case 4: _t->slot_changeSizeValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_ShowReturnDialog(); break;
        case 6: _t->slot_showProlongDlg(); break;
        case 7: _t->threadLoadReaderFinished((*reinterpret_cast< map<string,vector<string> >(*)>(_a[1]))); break;
        case 8: _t->slot_closeWithoutAuth(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (form_GetListReturnBooks::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_GetListReturnBooks::closed)) {
                *result = 0;
            }
        }
        {
            typedef void (form_GetListReturnBooks::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_GetListReturnBooks::stopAll)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject form_GetListReturnBooks::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_form_GetListReturnBooks.data,
      qt_meta_data_form_GetListReturnBooks,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *form_GetListReturnBooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_GetListReturnBooks::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_form_GetListReturnBooks.stringdata))
        return static_cast<void*>(const_cast< form_GetListReturnBooks*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int form_GetListReturnBooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void form_GetListReturnBooks::closed(string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void form_GetListReturnBooks::stopAll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
