/****************************************************************************
** Meta object code from reading C++ file 'qt_demo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt_demo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qt_demo_t {
    QByteArrayData data[12];
    char stringdata[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_demo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_demo_t qt_meta_stringdata_qt_demo = {
    {
QT_MOC_LITERAL(0, 0, 7), // "qt_demo"
QT_MOC_LITERAL(1, 8, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "index"
QT_MOC_LITERAL(4, 47, 24), // "on_pushButtonArp_clicked"
QT_MOC_LITERAL(5, 72, 23), // "on_pushButtonIp_clicked"
QT_MOC_LITERAL(6, 96, 24), // "on_pushButtonUdp_clicked"
QT_MOC_LITERAL(7, 121, 24), // "on_pushButtonTcp_clicked"
QT_MOC_LITERAL(8, 146, 25), // "on_pushButtonHttp_clicked"
QT_MOC_LITERAL(9, 172, 25), // "on_pushButtonIcmp_clicked"
QT_MOC_LITERAL(10, 198, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(11, 225, 25) // "on_pushButtonStop_clicked"

    },
    "qt_demo\0on_comboBox_currentIndexChanged\0"
    "\0index\0on_pushButtonArp_clicked\0"
    "on_pushButtonIp_clicked\0"
    "on_pushButtonUdp_clicked\0"
    "on_pushButtonTcp_clicked\0"
    "on_pushButtonHttp_clicked\0"
    "on_pushButtonIcmp_clicked\0"
    "on_pushButtonStart_clicked\0"
    "on_pushButtonStop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt_demo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qt_demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qt_demo *_t = static_cast<qt_demo *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonArp_clicked(); break;
        case 2: _t->on_pushButtonIp_clicked(); break;
        case 3: _t->on_pushButtonUdp_clicked(); break;
        case 4: _t->on_pushButtonTcp_clicked(); break;
        case 5: _t->on_pushButtonHttp_clicked(); break;
        case 6: _t->on_pushButtonIcmp_clicked(); break;
        case 7: _t->on_pushButtonStart_clicked(); break;
        case 8: _t->on_pushButtonStop_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject qt_demo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt_demo.data,
      qt_meta_data_qt_demo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qt_demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt_demo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qt_demo.stringdata))
        return static_cast<void*>(const_cast< qt_demo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qt_demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
