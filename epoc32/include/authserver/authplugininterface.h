/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
* CAuthPluginInterface 
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTHPLUGININTERFACE_H
#define AUTHPLUGININTERFACE_H


#include <authserver/authtypes.h>
#include <ecom/implementationinformation.h>

namespace AuthServer
{

/// The interface UID for the authentication plugin interface
const TUid KCAuthPluginInterfaceUid = { 0x102740FE }; 


/**
 * The ECOM interface for authentication plugins. An authentication plugin is
 * used to help identify the current device holder. When a plugin is asked to
 * identify the holder, it interacts with the user and potentially hardware or
 * services provided by other servers. The plugin then generates some data
 * which is unique and repeatable for the input recieved. This data should
 * not be persisted on the device in any form that can easily be used to
 * recover the data.
 *
 * For example, a plugin might request a PIN number from the user. The plugin
 * will take the number, perhaps compare the hash of the number against the
 * hashes recorded during training and if a match is found return the identity
 * along with some unique data associated with it.
 *
 */	
class CAuthPluginInterface : public CBase
	{
public:

	/**
	 * @return the id of the plugin. This should be the ECOM implementation id.
	 **/
	virtual TPluginId Id() const = 0;

	/**
	 *
	 * @return the name of the plugin.
	 * 
	 **/
	virtual const TPtrC& Name() const = 0;
	
	/**
	 *
	 * @return a description of the plugin.
	 * 
	 **/
	virtual const TPtrC& Description() const = 0;

	/**
	 *
	 * @return the minimum entropy of the plugin.
	 * 
	 **/
	virtual TEntropy MinEntropy() const = 0;
	
	/**
	 *
	 * @return the rate of false positive identifications.
	 * 
	 **/
	virtual TPercentage FalsePositiveRate() const = 0;

	/**
	 *
	 * @return the rate of false negative identifications.
	 * 
	 **/
	virtual TPercentage FalseNegativeRate() const = 0;

	/**
	 *
	 * @return the type of plugin
	 * 
	 **/
	virtual TAuthPluginType Type() const = 0;

	/**
	 * Performs actions required to identify the current device holder. 
	 *
	 * For details see the reference/test implementation of a knowledge-type 
	 * plugin called the pinplugin.
	 *
	 * @param aId in the event of a successfull call, aId will be set to the
	 * id of the identity. The value is not modified otherwise. It should be
	 * noted that a successful call includes the possibility of not
	 * recognising the user in which case aId should be set to
	 * KUnknownIdentity.
	 *
	 * @param aClientMessage A displayable text string parameter for authentication
	 * requests.It shall be passed to plug-ins to display to the users.
	 *
	 * @param aResult in the event of a successfull call, aResult contains the
	 * data generated from the identification process. This data is used by
	 * the authentication server to generate a transient key which in turn is
	 * used to decrypt the identities protection key. If the call was
	 * unsuccessful or the user is unknown no buffer will be created. Ownership of 
	 * the buffer is transfered to the caller.
	 *
	 * @param aRequest the request status through which the caller will be
	 * notified of completion. Upon completion, the status value will be one of the
	 * following :
	 * KErrNone if the identification process is successful.
	 * KErrAuthServPluginCancelled if the user cancels the identification process for
	 * this plugin.
	 * KErrAuthServPluginQuit if the user quits the whole identification
	 * process.
	 * ... or any of the system wide error codes.
	 **/


	virtual void Identify(TIdentityId& aId, const TDesC& aClientMessage, 
						  HBufC8*& aResult, TRequestStatus& aRequest) = 0;

	/**
	 * Cancel the current action. This method must complete with KErrCancel
	 * any outstanding asyncronous requests such as Train or Identify.
	 **/


	virtual void Cancel() = 0;
	
