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
* Description:  Logical feedback type enumeration. 
* Part of:      Tactile Feedback.
*
*/


#ifndef TOUCHLOGICALFEEDBACK_H
#define TOUCHLOGICALFEEDBACK_H

#include <e32std.h>

/**  
 *  Pointer event types, that can be used when registering
 *  areas to registry. 
 */
enum TTouchEventType
    {
    ETouchEventStylusDown,
    ETouchEventStylusUp,
    ETouchEventStylusPressDown,
    ETouchEventStylusPressUp
    };
    
/**  
 *  Logical feedback types, that can be used when producing direct
 *  feedback, or when registering areas to area registry.
 *
 *  Notice, that client application cannot decide the actual physical
 *  feedback that shall be generated. It depends on device configuration,
 *  and current settings. In current devices the user changeable settings
 *  includes vibra and sound feedbacks.
 *
 *  Instructions for using these feedback types:
 *
 *  ETouchFeedbackNone      - Use for disabling feedback for some areas of
 *                            window when using area registry.
 *
 *  ETouchFeedbackBasic     - Use as default feedback for pen down events.
 *                            For example, pressing a button or tab.
 *
 *  ETouchFeedbackSensitive - Sensitive feedback for those situations,
 *                            where the triggering action is not very 
 *                            important (e.g. change focus in list), or when
 *                            there can be a large amount of feedbacks in
 *                            a short time (e.g. text selection which gives
 *                            feedback on every new selected character).
 *                            Also used for scrolling and dragging.
 *
 *  Different UI components have specific feedback types, which should be 
 *  used to maintain similar feedback behaviour in components of same type.
 *
 */
enum TTouchLogicalFeedback
    {
    ETouchFeedbackNone = 0,
    ETouchFeedbackBasic,
    ETouchFeedbackSensitive,
    // New types for S60 5.2:
    ETouchFeedbackBasicButton = 0x100,    
    ETouchFeedbackSensitiveButton,
    ETouchFeedbackList,
    ETouchFeedbackSensitiveList,
    ETouchFeedbackBoundaryList,    
    ETouchFeedbackSlider,
    ETouchFeedbackEdit,
    ETouchFeedbackLineSelection,
    ETouchFeedbackBlankSelection,
    ETouchFeedbackTextSelection,
    ETouchFeedbackEmptyLineSelection,
    ETouchFeedbackTab,
    ETouchFeedbackPopUp,
    ETouchFeedbackIncreasingPopUp,
    ETouchFeedbackDecreasingPopUp,
    ETouchFeedbackFlick,
    ETouchFeedbackCheckbox,
    ETouchFeedbackSensitiveInput,
    ETouchFeedbackCharacterInputButton,
    ETouchFeedbackMultiTouchRecognized
    };
    
/**  
 *  Logical feedback types for producing continuous feedback.
 *
 */
enum TTouchContinuousFeedback
    {
    ETouchContinuousSmooth = 0x300, // For generic continuous feedback for custom controls
    ETouchContinuousSlider,
    ETouchContinuousInput,
    ETouchContinuousFlick
    };
    
/**  
 *  Physical feedback types as bitmask.
 *
 */  
enum TTouchFeedbackType
    {
    ETouchFeedbackAudio = 0x01,
    ETouchFeedbackVibra = 0x02
    };

#endif // TOUCHLOGICALFEEDBACK_H
