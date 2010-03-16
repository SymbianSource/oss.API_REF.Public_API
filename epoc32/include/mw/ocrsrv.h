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
*                in BMP format.And the size of images are also limited within
*                1600x1200 in pixel
*
*
*/

 
#ifndef OCRSRV_H
#define OCRSRV_H

//  INCLUDE FILES
#include <ocrcommon.h>

//  Constants

//class declaration
class OCREngineFactory;

/**
 *  OCR (Optical Character Recognition) Engine Observer
 *
 *  This set of interfaces defines the observers of the OCR engine. This is the unique set
 *  for all types of engines. User needs to implement a concrete class which is derived from
 *  this class.
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class MOCREngineObserver  
    {
    public:    
        /**
         * This interface will be called after the Block Recognition is completed. This calling
         * only valid when using the EEngineRecognizeBlock type of engine   
         * @see OCREngineFactory::TEngineType
         * @see MOCREngineRecognizeBlock
         *
         * @since S60 3.1
         * @param aError Error code to indicate the completion status
         * @param aBlocks Pointer to the text information of the recognized image block, Please note
                         that the memory ownership belongs to the OCR engine and will not be passed
                         to your procedure after this calling
         * @param aBlockCount Number of block identified
         * @return None
         */  
        virtual void RecognizeBlockComplete(TInt aError, 
                                            const TOCRTextRgnInfo* aBlocks, 
                                            const TInt aBlockCount) = 0;
        
        /**
         * This interface will be called after the Special Region Recognition is completed. This calling
         * only valid when using the EEngineRecognizeBlock type of engine   
         * @see OCREngineFactory::TEngineType
         * @see MOCREngineRecognizeBlock 
         *
         * @since S60 3.1
         * @param aError Error code to indicate the completion status
         * @param aBlocks Pointer to the text information of the recognized image block, Please note
                         that the memory ownership belongs to the OCR engine and will not be passed
                         to your procedure after this calling
         * @param aBlockCount Number of block identified
         * @return None
         */  
        virtual void RecognizeSpecialRegionComplete(TInt aError, 
                                                    const TOCRTextRgnInfo* aBlocks, 
                                                    const TInt aBlockCount) = 0;
     
        /**
         * This interface will be called after the Full Image Recognition is completed. This calling
         * only valid when using the EEngineLayoutRecognize type of engine   
         * @see OCREngineFactory::TEngineType
         * @see MOCREngineLayoutRecognize
         *
         * @since S60 3.1
         * @param aError Error code to indicate the completion status
         * @param aBlocks Pointer to the text information of the recognized image block, Please note
                         that the memory ownership belongs to the OCR engine and will not be passed
                         to your procedure after this calling
         * @param aBlockCount Number of block identified
         * @return None
         */
        virtual void RecognizeComplete(TInt aError, 
                                       const TOCRTextRgnInfo* aBlocks, 
                                       const TInt aBlockCount) = 0;

        /**
         * This interface will be called after the Full Image Layout Analysis is completed. This calling
         * only valid when using the EEngineLayoutRecognize type of engine  
         * @see OCREngineFactory::TEngineType
         * @see MOCREngineLayoutRecognize
         *
         * @since S60 3.1
         * @param aError Error code to indicate the completion status
         * @param aBlocks Pointer to the text information of the recognized image block, Please note
                         that the memory ownership belongs to the OCR engine and will not be passed
                         to your procedure after this calling
         * @param aBlockCount Number of block identified
         * @return None
         */
        virtual void LayoutComplete(TInt aError, 
                                    const TOCRBlockInfo* aBlocks, 
                                    const TInt aBlockCount) = 0;

        /**
         * This interface will be called during the procession and indicates the progress.
         *
         * @since S60 3.1
         * @param aPercent A percentage of the current progression
         * @return None
         */
        virtual void RecognizeProcess(const TUint aPercent) = 0;
    };


