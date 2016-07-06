import java.util.Arrays;
import java.util.Date;
import java.lang.Math;
import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;

public class Test{

	public static void main(String [] args){


		Utils.show(args);
		Utils.show(System.nanoTime());
		// System.out.println("hello world");

		// String [] info = {"1","2","3"};

		// Utils.show(info);

		// String[] c = Arrays.copyOfRange(info,1,2);
		// Utils.show(c);

		// int[] ages = {12,23,34,11,5};
		// Utils.showInts(ages);

		// Arrays.sort(ages);
		// Utils.showInts(ages);

		// Base obj = new Base(){

		// 	public void show(){
		// 		System.out.println("hahahah");
		// 	}
		// };

		// obj.show();


		// Utils.show(123);

		// Utils.show(new Date().getTime());
		// Utils.show(Math.ceil(1.2));
		// Utils.show(Math.random());
		
		// Scanner input = new Scanner(System.in);
		// int a = input.nextInt();
		// Utils.show(a);
		Frame f = new Frame("my Frame");


		f.setVisible(true);
		f.setBackground(Color.RED);
		f.setSize(400,400);

		Panel p = new Panel();
		p.setLayout(null);
		p.setBackground(Color.GREEN);
		p.setBounds(1,1,200,200);
		f.add(p);

		Button btn = new Button("click me");
		btn.setBackground(Color.BLUE);
		btn.setBounds(100,100,100,30);
		p.add(btn);

		f.addWindowListener(new WindowAdapter(){

			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}

}

interface Base{
	public void show();
}


class Utils{

	public static <T> void show(T[] info){
		for(int i=0;i<info.length;i++){
			System.out.println(""+info[i]);
		}

		showLine();
	}

	public static void show(Object obj){
		System.out.println(obj);
		showLine();
	}

	public static void showLine(){
		System.out.println("----------------------------------------");
	}

	public static void showInts(int[] info){
		for(int i=0;i<info.length;i++){
			System.out.println(""+info[i]);
		}
	}
}