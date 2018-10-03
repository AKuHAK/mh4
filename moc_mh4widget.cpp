/****************************************************************************
** mh4widget meta object code from reading C++ file 'mh4widget.h'
**
** Created: Sun Oct 20 19:32:22 2002
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_mh4widget
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mh4widget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *mh4widget::className() const
{
    return "mh4widget";
}

QMetaObject *mh4widget::metaObj = 0;

void mh4widget::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("mh4widget","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString mh4widget::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("mh4widget",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* mh4widget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"mh4widget", "QWidget",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
