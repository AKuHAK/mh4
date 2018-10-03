/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: AKUHAK and Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#ifndef __MH4WINDOW_H__
#define __MH4WINDOW_H__


#include <qmainwindow.h>
#include "mh4.h"


// Window min size
#define MIN_WIDTH  320
#define MIN_HEIGHT 240


class mh4widget;
class QGridLayout;
class QListView;
class QProgressDialog;


class mh4Window: public QMainWindow
{
  Q_OBJECT

  public:
    mh4Window (QWidget *parent = NULL,const char *name = NULL,WFlags f = WType_TopLevel);
    mh4Window::~mh4Window (void);

  protected:
    mh4widget *m_pView;
    H4RFile *m_pH4RFile;

  protected slots:
    // Options menu functions
    void createSelection (void);
    void deleteSelection (void);
    void extractSelection (void);
    void dumpSelection (void);
    void build (void);

    // Selection menu functions
    void selectAll (void);
    void selectNothing (void);
    void inverseSelection (void);
    void selectDataType (ui32 dataType);
    void selectDataType0 (void);
    void selectDataType1 (void);
    void selectDataType2 (void);
    void selectDataType3 (void);
    void selectDataType4 (void);
    void selectDataType5 (void);
    void selectDataType6 (void);
    void selectDataType7 (void);
    void selectDataType8 (void);
    void selectDataType9 (void);
    void selectDataType10 (void);
    void selectDataType11 (void);
    void selectDataType12 (void);
    void selectDataType13 (void);
    void selectDataType14 (void);
    void selectDataType15 (void);
    void selectDataType16 (void);
    void selectDataType17 (void);
    void selectDataType18 (void);
    void selectDataType19 (void);
	void selectPointer (void);

    // About menu functions
    void about (void);
};


#endif // __MH4WINDOW_H__