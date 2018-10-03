/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: AKUHAK and Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#include <qapplication.h>
#include "mh4window.h"
#include <qfileinfo.h>
#include <qlistbox.h>
 

// ------------------------------------------------------------------------------------------
// main
// ------------------------------------------------------------------------------------------
// Description:
//    Main function.
// ------------------------------------------------------------------------------------------
// In:
//    argc: number of arguments
//    argv: arguments list
//
// Out:
//    Error code
// ------------------------------------------------------------------------------------------
int main (int argc,char **argv)
{
  QApplication app( argc,argv );
//	QListBox b;
//	QFileInfo heh=app.argv()[0],heh1=app.argv()[1];
//	QString qq,qq1;
//	qq=heh.absFilePath();
//	
//	qq1=heh1.absFilePath();
//	b.insertItem( app.argv()[0] );        // a.argv()[i] == argv[i]
//	b.insertItem(qq);
//	b.insertItem( app.argv()[1] );        // a.argv()[i] == argv[i]
//	b.insertItem(qq1);
//	b.show();
 
	mh4Window window;
	app.setMainWidget( &window );
 
  
	window.show();
  //}
  return app.exec();
}