/**
 *  OCR (Optical Character Recognition) Engine Base
 *
 *  Base class of the OCR engine, this offers definitions of the features which
 *  all engines shall give support
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class MOCREngineBase  
    {
    public:
    
        /**
         * Get the current version of the OCR interfaces
         *
         * @since S60 3.1
         * @return Current version
         */
        virtual TVersion GetVersion() const = 0;

        /**
         * This interface refreshes the installed language packages. The OCR engine
         * supports the languages to be installed as SIS packages and can be installed
         * or uninstalled dynamically. This method shall be called after changes made
         * on the installed language packages
         *
         * @leave KErrNotFound No OCR engine found
         * @since S60 3.1
         * @return None
         */
        virtual void RefreshInstalledLanguageL() = 0;

        /**
         * This method sets the languages for the recognition, maximum 2 languages can
         * be passed together, regardless of their position in the array
         *
         * @since S60 3.1         
         * @param aActiveLanguage Array of specified languages @see GetInstalledLanguage
         * @return None
         *
         * @leave KErrArgument Language count is more than two
         * @leave KErrNotSupported The language is not supported by current OCR engine
         * @leave KErrOcrBadLanguage Unsupported language
         * @leave KErrOcrBadDictFile Not set any language packages
         */
        virtual void SetActiveLanguageL(const RArray<TLanguage>& aActiveLanguage) = 0;

        /**
         * This method gets the languages which are currently installed and supported
         *
         * @since S60 3.1         
         * @param aLanguages Array of installed languages @see SetActiveLanguageL
         * @return None
         */
        virtual void GetInstalledLanguage(RArray<TLanguage>& aLanguages) const = 0;

        /**
         * This method cancels the recognition
         * Call to this method the process will be terminated, and a KErrCancel flag
         * will be passed to MOCREngineObserver's observers and through the aError
         * parameter. Call this method when the engine is not working will not take
         * any effect, this method internally calls IsEngineActive method 
         * @see MOCREngineObserver
         *
         * @since S60 3.1         
         * @return None
         */
        virtual void CancelOperation() = 0;

        /**
         * This method judges whether a language is supported
         *
         * @since S60 3.1 
         * @param aLanguage A language specifed    
         * @return ETrue if supported; EFalse otherwise
         */
        virtual TBool IsLanguageSupported(const TLanguage aLanguage) = 0;
        
        /**
         * This method tests whether the engine is working or not
         * Typically you could call this method to test whether there is
         * an outstanding request or not.
         * Note that when you are trying to exit the application when
         * there's an outstanding issue, you should first call this method
         * and call CancelOperation method before really terminate the 
         * client application
         *
         * @since S60 3.1  
         * @return ETrue if the engine is working; EFalse otherwise
         */
         virtual TBool IsEngineActive() const = 0;
    };


/**
 *  OCR (Optical Character Recognition) Engine Interface Base
 *
 *  Base interfaces for the OCR engine, all engines derived from this class
 *  User can access base features from Base method
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class MOCREngineInterface
    {
    public:
    
        /**
         * This method gets the MOCREngineBase interface, user can access base features
         * from this method
         *
         * @since S60 3.1 
         * @return Pointer to the engine base @see MOCREngineBase
         */
        virtual MOCREngineBase* Base() const = 0;
        
        /**
        * Virtual destructor
        */
        virtual ~MOCREngineInterface() { };
    };


