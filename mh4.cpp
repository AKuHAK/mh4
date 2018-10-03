/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <zlib.h>
#include "mh4.h"


// h4r data types info
char *g_FileDataName[] = { "unknown","actor_sequence","adv_actor","adv_object","animation","battlefield_preset_map","bitmap_raw","bink","castle","combat_actor","combat_header_table_cache","combat_object","font","game_maps","layers","sound","strings","table","terrain","transition" };
char *g_FileDataSuffix[] = { ".unk",".seq",".act",".obj",".ani",".map",".raw",".bik",".cst",".cmb",".cht",".obj",".fnt",".h4c",".lay",".mp3",".txt",".txt",".ter",".tra" };


// ------------------------------------------------------------------------------------------
// removeFileNameSuffix
// ------------------------------------------------------------------------------------------
// Description:
//    Remove the suffix of a file name.
// ------------------------------------------------------------------------------------------
// In:
//    szFileNameWithSuffix: file name with a suffix
//
// Out:
//    Error ?
// ------------------------------------------------------------------------------------------
void removeFileNameSuffix (char *szFileNameWithSuffix)
{
  if( !szFileNameWithSuffix )
  {
    return;
  }

  ui32 length = strlen( szFileNameWithSuffix ) - 1;
  bool done = false;

  ui32 i;
  for( i=0;i<=length && !done;i++ )
  {
    if( szFileNameWithSuffix[length - i] == '.' )
    {
      szFileNameWithSuffix[length - i] = '\0';
      break;
    }
  }
}


// ------------------------------------------------------------------------------------------
// getFilePath
// ------------------------------------------------------------------------------------------
// Description:
//    Get only the path without the name.
// ------------------------------------------------------------------------------------------
// In:
//    szFileNameWithPath: file name with a path
//
// Out:
//
// ------------------------------------------------------------------------------------------
void getFilePath (char *szFileNameWithPath)
{
  if( !szFileNameWithPath )
  {
    return;
  }

  ui32 length = strlen( szFileNameWithPath ) - 1;

  ui32 i;
  for( i=0;i<=length;i++ )
  {
    if( szFileNameWithPath[length-i] == '\\' || szFileNameWithPath[length-i] == '/' )
    {
      break;
    }
    else
    {
      szFileNameWithPath[length-i] = '\0';
    }
  }
}


// ------------------------------------------------------------------------------------------
// getFileName
// ------------------------------------------------------------------------------------------
// Description:
//    Get only the file name without the path.
// ------------------------------------------------------------------------------------------
// In:
//    szFileNameWithPath: file name with a path
//
// Out:
//
// ------------------------------------------------------------------------------------------
void getFileName (char *szFileNameWithPath)
{
  if( !szFileNameWithPath )
  {
    return;
  }

  ui32 length = strlen( szFileNameWithPath ) - 1;
  ui32 l;

  bool readChar = false;

  for( l=0;l<=length;l++ )
  {
    if( szFileNameWithPath[length - l] == '\\' || szFileNameWithPath[length - l] == '/' )
    {
      if( readChar )
      {
        break;
      }
      else
      {
        szFileNameWithPath[length - l] = '\0';
      }
    }
    else
    {
      readChar = true;
    }
  }

  if( l < length )
  {
    char temp[MAX_FILENAME_LENGTH];
    temp[l] = '\0';
    l--;

    ui32 i;
    for( i=0;i<=l;i++ )
    {
      if( szFileNameWithPath[length - i] == '\\' || szFileNameWithPath[length - i] == '/' )
      {
        temp[l - i] = '\0';
      }
      else
      {
        temp[l - i] = szFileNameWithPath[length - i];
      }
    }

    strcpy( szFileNameWithPath,temp );
  }
}


