/****************************************************************************
** Meta object code from reading C++ file 'statchild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OperationGraduation_Integrated_V3_6_6/statchild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statchild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StatChild_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StatChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StatChild_t qt_meta_stringdata_StatChild = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StatChild"
QT_MOC_LITERAL(1, 10, 9), // "statClick"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "updateStats"
QT_MOC_LITERAL(4, 33, 13), // "updateDisplay"
QT_MOC_LITERAL(5, 47, 11) // "std::string"

    },
    "StatChild\0statClick\0\0updateStats\0"
    "updateDisplay\0std::string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    7,   30,    2, 0x0a /* Public */,
       4,    4,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,

       0        // eod
};

void StatChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StatChild *_t = static_cast<StatChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statClick(); break;
        case 1: _t->updateStats((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 2: _t->updateDisplay((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StatChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatChild::statClick)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject StatChild::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_StatChild.data,
      qt_meta_data_StatChild,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StatChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatChild::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StatChild.stringdata0))
        return static_cast<void*>(const_cast< StatChild*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int StatChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void StatChild::statClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
