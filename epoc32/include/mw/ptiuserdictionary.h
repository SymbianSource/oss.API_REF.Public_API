/*
* Copyright (c) 2003-2007 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0""
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:               Predective text input engine user dictionary 
*               class definition.
*
*/














#ifndef _PTI_USER_DICTIONARY_H
#define _PTI_USER_DICTIONARY_H

// INCLUDES
#include <e32base.h>

/**
* A base class for PtiEngine user dictionary implementations. Normally
* not needed by a client side application.
*/
class MPtiUserDictionary
	{
	public:
		/**
		* Returns user dictionary id value.
		*
		* @since S60 V2.6 
		* @return User dictionary id value.
		*/
		virtual TInt Id() const = 0;

		/**
		* Returns size of user dictionary.
		*
		* @since S60 V2.6 		
		* @return Size of user dictionary.
		*/
		virtual TInt Size() const = 0;

		/**
		* Returns Uid for core DLL.
		*
		* @since S60 V2.6 		
		* @return Uid value for core DLL.
		*/
		virtual TInt32 CoreUID() const = 0;

		/**
		* Returns a boolean value indicating whether this is the default user dictionary. 
		*
		* @since S60 V2.6 		
		* @return ETrue if this user dictionary is default user dictionary.
		*         EFalse if not.  
		*/
		virtual TBool IsDefault() const = 0;

		/**
		* Reuturns user dictionary file name.
		*
		* @since S60 V2.6 		
		* @return   User dictionary file name.
		*/
		virtual TPtrC FileName() const = 0;
		
		/**
		* Returns the amount of free space in user dictionary.
		*
		* @since S60 V2.6 		
		* @return  The Amount of free space in dictionary.
		*          Negative value if the amount of free space
		*          value couldn't be found out.
		*/		
		virtual TInt SpaceLeft() const = 0;

		/**
		* If this flag is set, PtiEngine framework calls
		* WriteL before exiting.
		*
		* @since S60 V2.6 		
		* @return A boolean valua indicating status of the update flag.
		*/
		virtual TBool UpdateFlag() const = 0;

		/**
		* Set update flag to given value. If update flag is set, PtiEngine tries
		* to save user dictionary when PtiEngine destructor is called.
		*  
		* @since S60 V2.6 				
		* @param aFlag New status for the update flag.
		*/
		virtual void SetUpdateFlag(TBool aFlag) = 0;	
	};


class CPtiUserDictionary : public CBase, public MPtiUserDictionary
	{
	public:
		IMPORT_C static CPtiUserDictionary* NewL(TInt aMaxSize);
		IMPORT_C static CPtiUserDictionary* NewL(TDesC& aFileName, TInt aMaxSize);
		IMPORT_C virtual ~CPtiUserDictionary();

		IMPORT_C virtual TInt OpenL(TDesC& aFileName, TInt aMaxSize);
		IMPORT_C virtual TInt WriteL(TDesC& aFileName);
		IMPORT_C virtual TInt WriteL();
		inline void SetFileName(TDesC& aFileName);
		inline TInt Id() const;
		inline void SetId(TInt aId);
		inline TInt Size() const;
		inline TInt32 CoreUID() const;
		inline void SetCoreUID(TInt32 aUid);
		inline virtual TPtr8 Data();
		inline TBool IsDefault() const;
		inline void SetDefault(TBool aValue);
		inline TPtrC FileName() const;
		inline TBool UpdateFlag() const;
		inline void SetUpdateFlag(TBool aFlag);	
		inline TInt SymbolClass() const;
		inline void SetSymbolClass(TInt aSymbolClass);
		IMPORT_C virtual TInt SpaceLeft() const;
		IMPORT_C virtual void SetDataL(TAny* aData, TInt aLength);

	protected:
		IMPORT_C CPtiUserDictionary();

	private:
		void ConstructL(TInt aMaxSize);
		void ConstructL(TDesC& aFileName, TInt aMaxSize);

	protected:	
		TFileName iFileName;
		HBufC8* iData;
		TInt    iId;
		TInt32  iCoreUID;
		TBool   iDefault;
		TBool   iUpdateFlag;
		TInt    iSymbolClass;
		TUint32 iChecksum;   // Holds checksum of lastest version that was saved to disk.
	};

#include "PtiUserDictionary.inl"

#endif

// End of file
