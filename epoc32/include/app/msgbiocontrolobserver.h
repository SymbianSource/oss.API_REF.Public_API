/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  
*     Bio control observer.
*
*/



#ifndef __MSGBIOCONTROLOBSERVER_H_
#define __MSGBIOCONTROLOBSERVER_H_

// INCLUDES 
// CONSTANTS
// MACROS
// DATA TYPES
// FUNCTION PROTOTYPES
// FORWARD DECLARATIONS
// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
 * Interface for Bio Control Observer. The MMsgBioControlObserver is used
 * for observing the Bio Control from the editor application.
 */
class MMsgBioControlObserver
    {
    public:

        /**
         * The command types. For use in conjunction with the
         * functions of this class.
         */
        enum TMsgCommands
            {
            EMsgNone = 0,
            EMsgSave,
            EMsgReply,
            EMsgForwad,
            EMsgSend,
            EMsgAddressBook,          
            EMsgClose
            };
	
    public:

        /**
         * Returns the first free command id that a BIO control can use for
         * its own purposes. All the commands having ids of more or equal to
         * an id returned by this function are passed to the BIO control.
         * @return First free command.
         */
        virtual TInt FirstFreeCommand() const = 0;

        /**
         * Requests the BIO message editor/viewer to handle a command.
         * Typically the BIO message editor/viewer does not handle a requested
         * command immediately but after the BIO control has returned from the
         * HandleCommandL function.
         * @param aCommand The command that can be handled.
         * @return KerrNone or KerrNotSupported
         */
        virtual TInt RequestHandleCommandL(TMsgCommands aCommand) = 0;

        /**
         * Returns ETrue or EFalse whether a requested aCommand is supported
         * by the BIO message editor or not. This command should be used
         * before requesting command handling by RequestHandleCommand().
         * @param aCommand The command
         * @return ETrue if command is support and EFalse if not.
         */
        virtual TBool IsCommandSupported(TMsgCommands aCommand) const = 0;
    };


#endif // __MSGBIOCONTROLOBSERVER_H_

//end of file
