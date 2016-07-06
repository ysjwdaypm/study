


public class St{


	public St(){
		User u = new User();
		u.name = "ysjsa";
		log(u.name);

		u.age = 1234;
		log(u.age);
	}

	public static void main(String []args){
		new St();
	}

	public <T> void log(T info){
		System.out.println("" + info);
	}


	class User{

		public String name;
		public int age;
	}
}