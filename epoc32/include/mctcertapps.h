/*
* Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/




/**
 @file 
 @internalAll
*/
 
#ifndef __MCTCERTAPPS_H__
#define __MCTCERTAPPS_H__

#include <e32base.h>
#include <f32file.h>
#include <s32file.h>
#include <ct/mcttokeninterface.h>

/** The UID of certificate application token type */
const TInt KTokenTypeCertApps = 0x101f7a37;

/** The UID of certificate application interface */
const TInt KInterfaceCertApps = 0x101f7a38;

/**
 * Information about a certificate application.
 *
 * Certificate applications are used to represent classes of certificate use,
 * for example Software Install, TLS, WTLS, WMLScript, SignText, etc.
 *
 * CA Certificates are associated with zero or more applications, and this
 * information is used to determine which certificates are used when building
 * and validating certificate chains.
 *
 * An application is identified by a UID.  A TCertificateAppInfo contains this
 * and the name of the application.
 * 
 * @publishedAll
 * @released
 */
class TCertificateAppInfo
	{
public:
	IMPORT_C TCertificateAppInfo(const TUid& aUid, const TName& aName);
	IMPORT_C TCertificateAppInfo& operator = (const TCertificateAppInfo& aClient);
	IMPORT_C TCertificateAppInfo();
	IMPORT_C const TUid& Id() const;
	IMPORT_C const TName& Name() const;
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);

private:
	TUid iUid;                    
	TName iName;
	};

/**
 * Interface for certificate applications manager token.
 */
class MCTCertApps : public MCTTokenInterface
	{
public:
	virtual void AddL(const TCertificateAppInfo& aClient) = 0;
	virtual void RemoveL(const TUid& aUid) = 0;
	virtual TInt ApplicationCountL() const = 0;
	virtual void ApplicationsL(RArray<TCertificateAppInfo>& aAppArray) const = 0;
	virtual void ApplicationL(const TUid& aUid, TCertificateAppInfo& aInfo) const = 0;
	};


#endif // __MCTCERTAPPS_H__
