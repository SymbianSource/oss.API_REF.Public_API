/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Phonebook 2 contact name formatter interface.
*
*/


#ifndef MPBK2CONTACTNAMEFORMATTER2_H
#define MPBK2CONTACTNAMEFORMATTER2_H


/**
 * This class is an extension to MPbk2ContactNameFormatter.
 * See documentation of MPbk2ContactNameFormatter from header
 * MPbk2ContactNameFormatter.h
 * 
 * you can access this extension by calling
 * MPbk2ContactNameFormatter->ContactNameFormatterExtension()
 */
class MPbk2ContactNameFormatter2
    {
    public: // Interface

        /**
         * Returns the title text for a contact.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aFormattingFlags Formatting flags, 
         *                         see TPbk2ContactTitleFormattingFlags.
         * @return  A buffer containing the formatted title,
         *          or the UnnamedText() method's result if no title 
         *          can be created.
         */
        virtual HBufC* GetContactTitleWithCompanyNameL(
                const MVPbkBaseContactFieldCollection& aContactFields,
                TUint32 aFormattingFlags ) = 0;
                
    protected:
    
        virtual ~MPbk2ContactNameFormatter2()
                {}

     
      
    };

#endif // MPBK2CONTACTNAMEFORMATTER2_H

// End of File
