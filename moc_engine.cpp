/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_engine_t {
    QByteArrayData data[12];
    char stringdata[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_engine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_engine_t qt_meta_stringdata_engine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "engine"
QT_MOC_LITERAL(1, 7, 8), // "finished"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 27), // "map<string,vector<string> >"
QT_MOC_LITERAL(4, 45, 16), // "finishReturnBook"
QT_MOC_LITERAL(5, 62, 7), // "success"
QT_MOC_LITERAL(6, 70, 27), // "sendProlongRequestComplited"
QT_MOC_LITERAL(7, 98, 16), // "closeWithoutAuth"
QT_MOC_LITERAL(8, 115, 7), // "working"
QT_MOC_LITERAL(9, 123, 10), // "makeReturn"
QT_MOC_LITERAL(10, 134, 4), // "stop"
QT_MOC_LITERAL(11, 139, 18) // "sendProlongRequest"

    },
    "engine\0finished\0\0map<string,vector<string> >\0"
    "finishReturnBook\0success\0"
    "sendProlongRequestComplited\0"
    "closeWithoutAuth\0working\0makeReturn\0"
    "stop\0sendProlongRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_engine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,
       7,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        engine *_t = static_cast<engine *>(_o);
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< map<string,vector<string> >(*)>(_a[1]))); break;
        case 1: _t->finishReturnBook((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendProlongRequestComplited(); break;
        case 3: _t->closeWithoutAuth(); break;
        case 4: _t->working(); break;
        case 5: _t->makeReturn(); break;
        case 6: _t->stop(); break;
        case 7: _t->sendProlongRequest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (engine::*_t)(map<string,vector<string>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::finished)) {
                *result = 0;
            }
        }
        {
            typedef void (engine::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::finishReturnBook)) {
                *result = 1;
            }
        }
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::sendProlongRequestComplited)) {
                *result = 2;
            }
        }
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::closeWithoutAuth)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject engine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_engine.data,
      qt_meta_data_engine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *engine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_engine.stringdata))
        return static_cast<void*>(const_cast< engine*>(this));
    return QObject::qt_metacast(_clname);
}

int engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void engine::finished(map<string,vector<string>> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void engine::finishReturnBook(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void engine::sendProlongRequestComplited()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void engine::closeWithoutAuth()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
