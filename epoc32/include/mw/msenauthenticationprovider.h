/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Callback interface through which (web service consumer/management)
*                applications can provide userinfo / account (username & password)
*                to WS-stack. This information can be used in actual authentication
*                with (remote) web service (Liberty Authentication Service or 
*                WS-* STS), or locally (in device) to allow secure access to private
*                information (like credentials to the service, etc).
*
*/








#ifndef M_SEN_AUTHENTICATION_PROVIDER_H
#define M_SEN_AUTHENTICATION_PROVIDER_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class CSenIdentityProvider;

/**
* Interface description:
*
* The applications can register this callback interface, through which they will receive
* userinfo callbacks (when data like username and password is needed).
*
* Both Service Connection and Service Manager APIs utilize this interface.
*
* In practice, service consumer applications often integrate these callbacks to their UI 
* events, allowing them a control point end-user (login) prompts. 
*
* Furthermore, (remote) service management applications can provide identity (user account)
* spesific "secret", in order to manipulate associated credentials stored in Web Services
* -stack database(s).
*/
class MSenAuthenticationProvider
    {
    public: 
        /**
        * If (consumer) application needs to access protected information or service
        * (behind some identity / account / sing-in process), it may choose to override
        * this method. Returned object represents XML containing all required information
        * that is required to securely authenticate the identity in question.
        * In case that only username & password  -pair is needed, application may 
        * alternatively implement UsernameL() and PasswordL() callbacks.
        * @returs the identity provider description that contains "credentials", like
        * like username and password of some identity (user's account), or other (binary)
        * secret, like fingerprint. 
 
        */
        virtual const CSenIdentityProvider* IdentityProviderL() { return NULL; }

        /**
        * Callback type getter for username.
        * through this method an application may choose to provide the username of
        * an account it wishes to use. 
        * In cases where the username (login ID) is in simple text format (descriptor),
        * this may be the most convenient method to be overridden. Alternatively,
        * in complex cases, applications may choose to provide identity provider (IDP)
        * description, a piece of XML through IdentityProviderL() callback; that
        * XML could contain extended amount of (binary) information, like fingerprint.
        * Consumer application is supposed to decide, whether or not to show a GUI
        * dialog when this callback is issued: in many cases, that is a common
        * approach to prompt userinfo directly from end-user (unless data is cached
        * elsewhere).
        * @return Password as string (UTF-8 descriptor)
        */
        virtual const TPtrC8 UsernameL() { return TPtrC8(KNullDesC8); }

        /**
        * Callback type getter for password.
        * Application may choose to provide the passport of an account through this
        * method. In cases where the "secret" is in simple text format (descriptor),
        * this may be the most convenient method to be overridden. Alternatively,
        * in complex cases, applications may choose to provide identity provider (IDP)
        * description, a piece of XML through IdentityProviderL() callback; that
        * XML could contain extended amount of (binary) information, like fingerprint.
        * Consumer application is supposed to decide, whether or not to show a GUI
        * dialog when this callback is issued: in many cases, that is a common
        * approach to prompt userinfo directly from end-user (unless data is cached
        * elsewhere).
        * @return Password as string (UTF-8 descriptor)
        */
        virtual const TPtrC8 PasswordL() { return TPtrC8(KNullDesC8); }
        
        /**
        * This method obtains the callback interface matching the specified uid.
        * @param				aUid the uid identifying the required interface.
        * @return				NULL if no interface matching the uid is found.
        * 					    Otherwise, attempt to dynamically cast this pointer
        *                       to that interface will be made.
        */
    	inline virtual TAny* ExtendedInterface(const TInt32 /* aUid */) { return NULL; }
    };

#endif // M_SEN_PROPERTIES_H

// End of File

