/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Offers functionality for resolving corresponding error texts
*                for error codes. 
*
*/



#if !defined TEXT_RESOLVER_H
#define TEXT_RESOLVER_H

#include <coemain.h>    //  CCoeEnv
#include <TextResolver.hrh> // Resource flags 

// DEFINES
typedef CArrayFixFlat<TInt> CErrorResourceIdArray;
typedef CArrayFixFlat<TInt> CErrorResourceFlagArray;

/**
* Class offers functionality for resolving corresponding error texts for 
* error codes. Text Resolver API provides operations with which a specific 
* error code can be resolved to a human readable text. Descriptions for the
* different error codes must be defined in the resource files of this 
* component. 
*
* Text Resolver uses the CCoeEnv environment class to access the resource
* files if the CCoeEnv environment is available. If the CCoeEnv environment
* is not available, the files are accessed through the RResourceFile API.
*
* The API consist of the CTextResolver class which is used together with 
* Text Resolver flags defined in textresolver.hrh file. The flags are used
* to tell the priority of the error to the client:
*
* - EErrorResBlankErrorFlag is used to tell that error has no proper explanation.
* - EErrorResUnknownErrorFlag indicates that Text Resolver does not support the error. 
* - EErrorResOOMFlag Flag is returned while processing KErrNoMemory error code. 
*
*
* Usage:
*
* @code
*  #include <textresolver.h>
*
*  // Typically used as an instance variable.
*  
*  // Call the factory method NewLC() to create a new instance of CTextResolver.
*  // NewLC() method leaves the instance of the object on the cleanup stack.	
*  // The passed CCoeEnv instance is needed to access the resource files.
*  CTextResolver* iTextResolver = CTextResolver::NewLC(*iCoeEnv); 
*
*  // // Error Resolving, simple:
*
*  // Get error code to be resolved.
*  // TInt err1 = MyMethod(KInvalidValue);
*  TInt err1 = KErrNoMemory;
*    
*  TPtrC buf1;  // For returned error text
*    
*  if (err1 != KErrNone)
*      {
*      // Resolve the given error code. 
*      // The operation returns the error text for the resolved error.
*      // There's no limit how long the resolved string can be.
*      // Add context to 2nd param if needed.
*      buf1.Set(iTextResolver->ResolveErrorString(err)); 
*      }
*  else
*      {
*      // Do something.
*      }
*        
*  // Note that buf1 will only be valid as long as CTextResolver 
*  // instance is alive and no new error is resolved by the same instance.
*  // If for some reason you need to store the resolved error
*  // beyond immediate use, make a copy of it.
*
*  // Error Resolving, advanced:
* 
*  // Get error code to be resolved.
*  // TInt err2 = MyMethod(KInvalidValue);
*  TInt err2 = KErrNotSupported;
*        
*  TInt textId(0);    // ID of the returned text
*  TUint flags(0);    // Priority of the returned error 
*  TPtrC buf2;      // For returned error text
*   
*  if (err2 != KErrNone)
*      {
*      // Resolve the given error code.
*      // The operation returns the error text for the resolved error.
*      // There's no limit on how long the resolved string can be.
*      // Add Context to 4th param if needed.
*      buf2.Set(iTextResolver->ResolveErrorString(err, textId, flags)); 
*
*      if (flags & EErrorResUnknownErrorFlag)
*          {
*          // The flag indicates that Text Resolver does not support
*          // the error code. 
*          // Do something.
*          }
*      }
*  else
*      {
*      // Do something.
*      }
*    
*  // Note that buf2 will only be valid as long as CTextResolver 
*  // instance is alive and no new error is resolved by the same instance.
*  // If for some reason you need to store the resolved error
*  // beyond immediate use, make a copy of it.
*
*  // iTextResolver, Free loaded resources
*  CleanupStack::PopAndDestroy(); 
* @endcode
*
* @lib commonengine.lib
* @since S60 2.0
*/

