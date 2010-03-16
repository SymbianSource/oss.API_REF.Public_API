// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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

inline CPitBoss& CPlayer::PitBoss() const
	{
	return WorkerThread().PitBoss();
	}

inline TWorkerId CPlayer::WorkerId() const
	{
	return WorkerThread().WorkerId();
	}

inline const RMessage2& CPlayer::Message() const
	{
	return *iCurrentMessage;
	}

inline CSockSession* CPlayer::CurrentSession() const
	{
	return iSession;
	}

inline CPlayer::TSubSessionContainer& CPlayer::SubSessions()
	{
	return iSubSessions;
	}

inline TSockManData* CPlayer::SockManGlobals() const
	{
	return WorkerThread().SockManGlobals();
	}
