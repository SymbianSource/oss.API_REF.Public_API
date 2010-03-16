/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
*     Phonebook contact editor exit callback abstract interface.
*
*/


#ifndef __MPbkEditorOkToExitCallback_H__
#define __MPbkEditorOkToExitCallback_H__

// CLASS DECLARATION

/**
 * Phonebook contact editor exit callback interface. This callback is used in
 * conjunction with the CPbkContactEditorDlg editing dialog. The user can set
 * a callback function that is called before the dialog exit happens.
 * @see CPbkContactEditorDlg
 */
class MPbkEditorOkToExitCallback
    {
    public: // Interface

        /**
         * Returns ETrue if it is ok to exit the contact editor and
         * EFalse if not.
         *
         * @param aCommandId    The exit command id.
         * @return  ETrue to exit the editor.
         */
        virtual TBool OkToExitL(
                TInt aCommandId ) = 0;
    };


#endif // __MPbkEditorOkToExitCallback_H__

// End of File
