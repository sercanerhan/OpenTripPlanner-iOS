//
//  OTPDirectionsInputViewController.h
//  OpenTripPlanner
//
//  Created by asutula on 9/10/12.
//  Copyright (c) 2012 OpenPlans. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <RestKit/RestKit.h>

#import "RouteMe.h"

#import "OTPTransitTimeViewController.h"
#import "OTPGeocodedTextField.h"

typedef enum {
    WALK_TRANSIT,
    BIKE_TRANSIT,
    WALK,
    BIKE
} kTransitModeType;

@protocol OTPDirectionsInputViewControllerDelegate;

@interface OTPDirectionsInputViewController : UIViewController <RKObjectLoaderDelegate, UITextFieldDelegate, RMMapViewDelegate, OTPTransitTimeViewControllerDelegate>
{
    UISegmentedControl *_modeControl;
    UIView *_textFieldContainer;
    OTPGeocodedTextField *_fromTextField;
    OTPGeocodedTextField *_toTextField;
    UITextField *_dummyField;
    UISegmentedControl *_switchFromAndToButton;
    RMMapView *_mapView;
    
    NSNumber *_arriveOrDepartByIndex;
    NSDate *_date;
    
    RMUserLocation *_userLocation;
}

@property (nonatomic, strong) IBOutlet UISegmentedControl *modeControl;
@property (nonatomic, strong) IBOutlet UIView *textFieldContainer;
@property (nonatomic, strong) IBOutlet OTPGeocodedTextField *fromTextField;
@property (nonatomic, strong) IBOutlet OTPGeocodedTextField *toTextField;
@property (nonatomic, strong) IBOutlet UITextField *dummyField;
@property (nonatomic, strong) UISegmentedControl *switchFromAndToButton;
@property (nonatomic, strong) IBOutlet RMMapView *mapView;
@property (nonatomic, strong) NSNumber *arriveOrDepartByIndex;
@property (nonatomic, strong) NSDate *date;
@property (nonatomic, strong) RMUserLocation *userLocation;

- (void) planTripFrom:(CLLocationCoordinate2D)startPoint to:(CLLocationCoordinate2D)endPoint;
//- (void) planTripFromCurrentLocationTo:(CLLocationCoordinate2D)endPoint;
//- (void) planTripToCurrentLocationFrom:(CLLocationCoordinate2D)startPoint;

- (IBAction)updatedTextField:(id)sender;
- (IBAction)doneEditingTextField:(id)sender;

@end