// ------------------------------------------------------------------------------------------
// getFileSize
// ------------------------------------------------------------------------------------------
// Description:
//    Get the file size.
// ------------------------------------------------------------------------------------------
// In:
//    szFileName: file name
//
// Out:
//    File size
// ------------------------------------------------------------------------------------------
ui32 getFileSize (char *szFileName)
{
  if( !szFileName )
  {
    return 0;
  }

  FILE *file = fopen( szFileName,"rb" );
  if( !file )
  {
    return 0;
  }

  fseek( file,0,SEEK_END );
  ui32 filePos = ftell( file );
  fclose( file );

  return filePos;
}


// ------------------------------------------------------------------------------------------
// copyFile
// ------------------------------------------------------------------------------------------
// Description:
//    Copy a file.
// ------------------------------------------------------------------------------------------
// In:
//    szSrcFileName : source file name
//    szDestFileName: destination file name
//
// Out:
//    File size
// ------------------------------------------------------------------------------------------
ui32 copyFile (char *szSrcFileName,char *szDestFileName)
{
  if( !szSrcFileName || !szDestFileName )
  {
    return 0;
  }

  FILE *srcFile = fopen( szSrcFileName,"rb" );
  FILE *destFile = fopen( szDestFileName,"wb" );
  if( !srcFile || !destFile )
  {
    return 0;
  }

  // Our data buffer
  ui8 pDataBuffer[BUFFER_SIZE];

  ui32 bufferSizeRead;
  do
  {
    bufferSizeRead = fread( pDataBuffer,sizeof( ui8 ),BUFFER_SIZE,srcFile );
    fwrite( pDataBuffer,sizeof( ui8 ),bufferSizeRead,destFile );
  }
  while( bufferSizeRead > 0 );

  // File size
  ui32 filePos = ftell( srcFile );

  fclose( srcFile );
  fclose( destFile );

  return filePos;
}


// ------------------------------------------------------------------------------------------
// zipFile
// ------------------------------------------------------------------------------------------
// Description:
//    Zip a file and add some bytes.
// ------------------------------------------------------------------------------------------
// In:
//    szFileName      : source file name
//    szZippedFileName: destinamtion file name
//    sizeToAdd       : number of bytes to add
//
// Out:
//    Zipped file size
// ------------------------------------------------------------------------------------------
ui32 zipFile (char *szFileName,char *szZippedFileName,ui32 sizeToAdd)
{
  if( !szFileName || !szZippedFileName )
  {
    return 0;
  }

  // Source file
  FILE *unzipFile = fopen( szFileName,"rb" );
  // Impossible to open the file ?
  if( !unzipFile )
  {
    return 0;
  }

  // Destination file
  gzFile zipFile = gzopen( szZippedFileName,"wb6" );
  // Impossible to open the file ?
  if( !zipFile )
  {
    return 0;
  }

  // Our data buffer
  ui8 pDataBuffer[BUFFER_SIZE];
  memset( pDataBuffer,0,BUFFER_SIZE*sizeof( ui8 ));

  ui32 bufferSizeRead;
  do
  {
    if( sizeToAdd == 0 )
    {
      bufferSizeRead = fread( pDataBuffer,sizeof( ui8 ),BUFFER_SIZE,unzipFile );
    }
    else
    {
      if( sizeToAdd < BUFFER_SIZE )
      {
        bufferSizeRead = sizeToAdd;
        sizeToAdd = 0;
      }
      else
      {
        bufferSizeRead = BUFFER_SIZE;
        sizeToAdd -= BUFFER_SIZE;
      }
    }

    gzwrite( zipFile,pDataBuffer,bufferSizeRead * sizeof( ui8 ));
  }
  while( bufferSizeRead > 0 );

  gzclose( zipFile );
  fclose( unzipFile );

  return getFileSize( szZippedFileName );
}


