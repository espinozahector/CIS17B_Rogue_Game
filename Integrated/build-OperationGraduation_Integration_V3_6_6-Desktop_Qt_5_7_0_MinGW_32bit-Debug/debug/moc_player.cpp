/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OperationGraduation_Integrated_V3_6_6/player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[12];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 10), // "playToStat"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "playLvlUpdate"
QT_MOC_LITERAL(4, 33, 11), // "std::string"
QT_MOC_LITERAL(5, 45, 9), // "enterDoor"
QT_MOC_LITERAL(6, 55, 7), // "eatTaco"
QT_MOC_LITERAL(7, 63, 8), // "newLevel"
QT_MOC_LITERAL(8, 72, 9), // "newBullet"
QT_MOC_LITERAL(9, 82, 10), // "timerEvent"
QT_MOC_LITERAL(10, 93, 11), // "timerEvent2"
QT_MOC_LITERAL(11, 105, 14) // "checkCollision"

    },
    "Player\0playToStat\0\0playLvlUpdate\0"
    "std::string\0enterDoor\0eatTaco\0newLevel\0"
    "newBullet\0timerEvent\0timerEvent2\0"
    "checkCollision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   59,    2, 0x06 /* Public */,
       3,    4,   74,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    2,   84,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,
       8,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playToStat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 1: _t->playLvlUpdate((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->enterDoor(); break;
        case 3: _t->eatTaco((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->newLevel(); break;
        case 5: _t->newBullet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->timerEvent(); break;
        case 7: _t->timerEvent2(); break;
        case 8: _t->checkCollision(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Player::*_t)(int , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::playToStat)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Player::*_t)(std::string , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::playLvlUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::enterDoor)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Player::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::eatTaco)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::newLevel)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Player::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::newBullet)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Player.data,
      qt_meta_data_Player,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(const_cast< Player*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Player*>(this));
    if (!strcmp(_clname, "Character"))
        return static_cast< Character*>(const_cast< Player*>(this));
    return QObject::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Player::playToStat(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Player::playLvlUpdate(std::string _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Player::enterDoor()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Player::eatTaco(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Player::newLevel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Player::newBullet(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
