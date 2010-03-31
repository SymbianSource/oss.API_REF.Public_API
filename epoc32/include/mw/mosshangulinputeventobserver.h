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

#ifndef _MOSSHANGULINPUTEVENTOBSERVER_H_
#define _MOSSHANGULINPUTEVENTOBSERVER_H_

class MOssHangulInputEventObserver
    {
public:
    
    virtual TBool MOhieoOnTranslate(const TChar& aAscII,const TDesC& aChar) = 0;
    
    virtual TBool MOhieoOnTransition(const TChar& aChar,const TDesC& aPreEdit) = 0;
    
    };

#endif // _MOSSHANGULINPUTEVENTOBSERVER_H_ 
