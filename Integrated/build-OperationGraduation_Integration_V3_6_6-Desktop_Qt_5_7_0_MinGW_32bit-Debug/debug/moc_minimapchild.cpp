/****************************************************************************
** Meta object code from reading C++ file 'minimapchild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OperationGraduation_Integrated_V3_6_6/minimapchild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minimapchild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MiniMapChild_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiniMapChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiniMapChild_t qt_meta_stringdata_MiniMapChild = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MiniMapChild"
QT_MOC_LITERAL(1, 13, 9), // "reconnect"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "miniClick"
QT_MOC_LITERAL(4, 34, 8) // "newTacos"

    },
    "MiniMapChild\0reconnect\0\0miniClick\0"
    "newTacos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiniMapChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MiniMapChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiniMapChild *_t = static_cast<MiniMapChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reconnect(); break;
        case 1: _t->miniClick(); break;
        case 2: _t->newTacos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MiniMapChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MiniMapChild::reconnect)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MiniMapChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MiniMapChild::miniClick)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MiniMapChild::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_MiniMapChild.data,
      qt_meta_data_MiniMapChild,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MiniMapChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiniMapChild::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MiniMapChild.stringdata0))
        return static_cast<void*>(const_cast< MiniMapChild*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int MiniMapChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MiniMapChild::reconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MiniMapChild::miniClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
