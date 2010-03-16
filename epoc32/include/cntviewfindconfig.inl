// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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


// -----------------------CContactViewFindConfigInterface --------------------------------
inline CContactViewFindConfigInterface* CContactViewFindConfigInterface::NewL(TUid aImplementationUid)
/** Allocates and constructs an instance of the plug-in interface.

@param aImplementationUid The UID of the find configuration implementation 
to instantiate.
@return Pointer to the newly created implementation object. */
	{
		TAny* ptr = REComSession::CreateImplementationL(aImplementationUid,
					_FOFF(CContactViewFindConfigInterface,iDtor_ID_Key));
		return reinterpret_cast<CContactViewFindConfigInterface*>(ptr);
	}
inline CContactViewFindConfigInterface::~CContactViewFindConfigInterface()
/** Virtual destructor. */
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}
