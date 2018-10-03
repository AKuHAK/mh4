/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#ifndef __MH4WIDGET_H__
#define __MH4WIDGET_H__


#include <qwidget.h>
#include "mh4.h"


class QListView;
class QListViewItem;
class QGridLayout;


class mh4widget: public QWidget
{
  Q_OBJECT

  public:
    mh4widget (QWidget *parent,const char *name = NULL);
    ~mh4widget (void);
    void createListViewItem (ui32 nbItem);
    void deleteListViewItem (void);

  protected slots:

  public:
    QGridLayout *m_pMainGrid;
    QListView *m_pListView;
    ui32 m_NbItem;
    QListViewItem **m_pListViewItem;
};


#endif  // __MH4WIDGET_H__