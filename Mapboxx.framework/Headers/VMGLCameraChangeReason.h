#import "VMGLFoundation.h"

/**
 :nodoc:
 Bitmask values that describe why a camera move occurred.

 Values of this type are passed to the `MGLMapView`'s delegate in the following methods:

 - `-mapView:shouldChangeFromCamera:toCamera:reason:`
 - `-mapView:regionWillChangeWithReason:animated:`
 - `-mapView:regionIsChangingWithReason:`
 - `-mapView:regionDidChangeWithReason:animated:`

 It's important to note that it's almost impossible to perform a rotate without zooming (in or out),
 so if you'll often find `MGLCameraChangeReasonGesturePinch` set alongside `MGLCameraChangeReasonGestureRotate`.

 Since there are several reasons why a zoom or rotation has occurred, it is worth considering
 creating a combined constant, for example:

 ```
 static const MGLCameraChangeReason anyZoom = MGLCameraChangeReasonGesturePinch |
                                                MGLCameraChangeReasonGestureZoomIn |
                                                MGLCameraChangeReasonGestureZoomOut |
                                                MGLCameraChangeReasonGestureOneFingerZoom;

 static const MGLCameraChangeReason anyRotation = MGLCameraChangeReasonResetNorth | MGLCameraChangeReasonGestureRotate;
 ```
 */
typedef NS_OPTIONS(NSUInteger, VMGLCameraChangeReason)
{
    /// :nodoc: The reason for the camera change has not be specified.
    VMGLCameraChangeReasonNone = 0,

    /// :nodoc: Set when a public API that moves the camera is called. This may be set for some gestures,
    /// for example MGLCameraChangeReasonResetNorth.
    VMGLCameraChangeReasonProgrammatic = 1 << 0,

    /// :nodoc: The user tapped the compass to reset the map orientation so North is up.
    VMGLCameraChangeReasonResetNorth = 1 << 1,

    /// :nodoc: The user panned the map.
    VMGLCameraChangeReasonGesturePan = 1 << 2,

    /// :nodoc: The user pinched to zoom in/out.
    VMGLCameraChangeReasonGesturePinch = 1 << 3,

    // :nodoc: The user rotated the map.
    VMGLCameraChangeReasonGestureRotate = 1 << 4,

    /// :nodoc: The user zoomed the map in (one finger double tap).
    VMGLCameraChangeReasonGestureZoomIn = 1 << 5,

    /// :nodoc: The user zoomed the map out (two finger single tap).
    VMGLCameraChangeReasonGestureZoomOut = 1 << 6,

    /// :nodoc: The user long pressed on the map for a quick zoom (single tap, then long press and drag up/down).
    VMGLCameraChangeReasonGestureOneFingerZoom = 1 << 7,

    // :nodoc: The user panned with two fingers to tilt the map (two finger drag).
    VMGLCameraChangeReasonGestureTilt = 1 << 8,

    // :nodoc: Cancelled
    VMGLCameraChangeReasonTransitionCancelled = 1 << 16

};
