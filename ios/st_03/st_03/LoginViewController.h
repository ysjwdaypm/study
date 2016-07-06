//
//  LoginViewController.h
//  st_03
//
//  Created by user-pc on 16/1/14.
//  Copyright © 2016年 user-pc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController

@property(weak,nonatomic) NSString* name;

@property (weak, nonatomic) IBOutlet UILabel *msg;

@end