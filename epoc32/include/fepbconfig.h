// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __FEPBCONFIG_H__
#define __FEPBCONFIG_H__

#include <e32base.h>
#include <coemain.h>	// class CCoeEnv

class CRepository;

/** Specifies the maximum size of a FEP attribute in bytes.

@publishedAll
@released */
const TInt KCoeFepMaxAttribDataSize = 200;


/** On or off key data for FEPs. 

The CCoeFep class uses instances of this class to specify the key combination which 
is used to turn the FEP on and off. These values are initialised during construction 
of the FEP (see CCoeFep::BaseConstructL()).

The class consists of three TUints. They represent: 

- the character code of the key combination

- a modifier mask which indicates which modifiers are relevant to the key combination

- the modifier values which indicate which of the modifiers specified in the 
modifier mask must be on and which must be off

For example, if the key combination to turn the FEP off is Fn+Enter, where 
the Shift modifier must not be down (and the state of all other modifiers 
is irrelevant), the TFepOnOrOffKeyData object would be constructed as follows:

@code
TFepOnOrOffKeyData(EKeyEnter, EModifierFunc|EModifierShift, EModifierFunc) 
@endcode

Note that modifiers should not be set in the values if they are not also set 
in the mask. 

@publishedAll 
@released */
class TFepOnOrOffKeyData
	{
public:
	inline TFepOnOrOffKeyData(TUint aCharacterCodeForFoldedMatch, TUint aModifierMask, TUint aModifierValues) :iCharacterCodeForFoldedMatch(aCharacterCodeForFoldedMatch), iModifierMask(aModifierMask), iModifierValues(aModifierValues) 
	/** The C++ constructor is used to construct the key data object with the character 
	code, the modifier mask and the modifier values.
	
	@param aCharacterCodeForFoldedMatch The character code.
	@param aModifierMask The modifier mask.
	@param aModifierValues The modifier values. */
		{}

	inline TUint CharacterCodeForFoldedMatch() const 
	/** Gets the character code.
	
	@return The character code. */
		{return iCharacterCodeForFoldedMatch;}
	inline TUint ModifierMask() const 
	/** Gets the modifier mask.
	
	@return The modifier mask. */
		{return iModifierMask;}
	inline TUint ModifierValues() const 
	/** Gets the modifier values.
	
	@return The modifier values. */
		{return iModifierValues;}
	/**
	Checks if 2 TFepOnOrOffKeyData objects have the same values.

	returns Etrue if the 2 objects have the same values, EFalse otherwise
	*/
	IMPORT_C TBool operator==(const TFepOnOrOffKeyData& aAnother) const;
	
	
	/**
	Checks if 2 TFepOnOrOffKeyData objects do not have the the same values.
	
	returns Etrue if the 2 objects have the same values, EFalse otherwise
	*/
	IMPORT_C TBool operator!=(const TFepOnOrOffKeyData& aAnother) const;
private:
	TUint iCharacterCodeForFoldedMatch;
	TUint iModifierMask;
	TUint iModifierValues;
	};

class CDictionaryStore;
class RWriteStream;
class RReadStream;


