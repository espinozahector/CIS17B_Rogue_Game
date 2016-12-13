/****************************************************************************
** Meta object code from reading C++ file 'chatchild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OperationGraduation_Integrated_V3_6_6/chatchild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatchild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatChild_t {
    QByteArrayData data[5];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatChild_t qt_meta_stringdata_ChatChild = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ChatChild"
QT_MOC_LITERAL(1, 10, 11), // "sendMessage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "send"
QT_MOC_LITERAL(4, 28, 7) // "receive"

    },
    "ChatChild\0sendMessage\0\0send\0receive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatChild[] = {

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
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatChild *_t = static_cast<ChatChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage(); break;
        case 1: _t->send(); break;
        case 2: _t->receive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatChild::sendMessage)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ChatChild::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_ChatChild.data,
      qt_meta_data_ChatChild,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatChild::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatChild.stringdata0))
        return static_cast<void*>(const_cast< ChatChild*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int ChatChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ChatChild::sendMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
