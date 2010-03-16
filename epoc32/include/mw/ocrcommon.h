/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  APIs of the OCR(Optical Character Recognition), current engine
*                can recognize 24 bit colored image and 8 bit gray scale image
*                in BMP format.
*
*
*/


#ifndef OCRCOMMON_H
#define OCRCOMMON_H
 
// INCLUDE FILES
#include <e32std.h>
#include <e32def.h>
#include <e32base.h>

/** 
* Bad image or unsupported format 
*/
const TInt KErrOcrBadImage (-1001);     

/** 
* Unsupported language 
*/ 
const TInt KErrOcrBadLanguage (-1002);      

/**
* Bad layout region
*/ 
const TInt KErrOcrBadRegion (-1003);      

/**
* Not set any language
*/ 
const TInt KErrOcrNotSetLanguage (-1004);      

/**
* Not set any language packages
*/ 
const TInt KErrOcrBadDictFile (-1005);      

/** Type of the text layouts 
*/
enum TOcrLayoutType
    {
    /** Texts in the block is horizontal 
    */
    EOcrLayoutTypeH,
    
    /** Texts in the block is vertical 
    */
    EOcrLayoutTypeV
    };

/** Type of the text 
*/
enum TOcrTextType   
    {
    /** when the image or recognition area has multi-line format 
    */
    EOcrTextMultiLine,
    
    /** when the image or recognition area has single-line format 
    */
    EOcrTextSingleLine
    };

/** Type of the text background 
*/
enum TOcrBackgroundType
    {
    /** light character with light background 
    */
    EOcrBackgroundLight,
    
    /** dark character with dark background 
    */
    EOcrBackgroundDark,
    
    /** un-suspected background 
    */
    EOcrBackgroundUnknown
    };
    
/**
 *  OCR (Optical Character Recognition) Text Line Information
 *
 *  This class holds the information from the OCR engine after the recognition
 *  Note that all memory ownership belongs to the OCR engine, so do not need to
 *  either allocate memory for it or push it to the CleanupStack. Engine will 
 *  release the memory whenever necessary
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */        
class TOCRTextLineInfo
    {
public:    

    /**
    * Text buffer for the line. Note that after layout analysis, this is NULL
    * and the buffer will be filled after recognition (Not Own)
    */
    HBufC16* iText;
    
    /**
    * Region coordinate to be processed
    */
    TRect iRect;

    /**
    * Array of the character rects. (Not Own)
    */
    TRect* iCharRect;
    
    /**
    * Number of characters
    */
    TInt iCharCount;
    };

/**
 *  OCR (Optical Character Recognition) Text Line Information
 *
 *  This class holds the information from the layout analysis, the engine
 *  will allocate the memory of TOCRBlockInfo array, and pass the ownership
 *  to you while you can remove it by delete[]
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */      
class TOCRBlockInfo
    {
public:
    
    /**
    * Region coordinate to be processed
    */
    TRect iRect;
    
    /**
    * Layout Type (Horizontal or Vertical)
    */
    TOcrLayoutType iType;
    
    /**
    * Id of the block
    */
    TInt iBlockId;
    };

/**
 *  OCR (Optical Character Recognition) Text Block Information
 *
 *  This class holds the information from the OCR engine after the recognition
 *  Note that all memory ownership belongs to the OCR engine, so do not need to
 *  either allocate memory for it or push it to the CleanupStack. Engine will 
 *  release the memory whenever necessary
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */   
class TOCRTextRgnInfo
    {
public:

    /**
    * Region coordinate to be processed
    */
    TRect iRect;
    
    /**
    * Layout Type (Horizontal or Vertical)
    */
    TOcrLayoutType iType;
    
    /**
    * Id of the block
    */
    TInt iBlockId;

    /**
    * Text line Information (Not Own)
    */
    TOCRTextLineInfo* iLines;
    
    /**
    * Number of Lines
    */
    TInt iLineCount;
    };

/**
 *  OCR (Optical Character Recognition) Setting for Layout Analysis
 *
 *  The setting for layout analysis
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */   
class TOCRLayoutSetting
    {
public:

    /** 
    * Image brightness 
    */
    enum TOcrBrightness
        {  
        ENormal, ///< brightness is normal
        ELight,  ///< brightness is light
        EDark    ///< brightness is dark
        };

    /**
    * Whether skew adjustment enabled, in most cases
    * this flag shall be always on; But if images are in
    * very good contition, this flag can be off to increase
    * the recognition speed
    */
    TBool iSkew;
    
    /**
    * Brightness for text background
    */
    TOcrBrightness iBrightness;
    };

/**
 *  OCR (Optical Character Recognition) Setting for Recognize (Reserved)
 *
 *  The setting for recognition
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */ 
class TOCRRecognizeSetting
    {
public:

    /** 
    * Reserved for future use
    */
    TAny* iAny;
    };

/**
 *  OCR (Optical Character Recognition) Block Information for Recognizing Blocks
 *
 *  This class is for recognizing blocks. @see MOCREngineRecognizeBlock::RecognizeBlockL 
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */ 
class TOCRLayoutBlockInfo
    {
public:
    
    /**
    * Region coordinate to be processed
    */
    TRect iRect;
    
    /**
    * Layout Type (Horizontal or Vertical)
    */
    TOcrLayoutType iLayout;
    
    /**
    * Text Type (Multi or Single line)
    */
    TOcrTextType iText;
    
    /**
    * Brightness for text background
    */
    TOcrBackgroundType iBackgroundColor;
    };

/**
 *  OCR (Optical Character Recognition) Block Information for Recognizing Blocks
 *
 *  This class is for recognizing blocks. @see MOCREngineRecognizeBlock::RecognizeSpecialRegionL
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */ 
class TRegionInfo
    {
public:
    
    /** 
    * Content Type 
    */
    enum TOcrRegionType
        {
        EEmailAddress,     ///< E-mail address
        ETelephoneNumber,  ///< telephone number
        EWWWAddress        ///< website address
        };

public:            
    /**
    * Region coordinate to be processed
    */
    TRect iRect;
    
    /** 
    * Brightness for text background
    */
    TOcrBackgroundType iBackgroundColor;
    
    /**
    * Content Type
    */
    TOcrRegionType iType;
    };

/**
 *  OCR (Optical Character Recognition) Engine Environment Settings
 *
 *  This class is for setting the thread priority and the maximum heap
 *  allocation for the ocr engine
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */     
class TOcrEngineEnv
    {
public:
    /**
    * Thread priority. The Engine Factory will create a child thread
    * for the OCR process, EPriorityLess is recommended for most cases
    */
    TThreadPriority iPriority;
    
    /**
    * The maximum heap size for the OCR process, must be larger than
    * KMinHeapGrowBy x 1200 to do recognition for 1600x1200 images. If
    * this value is lower(equal) than KMinHeapGrowBy*1000, a leave will
    * happen in CreateOCREngineL with KErrArgument
    */
    TInt iMaxHeapSize;
    };    

#endif // OCRCOMMON_H

// End of file
