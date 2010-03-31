/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Implementation of XML namespace functionality
*
*/








#ifndef SEN_NAME_SPACE_H
#define SEN_NAME_SPACE_H

//  INCLUDES
#include <e32base.h>
#include <s32mem.h>

// CLASS DECLARATION

/**
* Implementation of XML namespace functionality
* All data is in UTF-8 form.
* @lib SenXML.dll
* @since Series60 3.0
*/
class CSenNamespace :   public CBase
    {
    public:  // Constructors and destructor
        
        /**
         * Basic constructor.
         * @param   aPrefix The prefix for the namespace.
         * @param   aUri    The namespace uri for the namespace.
         */
        IMPORT_C static CSenNamespace* NewL(const TDesC8& aPrefix,
                                            const TDesC8& aUri);
        /**
         * Basic constructor.
         * @param   aPrefix The prefix for the namespace.
         * @param   aUri    The namespace uri for the namespace.
         */
        IMPORT_C static CSenNamespace* NewLC(const TDesC8& aPrefix,
                                             const TDesC8& aUri);
        /**
         * Basic constructor.
         * @param   aUri    The namespace uri for the namespace.
         */
        IMPORT_C static CSenNamespace* NewL(const TDesC8& aUri);

        /**
         * Basic constructor.
         * @param   aUri    The namespace uri for the namespace.
         */
        IMPORT_C static CSenNamespace* NewLC(const TDesC8& aUri);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenNamespace();
        
    public: // New functions
        
        /**
         * Getter for the URI of the namespace object.
         * @return  The URI
         */
        IMPORT_C const TDesC8& URI() const;

        /**
         * Getter for the prefix of the namespace object.
         * @return  The prefix
         */
        IMPORT_C const TDesC8& Prefix() const;

        /**
         * Setter for the URI of the namespace object.
         * @param aUri  The URI.
         */
        IMPORT_C void SetUriL(const TDesC8& aUri);

        /**
         * Setter for the prefix of the namespace object.
         * @param aPrefix   The prefix.
         */
        IMPORT_C void SetPrefixL(const TDesC8& aPrefix);

        /**
         * Method for comparing the namespace object to other prefix 
         * and URI.
         * @param aOtherPrefix  The prefix to be compared to
         * @param aOtherUri     The URI to be compared to.
         * @return ETrue if both of the parameters were matching to the 
         *               object's corresponding ones. EFalse otherwise
         */
        IMPORT_C TBool Compare(const TDesC8& aOtherPrefix,
                               const TDesC8& aOtherUri) const;

        /**
         * Method for comparing the namespace object to other namespace 
         * object.
         * @param aOtherNamespace       The namespace to be compared to.
         * @return ETrue if the given namespace has same URI and prefix as the
         *              current one. EFalse otherwise.
         */
        IMPORT_C TBool Compare(const CSenNamespace& aOtherNamespace) const;
        
        /**
         * Method for comparing the namespace object to other namespace 
         * object. Differs from Compare(...) methods so that this one
         * compares only URIs.
         * @return  ETrue   if the given namespace has the same URI as 
         *                  the current one. EFalse otherwise.
         */
        IMPORT_C TBool MatchesL(const CSenNamespace& aOtherNamespace) const;

        /**
         * Method to ask this namespace object to write itself into a 
         * writestream. Doesn't write anything if no URI has been set.
         * @param aWs   The writestream where object should be written.
         */
        IMPORT_C void InsertL(RBufWriteStream& aWs);
    
    private:

        /**
        * C++ default constructor.
        */
        CSenNamespace();

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL(const TDesC8& aPrefix, const TDesC8& aUri);

    private: // Data
        HBufC8* ipPrefix;
        HBufC8* ipUri;
    };

#endif // SEN_NAME_SPACE_H

// End of File



