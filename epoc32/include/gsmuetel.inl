// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Constructor.
// 
//




/**
 @file
 @publishedAll
 @released 
*/
inline TGsmSms::TGsmSms()
	{
	}


/**
 *  Gets a descriptor containing the PDU.
 *  
 *  @return Descriptor containing the PDU 
 */
inline const TDesC8& TGsmSms::Pdu() const
	{
	return iPdu;
	}


/**
 *  Sets the PDU.
 *  
 *  @param aPdu Descriptor containing the PDU 
 */
inline void TGsmSms::SetPdu(const TDesC8& aPdu)
	{
	iPdu = aPdu;
	}


/**
 *  Gets the Service Centre Address.
 *  
 *  @return Service Centre Address 
 */
inline const TGsmSmsTelNumber& TGsmSms::Sca() const
	{
	return iSca;
	}


/**
 *  Sets the Service Centre Address.
 *  
 *  @param aSca Service Centre Address 
 */
inline void TGsmSms::SetSca(const TGsmSmsTelNumber& aSca)
	{
	iSca = aSca;
	}