/**
 *  OCR (Optical Character Recognition) Engine Interfaces with Layout Analysis
 *
 *  This set of interfaces offers the OCR engine which supports Layout Analysis
 *  on full images. User shall pass the handle of the image through LayoutAnalysisL
 *  first, and then pass block ids to RecognizeL to complete the recognition.
 *  
 *  For Example:
 *  After passing the image handle to LayoutAnalysisL, the MOCREngineObserver::LayoutComplete
 *  will be called after the process. Then through the TOCRBlockInfo array (const TOCRBlockInfo* aBlock
 *  and const TInt aBlockCount), the user knows how many blocks have been identified 
 *  together with their position information. Those blocks are marked with ids from Zero to 
 *  aBlockCount - 1. 
 *
 *  Then the user must specify which blocks are going to be further processed (Note that layout analysis
 *  only gets you the position of those blocks, but does not recognize the characters inside each block).
 *  The const RArray<TInt>& aBlock in MOCREngineLayoutRecognize::RecognizeL saves all the ids that are
 *  selected to be further processed. e.g. if you have 10 blocks from LayoutComplete, you can append 
 *  1, 3, 5, 7 to the TInt array and pass it to RecognizeL
 *
 *  Note that this class shall be used together with TEngineType set to EEngineLayoutRecognize
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class MOCREngineLayoutRecognize : public MOCREngineInterface
    { 
    public:
    
        /**
         * This method does the layout analysis for the full image
         *
         * @since S60 3.1         
         * @param aBitmapHandle Handle of the image(get from CFbsBitmap::Handle())
         * @param aSettings Settings for layout analysis @see TOCRLayoutSetting
         * @return None
         *
         * @leave KErrNotSupported Image shall be in BMP format (24bit colored or 8 bit grayscale) 
         * and the size shall not exceed 1600x1200 in pixel 
         * @leave KErrNotReady Internal object is not constructed
         * @leave KErrAbort Child thread does not exist or operation is aborted
         * @leave KErrServerBusy OCR service is busy
         */
        virtual void LayoutAnalysisL(const TInt aBitmapHandle, 
                                     const TOCRLayoutSetting aSettings) = 0;

        /**
         * This method does the character recognition for the image on base of the result from 
         * LayoutAnalysisL
         *
         * @since S60 3.1         
         * @param aSettings Settings for recognition
         * @param aBlockIdsToRecognize Block Ids to be recognized
         * @return None
         *
         * @leave KErrNotReady Internal object is not constructed
         * @leave KErrAbort Child thread does not exist or operation is aborted
         * @leave KErrArgument Bolck information is available        
         * 
         */
        virtual void RecognizeL(const TOCRRecognizeSetting aSettings, 
                                const RArray<TInt>& aBlockIdsToRecognize) = 0;
    };

/**
 *  OCR (Optical Character Recognition) Engine Interfaces without Layout Analysis
 *
 *  This set of interfaces offers the OCR engine which does not support Layout Analysis
 *  on full images. User shall implement their own layout solution
 *  
 *  RecognizeBlockL recognizes text information in a single block area regardless of content
 *
 *  RecognizeSpecialRegionL recognizes text information in a single block area and its content
 *  sensitive. User can select three different types of contents: e-mail address, phone numbers
 *  or web addresses @see TRegionInfo
 *
 *  Note that this class shall be used together with TEngineType set to EEngineRecognizeBlock
 *
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class MOCREngineRecognizeBlock : public MOCREngineInterface
    {
    public:
    
        /**
         * This method recognizes text in a single block
         *
         * @since S60 3.1         
         * @param aBitmapHandle Handle of the image(get from CFbsBitmap::Handle())
         * @param aLayoutInfo Block information
         * @return None
         *
         * @leave KErrNotSupported Image shall be in BMP format (24bit colored or 8 bit grayscale) 
         * and the size shall not exceed 1600x1200 in pixel 
         * @leave KErrNotReady Internal object is not constructed
         * @leave KErrAbort Child thread does not exist or operation is aborted         
         * @leave KErrCouldNotConnect No connection to the font and bitmap server could be made 
         * @leave KErrUnknown No bitmap could be found with the specified handle number
         * @leave KErrArgument aRegionInfo is available
         * @leave KErrServerBusy OCR service is busy 
         */
        virtual void RecognizeBlockL(const TInt aBitmapHandle, 
                                     const TOCRLayoutBlockInfo aLayoutInfo) = 0;

        /**
         * This method recognizes text with special content in a single block
         *
         * Note that SetActiveLanguageL has to be called first and language must be set to TLanguage::ELangEnglish
         *
         * @since S60 3.1         
         * @param aBitmapHandle Handle of the image(get from CFbsBitmap::Handle())
         * @param aRegionInfo Block information
         * @return None
         *
         * @leave KErrNotSupported Image shall be in BMP format (24bit colored or 8 bit grayscale) 
         * and the size shall not exceed 1600x1200 in pixel 
         * @leave KErrNotReady Internal object is not constructed
         * @leave KErrAbort Child thread does not exist or operation is aborted         
         * @leave KErrCouldNotConnect No connection to the font and bitmap server could be made 
         * @leave KErrUnknown No bitmap could be found with the specified handle number
         * @leave KErrArgument aRegionInfo is available
         * @leave KErrServerBusy OCR service is busy 
         */
        virtual void RecognizeSpecialRegionL(const TInt aBitmapHandle, 
                                             const TRegionInfo aRegionInfo) = 0;
    };