// ------------------------------------------------------------------------------------------
// unzipFile
// ------------------------------------------------------------------------------------------
// Description:
//    Unzip a file and delete some bytes.
// ------------------------------------------------------------------------------------------
// In:
//    szFileName        : source file name
//    szUnzippedFileName: destinamtion file name
//    sizeToDelete      : number of bytes to delete
//
// Out:
//    Unzipped file size
// ------------------------------------------------------------------------------------------
ui32 unzipFile (char *szFileName,char *szUnzippedFileName,ui32 sizeToDelete)
{
  if( !szFileName || !szUnzippedFileName )
  {
    return 0;
  }

  // Source file
  gzFile zipFile = gzopen( szFileName,"rb" );
  // Impossible to open the file ?
  if( !zipFile )
  {
    return 0;
  }

  // Destination file
  FILE *unzipFile = fopen( szUnzippedFileName,"wb" );
  // Impossible to open the file ?
  if( !unzipFile )
  {
    return 0;
  }

  // Our data buffer
  ui8 pDataBuffer[BUFFER_SIZE];

  ui32 bufferSizeRead;
  do
  {
    bufferSizeRead = gzread( zipFile,pDataBuffer,BUFFER_SIZE * sizeof( ui8 ));
    if( sizeToDelete == 0 )
    {
      fwrite( pDataBuffer,sizeof( ui8 ),bufferSizeRead,unzipFile );
    }
    else if( sizeToDelete < bufferSizeRead )
    {
      // We don't write the "sizeToDelete" first bytes
      fwrite( pDataBuffer + sizeToDelete,sizeof( ui8 ),bufferSizeRead - sizeToDelete,unzipFile );

      // Nothing else to delete
      sizeToDelete = 0;
    }
    else
    {
      // We don't write the data buffer
      sizeToDelete -= bufferSizeRead;
    }
  }
  while( bufferSizeRead > 0 );

  ui32 filePos = ftell( unzipFile );

  gzclose( zipFile );
  fclose( unzipFile );

  return filePos;
}


// ------------------------------------------------------------------------------------------
// H4RFile::H4RFile
// ------------------------------------------------------------------------------------------
// Description:
//    Constructor.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
H4RFile::H4RFile (void)
{
  m_NbFile = 0;
}


// ------------------------------------------------------------------------------------------
// H4RFile::H4RFile
// ------------------------------------------------------------------------------------------
// Description:
//    Destructor.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
H4RFile::~H4RFile (void)
{
  destroy();
}


// ------------------------------------------------------------------------------------------
// H4RFile::create
// ------------------------------------------------------------------------------------------
// Description:
//    Memory allocation.
// ------------------------------------------------------------------------------------------
// In:
//    nbFile: number of files
//
// Out:
//
// ------------------------------------------------------------------------------------------
void H4RFile::create (ui32 nbFile)
{
  // Number of file
  m_NbFile = nbFile;

  // Offset
  m_pToExtract = new bool[m_NbFile];
  memset( m_pToExtract,false,m_NbFile * sizeof( bool ));

  // Offset
  m_pOffset = new ui32[m_NbFile];
  memset( m_pOffset,0,m_NbFile * sizeof( ui32 ));

  // Size
  m_pSize = new ui32[m_NbFile];
  memset( m_pSize,0,m_NbFile * sizeof( ui32 ));

  // File type
  m_pDataType = new ui32[m_NbFile];
  memset( m_pDataType,0,m_NbFile * sizeof( ui32 ));

  // File and path size
  m_pNameSize = new ui16[m_NbFile];
  memset( m_pNameSize,0,m_NbFile * sizeof( ui16 ));

  m_pPathSize = new ui16[m_NbFile];
  memset( m_pPathSize,0,m_NbFile * sizeof( ui16 ));

  /// File name and path
  m_ppName = new char*[m_NbFile];
  m_ppPath = new char*[m_NbFile];

  ui32 i;
  for( i=0;i<m_NbFile;i++ )
  {
    m_ppName[i] = new char[MAX_FILENAME_LENGTH];
    m_ppPath[i] = new char[MAX_FILENAME_LENGTH];
  }

  // Pre 1
  m_pPre1 = new ui32[m_NbFile];
  memset( m_pPre1,0,m_NbFile * sizeof( ui32 ));

  // Pre 2
  m_pPre2 = new ui32[m_NbFile];
  memset( m_pPre2,0,m_NbFile * sizeof( ui32 ));

  // Extra 1
  m_pExtra1 = new ui16[m_NbFile];
  memset( m_pExtra1,0,m_NbFile * sizeof( ui16 ));

  // Extra 2
  m_pExtra2 = new ui32[m_NbFile];
  memset( m_pExtra2,0,m_NbFile * sizeof( ui32 ));
}


