//
//  ViewController.m
//  sy_02
//
//  Created by user-pc on 16/1/14.
//  Copyright © 2016年 user-pc. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)onLogin:(id)sender {
    
    NSLog(@"name = %@,password = %@",[_username text],[_password text]);
}

@end
