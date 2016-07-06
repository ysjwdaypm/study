//
//  LoginViewController.m
//  st_03
//
//  Created by user-pc on 16/1/14.
//  Copyright © 2016年 user-pc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LoginViewController.h"


@interface LoginViewController ()

@end

@implementation LoginViewController


-(void) viewDidLoad{
    
    [super viewDidLoad];
//    self.view.backgroundColor = [UIColor purpleColor];
     NSLog(@"click in second window name = %@",[self name]);
    
    UIButton* btn = [[UIButton alloc] init];
    [btn setFrame:CGRectMake(130, 100, 100, 40)];
    [btn setTitle:@"返回" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
    
//    self a
    [self.view addSubview:btn];
    
}

-(void) back{
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];
}


- (IBAction)login:(id)sender {
     NSLog(@"click in second window");
}

@end