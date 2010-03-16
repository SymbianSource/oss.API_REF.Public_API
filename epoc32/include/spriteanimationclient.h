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

#ifndef __SPRITEANIMATIONCLIENT_H__
#define __SPRITEANIMATIONCLIENT_H__

#include <w32std.h>

class TAnimationConfig;

/** @internalComponent */
NONSHARABLE_CLASS(RSpriteAnimationClient) : public RAnim
	{
public:
	RSpriteAnimationClient(RAnimDll& aAnimDll);
	~RSpriteAnimationClient();
	void ConstructL(const RWsSprite& aDevice, const TDesC8& aDataType);
	void ConstructL(const RWsSprite& aDevice, const TDesC8& aDataType, TInt aHostHandle);
	void Start(const TAnimationConfig& aConfig);
	void Stop();
	void Pause();
	void Resume();
	void Hold();
	void Unhold();
	void Freeze();
	void Unfreeze();
	void SendEventL(TInt aEvent, const TAny* aData, TInt aDataLength);
	TSize Size();
protected:
	void SetMinBufferSizeL(TInt aSize);
private:
	TPtr8 iBuf;
	};
	
#endif // __SPRITEANIMATIONCLIENT_H__