/**
 *  OCR (Optical Character Recognition) API
 *
 *  This static class offers the OCR APIs. The user shall call CreateOCREngineL
 *  and get the instance of one type of the OCR engine and then convert the instance
 *  from MOCREngineInterface to MOCREngineLayoutRecognize or MOCREngineRecognizeBlock 
 *  according to the type information. And use ReleaseOCREngine to destroy the engine.
 *  @see OCREngineFactory::TEngineType
 * 
 *  Note: This procedure will create a new thread in your current process in order to 
 *        run the OCR APIs, so you don't need to create new threads for OCR by yourself
 *
 *  For example:
 *  A typical usage for the factory class would be like:
 *  @code
 *  const TOcrEngineEnv env;
 *  env.iPriority = EPriorityLess;
 *  env.iMaxHeapSize = 1200*KMinHeapGrowBy;
 *  MOCREngineInterface* myEngine = CreateOCREngineL( aObserver, env, EEngineLayoutRecognize);
 *  MOCREngineLayoutRecognize* layoutEngine = STATIC_CAST( MOCREngineLayoutRecognize*, myEngine );
 *  // TODO: call coresponding methods in layoutEngine
 *  ReleaseOCREngine( layoutEngine );
 *  @endcode
 *  @lib ocrsrv.lib
 *  @since S60 3.1
 */
class OCREngineFactory  
    {
    public:   
        /**  
        * OCR Engine Types 
        */
        enum TEngineType 
            {
            /**
            * OCR Engine with layout analysis feature:
            * by selecting this type of engine, LayoutAnalysisL
            * shall be called first before RecognizeL. 
            */
            EEngineLayoutRecognize,      
                                     
            /**
            * Engine without layout analysis feature:
            * Layout information shall be passed through TOCRLayoutBlockInfo
            * or TRegionInfo to the interfaces
            */                            
            EEngineRecognizeBlock        
                                         
            };  
              
    public: 
    
        /**
         * Create the OCR engine instance 
         *
         * @since S60 3.1
         * @param aObserver Pointer to the call callback function 
         * @param aEngineEnv Engine environment settings @see TOcrEngineEnv
         * @param aEngineType Select a type of engine to be created @see OCREngineFactory::TEngineType
         * @return Pointer to the engine created @see MOCREngineInterface
         * 
         * @leave KErrArgument aEngineEnv.iMaxHeapSize is lower(equal) than KMinHeapGrowBy*1000 
         * @leave KErrNotSupported aEngineType is not supported 
         */    
        IMPORT_C static MOCREngineInterface* CreateOCREngineL(MOCREngineObserver& aObserver, 
                                                              const TOcrEngineEnv aEngineEnv, 
                                                              TEngineType aEngineType); 

        /**
         * Release the OCR engine instance
         *
         * @since S60 3.1
         * @param aEng Pointer to the instance of the Engine
         * @return None
         */ 
        IMPORT_C static void ReleaseOCREngine(MOCREngineInterface* aEng);
        
    private:
        
        /**
        * Constructor
        */
        OCREngineFactory();
    };

#endif  // OCRSRV_H

// End of file
