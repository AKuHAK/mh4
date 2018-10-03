/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#include <malloc.h>
#include <qwidget.h>
#include <qlayout.h> 
#include <qlistview.h>
#include "mh4widget.h"


// ------------------------------------------------------------------------------------------
// mh4widget::mh4widget
// ------------------------------------------------------------------------------------------
// Description:
//    Constructor.
// ------------------------------------------------------------------------------------------
// In:
//    parent: parent widget
//    name  : widget name
//
// Out:
//
// ------------------------------------------------------------------------------------------
mh4widget::mh4widget (QWidget *parent,const char *name): QWidget( parent, name )
{
  m_pMainGrid = new QGridLayout( this );

  m_pListView = new QListView( this );
  // The 5 columns
  m_pListView->addColumn( "Name" );
  m_pListView->addColumn( "Offset" );
  m_pListView->addColumn( "Size" );
  m_pListView->addColumn( "Path" );
  m_pListView->addColumn( "Type" );

  m_pListView->setSelectionMode( QListView::Extended );

  m_pMainGrid->addWidget( m_pListView,0,0 );

  // No item
  m_NbItem = 0;
  m_pListViewItem = NULL;
}


// ------------------------------------------------------------------------------------------
// mh4widget::~mh4widget
// ------------------------------------------------------------------------------------------
// Description:
//    Destructor.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
mh4widget::~mh4widget (void)
{
  deleteListViewItem();
  delete m_pListView;
  delete m_pMainGrid;
}


// ------------------------------------------------------------------------------------------
// mh4widget::createListViewItem
// ------------------------------------------------------------------------------------------
// Description:
//    Create the items of the list view.
// ------------------------------------------------------------------------------------------
// In:
//    nbItem: number of items in the list view
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4widget::createListViewItem (ui32 nbItem)
{
  if( m_pListViewItem )
  {
    deleteListViewItem();
  }

  m_NbItem = nbItem;
  if( m_NbItem > 0 )
  {
    m_pListViewItem = new QListViewItem*[nbItem];
  }
}


// ------------------------------------------------------------------------------------------
// mh4widget::deleteListViewItem
// ------------------------------------------------------------------------------------------
// Description:
//    Delete the items of the list view.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4widget::deleteListViewItem (void)
{
  if( m_NbItem > 0 )
  {
    delete[] m_pListViewItem;
    m_pListView->clear();

    // No more item
    m_NbItem = 0;
    m_pListViewItem = NULL;
  }
}