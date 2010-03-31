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


#ifndef OSSHANGULINPUTCONTEXT_H
#define OSSHANGULINPUTCONTEXT_H

#include <e32std.h>
#include <e32base.h>

#include <MOssHangulInputEventObserver.h>

typedef struct _HangulInputContext HangulInputContext;

class COssKeyboard;
class COssCombination;

class COssHangulInputContext : public CBase
    {
public:

    IMPORT_C static COssHangulInputContext* NewLC(const TDesC8& aKeyboardType);

    IMPORT_C static COssHangulInputContext* NewL(const TDesC8& aKeyboardType);

    IMPORT_C virtual ~COssHangulInputContext();

private:

    COssHangulInputContext();

    void ConstructL(const TDesC8& aKeyboardType);
    
public:
    
    IMPORT_C TBool Process(const TChar& aAscII);
    
    IMPORT_C void Reset();
    
    IMPORT_C TBool BackSpace();
    
    IMPORT_C TBool IsEmpty();
    
    IMPORT_C TBool HasChoseong();
    
    IMPORT_C TBool HasJungseong();
    
    IMPORT_C TBool HasJongseong();
    
    IMPORT_C void SetOutputMode(const TInt& aMode);
    
    IMPORT_C void SetKeyboard(const COssKeyboard& aOssKeyboard);
    
    IMPORT_C void SelectKeyboard(const TDesC8& aId);
    
    IMPORT_C void SetCombinationL(COssCombination& aOssCombination);
    
    IMPORT_C void AddEventObserver(MOssHangulInputEventObserver* aObserver);
    
    IMPORT_C void RemoveEventObserver(MOssHangulInputEventObserver* aObserver);
    
    IMPORT_C TPtrC GetPreeditString();
    
    IMPORT_C TPtrC GetCommitString();
    
    IMPORT_C TPtrC Flush();
    
public:
    
    TBool OnTranslate(const TChar& aAscII,const TDesC& aUcsStr);
    
    TBool OnTransition(const TChar& aChar,const TDesC& aPreEdit);
    
private:
    
    HBufC8* iKeyboardType;
    
    HangulInputContext* iHic;
    
    RPointerArray<MOssHangulInputEventObserver> iObservers;

    };

#endif // OSSHANGULINPUTCONTEXT_H
