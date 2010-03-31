/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:    LandmarksUi Error & Panic Codes      
*
*/

#ifndef LMKERRORS_H
#define LMKERRORS_H

// landmarksui panic code
enum TPanicCode
    {
    KLmkPanicNullMember = 1,
    KLmkPanicIllegalMethodCall,
    KLmkPanicInvalidResourceData,
    KLmkPanicNullPointer,
    KLmkPanicOutOfRange,    
    KLmkPanicIllegalConstruction,    
    KLmkPanicMathError,    
    KLmkPanicUnexpectedEvent,    
    KLmkPanicUnknownOperation,    
    KLmkPanicUnknownControlType,    
    KLmkPanicUnknownItemType,    
    KLmkPanicIllegalMementoAccess, 
    KLmkPanicWrongSelector,
    KLmkPanicInvalidIndex,    
    KLmkPanicIndexesZeroOneNotSet,    
    KLmkPanicSelectorArrayIndex,
    KLmkPanicNullListBox,
    KLmkPanicNullListProvider,
    KLmkPanicPostponedRestoration,
    KLmkPanicDeletionInfo,
	KLmkPanicNoLbModel,        
    KLmkPanicNullNaviPane,
    KLmkPanicSenderNotExist,
	KLmkPanicKeyNotSet,
    KLmkPanicAlreadyActive,
    KLmkPanicIntermediateCallback        
    };
	
#endif	// LMKERRORS_H

// End of File
