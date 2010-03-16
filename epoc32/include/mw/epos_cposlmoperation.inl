/*
* Copyright (c) 2005-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Inline utility methods for CPosLmOperation class
*
*/



// -----------------------------------------------------------------------------
// ExecuteAndDeleteLD
//
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
inline void ExecuteAndDeleteLD(CPosLmOperation* aOperation)
    {
    CleanupStack::PushL(aOperation);
    aOperation->ExecuteL();
    CleanupStack::PopAndDestroy(aOperation);
    }


//  End of File