	/**
	 * This method tells the plugin to operate in training mode. After the
	 * successful this method the plugin should be able to correctly identify
	 * the specified identity using the Identify method. If the plugin already
	 * has existing training data for the identity then the data should be
	 * replaced. Care should be taken to allow the user to cancel or quit the
	 * training without losing the existing training.  
	 * 
	 * @param aId the identity for whom to train the plugin. This allows the
	 * plugin to persist training data associated with the identity and delete
	 * or update that data later on.
	 *
	 * @param aResult this buffer will be filled with data that matches the
	 * current device holder. This should be the same data as is returned by
	 * the Identify method for the same identity. Ownership of the buffer is 
	 * transfered to the caller.
	 *
	 * @param aRequest the request status through which the caller will be
	 * notified of completion. Upon completion the status value will be one of the
	 * following :
	 * KErrNone if the training process is successful.
	 * KErrAuthServPluginCancelled if the user cancels the training process for
	 * this plugin.
	 * KErrAuthServPluginQuit if the user quits the whole training
	 * process.
	 * ... or any of the system wide error codes.
	 **/


	 virtual void Train(TIdentityId aId, HBufC8*& aResult,
						TRequestStatus& aRequest) = 0;

	/**
	 * @return true if the plugin can be used for identification or training
	 * purposes without further user intervention. 
	 **/


	virtual TBool IsActive() const = 0;
	
	/**
	 * Remove any stored training data for the specified identity. This is
	 * used if an identity is being removed from the device. No user
	 * interaction should take place as a result of this call.
	 *
	 * @param aId the identity for whom to remove any persisted training data.
	 *
	 * @return KErrNone if the operation is successful.
	 * @return KErrAuthServNoSuchIdentity if the TIdentityId wasn't recognised.
	 * @return ... or any of the system wide error codes.
	 **/


	 virtual TInt Forget(TIdentityId aId) = 0;

	/**
	 * Pretend the device holder has identified themselves using a default
	 * entry. For example, a pin number plugin would return the same data as
	 * if the holder had entered the default pin. This call is used during the
	 * creation of the initial device identity and allows the device to be
	 * operated without the user being forced to train plugins the first time
	 * the device is started. No user interaction should take place as a
	 * result of this call.
	 *
	 * Only plugins of type EAuthKnowledge should support default
	 * data. Plugins of other types will be ignored.
	 *
	 * @param aId The identity that will be registered using the default data. 
	 * 
	 * @param aOutputBuf This buffer should be filled with the data that would
	 * be generated if the phone holder identified themselves using the
	 * default manner. Ownership of the buffer is transfered to the caller. 
	 *
	 * @return KErrNone if the plugin supports default data.
	 * @return KErrNotSupported if the plugin doesn't support default data.
	 * @return ... or any of the system wide error codes.
	 **/


	 virtual TInt DefaultData(TIdentityId aId, HBufC8*& aOutputBuf) = 0;

	/**
	 * This method tells the plugin to remove the training data held for the given identity 
	 * and to regenerate it using the supplied registration data. The intent of this method 
	 * is to allow a backend reset of user credentials in situations where the user is not 
	 * able to provide the credentials for some reason (for instance the user has forgotten 
	 * the password). Note that no user interaction should take place as a result of this call. 
	 * Since the registration data may not be usable by all plugin types it is expected that only 
	 * EAuthKnowledge type plugins (those based on pins, passphrases, etc.) use this data for 
	 * registering the user and return the result.
	 *
	 * @param aId The identity whose training data should be reset. 
	 * 
	 * @param aRegistrationData The data that can be used to register the identity. 
	 * This data is meaningful for EAuthKnowledge type plugins. Other plugins may choose to 
	 * ignore this parameter. An empty descriptor signifies the absence of registration data.
	 *
	 * @param aResult This buffer will be filled with data that matches the specified identity. 
	 * This should be the same data subsequently returned by the Identify method for the same identity. 
	 * Note that plugins that aren't supplied registration data or those that don't use the supplied 
	 * registration data for the reset can return NULL. Ownership of the buffer is transfered to 
	 * the caller.
	 *
	 * @return KErrNone if the plugin is successfully able to either remove and/or reset the training data.
	 * @return KErrNotSupported if the plugin doesn't support a reset functionality.
	 * @return ... or any of the system wide error codes.
	 **/


	 virtual TInt Reset(TIdentityId aId, const TDesC& aRegistrationData, 
			 			HBufC8*& aResult) = 0;
	
	/**
	 * 
	 * Destructor.
	 * 
	 **/


	virtual ~CAuthPluginInterface() {};
	
};	

} // namespace

#endif
