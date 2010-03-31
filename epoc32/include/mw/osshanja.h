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


#ifndef OSSHANJA_H
#define OSSHANJA_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

class COssHanja : public CBase
    {
public:
    
    static COssHanja* NewLC();

    static COssHanja* NewL();

    virtual ~COssHanja();

private:

    COssHanja();

    void ConstructL();
    
public:

    };

#endif // OSSHANJA_H