// ------------------------------------------------------------------------------------------
// H4RFile::destroy
// ------------------------------------------------------------------------------------------
// Description:
//    Destroyer.
// ------------------------------------------------------------------------------------------
// In:
//
// Out:
//
// ------------------------------------------------------------------------------------------
void H4RFile::destroy (void)
{
  if( m_NbFile == 0 )
  {
    return;
  }

  delete[] m_pToExtract;
  delete[] m_pOffset;
  delete[] m_pSize;
  delete[] m_pDataType;
  delete[] m_pNameSize;
  delete[] m_pPathSize;
  ui32 i;
  for( i=0;i<m_NbFile;i++ )
  {
    delete[] m_ppName[i];
    delete[] m_ppPath[i];
  }
  delete[] m_ppName;
  delete[] m_ppPath;
  delete[] m_pPre1;
  delete[] m_pPre2;
  delete[] m_pExtra1;
  delete[] m_pExtra2;

  m_NbFile = 0;
}


// ------------------------------------------------------------------------------------------
// H4RFile::findDataType
// ------------------------------------------------------------------------------------------
// Description:
//    Find the data type of a file from its name.
// ------------------------------------------------------------------------------------------
// In:
//    numFile: file number
//
// Out:
//
// ------------------------------------------------------------------------------------------
void H4RFile::findDataType (ui32 numFile)
{
  char headName[MAX_FILENAME_LENGTH];

  strcpy( headName,m_ppName[numFile] );

  // Extract the head of the file name
  ui32 pt;
  for( pt=0;pt<MAX_FILENAME_LENGTH && headName[pt] != '.';pt++ );
  headName[pt] = '\0';

  ui32 type;
  for( type=0;type<NB_DATATYPE;type++ )
  {
    // We found the correct data type
    if( !strcmp( headName,g_FileDataName[type] ))
    {
      m_pDataType[numFile] = type;
      break;
    }
  }
}


