/****************************************************************************
** Meta object code from reading C++ file 'form_apmSelect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_apmSelect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_apmSelect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_apmSelect_t {
    QByteArrayData data[6];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form_apmSelect_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form_apmSelect_t qt_meta_stringdata_form_apmSelect = {
    {
QT_MOC_LITERAL(0, 0, 14), // "form_apmSelect"
QT_MOC_LITERAL(1, 15, 16), // "slot_bookCatalog"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "slot_GetListReturnBooks"
QT_MOC_LITERAL(4, 57, 11), // "slot_closed"
QT_MOC_LITERAL(5, 69, 6) // "string"

    },
    "form_apmSelect\0slot_bookCatalog\0\0"
    "slot_GetListReturnBooks\0slot_closed\0"
    "string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_apmSelect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void form_apmSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_apmSelect *_t = static_cast<form_apmSelect *>(_o);
        switch (_id) {
        case 0: _t->slot_bookCatalog(); break;
        case 1: _t->slot_GetListReturnBooks(); break;
        case 2: _t->slot_closed((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject form_apmSelect::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_apmSelect.data,
      qt_meta_data_form_apmSelect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *form_apmSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_apmSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_form_apmSelect.stringdata))
        return static_cast<void*>(const_cast< form_apmSelect*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_apmSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
