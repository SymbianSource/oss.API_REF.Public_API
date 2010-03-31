/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: Definition of dm constants/exported methods
* 	This is part of remotemgmt_plat. 
*/
// SmlDmAdapter.inl
//


inline /*static*/ CSmlDmAdapter* CSmlDmAdapter::NewL(const TUid& aImplementationUid, MSmlDmCallback& aDmCallback)
	/**
	The construction for CSmlDmAdapter class.
    @param aDmCallback An address of the callback interface class.
	@publishedPartner
	@prototype
	*/
	{
	TAny* arg = reinterpret_cast<TAny*>(&aDmCallback);
	TAny* ptr = REComSession::CreateImplementationL(aImplementationUid,
													_FOFF(CSmlDmAdapter, iDtor_ID_Key),
													arg);
	return static_cast<CSmlDmAdapter*>(ptr);
	}

inline /*virtual*/ CSmlDmAdapter::~CSmlDmAdapter()
	/**
	C++ default destructor.
	@publishedPartner
	@prototype
	*/
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}

inline CSmlDmAdapter::CSmlDmAdapter(TAny* aEcomArguments)
	: iCallback(*(reinterpret_cast<MSmlDmCallback*>(aEcomArguments)))
	/**
	Constructor.
	@publishedPartner
	@prototype
	*/
	{
	}
	
inline MSmlDmCallback& CSmlDmAdapter::Callback()
	/**
	Accessor for the callback supplied to this adapter on construction.
	@publishedPartner
	@prototype
	*/
	{
	return iCallback;
	}

inline TSmlDmAccessTypes::TSmlDmAccessTypes()
	/**
	Class constructor 
	@publishedPartner
	@prototype
	*/
	{
	iACL = 0;
	}	

inline void TSmlDmAccessTypes::SetAdd()
	/**
	The function sets Add access type property. 
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Add;
	}	

inline void TSmlDmAccessTypes::SetCopy()
	/**
	The function sets Copy access type property.
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Copy;
	}	

inline void TSmlDmAccessTypes::SetDelete()
	/**
	The function sets Delete access type property. 
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Delete;
	}	

inline void TSmlDmAccessTypes::SetExec()
	/**
	The function sets Execute access type property.
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Exec;
	}	

inline void TSmlDmAccessTypes::SetGet()
	/**
	The function sets Get access type property. 
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Get;
	}	

inline void TSmlDmAccessTypes::SetReplace()
	/**
	The function sets Replace access type property. 
	@publishedPartner
	@prototype
	*/
	{
	iACL |= EAccessType_Replace;
	}	

inline TUint8 TSmlDmAccessTypes::GetACL()
	/**
	The function obtains the bitfield composed from each access type that has
	been set 
	@publishedPartner
	@prototype
	*/
	{
	return iACL;
	}

inline void TSmlDmAccessTypes::Reset()
	/**
	The function resets all access types previously defined in this object.
	@publishedPartner
	@prototype
	*/
	{
	iACL = 0;
	}
