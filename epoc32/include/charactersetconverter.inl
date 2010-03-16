/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: 
*
*/



#include <CharacterSetConverter.h>

/**
Creates a Charconv Plug-in interface implementation.
@param		aInterfaceImplUid The UID for the required Charconv Plug-in interface implementation.
*/
CCharacterSetConverterPluginInterface* CCharacterSetConverterPluginInterface::NewL(TUid aInterfaceImplUid)
	{
	return reinterpret_cast <CCharacterSetConverterPluginInterface*> (
		REComSession::CreateImplementationL(
			aInterfaceImplUid,
			_FOFF(CCharacterSetConverterPluginInterface, iDtor_ID_Key))); 
	}
/**
Destroys the Charconv Plug-in interface implementation specified by iDtor_ID_Key
*/
CCharacterSetConverterPluginInterface::~CCharacterSetConverterPluginInterface()
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}