// ------------------------------------------------------------------------------------------
// H4RFile::scan
// ------------------------------------------------------------------------------------------
// Description:
//    Read info in a h4r file.
// ------------------------------------------------------------------------------------------
// In:
//    szH4rFileName: h4r file name
//
// Out:
//    Number of files found
// ------------------------------------------------------------------------------------------
ui32 H4RFile::scan (char *szH4rFileName)
{
  if( !szH4rFileName )
  {
    return 0;
  }

  // Save the h4r file name
  strcpy( m_szH4rFileName,szH4rFileName );

  FILE *h4File;
  h4File = fopen( m_szH4rFileName,"rb" );
  // Impossible to open the file ?
  if( !h4File )
  {
    return 0;
  }

  // Test the header
  ui32 header;
  fread( &header,sizeof( ui32 ),1,h4File );
  // Bad header: not a h4r file
  if( header != H4R_HEADER )
  {
    return 0;
  }

  // Table offset
  ui32 tableOffset;
  fread( &tableOffset,sizeof( ui32 ),1,h4File );
  fseek( h4File,tableOffset,SEEK_SET );

  // Number of files in the h4r file
  ui32 nbFile;
  fread( &nbFile,sizeof( ui32 ),1,h4File );

  // Memory allocation
  create( nbFile );

  bool specialCase;

  ui32 numFile;
  for( numFile=0;numFile<m_NbFile;numFile++ )
  {
    // Offset
    fread( m_pOffset + numFile,sizeof( ui32 ),1,h4File );

    // Size
    fread( m_pSize + numFile,sizeof( ui32 ),1,h4File );

    // Special case ?
    specialCase = ((m_pOffset[numFile] == 0) && (m_pSize[numFile] == 0));

    // Pre 1
    fread( m_pPre1 + numFile,sizeof( ui32 ),1,h4File );

    // Pre 2
    fread( m_pPre2 + numFile,sizeof( ui32 ),1,h4File );

    // Name
    fread( m_pNameSize + numFile,sizeof( ui16 ),1,h4File );
    if( m_pNameSize[numFile] > 0 )
    {
      fread( m_ppName[numFile],sizeof( ui8 ),m_pNameSize[numFile],h4File );
    }
    m_ppName[numFile][m_pNameSize[numFile]] = '\0';

    // With the file name, we find the data type
    findDataType( numFile );

    // Path
    fread( m_pPathSize + numFile,sizeof( ui16 ),1,h4File );
    if( m_pPathSize[numFile] > 0 )
    {
      fread( m_ppPath[numFile],sizeof( ui8 ),m_pPathSize[numFile],h4File );
    }
    m_ppPath[numFile][m_pPathSize[numFile]] = '\0';

    if( !specialCase )
    {
      // Extra 1
      fread( m_pExtra1 + numFile,sizeof( ui16 ),1,h4File );

      // Extra 2
      fread( m_pExtra2 + numFile,sizeof( ui32 ),1,h4File );
    }
    else
    {
      // Special case: we read another file name
      ui16 length;
      fread( &length,sizeof( ui16 ),1,h4File );
      fseek( h4File,length + sizeof( ui32 ),SEEK_CUR );
    }
  }

  fclose( h4File );

  return nbFile;
}


// ------------------------------------------------------------------------------------------
// H4RFile::checkFileToExtract
// ------------------------------------------------------------------------------------------
// Description:
//    Check files to extract.
// ------------------------------------------------------------------------------------------
// In:
//    pDataTypeToExtract: data type to extract from the file
//
// Out:
//    Number of files to extract
// ------------------------------------------------------------------------------------------
ui32 H4RFile::checkFileToExtract (ui32 *pDataTypeToExtract)
{
  ui32 numFileToExtract = 0;

  bool *pToExtract = m_pToExtract;

  ui32 numFile,i;
  for( numFile=0;numFile<m_NbFile;numFile++,pToExtract++ )
  {
    *pToExtract = false;
    for( i=0;i<NB_DATATYPE && !(*pToExtract);i++ )
    {
      *pToExtract = ((m_pDataType[numFile] == pDataTypeToExtract[i]) || (pDataTypeToExtract[i] == H4R_ALL));
    }

    if( *pToExtract )
    {
      numFileToExtract++;
    }
  }

  return numFileToExtract;
}


