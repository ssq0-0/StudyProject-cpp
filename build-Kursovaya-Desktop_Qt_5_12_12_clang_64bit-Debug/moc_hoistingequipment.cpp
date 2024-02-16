/****************************************************************************
** Meta object code from reading C++ file 'hoistingequipment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Kursovaya/hoistingequipment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hoistingequipment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HoistingEquipment_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HoistingEquipment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HoistingEquipment_t qt_meta_stringdata_HoistingEquipment = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HoistingEquipment"
QT_MOC_LITERAL(1, 18, 15), // "tablehoistequip"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 57, 15), // "onButtonClicked"
QT_MOC_LITERAL(5, 73, 19), // "updateEquipmentFile"
QT_MOC_LITERAL(6, 93, 24), // "on_push_to_hoist_clicked"
QT_MOC_LITERAL(7, 118, 7) // "isAdmin"

    },
    "HoistingEquipment\0tablehoistequip\0\0"
    "on_pushButton_clicked\0onButtonClicked\0"
    "updateEquipmentFile\0on_push_to_hoist_clicked\0"
    "isAdmin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HoistingEquipment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void HoistingEquipment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HoistingEquipment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tablehoistequip(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->onButtonClicked(); break;
        case 3: _t->updateEquipmentFile(); break;
        case 4: _t->on_push_to_hoist_clicked(); break;
        case 5: { bool _r = _t->isAdmin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HoistingEquipment::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_HoistingEquipment.data,
    qt_meta_data_HoistingEquipment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HoistingEquipment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HoistingEquipment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HoistingEquipment.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HoistingEquipment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