/** Reads and writes generic FEP settings.

Used by the CCoeFep class. The generic FEP settings are whether the FEP is 
on or off and what key combinations should turn the FEP on or off. Also used 
to synchronise these settings across all running instances of the FEP. These 
settings are generic, unlike FEP attributes which are FEP-specific. FEP attributes 
are stored, restored and synchronised using class MFepAttributeStorer. Generic 
FEP settings are changed locally using the Set...() member functions. Then, 
to store these as the system settings and to apply them globally, call StoreChangesAndBroadcastL().

Class CCoeFep initialises its generic FEP settings from the global system 
settings during construction. Its generic FEP settings are updated when the 
settings are changed by a call to StoreChangesAndBroadcastL() by another running 
instance of the FEP. 

@publishedAll
@released */
class CFepGenericGlobalSettings : public CBase
	{
public:
	IMPORT_C static CFepGenericGlobalSettings* NewL(CCoeEnv& aConeEnvironment, const TFepOnOrOffKeyData& aDefaultOnKeyData, const TFepOnOrOffKeyData& aDefaultOffKeyData, TBool aDefaultIsOn);
	IMPORT_C static CFepGenericGlobalSettings* NewLC(CCoeEnv& aConeEnvironment, const TFepOnOrOffKeyData& aDefaultOnKeyData, const TFepOnOrOffKeyData& aDefaultOffKeyData, TBool aDefaultIsOn);
	IMPORT_C static CFepGenericGlobalSettings* NewL();
	IMPORT_C static CFepGenericGlobalSettings* NewLC();
	IMPORT_C TFepOnOrOffKeyData OnKeyData() const;
	IMPORT_C void SetOnKeyData(const TFepOnOrOffKeyData& aOnKeyData);
	IMPORT_C TFepOnOrOffKeyData OffKeyData() const;
	IMPORT_C void SetOffKeyData(const TFepOnOrOffKeyData& aOffKeyData);
	IMPORT_C TBool IsOn() const;
	IMPORT_C void SetIsOn(TBool aIsOn);
	IMPORT_C void StoreChangesAndBroadcastL();
	IMPORT_C void RefreshL();
public: // not for external use
	IMPORT_C static void ReadOnState(CRepository& aRepository, TBool& aOnState, TInt* aError=NULL);
	IMPORT_C static void ReadOnOrOffKeyData(CRepository& aRepository, TFepOnOrOffKeyData& aOnOrOffKeyData, TUint32 aRepositoryKeyMask_OnOrOff, TInt* aError=NULL);
	IMPORT_C static void WriteOnStateAndBroadcastL(CRepository& aRepository, TBool aOnState, TUint32 aRepositoryKeyMask_DefaultOrDynamic);
	IMPORT_C static void WriteOnOrOffKeyDataAndBroadcastL(CRepository& aRepository, const TFepOnOrOffKeyData& aOnOrOffKeyData, TUint32 aRepositoryKey);
private:
	CFepGenericGlobalSettings();
	void ConstructL();
private:
	enum
		{
		EFlagIsOn				=0x00000001,
		// the EFlagStoreXxx flags below indicate whether this object has had any SetXxx functions called on it, which can be used to optimize what work StoreChangesAndBroadcastL has to do
		EFlagStoreIsOn			=0x00000002,
		EFlagStoreOnKeyData		=0x00000004,
		EFlagStoreOffKeyData	=0x00000008
		};
private:
	TUint iFlags;
	TFepOnOrOffKeyData iOnKeyData;
	TFepOnOrOffKeyData iOffKeyData;
	};


/** Protocol for storing, restoring and synchronising FEP attributes. 

An abstract base class for CCoeFep, so FEPs must implement the pure virtual 
functions declared in this class.

Rather than using a single device-wide instance of a FEP, each application 
has its own instance of the FEP. MFepAttributeStorer provides a framework 
for synchronising FEP attributes across each running instance of the same 
FEP. For this to happen, the FEP must implement MFepAttributeStorer::WriteAttributeDataToStreamL() 
and MFepAttributeStorer::ReadAttributeDataFromStreamL().

Attributes are FEP-specific, and are identified by a UID which can be accessed 
using AttributeAtIndex(). An example of a FEP attribute might be whether inline 
editing is enabled or disabled. 

@publishedAll 
@released */
class MFepAttributeStorer
	{
public:
	IMPORT_C void ReadAllAttributesL(CCoeEnv& aConeEnvironment);
	IMPORT_C void WriteAttributeDataAndBroadcastL(CCoeEnv& aConeEnvironment, TUid aAttributeUid);
	IMPORT_C void WriteAttributeDataAndBroadcastL(CCoeEnv& aConeEnvironment, const TArray<TUid>& aAttributeUids);
	/** Returns the total number of FEP attributes.
	
	@return The number of FEP attributes. */
	virtual TInt NumberOfAttributes() const=0;
	/** Returns the UID of the FEP attribute at the index specified.
	
	@param aIndex An array index.
	@return The UID of the FEP attribute at aIndex. */
	virtual TUid AttributeAtIndex(TInt aIndex) const=0;
	/** Writes the value of the attribute specified to the specified write stream.
	
	Called by MFepAttributeStorer::WriteAttributeDataAndBroadcastL() for each 
	attribute passed to it.
	
	@param aAttributeUid UID of the attribute to write to the stream.
	@param aStream The stream to which to write the attribute. */
	virtual void WriteAttributeDataToStreamL(TUid aAttributeUid, RWriteStream& aStream) const=0;
	/** Reads the value of the attribute identified by the UID specified in aAttributeUid 
	from the specified read stream.
	
	You should take appropriate action if the attribute has changed, e.g. 
	if inline editing has been disabled, you might cancel the current transaction.
	
	This function is called by MFepAttributeStorer::ReadAllAttributesL() for all 
	attributes. It is also called when the FEP receives a message that an attribute 
	has been changed by another running instance of the FEP (using WriteAttributeDataAndBroadcastL()).
	
	@param aAttributeUid Identifies the attribute whose value should be read.
	@param aStream Read stream from which to read the attribute's value. */
	virtual void ReadAttributeDataFromStreamL(TUid aAttributeUid, RReadStream& aStream)=0;
private:
	IMPORT_C virtual void MFepAttributeStorer_Reserved_1();
	IMPORT_C virtual void MFepAttributeStorer_Reserved_2();
	TInt NumberOfOccurrencesOfAttributeUid(TUid aAttributeUid) const;
	};

#endif	// __FEPBCONFIG_H__