// ------------------------------------------------------------------------------------------
// H4RFile::extract
// ------------------------------------------------------------------------------------------
// Description:
//    Extract files from a h4r file.
// ------------------------------------------------------------------------------------------
// In:
//    srcFile            : source file
//    numFile            : number of the file to extract
//    szDirName          : directory
//    szExtractedFileName: file name of the extracted file
//
// Out:
//    Error ?
// ------------------------------------------------------------------------------------------
bool H4RFile::extract (FILE *srcFile,ui32 numFile,char *szDirName,char *szExtractedFileName)
{
  if( !srcFile || numFile >= m_NbFile || m_pSize[numFile] == 0 || !m_pToExtract[numFile] )
  {
    return false;
  }

  // Extracted file name
  strcpy( szExtractedFileName,szDirName );
  strcat( szExtractedFileName,m_ppName[numFile] );

  // We remove the suffix ".h4d"
  removeFileNameSuffix( szExtractedFileName );

  // Bink files are not zipped
  bool bUnzip;
  if( m_pDataType[numFile] == H4R_BINK )
  {
    strcat( szExtractedFileName,g_FileDataSuffix[m_pDataType[numFile]] );
    bUnzip = false;
  }
  else
  {
    bUnzip = true;
  }

  FILE *destFile;
  destFile = fopen( szExtractedFileName,"wb" );
  // Impossible to open the file ?
  if( !destFile )
  {
    return false;
  }

  // Our buffer
  ui8 buffer[BUFFER_SIZE];

  fseek( srcFile,m_pOffset[numFile],SEEK_SET );

  ui32 countSize = 0;

  while( countSize < m_pSize[numFile] )
  {
    ui32 bufferSize;
    if( countSize + BUFFER_SIZE > m_pSize[numFile] )
    {
      bufferSize = m_pSize[numFile] - countSize;
    }
    else
    {
      bufferSize = BUFFER_SIZE;
    }

    ui32 bufferReadSize = fread( buffer,sizeof( ui8 ),bufferSize,srcFile );
    fwrite( buffer,sizeof( ui8 ),bufferReadSize,destFile );

    countSize += bufferSize;
  }

  fclose( destFile );

  // For unzipped files, we stop here
  if( !bUnzip )
  {
    return true;
  }

  char szH4dFileName[MAX_FILENAME_LENGTH];
  strcpy( szH4dFileName,szExtractedFileName );
  // Add suffix
  strcat( szExtractedFileName,g_FileDataSuffix[m_pDataType[numFile]] );

  if( m_pDataType[numFile] == H4R_GAME_MAPS )
  {
    // For this file type, we have to delete the first 16 bytes of the h4d file
    unzipFile( szH4dFileName,szExtractedFileName,16 );
  }
  else
  {
    // Unzip the file
    unzipFile( szH4dFileName,szExtractedFileName,0 );
  }

  // Delete the h4d file
  unlink( szH4dFileName );

  return true;
}


// ------------------------------------------------------------------------------------------
// H4RFile::dump
// ------------------------------------------------------------------------------------------
// Description:
//    Write a dump file with all selected files info.
// ------------------------------------------------------------------------------------------
// In:
//    szDirName: directory
//
// Out:
//    Error ?
// ------------------------------------------------------------------------------------------
bool H4RFile::dump (char *szDirName)
{
  if( !szDirName )
  {
    return false;
  }

  char szFileName[MAX_FILENAME_LENGTH],szH4rFileName[MAX_FILENAME_LENGTH];
  strcpy( szFileName,szDirName );
  strcpy( szH4rFileName,m_szH4rFileName );
  getFileName( szH4rFileName );
  strcat( szFileName,szH4rFileName );
  removeFileNameSuffix( szFileName );
  strcat( szFileName,".log" );

  FILE *dumpFile = fopen( szFileName,"wt" );
  // Impossible to open the file ?
  if( !dumpFile )
  {
    return false;
  }

  fprintf( dumpFile,"mh4 dump file of the h4r file %s (%d files)\n\n\n",m_szH4rFileName,m_NbFile );

  for( ui32 numFile=0;numFile<m_NbFile;numFile++ )
  {
    fprintf( dumpFile,"[File %d]\nName=%s\nPath=%s\nType=%s\nOffset=%d\nSize=%d\nPre1=%d\nPre2=%d\nExtra1=%d\nExtra2=%d\n\n",numFile+1,m_ppName[numFile],m_ppPath[numFile],g_FileDataName[m_pDataType[numFile]],m_pOffset[numFile],m_pSize[numFile],m_pPre1[numFile],m_pPre2[numFile],m_pExtra1[numFile],m_pExtra2[numFile] );
  }

  fprintf( dumpFile,"\n[End]" );
  fclose( dumpFile );

  return true;
}


