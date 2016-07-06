//
//  ViewController.m
//  st_03
//
//  Created by user-pc on 16/1/14.
//  Copyright © 2016年 user-pc. All rights reserved.
//




/*
 
 1、简单方式（从Xib加载UIView比较原始的方法）
 
 这种方式仅仅适用于只有一个视图并且没有任何其他交互绑定。除了对Cocoa的初学阶段比较有容易理解之外，这种方式真的没有什么特别的优势
 
 首先使用[NSBundle loadNibNamed:owner:options]方法，只带第一个参数。
 
 只要把以下代码放到你控制器（Controller）的 implementation块里面；
 
 // Instantiate the nib content without any reference to it.
 NSArray *nibContents = [[NSBundle mainBundle] loadNibNamed:@"EPPZPlainView" owner:nil options:nil];
 
 // Find the view among nib contents (not too hard assuming there is only one view in it).
 UIView *plainView = [nibContents lastObject];
 
 // Some hardcoded layout.
 CGSize padding = (CGSize){ 22.0, 22.0 };
 plainView.frame = (CGRect){padding.width, padding.height, plainView.frame.size};
 
 // Add to the view hierarchy (thus retain).
 [self.view addSubview:plainView];
 
 
 2、引用方式（更加明确一点）
 
 这种方式跟上有方式比相当于是上一种方式的更进一步，我们需要定义一个明确的应用来对应一个View. 有一点比较麻烦的地方就是你需要在你的控制器类里面定义一个视图链接属性来跟你的视图链接起来。这主要是使这个方法太具体化，或者可以说是移植性差
 
 @interface EPPZViewController ()
 
 // Define an outlet for the custom view.
 @property (nonatomic, weak) IBOutlet UIView *referencedView;
 // An action that triggers showing the view.
 -(IBAction)showReferencedView;
 
 @end
 
 @implementation EPPZViewController
 
 -(IBAction)showReferencedView
 {
 // Instantiate a referenced view (assuming outlet has hooked up in XIB).
 [[NSBundle mainBundle] loadNibNamed:@"EPPZReferencedView" owner:self options:nil];
 
 // Controller's outlet has been bound during nib loading, so we can access view trough the outlet.
 [self.view addSubview:self.referencedView];
 }
 
 @end
 　　上面这段代码是指，你可以在界面编辑器里面定义一个上下文view（实际上是一个包裹器，或者说是一个容器）。这对于在XIB文件里面定义一个上下有关联的布局视图来说真的非常有用（比使用代码布局方便多了）。但同时你需要知道界面编辑器的设置。File's Owner这里必须设置为控制器的实例并且Outlets里面的referencedView这里必须要跟一个你的视图（View）关联在一起。
 */


#import "ViewController.h"
#import "LoginViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //九宫格布局
         int totalloc=3;
         CGFloat appviewW=80;
         CGFloat appviewH=90;
         CGFloat margin=(self.view.frame.size.width-totalloc*appviewW)/(totalloc+1);
            for (int i=0; i<20; i++) {
        
                 int row=i/totalloc;
                 int loc=i%totalloc;
                 CGFloat appviewX=margin + (margin +appviewW)*loc;
                 CGFloat appviewY=margin + (margin +appviewH)*row;
        
                 //拿出xib视图
                 NSArray  *apparray= [[NSBundle mainBundle]loadNibNamed:@"View" owner:nil options:nil];
                 UIView *appview=[apparray firstObject];
                 //加载视图
                 appview.frame=CGRectMake(appviewX, appviewY, appviewW, appviewH);
        
                NSString* v = [NSString stringWithFormat:@"%d",i];
        
                 UILabel *label=(UILabel *)[appview viewWithTag:1];
                 label.text = v;
            
                 [self.view addSubview:appview];
             }
    
    
    NSLog(@" hash =  %d",[self hash]);
    
    
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    
    if([segue.identifier isEqualToString:@"SendValue"]){
        LoginViewController* c = segue.destinationViewController;
        c.name = @"xiexie";
    }
    
}

- (IBAction)login:(id)sender {
    
//    NSLog(@"click in first window");
//    LoginViewController* c = [[LoginViewController alloc] init];
//    [self presentViewController:c animated:YES completion:^{
//        
//        NSLog(@"show window success");
//    }];
    
//    [self performSegueWithIdentifier:@"SendValue" sender:self];
}

@end
