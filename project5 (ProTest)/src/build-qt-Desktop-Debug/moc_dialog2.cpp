/****************************************************************************
** Meta object code from reading C++ file 'dialog2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt/dialog2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog2_t {
    QByteArrayData data[16];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog2_t qt_meta_stringdata_Dialog2 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Dialog2"
QT_MOC_LITERAL(1, 8, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "index"
QT_MOC_LITERAL(4, 47, 23), // "on_textEdit_textChanged"
QT_MOC_LITERAL(5, 71, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(6, 95, 4), // "arg1"
QT_MOC_LITERAL(7, 100, 25), // "on_lineEdit_2_textChanged"
QT_MOC_LITERAL(8, 126, 25), // "on_lineEdit_4_textChanged"
QT_MOC_LITERAL(9, 152, 25), // "on_lineEdit_3_textChanged"
QT_MOC_LITERAL(10, 178, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(11, 201, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(12, 226, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(13, 251, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(14, 276, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 298, 15) // "check_all_stuff"

    },
    "Dialog2\0on_comboBox_currentIndexChanged\0"
    "\0index\0on_textEdit_textChanged\0"
    "on_lineEdit_textChanged\0arg1\0"
    "on_lineEdit_2_textChanged\0"
    "on_lineEdit_4_textChanged\0"
    "on_lineEdit_3_textChanged\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_4_clicked\0on_pushButton_clicked\0"
    "check_all_stuff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       7,    1,   81,    2, 0x08 /* Private */,
       8,    1,   84,    2, 0x08 /* Private */,
       9,    1,   87,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,

       0        // eod
};

void Dialog2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_textEdit_textChanged(); break;
        case 2: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_4_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_3_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_radioButton_clicked(); break;
        case 7: _t->on_radioButton_2_clicked(); break;
        case 8: _t->on_radioButton_3_clicked(); break;
        case 9: _t->on_radioButton_4_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: { int _r = _t->check_all_stuff();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog2::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Dialog2.data,
    qt_meta_data_Dialog2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog2.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
