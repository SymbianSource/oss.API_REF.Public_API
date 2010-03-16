/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  
*     A UI control used by Smart Messaging Viewers.
*
*/



#ifndef _CRICHBIO_H_
#define _CRICHBIO_H_

// INCLUDES

#include <coecntrl.h>           // CCoeControl
#include <badesca.h>            // CDesC16ArrayFlat
#include <txtfrmat.h>           // TCharFormat
#include <MsgEditor.hrh>        // TMsgCursorLocation

// DATA TYPES

/**
 * This enumeration defines the types of CRichBio
 * No longer used meaningfully but defined for BC
 *
 */
enum TRichBioMode
    {
    ERichBioModeEditorBase,
    ERichBioModeStandard
    };

// FORWARD DECLARATIONS

class CEikRichTextEditor;
class CMsgExpandableControlEditor;

/**
 * A UI control used by Smart Messaging Viewers.
 * This control owns an editor, which is capable of viewing rich text content.
 * NOTE! This is only intended for use with the Smart Message Viewers.
 */
class CRichBio : public CCoeControl
    {
    public: // construction

        /**
         * Two-phased constructor. Constructs the complete object.
         * The parent control has to have a container window at this stage.
         * The type (TRichBioMode) is legacy code and has no effect on the
         * construction or use of the object. Either ERichBioModeEditorBase
         * or ERichBioModeStandard can be used with the same effect
         * @param aParent The parent control.
         * @param aMode Either ERichBioModeEditorBase or ERichBioModeStandard
         * @return a pointer to the created object.
         */
        IMPORT_C static CRichBio* NewL( const CCoeControl* aParent,
            TRichBioMode aMode );

        /**
         * Constructor.
         * ConstructL must be called after the container window is get.
         * The type (TRichBioMode) is legacy code and has no effect on the
         * construction or use of the object. Either ERichBioModeEditorBase
         * or ERichBioModeStandard can be used with the same effect
         * @param aMode Either ERichBioModeEditorBase or ERichBioModeStandard
         */
        IMPORT_C CRichBio( TRichBioMode aMode );

        /**
         * Second phase constructor.
         * The parent control has to have a container window at this stage.
         * @param aParent The parent control, which has container window.
         */
        IMPORT_C void ConstructL( const CCoeControl* aParent );

    public: // destruction

        /**
         * Destructor
         */
        ~CRichBio();

    public: // own methods

        /**
         * Adds a label and value pair.
         * The client does not need to check the length of the strings. This function will
         * wrap strings that are too long.
         * @param aLabel text to displayed in label text format.
         * @param aValue text to displayed in text format.
         */
        IMPORT_C void AddItemL(const TDesC& aLabel, const TDesC& aValue);

        /**
         * This is needed for scrolling with Editor Base.
         * @return TRect Returns the rectangle of the "current" line.
         */
        IMPORT_C TRect CurrentLineRect();

        /**
         * For accessing the richtext editor.
         * Must not be called before ConstructL has been called.
         * @return Reference to the CEikRichTextEditor
         * @exception Panics if the iEditor is NULL.
         */
        IMPORT_C CEikRichTextEditor& Editor();

        /**
         * Is the editor base mode on.
         * @return ETrue if it is in Editor Base mode.
         */
        IMPORT_C TBool IsEditorBaseMode() const;

        /**
         * Empties the data contents.
         */
        IMPORT_C void Reset();

        /**
        * Returns the preferred size of the control.
        * @param aSize Control may set its preferred size
        */
        IMPORT_C void SetAndGetSizeL( TSize& aSize );

        /**
        * Returns the rich text virtual length.
        * @return text length in rich text.
        */
        IMPORT_C TInt VirtualHeight();

        /**
        * Returns the current cursor position.
        * Even in the viewer mode control contains a hidden cursor.
        * This method return its position.
        * @return a position of the hidden cursor relative to the virtual length.
        */
        IMPORT_C TInt VirtualVisibleTop();

        /**
        * Find out if the cursor is at a certain position.
        * @param aLocation indicates either that the cursor is at the topmost
        * position of the control or at the bottom most position.
        * @return ETrue if the cursor is at the specified position, EFalse otherwise.
        */
        IMPORT_C TBool IsCursorLocation(TMsgCursorLocation aLocation) const;

        /**
         * Performs the internal scrolling of control if needed.
         * @since 3.2
         *
         * @param aPixelsToScroll Amount of pixels to scroll.
         * @param aDirection      Scrolling direction.
         * @return Amount of pixels the where scrolled. Zero value means the component cannot
         * be scrolled to that direction anymore
         */

        IMPORT_C TInt ScrollL( TInt aPixelsToScroll, TMsgScrollDirection aDirection );
        
        /**
         * Prepares control for viewing.
         * @since 3.2
         * @param aEvent	The event type
         * @param aParam Event related parameters
         */
        IMPORT_C void NotifyViewEvent( TMsgViewEvent aEvent, TInt aParam );

    public: // from CCoeControl

        TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

    private: // Helper methods.

        /**
        * Applies the format of label text to viewer.
        * @param aFormat Character format to be applied.
        * @param aMask Character format mask
        */
        void ApplyLabelFormat(TCharFormat& aFormat, TCharFormatMask& aMask);

        /**
        * Applies the format of value text to viewer.
        * @param aFormat Character format to be applied.
        * @param aMask Character format mask
        */
        void ApplyValueFormat(TCharFormat& aFormat, TCharFormatMask& aMask);

        /**
        * Applies the format of value and label text to viewer.
        * @param aFormat Character format to be applied.
        * @param aMask Character format mask
        * @aIsLabel Determines is the text label or value.
        */
        void ApplyFormat(TCharFormat& aFormat, TCharFormatMask& aMask, TBool aIsLabel);

        /**
        * Appends text to RichText viewer.
        * @param aLabel Label text
        * @param aValue value text
        */
        void AddItemToRichTextL(const TDesC& aLabel, const TDesC& aValue);

        /**
        * Add text to viewer, checks and removes linefeeds and carriage returns
        * @param aText text to be added
        * @param aFormat Character format
        * @param aMask Character format mask
        */
        void AppendTextL( const TDesC& aText,
            const TCharFormat& aFormat,
            const TCharFormatMask& aMask );

        /**
        * Checks either cache exists or not.
        * @return TBool exists cache or not
        */
        TBool CacheExists();

        /**
        * Adds items to richtext from cache.
        */
        void LoadFromCacheL();

        /**
        * Adds item to cache
        * @param aLabel label text
        * @param aValue value text
        */
        void CacheItemL(const TDesC& aLabel, const TDesC& aValue);

        /**
        * panic wrapper
        * @param aCode panic code.
        */
        static void Panic( TInt aPanic );



    private:

        /**
         * Default constructor prohibited
         */
        CRichBio();

        /**
         * Copy constructor hidden away.
         */
        CRichBio(const CRichBio& aSource);

        /**
         * Assignment operator hidden away.
         */
        const CRichBio& operator=(const CRichBio& aSource);

    private: // from CCoeControl

        void Draw(const TRect& aRect) const;

        TInt CountComponentControls() const;

        CCoeControl* ComponentControl(TInt aIndex) const;

        void SizeChanged();

    private:

        /// Introduce inner class.
        class CEdwinSizeObserver;

        /// Declare inner class friend.
        friend class CEdwinSizeObserver;

        /// Pointer to the editor size observer.
        CEdwinSizeObserver* iEdwinSizeObserver;

        /// Editor control
        CMsgExpandableControlEditor* iEditor;

        /// preserved for binary compatibility
        TInt iVirtualHeight;

        // startup cache for data
        CDesC16ArrayFlat* iLabelCache;

        // startup cache for data
        CDesC16ArrayFlat* iValueCache;

        // Editor Base mode on or off.
        const TRichBioMode iMode;

        /// is first item
        TBool iIsFirstItem;

    private:
        friend class T_RichBioTestSuite;
    };

#endif //_CRICHBIO_H_

// end of file
