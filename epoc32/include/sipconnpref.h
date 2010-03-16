// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// SIP extension events definition
// 
//



/**
 @file
 @publishedAll
 @released since v9.2
*/


#ifndef SIPCONNPREFS_H
#define SIPCONNPREFS_H
	
#include <connpref.h>
#include <cdbcols.h>

/** The numeric value of SIP protocol family ID .*/
const TUint KAFSip = 0x10000; 


struct SSipConnPref
/** 
This contains the information about the Id of the profile
@publishedAll
@released since v9.2 
*/
	{
	/** The numeric value of SIP Profile ID **/
	TUint32 iProfileId;
	};

	
class TSipConnPref : public TConnPref
/** 
This contains the information about the type of the connection preferences used by the SIP in the form of the profiles
@publishedAll
@released since v9.2 
*/
	{
public:
	/** Constructor. */
	TSipConnPref();
	/** Sets the profile ID same as the prameter **/
	inline void 	SetProfileId(TUint32 aProfileId);
	/** Gets the default profile ID  **/
	inline TUint32  GetProfileId() const;
	/** cast to appropriate SIP connection provider type  **/
	inline static TSipConnPref& TSipConnPref::Cast(const TConnPref& aPref);
	
protected:
	inline SSipConnPref* PrefPtr() const;

	};

#include <sipconnpref.inl>

#endif  // sipconnpref.h