// ------------------------------------------------------------------------------------------
// H4RFile::scanList
// ------------------------------------------------------------------------------------------
// Description:
//    Scan the header of a file list.
// ------------------------------------------------------------------------------------------
// In:
//    szLstFileName: lst file name
//    szDirName    : directory
//    tableSize    : size of the file table (updated)
//
// Out:
//    lst file (with the file pointer just after the header)
// ------------------------------------------------------------------------------------------
FILE *H4RFile::scanList (char *szLstFileName,char *szDirName,ui32 *tableSize)
{
  FILE *lstFile = fopen( szLstFileName,"rt" );
  // Impossible to open the file ?
  if( !lstFile )
  {
    return NULL;
  }

  char szLine[MAX_FILENAME_LENGTH];

  // Header
  fgets( szLine,MAX_FILENAME_LENGTH,lstFile );
  if( strcmp( szLine,"[H4R File List]\n" ))
  {
    // Bad header
    return NULL;
  }

  // h4r file name
  fgets( szLine,MAX_FILENAME_LENGTH,lstFile );
  ui32 length = strlen( szLine );
  // Remove the '\n'
  if( length > 0 && szLine[length - 1] == '\n' )
  {
    szLine[length - 1] = '\0';
  }

  // We add the path
  strcpy( m_szH4rFileName,szDirName );
  strcat( m_szH4rFileName,szLine );

  // Number of files
  fgets( szLine,MAX_FILENAME_LENGTH,lstFile );
  ui32 nbFile = atoi( szLine );

  // Memory allocation
  create( nbFile );

  *tableSize = 12;

  return lstFile;
}


// ------------------------------------------------------------------------------------------
// H4RFile::scanBuild
// ------------------------------------------------------------------------------------------
// Description:
//    Scan a lst file to build a h4r file, zip the file and prepare the build of the header.
// ------------------------------------------------------------------------------------------
// In:
//    lstFileName: lst file
//    numFile    : file number
//    szDirName  : directory
//    tableSize  : size of the file table (updated)
//
// Out:
//    h4r file (with the file pointer just after the header)
// ------------------------------------------------------------------------------------------
bool H4RFile::scanBuild (FILE *lstFile,ui32 numFile,char *szDirName,ui32 *tableSize)
{
  if( !lstFile || feof( lstFile ) || numFile >= m_NbFile )
  {
    return false;
  }

  char fileName[MAX_FILENAME_LENGTH],temp1[MAX_FILENAME_LENGTH],temp2[MAX_FILENAME_LENGTH];

  // Read file name
  fgets( fileName,MAX_FILENAME_LENGTH,lstFile );
  ui32 length = strlen( fileName );
  // Remove the '\n'
  if( length > 0 && fileName[length - 1] == '\n' )
  {
    fileName[length - 1] = '\0';
  }

  // This is the end ...
  if( !strcmp( fileName,"[End]" ))
  {
    m_NbFile = numFile;
    return true;
  }

  strcpy( m_ppName[numFile],fileName );
  removeFileNameSuffix( m_ppName[numFile] );
  strcat( m_ppName[numFile],".h4d" );
  m_pNameSize[numFile] = strlen( m_ppName[numFile] );

  findDataType( numFile );

  // No path
  m_ppPath[numFile][0]  = '\0';
  m_pPathSize[numFile] = 0;

  // We add the path
  strcpy( temp1,szDirName );
  strcat( temp1,fileName );
  strcpy( temp2,szDirName );
  strcat( temp2,m_ppName[numFile] );

  bool bZip = (m_pDataType[numFile] != H4R_BINK);

  if( bZip )
  {
    // We zip the file
    if( m_pDataType[numFile] == H4R_GAME_MAPS )
    {
      // Special case: we add 16 byte
      m_pSize[numFile] = zipFile( temp1,temp2,16 );
    }
    else
    {
      m_pSize[numFile] = zipFile( temp1,temp2,0 );
    }
  }
  else
  {
    m_pSize[numFile] = copyFile( temp1,temp2 );
  }

  if( numFile == 0 )
  {
    m_pOffset[numFile] = 0;
  }
  else
  {
    m_pOffset[numFile] = m_pOffset[numFile - 1] + m_pSize[numFile - 1];
  }

  *tableSize += 26 + m_pNameSize[numFile] + m_pPathSize[numFile];

  return true;
}


