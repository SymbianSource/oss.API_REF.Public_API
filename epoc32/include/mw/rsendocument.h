/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Class extends RDocument, enabling handle counting
*
*/









#ifndef R_SEN_DOCUMENT
#define R_SEN_DOCUMENT

#include <xmlengdocument.h>
#include <xmlengdomimplementation.h>

typedef struct
    {
    TInt* ipOpenDocuments;
    void* iInternal;
    RXmlEngDOMImplementation iDomImpl;
    } TSenDocumentData;

class RSenDocument : public RXmlEngDocument
    {
    public:


        /**
         * Default constructor.
         *
         * @since S60 v3.1
         */
        /*inline RSenDocument():RDocument()
            {
            ipOpenDocuments = new (ELeave) TInt(1);
            }*/

        /**
        * Create new document.
        *
        * @since S60 v3.1
        */
        IMPORT_C static RSenDocument NewL();

        /**
        * Create new document and put it on cleanup stack.
        *
        * @since S60 v3.1
        */
        IMPORT_C static RSenDocument NewLC();

        /**
        * Create new document.
        *
        * @since S60 v3.1
        * @param aInternal Document pointer
        */
        IMPORT_C static RSenDocument NewL(void* aInternal);

        /**
        * Create new document and put it on cleanup stack.
        *
        * @since S60 v3.1
        * @param aInternal Document pointer
        */
        IMPORT_C static RSenDocument NewLC(void* aInternal);

        /**
        * Copies a RSenDocument.
        * Both the original and the copy must be separately closed.
        *
        * @since S60 v3.1
        * @return Copy of this RSenDocument
        */
        IMPORT_C RSenDocument Copy();
        
        /**
        * Closes a RSenDocument.
        *
        * You must close (or destroy) every RSenDocument you create using NewL or NewLC.
        * In other words, every call to RSenDocument::Copy(), RSenDocument::NewL() and
        * RSenDocument::NewLC() must be matched by a close or destroy.
        * Note: Also Destroy() method can be used to close RSenDocument.
        *
        * @since S60 v3.1
        * @see RSenDocument::Destroy()
        */        
        IMPORT_C void Close();
        
        /**
        * Closes a RSenDocument.
        *
        * You must destroy (or close) every RSenDocument you create using NewL or NewLC.
        * In other words, every call to RSenDocument::Copy(), RSenDocument::NewL() and
        * RSenDocument::NewLC() must be matched by a close or destroy.
        * Note: Also Close() method can be used to destroy RSenDocument.
        *
        * @since S60 v3.1
        * @see RSenDocument::Close()
        */        
        IMPORT_C void Destroy();
        
        /**
        * Sets the Tls
        *
        * @return KErrNone
        *		  KErrUnknown if the Tls is unknown
        *		  KErrAlreadyExists	if the Tls already exist.
        */
        IMPORT_C static TInt ManualXmlEngineTlsAttachL();

        /**
        * Frees the Tls
        *
        * @return KErrNone
        *		  KErrNotFound if the Tls is not found
        */
        IMPORT_C static TInt ManualXmlEngineTlsCleanup();

    public:
    	TSenDocumentData* ipData;
    };

#endif // R_SEN_DOCUMENT

// End of File


