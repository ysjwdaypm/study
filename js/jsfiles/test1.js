// debug("hello world from js");


// Array.prototype.toString = function(){
// 	return "hahahaha";
// }

// Array.prototype.show = function(){
// 	return "show";
// }

// var l = [12,34];
// debug(l.toString());
// debug(l.show());

// var name = "out";

// (function(width,height){


	
// 	var name = "inner";
// 	function innerFunction(){
// 		debug("innerFunction() 1" + this.name)
// 	}
	
// 	return function(a){

// 		return function(b){

// 			return function(c){
// 				debug("width:"+width+"height:"+height);
// 				debug(this.name);
// 				debug(a + b + c);


// 			}
// 		}
// 	}

// })(1200,5000)("ysj")("wda")("ypm")


// var fo = {
// 	name : "test",
// 	show  : function(){
// 		return "i am a " + this.name;
// 	}
// }

// debug(fo.show());

// var ch = {
// 	name : "child",

// 	toString : function(fun){
// 		debug(fun());
// 		return "i am a " + this.name;
// 	}
// }

// debug(ch.toString(fo.show));


function Point(x,y) {
	// body...
}

(function() {
	// body...


	function showTime() {
		var t = new Date();
		var nowTime = t.getTime();

		debug(nowTime)

		return nowTime;
	}

	var n = showTime();

	var cnt = 0;
	var p = new Point(12, 23);
	for (var i = 10000000; i >= 0; i--) {
		cnt += i;
		p.x = cnt;
	}

	debug("total = " + (showTime() - n));


	for(var key in new Date()){
		debug("key = " + key);
	}

	
	
})();


// debug("---------------------------------------");

// function showTime() {
// 		var t = new Date();
// 		var nowTime = t.getTime();
// 		debug(nowTime)

// 		return nowTime;
// 	}

// 	var n = showTime();

// 	var cnt = 0;
// 	for (var i = 10000000; i >= 0; i--) {
// 		cnt += i;
// 	}

// 	debug("total = " + (showTime() - n));

var hello = (function() {
	var name1 = "hello out";
	var instance;
	var o = {};

	getInstance = function(args) {
		if (instance) {
			return instance;
		}
		
		debug("----------------");
		instance = o;
		init();
		return instance;
	};

	init = function(){
		o.name1 = "asdad";
	}


	return getInstance;
}());


// debug(hello().name1);
// debug(hello().name1);
// debug(hello());
// debug(hello());
// hello();
// hello();
// debug(this.name1);
var instance = new hello();
debug(instance.name1);
debug(new hello().name1);


