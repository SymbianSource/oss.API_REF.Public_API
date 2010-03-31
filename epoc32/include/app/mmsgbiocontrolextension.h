/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:   Interface to extend bio control functionality
*
*/



#ifndef MSGBIOCONTROLEXTENSION_H
#define MSGBIOCONTROLEXTENSION_H

/**
 * Bio control extension interface ids.
 *
 * @see MMsgBioControlExtension::BioControlExtension
 */
enum TMsgBioControlExtensions
    {
    // Add new enum tag for a new extension. To maintain BC always add new
    // tags only to the end of existing tags and do not touch existing tags,
    // even if extensions are deprecated. Link the enum tags to types using
    // Doxygen comments.

    /**
     * Extension interface id for MMsgBioControlScrollExtension.
     */
    KMsgBioControlScrollExtension = 1
    };

/**
 * Interface for Bio control extension.
 *
 * @since 3.2
 */
class MMsgBioControlExtension
    {
    public:

    /**
     * Extension point for future BIO control extension interfaces.
     * @since 3.2
     * @param aExtensionId The identifier for the requested extension interface.
     *                     See TMsgBioControlExtensions.
     * @return Untyped pointer to the extension interface.
     *         The pointer must be cast to appropriate type.
     */
    virtual TAny* BioControlExtension( TInt aExtensionId ) = 0;
    };

/**
 * Interface for scrolling extension
 *
 * @since 3.2
 */
class MMsgBioControlScrollExtension
    {
    public:

    /**
     * Performs the internal scrolling of control if needed.
     * @since 3.2     
     * @param aPixelsToScroll Amount of pixels to scroll.
     * @param aDirection      Scrolling direction.
     * @return Amount of pixels that were scrolled. Zero value means the component
     * cannot be scrolled to that direction anymore and view should be moved.
     */
    virtual TInt ExtScrollL( TInt aPixelsToScroll, TMsgScrollDirection aDirection ) = 0;

    /**
     * Prepares control for viewing.
     * @since 3.2     
     * @param aEvent	The event type
     * @param aParam Event related parameters
     */
    virtual void ExtNotifyViewEvent( TMsgViewEvent aEvent, TInt aParam ) = 0;
    };

#endif // MSGBIOCONTROLEXTENSION_H