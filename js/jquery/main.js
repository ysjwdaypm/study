
var name = "this class";

function startJs()
{
	console.log("start")
	$("#btn").on("click",function(evt)
	{
		// alert("click me")
		this.value = "clicked";
		this.style.color = "red";
		// updateDom();
		$("#sp").html("this is a span word");
		console.log("click = " + this);
	});
	console.log($("input#btn"));

	// $("input#name").val("test")
	$("input#name").attr("placeholder","input some");
	$("input#name").attr("style","color : blue;");
	$("#b").html("login");
	console.log($("input#name").attr("style"));
	$("#b").click(function(e){

		// alert("click b");
		this.style.color = "orange";

	});

	$("#sp>p").html("this is a p seg");


	console.log("this = " + this);


	var fun = function(){
		console.log("fun = " + this);
	}
	fun();

	var f = function(){
		console.log("f = " + this)
		return "123";
	}

	// var name = "The Window";   
　　var object = {   
　　　　name : "My Object",  
　　　　getNameFunc : function(){
	   // var name = "internal"; 	   
　　　　　　return function(){   
　　　　　　　　return name;  
　　　　　};   
　　　　}   
	};   

	// alert(object.getNameFunc()());  //The Window
}





function getWether(){

	$.ajax({
	  url: "/api/getWeather",
	  data: {
	    zipcode: 97201
	  },
	  success: function( data ) {
	    $( "#weather-temp" ).html( "<strong>" + data + "</strong> degrees" );
	  }
	});

}


function updateDom(){
	// alert("sss")
	$("#sp").html("this is a span word");
}