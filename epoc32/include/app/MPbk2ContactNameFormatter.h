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


#ifndef MPBK2CONTACTNAMEFORMATTER_H
#define MPBK2CONTACTNAMEFORMATTER_H

// INCLUDE FILES
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkBaseContactFieldCollection;
class MVPbkFieldType;
class MVPbkFieldTypeList;
class CVPbkFieldTypeRefsList;
class MVPbkBaseContactField;
class CVPbkBaseContactFieldTypeListIterator;

//Use this UID to access field property interface extension 2. Used as
//a parameter to ContactNameFormatterExtension() method.
const TUid MPbk2ContactNameFormatterExtension2Uid = { 2 };
/**
 * Abstract Phonebook 2 contact name formatter interface.
 */
class MPbk2ContactNameFormatter
    {
    public: // Interface

        /// Flags
        enum TPbk2ContactTitleFormattingFlags
            {
            /// Formatter preserves all leading spaces
            /// in the formatted title
            EPreserveLeadingSpaces      = 0x0001,
            /// Formatter uses custom separator
            /// for separating firstname and lastname
            EUseSeparator               = 0x0002,
            /// Formatter replaces all non-graphical
            /// characters with space character
            EReplaceNonGraphicChars     = 0x0004,
            /// Formatter to retain all original space characters
            EPreserveAllOriginalSpaces  = 0x0008
            };

        /**
         * Destructor.
         */
        virtual ~MPbk2ContactNameFormatter()
                {}

        /**
         * Returns the title text for a contact.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aFormattingFlags  @see TPbk2ContactTitleFormattingFlags
         * @return  A buffer containing the formatted title,
         *          NULL if no title can be created.
         */
        virtual HBufC* GetContactTitleOrNullL(
                const MVPbkBaseContactFieldCollection& aContactFields,
                TUint32 aFormattingFlags ) = 0;

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
        virtual HBufC* GetContactTitleL(
                const MVPbkBaseContactFieldCollection& aContactFields,
                TUint32 aFormattingFlags ) = 0;

        /**
         * Returns the title text for a contact.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aTitle            Buffer containing the formatted title.
         * @param aFormattingFlags  @see TPbk2ContactTitleFormattingFlags
         */
        virtual void GetContactTitle(
                const MVPbkBaseContactFieldCollection& aContactFields,
                TDes& aTitle,
                TUint32 aFormattingFlags ) = 0;

        /**
         * Returns the title text for a contact. Unlike GetContactTitle,
         * this method will build the title using all the possible fields
         * (not restricting the field count). Should not be used for
         * regular name formatting needs.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aTitle            Buffer containing the formatted title.
         * @param aFormattingFlags  @see TPbk2ContactTitleFormattingFlags
         */
        virtual void GetContactTitleForFind(
                const MVPbkBaseContactFieldCollection& aContactFields,
                TDes& aTitle,
                TUint32 aFormattingFlags ) = 0;

        /**
         * Returns the name text to be used for unnamed contacts.
         *
         * @return  Text used with unnamed contacts.
         */
        virtual const TDesC& UnnamedText() const = 0;

        /**
         * Returns ETrue if the given field is part of the fields used to
         * build the contact title.
         *
         * @param aContactField     The contact field to inspect.
         * @return  ETrue if the given field is used when building
         *          contact titles.
         */
        virtual TBool IsTitleField(
                const MVPbkBaseContactField& aContactField ) const = 0;

        /**
         * Returns ETrue if the given field is part of the fields used to
         * build the contact title.
         *
         * @param aFieldType    Type of the field to inspect.
         * @return  ETrue if the given field type is used when
         *          building contact titles.
         */
        virtual TBool IsTitleFieldType(
                const MVPbkFieldType& aFieldType ) const = 0;

        /**
         * Return iterator that contains all fields that are used for making
         * the formatted name.
         *
         * @param   aFieldTypeList  Field type list that is used to store
         *                          field types for the iterator. The list
         *                          will be resetted before use.
         * @param   aContactFields  Field collection representing
         *                          the data in a contact.
         * @return  Iterator for fields that are used for the formated title.
         */
        virtual CVPbkBaseContactFieldTypeListIterator* ActualTitleFieldsLC(
                CVPbkFieldTypeRefsList& aFieldTypeList,
                const MVPbkBaseContactFieldCollection& aContactFields ) = 0;

        /**
         * Returns the length of the formatted name.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aFormattingFlags  @see TPbk2ContactTitleFormattingFlags
         * @return  Length of the formatted name.
         */
        virtual TInt MaxTitleLength(
                const MVPbkBaseContactFieldCollection& aContactFields,
                const TUint32 aFormattingFlags ) = 0;

        /**
         * Returns the length of the formatted name. Unlike MaxTitleLength,
         * this method will count the length using all the possible fields
         * (not restricting the field count). Should not be used for
         * regular name formatting needs.
         *
         * @param aContactFields    Field collection representing
         *                          the data in a contact.
         * @param aFormattingFlags  @see TPbk2ContactTitleFormattingFlags
         * @return  Length of the formatted name.
         */
        virtual TInt MaxTitleLengthForFind(
                const MVPbkBaseContactFieldCollection& aContactFields,
                const TUint32 aFormattingFlags ) = 0;

        /**
         * Checks whether the given character is a separator character.
         *
         * @param aChar     Character that will be checked.
         * @return ETrue if character is a separator character.
         */
        virtual TBool IsFindSeparatorChar(
                TChar aCh ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid     Extension UID.
         * @return  Extension point.
         */
        virtual TAny* ContactNameFormatterExtension(
                TUid /*aExtensionUid*/ )
            {
            return NULL;
            }
    };

#endif // MPBK2CONTACTNAMEFORMATTER_H

// End of File