class CTextResolver : public CBase
    {

    public:

        /**
        * Defines used error contexts. 
        * Optional error contexes for aiding the mapping of error codes to 
        * texts in a unique way. If no context is given the assumption is 
        * that error codes are unique.
        */
        enum TErrorContext
            {
            /** Context is defined automatically from error code value.
            * Here it is assumed that each error code is unique and in
            * own range. This is a default value when resolving errors.
            */
            ECtxAutomatic = 0,
            /** Context text is not added to the beginning of the resolved error text,
            * just context separator ':' and newline are added.
            */
            ECtxNoCtx = 1,
            /** No context text, context separator ':' or newline added to the 
            * beginning of the resolved error text.
            */
            ECtxNoCtxNoSeparator = 2
            };
    public:
        /**
         * Two-phase constructor method that is used to create a new instance
         * of the CTextResolver class. The implementation uses the passed 
         * CCoeEnv instance to access the resource files.
         *
         * @param aEnv the CCoeEnv instance to be used to access the resource
         * files.
         * @return a pointer to a new instance of the CTextResolver class.
         */
        IMPORT_C static CTextResolver* NewL(CCoeEnv& aEnv);
           
         /**
         * Constructor creates a new instance of CTextResolver. The 
         * implementation uses the passed CCoeEnv instance to access the 
         * resource files. Leaves the object on the cleanup stack.
         *
         * @param aEnv the CCoeEnv instance to be used to access the resource
         * files.
         * @return a pointer to a new instance of the CTextResolver class.
         */
        IMPORT_C static CTextResolver* NewLC(CCoeEnv& aEnv);
        
         /**
         * Constructor creates a new instance of CTextResolver. Resource files 
         * are accessed through the RResourceFile API.
         *
         * @return a pointer to a new instance of the CTextResolver class.
         */
        IMPORT_C static CTextResolver* NewL();

         /**
         * Constructor creates a new instance of CTextResolver.Resource files 
         * are accessed through the RResourceFile API. Leaves the object on 
         * the cleanup stack.
         *
         * @return a pointer to a new instance of the CTextResolver class.
         */
        IMPORT_C static CTextResolver* NewLC();

        
        /** 
        * Destructor 
        */
        IMPORT_C ~CTextResolver();

        /**
        * Resolves the given error code and returns the error text for the
        * resolved error. Resolved text can be of any length. This version
        * is for advanced use
        *
        * @param aError The error code to be resolved.
        * @param aTextId ID of the returned text.
        * @param aFlags The priority of the returned error. The priority is 
        * defined by the this module! Flags are defined in textresolver.hrh.
        * @param aContext Optional context for error numbers. If the aContext 
        * parameter is not passed to the function, it uses the default value
        * ECtxAutomatic. 
        * @return the error text for the resolved error. "System error" (in 
        * English localisation) is returned when error code is not known. For 
        * unknown errors blank error flag (flags are defined in 
        * textresolver.hrh) is also set to hide errors without proper 
        * explanation. There is no limit on how long the resolved string 
        * can be.
        */
		IMPORT_C const TDesC& ResolveErrorString(
             TInt aError,
             TInt& aTextId,
             TUint& aFlags,
             TErrorContext aContext = ECtxAutomatic);

        /**
        * Resolves the given error code and returns the error text for the
        * resolved error. Resolved text can be of any length. This version 
        * is for "normal" use.
        *
        * @param aError The error code to be resolved.
        * @param aContext Optional context for error numbers. If the aContext 
        * parameter is not passed to the function, it uses the default value
        * ECtxAutomatic. 
        * @return the error text for the resolved error. "System error" (in 
        * English localisation) is returned when error code is not known. For 
        * unknown errors blank error flag (flags are defined in 
        * textresolver.hrh) is also set to hide errors without proper 
        * explanation. There is no limit on how long the resolved string
        * can be.
        */
	    IMPORT_C const TDesC& ResolveErrorString(
             TInt aError,
             TErrorContext aContext = ECtxAutomatic);

	private:
        
        virtual TInt ResourceForError(TInt aError);
        virtual void LoadResourceFilesL();

        // Construction
        CTextResolver(CCoeEnv& aEnv);
        CTextResolver();
        void ConstructL();

        // Utility
        void FindFullPathOfResourceFile(TFileName& aResFile) const;
        void ReadResourcesToArraysL(TInt& aError, TInt& aTextId);
        void Reset();
        void PrepareReaderLC(TResourceReader& reader);

        // returns NULL if fails
        HBufC* ReadUnicodeString(const TInt& aTextId);

        // returns false if any memory allocation fails or initial values 
        // of necessary pointers are NULL, indicating alloc failure earlier.
        TBool AddContextAndSeparator(TErrorContext aContext);

    private:
        
        CCoeEnv*                            iCoe;
        RResourceFile                       iRFile;
        TInt                                iRDSupport;
        TInt                                iBaseResourceFileOffset;
        CArrayFix<TInt>*                    iStartError;
        CArrayFix<TInt>*                    iAppTexts;
        CArrayPtr<CErrorResourceIdArray>*   iErrorTexts;
        CArrayPtr<CErrorResourceFlagArray>* iFlags;
        HBufC*                              iTextBuffer;
        HBufC*                              iAppNameText;
        HBufC*                              iContextSeparator;
        RFs                                 iFs;
        TPtrC                               iTruncatedTextPointer;
    };

#endif

// End of File
