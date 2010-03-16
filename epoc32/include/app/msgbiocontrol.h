/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:   Base class for bio controls.
*
*/



#ifndef MSGBIOCONTROL_H
#define MSGBIOCONTROL_H


// INCLUDES
#include <msvstd.h>
#include <coecntrl.h>           // for CCoeControl
#include <mmsgbiocontrol.h>     // for MMsgBioControl
#include <badesca.h>            // for CDesCArray
#include <aknglobalnote.h>
#include <MsgEditor.hrh>        // for TMsgCursorLocation

// FORWARD DECLARATIONS

class MMsgBioControlObserver;
class CMsvSession;
class MMsgBioControlExtension;  


// CLASS DECLARATION

/**
 * The base class for Bio controls.
 */
class CMsgBioControl : public CCoeControl, public MMsgBioControl
    {

    public: //construction and destruction
            
        /**
         * Constructor. Call this from your Bio Control constructor.
         * @param aObserver Reference to the Bio control observer.
         * @param aSession Message Server session. Ownership not transferred.
         * @param aId Id of the message in the server.
         * @param aEditorOrViewerMode Sets Bio Control into editor or viewer mode.
         * @param aFile Data file handle. Bio controls can also be file based. Not owned.
         */
        IMPORT_C CMsgBioControl(
            MMsgBioControlObserver& aObserver,
            CMsvSession* aSession, //ownership is NOT transferred
            TMsvId aId,
            TMsgBioMode aEditorOrViewerMode,
            const RFile* aFile);   //ownership is NOT transferred

        /**
         * Destructor
         */
        IMPORT_C ~CMsgBioControl();

    public: // static helper functions

        /**
         * Pops a confirmation query. The result is given by the return value.
         * The standard resource must have been loaded using
         * LoadStandardBioResourceL().
         * @param aText The text that is to be used in the query.
         * @return A user confirmation results in ETrue, and vice versa.
         */
        IMPORT_C static TBool ConfirmationQueryL(const TDesC& aText);

        /**
         * Pops a confirmation query. The result is given by the return value.
         * The standard resource must have been loaded using
         * LoadStandardBioResourceL(). Your resource must also be loaded, for
         * eg. with LoadResourceL().
         * CCoeEnv must exist.
         * @param aStringResource The string resource id.
         * @return A user confirmation results in ETrue, and vice versa.
         */
        IMPORT_C static TBool ConfirmationQueryL(TInt aStringResource);

    public: // from MMsgBioControl

        /**
         * The application can get the option menu recommendations using this
         * function. The function comes from MMsgBioControl. This is the
         * default implementation which returns the flags
         * EMsgBioCallBack | EMsgBioDelete | EMsgBioMessInfo | EMsgBioMove | 
         * EMsgBioCreateCC | EMsgBioSend | EMsgBioAddRecipient | EMsgBioSave |
         * EMsgBioSendingOpt | EMsgBioHelp | EMsgBioExit. 
         * Bio Controls should override this if it is not ok.
         * @return The option menu permission flags. If the flag is off it
         * means that the option menu command is not recommended with this
         * Bio Control.
         */
        IMPORT_C TUint32 OptionMenuPermissionsL() const;

        /**
         * Gives the height of the text in pixels.
         * It is used by the scrolling framework.
         * @return Height of the text in pixels.
         */
        IMPORT_C TInt VirtualHeight();

        /**
         * Gives the cursor position in pixels.
         * It is used by the scrolling framework.
         * @return Cursor position in pixels.
         */
        IMPORT_C TInt VirtualVisibleTop();

        /**
         * Tells whether the cursor is in the topmost or bottom position.
         * It is used by the scrolling framework.
         * @param aLocation Specifies either top or bottom.
         * @return ETrue if the cursor is in the part specified by aLocation.
         */
        IMPORT_C TBool IsCursorLocation(TMsgCursorLocation aLocation) const;
    
    public: //new functions
    
        /**
         * Performs the internal scrolling of control if needed.
         * Default implementation does not perform any scrolling and returns that
         * zero pixels were scrolled.
         * @since 3.2
         * @param aPixelsToScroll Amount of pixels to scroll.
         * @param aDirection      Scrolling direction.
         * @return Amount of pixels the where scrolled. Zero value means the component cannot
         *         be scrolled to that direction anymore and view should be moved.
         */
        IMPORT_C TInt ScrollL( TInt aPixelsToScroll, TMsgScrollDirection aDirection );

        /**
         * Prepares control for viewing.
         * @since 3.2
         * @param aEvent	The event type
         * @param aParam Event related parameters
         */
        IMPORT_C void NotifyViewEvent( TMsgViewEvent aEvent, TInt aParam );


    protected: //new functions

        /**
         * Returns true if the control has been launched as editor,
         * and false if it was launched as viewer.
         * @return ETrue or EFalse
         */
        IMPORT_C TBool IsEditor() const;

        /**
         * Is the Bio Control file based or not.
         * @return ETrue if is file based.
         */
        IMPORT_C TBool IsFileBased() const;

        /**
         * Accessor for MsvSession. The session exists only if the Bio Control
         * has been created as message server based.
         * @exception Panics if there is no session.
         * @return CMsvSession&
         */
        IMPORT_C CMsvSession& MsvSession() const;

        /**
         * Deprecated*
         * 
         * Returns name of input file.
         * @return Name of file.
         * @exception Panics if the control is not file based.
         */
        IMPORT_C const TFileName& FileName() const;

        /**
         * Deprecated* Handle is valid only at contsruction phase!!
         * To be removed.
         * Returns input file handle.
         * @return handle of file.
         * @exception Panics if the control is not file based.
         */
        IMPORT_C const RFile& FileHandle() const;

        /**
         * Loads a resource file from /system/data/ into eikon env. This
         * function should be used for loading the Bio Control resources.
         * The resources are unloaded in the destructor of this class. The
         * offsets are kept in iResourceOffsets.
         * @param aFile File name mask, for eg. "vcalbc.r??".
         */
        IMPORT_C void LoadResourceL(const TDesC& aFile);

        /**
         * Loads a resource file into eikon env. The resources are unloaded in
         * the destructor of this class. (the offsets are kept in
         * iResourceOffsets).
         * @param aFile File name mask, for eg. "vcalbc.r??".
         * @param aSearchPath Search path, for eg. "\\System\\libs\\".
         */
        IMPORT_C void LoadResourceL(const TDesC& aFile,
            const TDesC& aSearchPath);

        /**
         * This loads the msgeditorutils.rsc resource, which is needed by
         * the dialogs and notes of this class.
         */
        IMPORT_C void LoadStandardBioResourceL();

        /**
         * Adds a menu item to the menu pane which is given as a reference.
         * @param aMenuPane Reference to the menu pane.
         * @param aStringRes The string resource id.
         * @param aCommandOffset The offset of the command from the first free
         * command.
         * @param aPosition The inserting position. The default is at the top.
         */
        IMPORT_C void AddMenuItemL(CEikMenuPane& aMenuPane, TInt aStringRes,
            TInt aCommandOffset, TInt aPosition = 0);

        /**
         * Notify editor view.
         * This is used by the Bio Control for notifying the Editor Base
         * framework of an event, and usually for requesting something to
         * be done.
         */
        IMPORT_C TBool NotifyEditorViewL( 
            TMsgBioControlEventRequest aRequest,
            TInt aDelta = 0);

        /**
         * Call from base class if extension interface is supported.
         * @param Interface for bio control extension. Ownership is not taken.
         */
        IMPORT_C void SetExtension(MMsgBioControlExtension* aExt);    


    private: // new functions

        /**
        * Sets the bio body control reference.
        * Used only by CMsgBioBodyControl.
        * @param aBioBodyControl Address of the bio body control.
        */
        void SetBioBodyControl( MMsgBioBodyControl* aBioBodyControl );

        /// deprecated
        TBool IsNear(TInt aLafPos, TInt aPos) const;

    private: // not available

        /**
         * Default constructor hidden away
         */
        CMsgBioControl();

        /**
         * Copy constructor prohibited.
         */
        CMsgBioControl(const CMsgBioControl& aSource);

        /**
         * Assignment operator prohibited.
         */
        const CMsgBioControl& operator=(const CMsgBioControl& aSource);

    protected:

        /// Reference to the MMsgBioControlObserver
        MMsgBioControlObserver& iBioControlObserver;

        /// Id of the message in the server.
        TMsvId          iId;

    private:

        /**
         * Pointer to Message Server session. It is NOT owned here.
         * The reason for using pointer type is that the session is optional.
         * It can be NULL without implying any error.
         * This session is accessed using the function MsvSession().
         */
        CMsvSession*    iMsvSession;

        /// Tells if the control was launched in editor or viewer mode.
        TMsgBioMode iMode;

        /**
         * * Deprecated -> To be removed* 
         * Handle is valid only during contruction phase.
         * A pointer to the handle of the input file, not owned.
         * Accessed using FileHandle().
         * See also function FileBased().
         */
		const RFile* iFile;
		
        /**
         * A pointer to Bio control extension interface. It is not owned here.
         */
        MMsgBioControlExtension* iExt;

        // Filler needed to keep this object's size the same.
        // Let the compiler calculate the filler size needed using sizeof.
        TUint8 iBCFiller[sizeof(TFileName) - sizeof(TFileName*) - sizeof(MMsgBioControlExtension*)];
        

        /// This is the array of resource offsets.
        CArrayFixFlat<TInt>* iResourceOffsets;

        /// Pointer to the bio bodycontrol.
        MMsgBioBodyControl* iBioBodyControl;
        
        /// status flags
        TInt iBCStatusFlags;

    private:

        friend class CMsgBioBodyControl;

        };

#endif // MSGBIOCONTROL_H

// End of file
