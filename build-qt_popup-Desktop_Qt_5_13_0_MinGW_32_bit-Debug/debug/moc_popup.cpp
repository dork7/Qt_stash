/****************************************************************************
** Meta object code from reading C++ file 'popup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_popup/popup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PopUp_t {
    QByteArrayData data[13];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PopUp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PopUp_t qt_meta_stringdata_PopUp = {
    {
QT_MOC_LITERAL(0, 0, 5), // "PopUp"
QT_MOC_LITERAL(1, 6, 19), // "valueEntered_SIGNAL"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "setPopupText"
QT_MOC_LITERAL(4, 40, 4), // "text"
QT_MOC_LITERAL(5, 45, 4), // "show"
QT_MOC_LITERAL(6, 50, 7), // "setSize"
QT_MOC_LITERAL(7, 58, 1), // "h"
QT_MOC_LITERAL(8, 60, 1), // "w"
QT_MOC_LITERAL(9, 62, 16), // "setInputVal_SLOT"
QT_MOC_LITERAL(10, 79, 13), // "hideAnimation"
QT_MOC_LITERAL(11, 93, 4), // "hide"
QT_MOC_LITERAL(12, 98, 12) // "popupOpacity"

    },
    "PopUp\0valueEntered_SIGNAL\0\0setPopupText\0"
    "text\0show\0setSize\0h\0w\0setInputVal_SLOT\0"
    "hideAnimation\0hide\0popupOpacity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PopUp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   52,    2, 0x0a /* Public */,
       5,    0,   55,    2, 0x0a /* Public */,
       6,    2,   56,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Float, 0x00095103,

       0        // eod
};

void PopUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PopUp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEntered_SIGNAL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setPopupText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->show(); break;
        case 3: _t->setSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->setInputVal_SLOT(); break;
        case 5: _t->hideAnimation(); break;
        case 6: _t->hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PopUp::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PopUp::valueEntered_SIGNAL)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PopUp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getPopupOpacity(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PopUp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPopupOpacity(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PopUp::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PopUp.data,
    qt_meta_data_PopUp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PopUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopUp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PopUp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PopUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PopUp::valueEntered_SIGNAL(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
