/****************************************************************************
** Meta object code from reading C++ file 'form_ReturnDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_ReturnDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_ReturnDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_ReturnDialog_t {
    QByteArrayData data[6];
    char stringdata[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form_ReturnDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form_ReturnDialog_t qt_meta_stringdata_form_ReturnDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "form_ReturnDialog"
QT_MOC_LITERAL(1, 18, 7), // "stopAll"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "slot_closeBtnClicked"
QT_MOC_LITERAL(4, 48, 15), // "slot_returnBook"
QT_MOC_LITERAL(5, 64, 21) // "slot_finishReturnBook"

    },
    "form_ReturnDialog\0stopAll\0\0"
    "slot_closeBtnClicked\0slot_returnBook\0"
    "slot_finishReturnBook"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_ReturnDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void form_ReturnDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_ReturnDialog *_t = static_cast<form_ReturnDialog *>(_o);
        switch (_id) {
        case 0: _t->stopAll(); break;
        case 1: _t->slot_closeBtnClicked(); break;
        case 2: _t->slot_returnBook(); break;
        case 3: _t->slot_finishReturnBook((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (form_ReturnDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form_ReturnDialog::stopAll)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject form_ReturnDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_form_ReturnDialog.data,
      qt_meta_data_form_ReturnDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *form_ReturnDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_ReturnDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_form_ReturnDialog.stringdata))
        return static_cast<void*>(const_cast< form_ReturnDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int form_ReturnDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void form_ReturnDialog::stopAll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
