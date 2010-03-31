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
* Description: Implementation of Extended Connection Preferences API.
*              
*              This API defines extended connection parameters as a part of
*              custom preferences mechanism making possible for Symbian 
*              licensees to define their own parameter extensions.
*
*/

#if !(defined __EXTENDEDCONNPREF_H__)
#define __EXTENDEDCONNPREF_H__

#include <e32base.h>
#include <comms-infras/metadata.h>
#include <connpref.h>
#include <cmmanagerdef.h>


class TExtendedConnPref : public Meta::SMetaDataECom
/**
User of this API must remember to link against extendedconnpref.lib and 
netmeta.lib and add #include <extendedconnpref.h>.

Set methods for the extended connection preference. This preference cannot be
used with RConnection::Start as a TConnPref. It must be part of a 
TConnPrefList. The extented connection preference can be appeded to connection
setup parameters before RConnection::Start() dispatch. Appending is carried 
out as follows. 

See connpref.h for more details.

@code

RSocketServ sockSvr;
RConnection conn;

sockSvr.Connect();
User::LeaveIfError(conn.Open(sockSvr));
CleanupClosePushL(conn);

TConnPrefList prefList;
TExtendedConnPref extPrefs;

extPrefs.SetSnapPurpose( CMManager::ESnapPurposeInternet );
extPrefs.SetNoteBehaviour( ENoteBehaviourConnSilent );

prefList.AppendL(&extPrefs);

TInt error = conn.Start(prefList);

CleanupStack::PopAndDestroy(&conn);
@endcode

@see TConnPrefList
@see RConnection::Start

@publishedAll
@released since S60 5.2
*/
    {
public:
 
    enum
        {
        /** UID for Extended Connection Preference API implementation. */
        EUid = 0x20016A82, 
        /** Subidentifier. */
        ETypeId = 1
        };

    /**
    * ExtendedConnBearer enables application to request a specific bearer for
    * a connection.
    */
    enum TExtendedConnBearer
        {
        /** Bearer support unknown. */
        EExtendedConnBearerUnknown  = 0x00000000,
        /** Support GPRS, 3G and Cdma2000 bearers. CSD not supported. */
        EExtendedConnBearerCellular = 0x00000001,
        /** WLAN bearer support. */
        EExtendedConnBearerWLAN     = 0x00000002
        };

    /**
    * TNoteBehaviour enables application to request a specific behaviour from
    * the middleware regarding displaying of dialogs, notes and queries.
    */
    enum TNoteBehaviour
        {
        /** Displays notes and queries according to default settings. */
        ENoteBehaviourDefault            = 0x00000000,
        /**
        * Starts connection and roams between different bearers without any 
        * notes, i.e., notes about connection state are not shown to the user.
        */
        ENoteBehaviourConnDisableNotes   = 0x00000001,
        /**
        * Roams between different bearers without displaying any queries to
        * the user but informs the user on the events with dialogs or notes.
        * User is able to see only notes about connection state but not any
        * queries which would need user's confirmation.
        */
        ENoteBehaviourConnDisableQueries = 0x00000002
        };

    /**
    * Starts connection and roams between different bearers without any 
    * queries, dialogs or notes, i.e., nothing about connection is shown
    * to the user.
    */
    static const TUint32 ENoteBehaviourConnSilent =
        ENoteBehaviourConnDisableNotes | ENoteBehaviourConnDisableQueries;

    /** 
    * Constructor.
    */
    IMPORT_C TExtendedConnPref();
    
    /**
    * Sets the purpose of the SNAP identifying where the connection is 
    * requested to. This function enables applications to start a connection
    * to, e.g., Internet SNAP or intranet SNAP without iterating through all
    * SNAPs to find the ID of the right one.
    * Default value is ESnapPurposeUnknown meaning that any SNAP is fine.
    * 
    * If SNAP purpose is set, IAP id shall be zero.
    * If SNAP purpose is set, SNAP id shall be zero.
    * If SNAP purpose is set, Connection selection dialog shall be disabled.
    * Either SNAP purpose, SNAP id, or IAP id shall be given, or Connection
    * selection dialog shall be enabled.
    * 
    * @param aSnapPurpose SNAP Purpose.
    */
    IMPORT_C void SetSnapPurpose( CMManager::TSnapPurpose aSnapPurpose );

    /**
    * Gets SNAP purpose.
    *
    * @return SNAP purpose.
    */
    IMPORT_C CMManager::TSnapPurpose SnapPurpose() const;

    /**
    * Sets SNAP id. If SNAP id is zero, it is interpreted as 
    * client's request for not requesting any specific SNAP.
    * Default value is 0.
    *
    * If SNAP id is set, IAP id shall be zero.
    * If SNAP id is set, SNAP purpose shall be CMManager::ESnapPurposeUnknown.
    * If SNAP id is set, Connection selection dialog shall be disabled.
    * Either SNAP purpose, SNAP id, or IAP id shall be given, or Connection
    * selection dialog shall be enabled.
    *
    * @param aSnap SNAP id.
    */
    IMPORT_C void SetSnapId( TUint32 aSnapId );

    /**
    * Gets SNAP id.
    *
    * @return SNAP id.
    */
    IMPORT_C TUint32 SnapId() const;

    /**
    * Sets IAP id.
    * 
    * Setting IAP id means that the connection will be made utilizing given
    * IAP id no matter what existing connections are available.
    * 
    * If IAP id is zero, it is interpreted as
    * client's request for not requesting any specific IAP.
    * Default value is 0.
    * 
    * If IAP id is set, SNAP id shall be zero.
    * If IAP id is set, SNAP purpose shall be CMManager::ESnapPurposeUnknown.
    * If IAP id is set, Connection selection dialog shall be disabled.
    * If IAP id is set, bearer set shall be EExtendedConnBearerUnknown.
    * If IAP id is set, forced roaming is disabled automatically.
    * Either SNAP purpose, SNAP id, or IAP id shall be given, or Connection
    * selection dialog shall be enabled.
    * 
    * @param aIap IAP id.
    */
    IMPORT_C void SetIapId( TUint32 aIapId );

    /**
    * Gets IAP id.
    *
    * @return IAP id.
    */
    IMPORT_C TUint32 IapId() const;

    /**
    * Sets bearer, use combination of TExtendedConnBearer values.
    * Default value is KExtendedConnBearerUnknown.
    *
    * @param aBearerSet A set of bearers as a combination of
    *                   TExtendedConnBearer values.
    *                   Type is TUint32 due to bitfield character.
    */
    IMPORT_C void SetBearerSet( TUint32 aBearerSet );

    /**
    * Gets set of requested bearers.
    *
    * @return Set of requested bearers. Type is TUint32 due to bifield
    *         character.
    */
    IMPORT_C TUint32 BearerSet() const;

    /**
    * Sets note behaviour, use combination of TNoteBehaviour values.
    * Default value is ENoteBehaviourDefault.
    * This method does not control connection selection dialog or disconnect
    * dialog. There are own methods for these purposes in this API.
    *
    * @param aNoteBehaviour Note behaviour as a combination of TNoteBehaviour
    *                       values. Type is TUint32 due to bitfield
    *                       character.
    */ 
    IMPORT_C void SetNoteBehaviour( TUint32 aNoteBehaviour );

    /**
    * Gets note behaviour.
    *
    * @return Note behaviour as a combination of TNoteBehaviour values.
    *         Type is TUint32 due to bitfield character.
    */
    IMPORT_C TUint32 NoteBehaviour() const;

    /**
    * Enables or disables Disconnect dialog.
    * By default, Disconnect dialog is enabled.
    *
    * @param aEnableDisconnectDialog Indicates whether Disconnect dialog is
    *                                enabled or disabled.
    */
    IMPORT_C void SetDisconnectDialog( TBool aEnableDisconnectDialog );

    /**
    * Indicates whether Disconnect dialog is enabled.
    *
    * @return Indicates whether Disconnect dialog is enabled.
    */
    IMPORT_C TBool DisconnectDialog() const;

    /**
    * Enables or disables Connection selection dialog. Only the SNAPs/IAPs
    * matching with BearerSet are shown in the dialog.
    * By default, Connection selection dialog is disabled.
    *
    * If Connection selection dialog is enabled, SNAP id shall be zero.
    * If Connection selection dialog is enabled, IAP id shall be zero.
    * If Connection selection dialog is enabled, SNAP purpose shall be
    * CMManager::ESnapPurposeUnknown.
    * Either SNAP purpose, SNAP id, or IAP id shall be given, or Connection
    * selection dialog shall be enabled.
    *
    * @param aConnSelectionDialog Indicates whether Connection selection
    *                             dialog is enabled or disabled.
    */
    IMPORT_C void SetConnSelectionDialog( TBool aConnSelectionDialog );

    /**
    * Indicates whether Connection selection dialog is enabled.
    *
    * @return Indicates whether Connection selection dialog is enabled.
    */
    IMPORT_C TBool ConnSelectionDialog() const;

    /**
    * Enables or disables forced roaming.
    * By default, forced roaming is enabled.
    * Forced roaming only applies on connections made to Internet SNAP.
    * 
    * Forced roaming means that the connection can be torn down by the
    * middleware when better one is available. E.g., when known WLAN IAP
    * becomes available, 3G connection is disconnected.
    * 
    * @param aForcedRoaming Indicates whether forced roaming is enabled or
    *                       disabled.
    */
    IMPORT_C void SetForcedRoaming( TBool aForcedRoaming );

    /**
    * Indicates whether forced roaming is enabled.
    *
    * @return Indicates whether forced roaming is enabled.
    */
    IMPORT_C TBool ForcedRoaming() const;

protected:
    /** SMetaData implied functions */
    EXPORT_DATA_VTABLE_AND_FN

private:

    /** SNAP purpose. */
    CMManager::TSnapPurpose iSnapPurpose;
    /** SNAP id. */
    TUint32 iSnapId;
    /** IAP id. */
    TUint32 iIapId;
    /** Bearer set. */
    TUint32 iBearerSet;
    /** Note behaviour. */
    TUint32 iNoteBehaviour;
    /** Indicates whether UI disconnect dialog is shown. */
    TBool iDisconnectDialog;
    /** Indicates whether UI connection selection dialog is shown. */    
    TBool iConnSelectionDialog;
    /** Indicates whether forced roaming is enabled. */
    TBool iForcedRoaming;
    };


#endif __EXTENDEDCONNPREF_H__
