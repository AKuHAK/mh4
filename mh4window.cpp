/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: AKUHAK and Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#include <qdatetime.h>
#include <qapplication.h>
#include <qworkspace.h>
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qpopupmenu.h>
#include <qaction.h>
#include <qmessagebox.h> 
#include <qfiledialog.h>
#include <qprogressdialog.h>
#include <qpushbutton.h>
#include "mh4window.h"
#include "mh4widget.h"


// ------------------------------------------------------------------------------------------
// mh4Window::mh4Window
// ------------------------------------------------------------------------------------------
// Description:
//    Constructor.
// ------------------------------------------------------------------------------------------
// In:
//    parent: parent widget
//    name  : window name
//    f     : flag
//
// Out:
//
// ------------------------------------------------------------------------------------------
mh4Window::mh4Window (QWidget *parent,const char *name,WFlags f): QMainWindow( parent,name,f )
{
  setCaption( MH4_DESC );

  m_pView = new mh4widget( this );
  m_pView->setMinimumSize( MIN_WIDTH,MIN_HEIGHT );
  setCentralWidget( m_pView );

  // File menu
  QPopupMenu *fileMenu = new QPopupMenu( this );
  menuBar()->insertItem( tr( "&File" ),fileMenu );

  // Options menu
  QPopupMenu *optionsMenu = new QPopupMenu( this );
  menuBar()->insertItem( tr("&Options"),optionsMenu );

  // Selection menu
  QPopupMenu *selectionMenu = new QPopupMenu( this );
  menuBar()->insertItem( tr("&Selection"),selectionMenu );

  // About menu
  QPopupMenu *aboutMenu = new QPopupMenu( this );
  menuBar()->insertItem( tr( "&About" ),aboutMenu );

  QAction *action;


  // *********
  // File menu
  // *********

  // Open menu
  action = new QAction( tr( "Open a h4r file" ),tr( "Open a h4r file" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( createSelection()));
  action->addTo( fileMenu );

  // Close menu
  action = new QAction( tr( "Close the current file" ),tr( "Close the current file" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( deleteSelection()));
  action->addTo( fileMenu );

  fileMenu->insertSeparator();

  // Exit menu
  action = new QAction( tr( "Exit" ),tr( "Exit" ),0,this );
  action->addTo( fileMenu );
  connect( action, SIGNAL( activated()),qApp,SLOT( closeAllWindows()));


  // ************
  // Options menu
  // ************

  // Extract menu
  action = new QAction( tr( "Extract selected files" ),tr( "Extract selected files" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( extractSelection()));
  action->addTo( optionsMenu );

  // Dump menu
  action = new QAction( tr( "Dump the current file" ),tr( "Dump the current file" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( dumpSelection()));
  action->addTo( optionsMenu );

  optionsMenu->insertSeparator();

  // Build menu
  action = new QAction( tr( "Build a h4l file" ),tr( "Build a h4l file" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( build()));
  action->addTo( optionsMenu );


  // **************
  // Selection menu
  // **************

  // Select all menu
  action = new QAction( tr( "Select all" ),tr( "Select all" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectAll()));
  action->addTo( selectionMenu );

  // Select nothing menu
  action = new QAction( tr( "Select nothing" ),tr( "Select nothing" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectNothing()));
  action->addTo( selectionMenu );

  // Inverse selection menu
  action = new QAction( tr( "Inverse selection" ),tr( "Inverse selection" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( inverseSelection()));
  action->addTo( selectionMenu );

  selectionMenu->insertSeparator();

  // Select H4R_UNKNOWN menu
  action = new QAction( tr( "Select unknown" ),tr( "Select unknown" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType0()));
  action->addTo( selectionMenu );

  // Select H4R_ACTOR_SEQUENCE menu
  action = new QAction( tr( "Select actor_sequence" ),tr( "Select actor_sequence" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType1()));
  action->addTo( selectionMenu );

  // Select H4R_ADV_ACTOR menu
  action = new QAction( tr( "Select adv_actor" ),tr( "Select adv_actor" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType2()));
  action->addTo( selectionMenu );

  // Select H4R_ADV_OBJECT menu
  action = new QAction( tr( "Select adv_object" ),tr( "Select adv_object" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType3()));
  action->addTo( selectionMenu );

  // Select H4R_ANIMATION menu
  action = new QAction( tr( "Select animation" ),tr( "Select animation" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType4()));
  action->addTo( selectionMenu );

  // Select H4R_BATTLEFIELD_PRESET_MAP menu
  action = new QAction( tr( "Select battlefield_preset_map" ),tr( "Select battlefield_preset_map" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType5()));
  action->addTo( selectionMenu );

  // Select H4R_BITMAP_RAW menu
  action = new QAction( tr( "Select bitmap_raw" ),tr( "Select bitmap_raw" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType6()));
  action->addTo( selectionMenu );

  // Select H4R_BINK menu
  action = new QAction( tr( "Select bink" ),tr( "Select bink" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType7()));
  action->addTo( selectionMenu );

  // Select H4R_CASTLE menu
  action = new QAction( tr( "Select castle" ),tr( "Select castle" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType8()));
  action->addTo( selectionMenu );

  // Select H4R_COMBAT_ACTOR menu
  action = new QAction( tr( "Select combat_actor" ),tr( "Select combat_actor" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType9()));
  action->addTo( selectionMenu );

  // Select H4R_COMBAT_HEADER_TABLE_CACHE menu
  action = new QAction( tr( "Select combat_header_table_cache" ),tr( "Select combat_header_table_cache" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType10()));
  action->addTo( selectionMenu );

  // Select H4R_COMBAT_OBJECT menu
  action = new QAction( tr( "Select combat_object" ),tr( "Select combat_object" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType11()));
  action->addTo( selectionMenu );

  // Select H4R_FONT menu
  action = new QAction( tr( "Select font" ),tr( "Select font" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType12()));
  action->addTo( selectionMenu );

  // Select H4R_GAME_MAPS menu
  action = new QAction( tr( "Select game_maps" ),tr( "Select game_maps" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType13()));
  action->addTo( selectionMenu );

  // Select H4R_LAYERS menu
  action = new QAction( tr( "Select layers" ),tr( "Select layers" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType14()));
  action->addTo( selectionMenu );

  // Select H4R_SOUND menu
  action = new QAction( tr( "Select sound" ),tr( "Select sound" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType15()));
  action->addTo( selectionMenu );

  // Select H4R_STRING menu
  action = new QAction( tr( "Select strings" ),tr( "Select strings" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType16()));
  action->addTo( selectionMenu );

  // Select H4R_TABLE menu
  action = new QAction( tr( "Select table" ),tr( "Select table" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType17()));
  action->addTo( selectionMenu );

  // Select H4R_TERRAIN menu
  action = new QAction( tr( "Select terrain" ),tr( "Select terrain" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType18()));
  action->addTo( selectionMenu );

  // Select H4R_TRANSITION menu
  action = new QAction( tr( "Select transition" ),tr( "Select transition" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectDataType19()));
  action->addTo( selectionMenu );

  selectionMenu->insertSeparator();
  
  // Select Pointer menu
  action = new QAction( tr( "Select pointers" ),tr( "Select pointers" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( selectPointer()));
  action->addTo( selectionMenu );  
  
  
  // **********
  // About menu
  // **********

  // About menu
  action = new QAction( tr( "About" ),tr( "About" ),0,this );
  connect( action,SIGNAL( activated()),SLOT( about()));
  action->addTo( aboutMenu );

  m_pH4RFile = NULL;
}


// ------------------------------------------------------------------------------------------
// mh4Window::~mh4Window
// ------------------------------------------------------------------------------------------
// Description:
//    Destructor.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
mh4Window::~mh4Window (void)
{
  if( m_pView )
  {
    delete m_pView;
  }
  if( m_pH4RFile )
  {
    delete m_pH4RFile;
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::createSelection
// ------------------------------------------------------------------------------------------
// Description:
//    Create a selection of files to extract.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::createSelection (void)
{
  QString fileNameString = QFileDialog::getOpenFileName( "Select a h4r file to open","Heroes IV Ressources (*.h4r)",this,"salut !!!" );

  if( fileNameString.isEmpty())
  {
    return;
  }

  char *fileNameToExtract = (char *)fileNameString.latin1();

  if( m_pH4RFile )
  {
    delete m_pH4RFile;
  }

  m_pH4RFile = new H4RFile;

  ui32 nbFile = m_pH4RFile->scan( fileNameToExtract );
  if( nbFile < 1 )
  {
    QMessageBox::warning( this,"mh4","No file to extract !" );
    return;
  }

  m_pView->m_pListView->clear();
  m_pView->createListViewItem( nbFile );
  QString info, info3, info4;
  QDateTime info2;
  QDate dddate;
  QTime tttime;
  int iiiint, iint;
  int *mas1 = new int[nbFile];
  int *mas2 = new int[nbFile];
  
  for( ui32 numFilex=0;numFilex<nbFile;numFilex++ )
  {
	info.setNum( m_pH4RFile->m_pOffset[numFilex] );
	mas1[numFilex] = info.toInt();
	mas2[numFilex] = numFilex;
  }
  for( ui32 numFile1=0;numFile1<nbFile;numFile1++ )
  {
	for( ui32 numFile2=numFile1+1;numFile2<nbFile;numFile2++ )
	{
		if (mas1[numFile1] > mas1[numFile2])
		{
			iiiint = mas1[numFile1];
			mas1[numFile1] = mas1[numFile2];
			mas1[numFile2] = iiiint;
			iiiint = mas2[numFile1];
			mas2[numFile1] = mas2[numFile2];
			mas2[numFile2] = iiiint;
		}
	}
  }
  //for( ui32 numFile3=0;numFile3<nbFile;numFile3++ )
  //{
//	iiiint = mas2[numFile3];
//	mas1[iiiint] = numFile3;
  //}
  for( ui32 numFile4=0;numFile4<nbFile-1;numFile4++ )
  {
	iint = mas2[numFile4];
	iiiint = mas2[numFile4+1];
	info.setNum( m_pH4RFile->m_pOffset[iiiint] );
	info3.setNum( m_pH4RFile->m_pOffset[iint] );
	info4.setNum( m_pH4RFile->m_pSize[iint] );
	mas1[iint] = info.toInt() - info3.toInt() - info4.toInt();
	if (numFile4 == nbFile-2)
	{
		// info3.setNum( m_pH4RFile->m_pOffset[iiiint] );
		// info4.setNum( m_pH4RFile->m_pSize[iiiint] );	
		// mas1[iiiint] = 676966935 - info3.toInt() - info4.toInt();
		mas1[iiiint] = 0;
	}
  }	
  for( ui32 numFile=0;numFile<nbFile;numFile++ )
  {
    m_pView->m_pListViewItem[numFile] = new QListViewItem( m_pView->m_pListView );

    // File name
    info = QString( m_pH4RFile->m_ppName[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 0,info );

    // File offset
    info.setNum( m_pH4RFile->m_pOffset[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 1,info.rightJustify(11, ' ') );

    // File size (zipped)
    info.setNum( m_pH4RFile->m_pSize[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 2,info.rightJustify(8, ' ') );
		
    // File point
    info = QString( m_pH4RFile->m_ppPointer[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 3,info );

    // File number
    info.setNum(numFile );
    m_pView->m_pListViewItem[numFile]->setText( 4,info.rightJustify(5, '0') );

    // File type
    info = QString( g_FileDataName[m_pH4RFile->m_pDataType[numFile]] );
    m_pView->m_pListViewItem[numFile]->setText( 5,info );

    // File date
    info2.setTime_t( m_pH4RFile->m_pTime[numFile] );
	dddate = info2.date();
	iiiint = dddate.year();
	info3 = info.setNum(iiiint) + '.';
	iiiint = dddate.month();
	if (iiiint < 10)
	{
		info3 +='0';
	}
	info3 += info.setNum(iiiint) + '.';
	iiiint = dddate.day();
	if (iiiint < 10)
	{
		info3 +='0';
	}
	info3 += info.setNum(iiiint) + ' ';
	tttime = info2.time();
	iiiint = tttime.hour();
	if (iiiint < 10)
	{
		info3 +='0';
	}
	info3 += info.setNum(iiiint) + ':';
	iiiint = tttime.minute();
	if (iiiint < 10)
	{
		info3 +='0';
	}
	info3 += info.setNum(iiiint) + ':';
	iiiint = tttime.second();
	if (iiiint < 10)
	{
		info3 +='0';
	}
	info3 += info.setNum(iiiint);
    m_pView->m_pListViewItem[numFile]->setText( 6,info3 );

	// File path
    info = QString( m_pH4RFile->m_ppPath[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 7,info );

	// File size (unzipped)
    info.setNum( m_pH4RFile->m_pUnpSize[numFile] );
    m_pView->m_pListViewItem[numFile]->setText( 8,info.rightJustify(8, ' ') );

	// Gzip value
	info3=info.setNum( m_pH4RFile->m_pCompr[numFile] );
	info.setNum( m_pH4RFile->m_pCompr[numFile] );
    if (info == "3")
	{
		info3="Yes";
	}
	if (info == "1")
	{
		info3="No";
	}
    m_pView->m_pListViewItem[numFile]->setText( 9,info3 );

    info.setNum(mas1[numFile] );
	if ( mas1[numFile] > 0)
	{
      m_pView->m_pListViewItem[numFile]->setText( 10,info.rightJustify(8, ' ') );
	}
	else
	{
	  m_pView->m_pListViewItem[numFile]->setText( 10,'\0');
	}
	//If the file size is 0, the file is not selectable
    // if( m_pH4RFile->m_pSize[numFile] == 0 )
    // {
      // m_pView->m_pListViewItem[numFile]->setSelectable( false );
    // }

    m_pView->m_pListView->insertItem( m_pView->m_pListViewItem[numFile] );
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::deleteSelection
// ------------------------------------------------------------------------------------------
// Description:
//    Delete the selection of files to extract.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::deleteSelection (void)
{
  m_pView->deleteListViewItem();
  if( m_pH4RFile )
  {
    delete m_pH4RFile;
    m_pH4RFile = NULL;
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::extractSelection
// ------------------------------------------------------------------------------------------
// Description:
//    Extract the selection.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::extractSelection (void)
{
  // No h4r file
  if( !m_pH4RFile )
  {
    QMessageBox::warning( this,"Nothing to extract","Open an h4r file first !" );
    return;
  }

  // We check the file to extract
  ui32 nbFileToExtract = 0;
  for( ui32 i=0;i<m_pView->m_NbItem;i++ )
  {
    m_pH4RFile->m_pToExtract[i] = m_pView->m_pListView->isSelected( m_pView->m_pListViewItem[i] );
    if( m_pH4RFile->m_pToExtract[i] )
    {
      nbFileToExtract++;
    }
	// else
	// {
	  // if( m_pH4RFile->m_pSize[i] == 0 )
	  // {
		// nbFileToExtract++;
      // }
	// }
  }

  // Nothing is selected
  if( nbFileToExtract == 0 )
  {
    QMessageBox::warning( this,"Nothing is selected","Select the files you want to extract !" );
    return;
  }

  FILE *srcFile = fopen( m_pH4RFile->m_szH4rFileName,"rb" );
  if( !srcFile )
  {
    QMessageBox::warning( this,"Extraction error","Impossible to open the h4r file !" );
    return;
  }

  QString dirString = QFileDialog::getExistingDirectory( QString::null,this,NULL,"Where do you want to put the extracted files",true );
  if ( dirString.isEmpty())
  {
    return;
  }

  char *dirName = (char *)dirString.latin1();

  char extractedFileName[MAX_FILENAME_LENGTH];

  // We memorize in a file the list of all extracted files
  char lstFileName[MAX_FILENAME_LENGTH],tmp[MAX_FILENAME_LENGTH];
  strcpy( tmp,m_pH4RFile->m_szH4rFileName );
  getFileName( tmp );
  strcpy( lstFileName,dirName );
  strcat( lstFileName,tmp );
  removeFileNameSuffix( lstFileName );
  strcat( lstFileName,".h4l" );

  FILE *lstFile = fopen( lstFileName,"wt" );
  strcpy( tmp,m_pH4RFile->m_szH4rFileName );
  getFileName( tmp );
  fprintf( lstFile,"[H4R File List]\n%s\n%d\n",tmp,nbFileToExtract );

  QProgressDialog *pProgressBar = new QProgressDialog( "Extract","Cancel",nbFileToExtract,this,"progress",TRUE );
  pProgressBar->setCaption( "Please Wait" );

  ui32 nbExtractedFile = 0;
  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
    if( m_pH4RFile->extract( srcFile,numFile,dirName,extractedFileName ))
    {
	  if ( m_pH4RFile->m_pSize[numFile] == 0 )
		{
		  fprintf( lstFile,"%s%c",m_pH4RFile->m_ppName[numFile], '|');
		  fprintf( lstFile,"%s\n",m_pH4RFile->m_ppPointer[numFile] );
		}
	  else
		{
		  getFileName( extractedFileName );
		  fprintf( lstFile,"%s\n",extractedFileName );
		}
		nbExtractedFile++;
		pProgressBar->setProgress( nbExtractedFile );
    }

	// if ( m_pH4RFile->m_pSize[numFile] == 0 )
	// {
	  // fprintf( lstFile,"%s%c",m_pH4RFile->m_ppName[numFile], '|');
	  // fprintf( lstFile,"%s\n",m_pH4RFile->m_ppPath[numFile] );
	  // nbExtractedFile++;
	  // pProgressBar->setProgress( nbExtractedFile );
	// }
	
    if( pProgressBar->wasCancelled())
    {
      QMessageBox::warning( this,"File not build","The build has been stopped by the user !" );
      delete pProgressBar;
      return;
    }
  }
  delete pProgressBar;

  fprintf( lstFile,"[End]" );
  fclose( srcFile );
  fclose( lstFile );

  QString stringNbExtractedFile;
  stringNbExtractedFile.setNum( nbExtractedFile );

  QString stringNbFile;
  stringNbFile.setNum( m_pH4RFile->m_NbFile );

  QMessageBox::information( this,"Files extracted",stringNbExtractedFile  + " / " + stringNbFile + " files were extracted" );
}


// ------------------------------------------------------------------------------------------
// mh4Window::dumpSelection
// ------------------------------------------------------------------------------------------
// Description:
//    Dump the selection.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::dumpSelection (void)
{
  // No h4r file
  if( !m_pH4RFile )
  {
    QMessageBox::warning( this,"Nothing to extract","Open an h4r file first !" );
    return;
  }

  QString dirString = QFileDialog::getExistingDirectory( QString::null,this,NULL,"Where do you want to put the dump file",true );
  if( dirString.isEmpty())
  {
    return;
  }

  char *dirName = (char *)dirString.latin1();

  // Dump
  if( m_pH4RFile->dump( dirName ))
  {
    QMessageBox::information( this,"File dumped","The file was dumped" );
  }
  else
  {
    QMessageBox::warning( this,"File not dumped","Error during the dump of the file !" );
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::build
// ------------------------------------------------------------------------------------------
// Description:
//    Build a list file.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::build (void)
{
  // Choose the file to build
  QString fileNameString = QFileDialog::getOpenFileName( "Select a h4l file to build","Heroes IV List (*.h4l)",this );

  if( fileNameString.isEmpty())
  {
    return;
  }

  char *fileNameToBuild = (char *)fileNameString.latin1();
  char dirName[MAX_FILENAME_LENGTH];
  strcpy( dirName,fileNameToBuild );
  getFilePath( dirName );

  H4RFile h4rFile;

  // Scan the lst file
  ui32 tableSize;
  FILE *lstFile = h4rFile.scanList( fileNameToBuild,dirName,&tableSize );
  if( !lstFile )
  {
    QMessageBox::warning( this,"File not build","Error in the lst file !" );
    return;
  }

  QProgressDialog *pProgressBar = new QProgressDialog( "Build h4r header","Cancel",h4rFile.m_NbFile,this,"progress",TRUE );
  pProgressBar->setCaption( "Please Wait" );

  // Scan and zip each file
  ui32 numFile;
  for( numFile=0;numFile<h4rFile.m_NbFile;numFile++ )
  {
    if( !h4rFile.scanBuild( lstFile,numFile,dirName,&tableSize ))
    {
      QMessageBox::warning( this,"File not build","Error during the build of the file header !" );
      delete pProgressBar;
      return;
    }
    if( pProgressBar->wasCancelled())
    {
      QMessageBox::warning( this,"File not build","The build has been stopped by the user !" );
      delete pProgressBar;
      return;
    }
    pProgressBar->setProgress( numFile+1 );
  }
  delete pProgressBar;

  fclose( lstFile );

  // Build the header of the h4r file
  FILE *h4rBuildFile = h4rFile.headerBuild( tableSize );
  if( !h4rBuildFile )
  {
    QMessageBox::warning( this,"File not build","Error during the write of the file header !" );
    return;
  }

  pProgressBar = new QProgressDialog( "Build h4r file","Cancel",h4rFile.m_NbFile,this,"progress",TRUE );
  pProgressBar->setCaption( "Please Wait" );

  // Copy the zipped files into the h4r file
  for( numFile=0;numFile<h4rFile.m_NbFile;numFile++ )
  {
    if( !h4rFile.dataBuild( h4rBuildFile,numFile,dirName ))
    {
      QMessageBox::warning( this,"File not build","Error during the build of the file !" );
      delete pProgressBar;
      return;
    }
    if( pProgressBar->wasCancelled())
    {
      QMessageBox::warning( this,"File not build","The build has been stopped by the user !" );
      delete pProgressBar;
      return;
    }
    pProgressBar->setProgress( numFile+1 );
  }
  delete pProgressBar;

  fclose( h4rBuildFile );

  // QMessageBox::information( this,"File build","The file was build !" );
  QMessageBox::information( this,"File build","The file was build !" );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectAll
// ------------------------------------------------------------------------------------------
// Description:
//    Select all files.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectAll (void)
{
  if( !m_pH4RFile )
  {
    return;
  }

  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
    m_pView->m_pListView->setSelected( m_pView->m_pListViewItem[numFile],true );
  }
}



// ------------------------------------------------------------------------------------------
// mh4Window::selectAll
// ------------------------------------------------------------------------------------------
// Description:
//    Select all files.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectPointer (void)
{
  if( !m_pH4RFile )
  {
    return;
  }

  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
	if (m_pH4RFile->m_pSize[numFile] == 0 )
	  {
		m_pView->m_pListView->setSelected( m_pView->m_pListViewItem[numFile],true );
	  }
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectNothing
// ------------------------------------------------------------------------------------------
// Description:
//    Select no file.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectNothing (void)
{
  if( !m_pH4RFile )
  {
    return;
  }

  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
    m_pView->m_pListView->setSelected( m_pView->m_pListViewItem[numFile],false );
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::inverseSelection
// ------------------------------------------------------------------------------------------
// Description:
//    Inverse the selection.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::inverseSelection (void)
{
  if( !m_pH4RFile )
  {
    return;
  }

  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
    m_pView->m_pListView->setSelected( m_pView->m_pListViewItem[numFile],!m_pView->m_pListViewItem[numFile]->isSelected());
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType
// ------------------------------------------------------------------------------------------
// Description:
//    Select a kind of file.
// ------------------------------------------------------------------------------------------
// In:
//    dataType: data type to select
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType (ui32 dataType)
{
  if( !m_pH4RFile )
  {
    return;
  }

  for( ui32 numFile=0;numFile<m_pH4RFile->m_NbFile;numFile++ )
  {
    QString dataTypeString = m_pView->m_pListViewItem[numFile]->text( 4 );
    if( dataTypeString == g_FileDataName[dataType] )
    {
      m_pView->m_pListView->setSelected( m_pView->m_pListViewItem[numFile],true );
    }
  }
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType0
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 0.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType0 (void)
{
  selectDataType( 0 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType1
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 1.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType1 (void)
{
  selectDataType( 1 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType2
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 2.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType2 (void)
{
  selectDataType( 2 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType3
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 3.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType3 (void)
{
  selectDataType( 3 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType4
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 4.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType4 (void)
{
  selectDataType( 4 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType5
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 5.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType5 (void)
{
  selectDataType( 5 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType6
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 6.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType6 (void)
{
  selectDataType( 6 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType7
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 7.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType7 (void)
{
  selectDataType( 7 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType8
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 8.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType8 (void)
{
  selectDataType( 8 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType9
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 9.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType9 (void)
{
  selectDataType( 9 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType10
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 10.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType10 (void)
{
  selectDataType( 10 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType11
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 11.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType11 (void)
{
  selectDataType( 11 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType12
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 12.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType12 (void)
{
  selectDataType( 12 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType13
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 13.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType13 (void)
{
  selectDataType( 13 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType14
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 14.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType14 (void)
{
  selectDataType( 14 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType15
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 15.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType15 (void)
{
  selectDataType( 15 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType16
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 16.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType16 (void)
{
  selectDataType( 16 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType17
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 17.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType17 (void)
{
  selectDataType( 17 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType18
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 18.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType18 (void)
{
  selectDataType( 18 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::selectDataType19
// ------------------------------------------------------------------------------------------
// Description:
//    Select files with the data type 19.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::selectDataType19 (void)
{
  selectDataType( 19 );
}


// ------------------------------------------------------------------------------------------
// mh4Window::about
// ------------------------------------------------------------------------------------------
// Description:
//    What about mh4 ...
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void mh4Window::about (void)
{
  QMessageBox::information( this,"About","Heroes of Might and Magic IV Ressources Explorer and Modifier\nBy AKUHAK and Olivier Soares\nolivier@etranges-libellules.fr\n\nRemake  by AKuHAK\nakuhak@gmail.com" );
}
