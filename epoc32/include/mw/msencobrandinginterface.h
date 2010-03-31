/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:           Callback interface for co-branding interface.
*
*/




#ifndef M_SEN_COBRANDING_INTERFACE_H
#define M_SEN_COBRANDING_INTERFACE_H

// CLASS DECLARATION
/**
 * Callback interface for co-branding.
 * Note: UID for this interface is KSenInterfaceUidCoBrandingObserver.
 *
 * Application that wishes to enable billing also needs to enable
 * following properties of client policy by calling
 * CSenXmlServiceDescription::SetPolicy( const TDesC8& aName, const TDesC8& aValue ):
 *
 *  - Application Info      [ <AppInfo/>,       KSenLocalnameAppInfo ]
 *  - WAP gateway address   [ <WAPGW"/>,        KSenLocalnameWAPGW   ] 
 *  - MWS namespace         [ <MwsNamespace/>,  KSenLocalnameMwsNamespace   ]
 *
 * If application does not provide WAP GW address as part of client policy,
 * it signalizes that application wants to skip communication with WAP GW
 * and talk directly with billing gateway instead. Typically, this depends
 * on operator spesific environment.
 */
class MSenCoBrandingObserver
    {
    public:
    /**
    * This method is called when list of co-branding IDs is receieved during authentication.
    * @param aBrandIdListAsXmlSnippet is the list of brand IDs in form of XML snippet
    * @param aSelectedBrandId is supposed to point to the brand ID selected by the application
    * when this callback returns.
    * @return TBool indicates whether or not the application wants to proceed (enable)
    * the use of billing ecosystem or stop the whole progress.
    */
    virtual TBool OnGetBrandIdL(  const TDesC8& aBrandIdListAsXmlSnippet, RBuf8& aSelectedBrandId) = 0;
    };
#endif // M_SEN_COBRANDING_INTERFACE_H

// End of File
