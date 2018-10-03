/*
 * mh4
 * Heroes of Might and Magic IV Ressources Explorer and Modifier
 *
 * Author: Olivier Soares
 * olivier@etranges-libellules.fr
 *
 */


#ifndef __MH4_H__
#define __MH4_H__


#include <stdio.h>


#define MH4_DESC "mh4 v0.06"


#ifndef ui8
#define ui8  unsigned char
#endif
#ifndef ui16
#define ui16 unsigned short
#endif
#ifndef ui32
#define ui32 unsigned int
#endif


// Size of our buffer
#define BUFFER_SIZE 0x8000

// Max file length (with path)
#define MAX_FILENAME_LENGTH 256


// Data types
#define NB_DATATYPE 20
enum DATATYPE
{
  H4R_UNKNOWN = 0,                               // Unknown data

  // Default h4r types
  H4R_ACTOR_SEQUENCE,                            // Sprite animation
  H4R_ADV_ACTOR,                                 // Hero sprite
  H4R_ADV_OBJECT,                                // Object sprite
  H4R_ANIMATION,                                 // Animation
  H4R_BATTLEFIELD_PRESET_MAP,                    // ???
  H4R_BITMAP_RAW,                                // Image
  H4R_BINK,                                      // Movie
  H4R_CASTLE,                                    // ???
  H4R_COMBAT_ACTOR,                              // ???
  H4R_COMBAT_HEADER_TABLE_CACHE,                 // ???
  H4R_COMBAT_OBJECT,                             // ???
  H4R_FONT,                                      // Font
  H4R_GAME_MAPS,                                 // Map (campaign or tutorial)
  H4R_LAYERS,                                    // ???
  H4R_SOUND,                                     // Music or sound
  H4R_STRINGS,                                   // Text
  H4R_TABLE,                                     // Text
  H4R_TERRAIN,                                   // ???
  H4R_TRANSITION,                                // ???

  // New h4r types
  H4R_ALL,
  H4R_NOTHING
};


// All info concerning a h4r file
class H4RFile
{
  public:
    char m_szH4rFileName[MAX_FILENAME_LENGTH];   // h4r file name
    ui32 m_NbFile;                               // Number of files
    bool *m_pToExtract;                          // Extract file ?
    ui32 *m_pOffset;                             // Offsets array
    ui32 *m_pSize;                               // Sizes array
    ui32 *m_pDataType;                           // File types array
    ui16 *m_pNameSize;                           // Size of the name
    char **m_ppName;                             // File names array
    ui16 *m_pPathSize;                           // Size of the path
    char **m_ppPath;                             // File paths array
    ui32 *m_pPre1;                               // Pre-datas array
    ui32 *m_pPre2;
    ui16 *m_pExtra1;                             // Extra info array
    ui32 *m_pExtra2;

  public:
    H4RFile (void);
    ~H4RFile (void);
    void create (ui32 nbFile);
    void destroy (void);
    void findDataType (ui32 numFile);
    ui32 scan (char *szH4rFileName);
    ui32 checkFileToExtract (ui32 *pDataTypeToExtract);
    bool extract (FILE *srcFile,ui32 numFile,char *szDirName,char *szExtractedFileName);
    bool dump (char *szDirName);
    FILE *scanList (char *szLstFileName,char *szDirName,ui32 *tableSize);
    bool scanBuild (FILE *lstFile,ui32 numFile,char *szDirName,ui32 *tableSize);
    FILE *headerBuild (int tableSize);
    bool dataBuild (FILE *h4rFile,ui32 numFile,char *szDirName);
};


// h4r header
#define H4R_HEADER 0x5523448


// Gzip suffixes
#define GZ_SUFFIX ".gz"
#define GZ_SUFFIX_LENGTH 3
#define GUZ_SUFFIX ".ugz"


// Other tool functions
extern void removeFileNameSuffix (char *szFileNameWithSuffix);
extern void getFilePath (char *szFileNameWithPath);
extern void getFileName (char *szFileNameWithPath);
extern ui32 getFileSize (char *szFileName );
extern ui32 copyFile (char *szSrcFileName,char *szDestFileName);
extern ui32 zipFile (char *szFileName,char *szZippedFileName,ui32 sizeToAdd);
extern ui32 unzipFile (char *szFileName,char *szUnzippedFileName,ui32 sizeToDelete);


// File type name and suffix
extern char *g_FileDataName[];
extern char *g_FileDataSuffix[];


#endif // __MH4_H__