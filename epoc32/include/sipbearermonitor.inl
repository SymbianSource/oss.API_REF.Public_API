/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipbearermonitor.inl
* Part of       : SIP NetworkMonitor
* Version       : SIP/4.0 
*
*/



#ifndef CSIPBEARERMONITOR_INL
#define CSIPBEARERMONITOR_INL


// ---------------------------------------------------------------------------
// TSIPBearerParams::TSIPBearerParams
// ---------------------------------------------------------------------------
//
inline TSIPBearerParams::TSIPBearerParams( 
    MSIPBearerOwner& aOwner,
    TInt aIapId,
    TInt aError,
    MSIPNetworkInfoObserver& aNetworkInfoObserver ) :
    iOwner( aOwner ),
    iIapId( aIapId ),
    iError( aError ),
    iNetworkInfoObserver( aNetworkInfoObserver )
    {
    }

// ---------------------------------------------------------------------------
// CSIPBearerMonitor::~CSIPBearerMonitor
// ---------------------------------------------------------------------------
//
inline CSIPBearerMonitor::~CSIPBearerMonitor()
    {
	REComSession::DestroyedImplementation( iInstanceKey );
	}

// ---------------------------------------------------------------------------
// CSIPBearerMonitor::State
// ---------------------------------------------------------------------------
//
inline MSIPNetworkObserver::TNetworkState CSIPBearerMonitor::State() const
    {
    return iState;
    }

// ---------------------------------------------------------------------------
// CSIPBearerMonitor::RefreshL
// ---------------------------------------------------------------------------
//			
inline void CSIPBearerMonitor::RefreshL( TInt /*aError*/ )
    {
	}

// ---------------------------------------------------------------------------
// CSIPBearerMonitor::ContinueMonitoring
// By default, all other error codes than KErrNone lead to negative result
// ---------------------------------------------------------------------------
//	
inline TBool CSIPBearerMonitor::ContinueMonitoring( TInt aError )
    {    
    return aError == KErrNone;
    }

// ---------------------------------------------------------------------------
// CSIPBearerMonitor::CSIPBearerMonitor
// ---------------------------------------------------------------------------
//
inline CSIPBearerMonitor::CSIPBearerMonitor( TAny* aParams ) :
    iParent( reinterpret_cast< TSIPBearerParams* >( aParams )->iOwner ),
    iIapId( reinterpret_cast< TSIPBearerParams* >( aParams )->iIapId ),
	iError( reinterpret_cast< TSIPBearerParams* >( aParams )->iError ),
	iNetworkInfoObserver( reinterpret_cast< TSIPBearerParams* >
		( aParams )->iNetworkInfoObserver )
	{
	}

#endif // CSIPBEARERMONITOR_INL

// End of File