// ------------------------------------------------------------------------------------------
// H4RFile::headerBuild
// ------------------------------------------------------------------------------------------
// Description:
//    Build the header of a h4r file.
// ------------------------------------------------------------------------------------------
// In:
//    tableSize: size of the file table
//
// Out:
//    h4r build file (with file pointer after the header)
// ------------------------------------------------------------------------------------------
FILE *H4RFile::headerBuild (int tableSize)
{
  FILE *h4rFile = fopen( m_szH4rFileName,"wb" );
  if( !h4rFile )
  {
    return NULL;
  }

  // Write header
  ui32 header = H4R_HEADER;
  fwrite( &header,sizeof( ui32 ),1,h4rFile );

  // Write table offset: the table begin just after the header
  ui32 tableOffset = 8;
  fwrite( &tableOffset,sizeof( ui32 ),1,h4rFile );

  // Write the number of files
  fwrite( &m_NbFile,sizeof( ui32 ),1,h4rFile );

  for( ui32 numFile=0;numFile<m_NbFile;numFile++ )
  {
    // Add the table size to the offset
    m_pOffset[numFile] += tableSize;

    fwrite( m_pOffset + numFile,sizeof( ui32 ),1,h4rFile );
    fwrite( m_pSize + numFile,sizeof( ui32 ),1,h4rFile );

    fwrite( m_pPre1 + numFile,sizeof( ui32 ),1,h4rFile );
    fwrite( m_pPre2 + numFile,sizeof( ui32 ),1,h4rFile );

    fwrite( m_pNameSize + numFile,sizeof( ui16 ),1,h4rFile );
    fwrite( m_ppName[numFile],sizeof( char ),m_pNameSize[numFile],h4rFile );

    fwrite( m_pPathSize + numFile,sizeof( ui16 ),1,h4rFile );
    fwrite( m_ppPath[numFile],sizeof( char ),m_pPathSize[numFile],h4rFile );

    fwrite( m_pExtra1 + numFile,sizeof( ui16 ),1,h4rFile );
    fwrite( m_pExtra2 + numFile,sizeof( ui32 ),1,h4rFile );
  }

  return h4rFile;
}


// ------------------------------------------------------------------------------------------
// H4RFile::dataBuild
// ------------------------------------------------------------------------------------------
// Description:
//    Build a h4r file from a lst file.
// ------------------------------------------------------------------------------------------
// In:
//    h4rFile  : h4r file 
//    numFile  : file number to build
//    szDirName: directory
//
// Out:
//    Error ?
// ------------------------------------------------------------------------------------------
bool H4RFile::dataBuild (FILE *h4rFile,ui32 numFile,char *szDirName)
{
  if( !h4rFile || !szDirName || numFile >= m_NbFile )
  {
    return false;
  }

  // Our buffer
  ui8 buffer[BUFFER_SIZE];

  char fileName[MAX_FILENAME_LENGTH];

  // Write data
  strcpy( fileName,szDirName );
  strcat( fileName,m_ppName[numFile] );

  FILE *h4dFile = fopen( fileName,"rb" );
  // Impossible to open the file ?
  if( !h4dFile )
  {
    return false;
  }

  ui32 countSize=0;
  while( countSize < m_pSize[numFile] )
  {
    ui32 bufferSize;
    if( countSize + BUFFER_SIZE > m_pSize[numFile] )
    {
      bufferSize = m_pSize[numFile] - countSize;
    }
    else
    {
      bufferSize = BUFFER_SIZE;
    }

    ui32 bufferReadSize = fread( buffer,sizeof( ui8 ),bufferSize,h4dFile );
    fwrite( buffer,sizeof( ui8 ),bufferReadSize,h4rFile );

    countSize += bufferSize;
  }

  fclose( h4dFile );

  // Delete the h4d file
  unlink( fileName );

  return true;
}