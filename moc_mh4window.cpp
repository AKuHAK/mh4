/****************************************************************************
** mh4Window meta object code from reading C++ file 'mh4window.h'
**
** Created: Sun Apr 29 13:43:17 2018
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_mh4Window
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mh4window.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *mh4Window::className() const
{
    return "mh4Window";
}

QMetaObject *mh4Window::metaObj = 0;

void mh4Window::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("mh4Window","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString mh4Window::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("mh4Window",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* mh4Window::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(mh4Window::*m1_t0)();
    typedef void(mh4Window::*m1_t1)();
    typedef void(mh4Window::*m1_t2)();
    typedef void(mh4Window::*m1_t3)();
    typedef void(mh4Window::*m1_t4)();
    typedef void(mh4Window::*m1_t5)();
    typedef void(mh4Window::*m1_t6)();
    typedef void(mh4Window::*m1_t7)();
    typedef void(mh4Window::*m1_t8)(ui32);
    typedef void(mh4Window::*m1_t9)();
    typedef void(mh4Window::*m1_t10)();
    typedef void(mh4Window::*m1_t11)();
    typedef void(mh4Window::*m1_t12)();
    typedef void(mh4Window::*m1_t13)();
    typedef void(mh4Window::*m1_t14)();
    typedef void(mh4Window::*m1_t15)();
    typedef void(mh4Window::*m1_t16)();
    typedef void(mh4Window::*m1_t17)();
    typedef void(mh4Window::*m1_t18)();
    typedef void(mh4Window::*m1_t19)();
    typedef void(mh4Window::*m1_t20)();
    typedef void(mh4Window::*m1_t21)();
    typedef void(mh4Window::*m1_t22)();
    typedef void(mh4Window::*m1_t23)();
    typedef void(mh4Window::*m1_t24)();
    typedef void(mh4Window::*m1_t25)();
    typedef void(mh4Window::*m1_t26)();
    typedef void(mh4Window::*m1_t27)();
    typedef void(mh4Window::*m1_t28)();
    typedef void(mh4Window::*m1_t29)();
    typedef void(mh4Window::*m1_t30)();
    m1_t0 v1_0 = Q_AMPERSAND mh4Window::createSelection;
    m1_t1 v1_1 = Q_AMPERSAND mh4Window::deleteSelection;
    m1_t2 v1_2 = Q_AMPERSAND mh4Window::extractSelection;
    m1_t3 v1_3 = Q_AMPERSAND mh4Window::dumpSelection;
    m1_t4 v1_4 = Q_AMPERSAND mh4Window::build;
    m1_t5 v1_5 = Q_AMPERSAND mh4Window::selectAll;
    m1_t6 v1_6 = Q_AMPERSAND mh4Window::selectNothing;
    m1_t7 v1_7 = Q_AMPERSAND mh4Window::inverseSelection;
    m1_t8 v1_8 = Q_AMPERSAND mh4Window::selectDataType;
    m1_t9 v1_9 = Q_AMPERSAND mh4Window::selectDataType0;
    m1_t10 v1_10 = Q_AMPERSAND mh4Window::selectDataType1;
    m1_t11 v1_11 = Q_AMPERSAND mh4Window::selectDataType2;
    m1_t12 v1_12 = Q_AMPERSAND mh4Window::selectDataType3;
    m1_t13 v1_13 = Q_AMPERSAND mh4Window::selectDataType4;
    m1_t14 v1_14 = Q_AMPERSAND mh4Window::selectDataType5;
    m1_t15 v1_15 = Q_AMPERSAND mh4Window::selectDataType6;
    m1_t16 v1_16 = Q_AMPERSAND mh4Window::selectDataType7;
    m1_t17 v1_17 = Q_AMPERSAND mh4Window::selectDataType8;
    m1_t18 v1_18 = Q_AMPERSAND mh4Window::selectDataType9;
    m1_t19 v1_19 = Q_AMPERSAND mh4Window::selectDataType10;
    m1_t20 v1_20 = Q_AMPERSAND mh4Window::selectDataType11;
    m1_t21 v1_21 = Q_AMPERSAND mh4Window::selectDataType12;
    m1_t22 v1_22 = Q_AMPERSAND mh4Window::selectDataType13;
    m1_t23 v1_23 = Q_AMPERSAND mh4Window::selectDataType14;
    m1_t24 v1_24 = Q_AMPERSAND mh4Window::selectDataType15;
    m1_t25 v1_25 = Q_AMPERSAND mh4Window::selectDataType16;
    m1_t26 v1_26 = Q_AMPERSAND mh4Window::selectDataType17;
    m1_t27 v1_27 = Q_AMPERSAND mh4Window::selectDataType18;
    m1_t28 v1_28 = Q_AMPERSAND mh4Window::selectDataType19;
    m1_t29 v1_29 = Q_AMPERSAND mh4Window::selectPointer;
    m1_t30 v1_30 = Q_AMPERSAND mh4Window::about;
    QMetaData *slot_tbl = QMetaObject::new_metadata(31);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(31);
    slot_tbl[0].name = "createSelection()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "deleteSelection()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Protected;
    slot_tbl[2].name = "extractSelection()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Protected;
    slot_tbl[3].name = "dumpSelection()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Protected;
    slot_tbl[4].name = "build()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Protected;
    slot_tbl[5].name = "selectAll()";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Protected;
    slot_tbl[6].name = "selectNothing()";
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl_access[6] = QMetaData::Protected;
    slot_tbl[7].name = "inverseSelection()";
    slot_tbl[7].ptr = *((QMember*)&v1_7);
    slot_tbl_access[7] = QMetaData::Protected;
    slot_tbl[8].name = "selectDataType(ui32)";
    slot_tbl[8].ptr = *((QMember*)&v1_8);
    slot_tbl_access[8] = QMetaData::Protected;
    slot_tbl[9].name = "selectDataType0()";
    slot_tbl[9].ptr = *((QMember*)&v1_9);
    slot_tbl_access[9] = QMetaData::Protected;
    slot_tbl[10].name = "selectDataType1()";
    slot_tbl[10].ptr = *((QMember*)&v1_10);
    slot_tbl_access[10] = QMetaData::Protected;
    slot_tbl[11].name = "selectDataType2()";
    slot_tbl[11].ptr = *((QMember*)&v1_11);
    slot_tbl_access[11] = QMetaData::Protected;
    slot_tbl[12].name = "selectDataType3()";
    slot_tbl[12].ptr = *((QMember*)&v1_12);
    slot_tbl_access[12] = QMetaData::Protected;
    slot_tbl[13].name = "selectDataType4()";
    slot_tbl[13].ptr = *((QMember*)&v1_13);
    slot_tbl_access[13] = QMetaData::Protected;
    slot_tbl[14].name = "selectDataType5()";
    slot_tbl[14].ptr = *((QMember*)&v1_14);
    slot_tbl_access[14] = QMetaData::Protected;
    slot_tbl[15].name = "selectDataType6()";
    slot_tbl[15].ptr = *((QMember*)&v1_15);
    slot_tbl_access[15] = QMetaData::Protected;
    slot_tbl[16].name = "selectDataType7()";
    slot_tbl[16].ptr = *((QMember*)&v1_16);
    slot_tbl_access[16] = QMetaData::Protected;
    slot_tbl[17].name = "selectDataType8()";
    slot_tbl[17].ptr = *((QMember*)&v1_17);
    slot_tbl_access[17] = QMetaData::Protected;
    slot_tbl[18].name = "selectDataType9()";
    slot_tbl[18].ptr = *((QMember*)&v1_18);
    slot_tbl_access[18] = QMetaData::Protected;
    slot_tbl[19].name = "selectDataType10()";
    slot_tbl[19].ptr = *((QMember*)&v1_19);
    slot_tbl_access[19] = QMetaData::Protected;
    slot_tbl[20].name = "selectDataType11()";
    slot_tbl[20].ptr = *((QMember*)&v1_20);
    slot_tbl_access[20] = QMetaData::Protected;
    slot_tbl[21].name = "selectDataType12()";
    slot_tbl[21].ptr = *((QMember*)&v1_21);
    slot_tbl_access[21] = QMetaData::Protected;
    slot_tbl[22].name = "selectDataType13()";
    slot_tbl[22].ptr = *((QMember*)&v1_22);
    slot_tbl_access[22] = QMetaData::Protected;
    slot_tbl[23].name = "selectDataType14()";
    slot_tbl[23].ptr = *((QMember*)&v1_23);
    slot_tbl_access[23] = QMetaData::Protected;
    slot_tbl[24].name = "selectDataType15()";
    slot_tbl[24].ptr = *((QMember*)&v1_24);
    slot_tbl_access[24] = QMetaData::Protected;
    slot_tbl[25].name = "selectDataType16()";
    slot_tbl[25].ptr = *((QMember*)&v1_25);
    slot_tbl_access[25] = QMetaData::Protected;
    slot_tbl[26].name = "selectDataType17()";
    slot_tbl[26].ptr = *((QMember*)&v1_26);
    slot_tbl_access[26] = QMetaData::Protected;
    slot_tbl[27].name = "selectDataType18()";
    slot_tbl[27].ptr = *((QMember*)&v1_27);
    slot_tbl_access[27] = QMetaData::Protected;
    slot_tbl[28].name = "selectDataType19()";
    slot_tbl[28].ptr = *((QMember*)&v1_28);
    slot_tbl_access[28] = QMetaData::Protected;
    slot_tbl[29].name = "selectPointer()";
    slot_tbl[29].ptr = *((QMember*)&v1_29);
    slot_tbl_access[29] = QMetaData::Protected;
    slot_tbl[30].name = "about()";
    slot_tbl[30].ptr = *((QMember*)&v1_30);
    slot_tbl_access[30] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"mh4Window", "QMainWindow",
	slot_tbl, 31,
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
