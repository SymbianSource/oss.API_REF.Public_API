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


#ifndef OSSCOMBINATION_H
#define OSSCOMBINATION_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

typedef struct _HangulCombination HangulCombination;

class TOssCombinationItem
    {
    public:
        
        TBool operator == (const TOssCombinationItem& aCombination) const;
        
    public:
        
        TUint iFirst;
        
        TUint iSecond;
        
        TUint iResult;
    };

class COssCombination : public CBase
    {
public:
        
    IMPORT_C static COssCombination* NewLC();

    IMPORT_C static COssCombination* NewL();

    IMPORT_C virtual ~COssCombination();
    
public:
    
    IMPORT_C TInt AddCombinationL(const TOssCombinationItem& aCombination);
    
    IMPORT_C TInt RemoveCombination(const TOssCombinationItem& aCombination);

    IMPORT_C TInt FindCombination(const TOssCombinationItem& aCombination); 
    
private:

    COssCombination();

    void ConstructL();
    
private:
    
    TBool PopulateListL();
    
private:
    
    HangulCombination* iHangulCombination;
    
    RArray<TOssCombinationItem> iCombinationList;

    friend class COssHangulInputContext;
    
    };

#endif // OSSCOMBINATION_H
