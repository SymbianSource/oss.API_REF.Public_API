/*
* Copyright (c) 2005,2006 Choe Hwanjin
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


#ifndef OSSKEYBOARD_H
#define OSSKEYBOARD_H

#include <e32std.h>
#include <e32base.h>

typedef struct _HangulKeyboard HangulKeyboard;

class COssKeyboard : public CBase
    {
public:
    
    IMPORT_C static COssKeyboard* NewLC();

    IMPORT_C static COssKeyboard* NewL();

    IMPORT_C virtual ~COssKeyboard();

private:

    COssKeyboard();

    void ConstructL();
    
public:
    
    IMPORT_C void SetValue(const TInt& aKey,const TChar& aValue);
    
    IMPORT_C void SetType(const TInt& aType);
    
private:
    
    HangulKeyboard* iHangulKeyboard;

    friend class COssHangulInputContext;
    
    };

#endif // OSSKEYBOARD_H
