/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#include <qapplication.h>
#include "mh4window.h"


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

  mh4Window window;
  app.setMainWidget( &window );

  window.show();

  return app.exec();
}