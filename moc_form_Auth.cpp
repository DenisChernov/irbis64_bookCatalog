/****************************************************************************
** Meta object code from reading C++ file 'form_Auth.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_Auth.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_Auth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_Auth_t {
    QByteArrayData data[9];
    char stringdata[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form_Auth_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form_Auth_t qt_meta_stringdata_form_Auth = {
    {
QT_MOC_LITERAL(0, 0, 9), // "form_Auth"
QT_MOC_LITERAL(1, 10, 15), // "authentificated"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "stopAll"
QT_MOC_LITERAL(4, 35, 16), // "closeWithoutAuth"
QT_MOC_LITERAL(5, 52, 12), // "slot_tryAuth"
QT_MOC_LITERAL(6, 65, 29), // "slot_timerAccessDeniedTimeout"
QT_MOC_LITERAL(7, 95, 18), // "threadAuthFinished"
QT_MOC_LITERAL(8, 114, 27) // "map<string,vector<string> >"

    },
    "form_Auth\0authentificated\0\0stopAll\0"
    "closeWithoutAuth\0slot_tryAuth\0"
    "slot_timerAccessDeniedTimeout\0"
    "threadAuthFinished\0map<string,vector<string> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_Auth[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void form_Auth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_Auth *_t = static_cast<form_Auth *>(_o);
        switch (_id) {
        case 0: _t->authentificated(); break;
        case 1: _t->stopAll(); break;
        case 2: _t->closeWithoutAuth(); break;
        case 3: _t->slot_tryAuth(); break;
        case 4: _t->slot_timerAccessDeniedTimeout(); break;
        case 5: _t->threadAuthFinished((*reinterpret_cast< map<string,vector<string> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (form_Auth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_Auth::authentificated)) {
                *result = 0;
            }
        }
        {
            typedef void (form_Auth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_Auth::stopAll)) {
                *result = 1;
            }
        }
        {
            typedef void (form_Auth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_Auth::closeWithoutAuth)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject form_Auth::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_Auth.data,
      qt_meta_data_form_Auth,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *form_Auth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_Auth::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_form_Auth.stringdata))
        return static_cast<void*>(const_cast< form_Auth*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_Auth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void form_Auth::authentificated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void form_Auth::stopAll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void form_Auth::closeWithoutAuth()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
