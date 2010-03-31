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
//

#ifndef __OBEXUSBTRANSPORTINFO_H__
#define __OBEXUSBTRANSPORTINFO_H__

#include "obextransportinfo.h"
#include <obexconstants.h>

/**
Concrete transport info type for use when using the usb  transport controller.
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexUsbTransportInfo) : public TObexTransportInfo
	{	
//Data from TObexUsbProtocolInfo class, declared in obex\public\obexconstants.h
public:
		/** Provides a string to be attached to the Obex function's Communication Class interface,
		which may be used to identify the Obex service. */
		TBuf16<KUsbIntStringDescLength> iInterfaceStringDescriptor;
	};

/**
Concrete transport info type when using the USB transport controller with client driver extensions.
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexUsbV2TransportInfo) : public TObexUsbTransportInfo
	{
		
	//Data from TObexUsbProtocolInfoV2 class, declared in obex\public\obexconstants.h
public:
	/** Bitmap containing the bandwidth priorities to use on IN and OUT endpoints
	@see TUsbcBandwidthPriority
	*/
	TInt iBandwidthPriority;
	/** Specifies whether to use DMA on the bulk OUT endpoint */
	TBool iDmaOnOutEndpoint;
	/** Specifies whether to use DMA on the bulk IN endpoint */
	TBool iDmaOnInEndpoint;
	};

#endif
