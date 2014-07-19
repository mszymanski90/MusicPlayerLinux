/****************************************************************************
** Meta object code from reading C++ file 'loggerdevice.h'
**
** Created: Sat 19. Jul 11:33:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loggerdevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loggerdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoggerDevice[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LoggerDevice[] = {
    "LoggerDevice\0\0message\0log(std::string)\0"
};

void LoggerDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoggerDevice *_t = static_cast<LoggerDevice *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoggerDevice::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoggerDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LoggerDevice,
      qt_meta_data_LoggerDevice, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoggerDevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoggerDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoggerDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoggerDevice))
        return static_cast<void*>(const_cast< LoggerDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int LoggerDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
